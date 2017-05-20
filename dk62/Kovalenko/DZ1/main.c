#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
int main (char *argv[],int argc)
{
char stroka[255];
char slovo[255];
printf("vvedi stroku slov:\n");
gets(stroka);
printf("vvedi iskyemoe slovo:\n");
gets(slovo);
int otvet = peremennaya (stroka, slovo);
printf("%i\n", otvet);
return 0;
}
