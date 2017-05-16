#include "dk_tool.h"

void add( int size)
{
struct polka *m;
m = &mas[0];
system("cls");
printf("Enter the author: ");
gets(m[size].avtor);
printf("Enter the name of the book: ");
gets(m[size].nazva);
m[size].stan = 1;
}

void shov(int size)
{
int i;
struct polka *m;
m = &mas[0];
system("cls");
for (i = 0; i < size; i++)
{
printf("%i %s %s\n", i, m[i].avtor, m[i].nazva);
}
getch();
}


