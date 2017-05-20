#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dk_tool.h"
int peremennaya (char *stroka, char *slovo)
{
int otvet=0, a=0, b=0;
while(a<strlen(stroka))
{
if(stroka[a]=slovo[b])
{
do
{
a++; b++;
if (b==strlen(slovo)-1)
{
otvet++;
}
}while(stroka[a]==slovo[b]&&stroka[a]!='\0'); 
b=0;
}
else
{
a++;
}
}
return otvet;
}

