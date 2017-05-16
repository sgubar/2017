#include "dk_tool.h"

char ch;
int size;
int main(void)
{	
while(1)
{
system("cls"); 
printf("Select one of the options:\n\n");
printf("1. Add book.\n");
printf("2. Show shelf.\n");
printf("3. Output.\n");
printf("Enter the number of the selected item:");
ch = getch();
if (ch == '1' || ch == '2' || ch == '3' )
break;
}
switch (ch)
{

case '1':
add(size);
size++;
main();
return 0;

case '2':
shov(size);
main();
return 0;

case '3':
return 0;

}
}
