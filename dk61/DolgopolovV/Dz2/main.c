#include "dk_tool.h"


char ch;
int size;
int main(void)
{	
while(1)
{
system("cls"); 
printf("Select one of the options:\n\n");
printf("1. Populate list.\n");
printf("2. Add book.\n");
printf("3. Remove book.\n");
printf("4. Show shelf.\n");
printf("5. Output.\n");
printf("Enter the number of the selected item:");
ch = getch();
if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5')
break;
}
switch (ch)
{
case '1':
size = sozd();
main();
return 0;

case '2':
add(size);
size++;
main();
return 0;

case '3':
del(size);
size--;
main();
return 0;

case '4':
shov(size, 1);
main();
return 0;

case '5':
return 0;
}
}
