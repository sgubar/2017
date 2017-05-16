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

int sozd(void)
{
int i;
int size;
system("cls");
printf("Enter the number of books you want to enter: ");
size = valid_i();
struct polka *m;
m = &mas[0];
for (i = 0; i < size; i++)
{
void add( int size);
}
return size;
}

void del(int size)
{
int i;
int number;
struct polka *m;
m = &mas[0];
system("cls");
shov(size, 0);
printf("Enter the number you want to delete: ");
number = valid_i();
for (i = number; i < size; i++)
{
mas[i] = mas[i + 1];
}
}

void shov(int size, int flag)
{
int i;
struct polka *m;
m = &mas[0];
system("cls");
for (i = 0; i < size; i++)
{
printf("%i %s %s\n", i, m[i].avtor, m[i].nazva);
}
if (flag == 1)
getch();
}

int valid_i(void)
{
char simvol[20];
int z = 0, k, res;
do
{
fflush(stdin);
scanf("%s", &simvol);
while (getchar() != '\n');
while (simvol[z] >= '0' && simvol[z] <= '9')
z++;
res = atoi(simvol);
if (simvol[z])
printf("You have entered an invalid value, try again: ");
else
return res;
} 
while (simvol[z]);
}
