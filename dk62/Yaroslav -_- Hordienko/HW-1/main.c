#include <stdio.h>
#include "dk_tool.h"
#include <locale.h>

void main() {
int z = 0;
int dlinna = 0;
int visota = 0;
matrixa theLocal = {0};
int mass [10][10];
setlocale(LC_ALL, "russian_russia.1251");
matrix (&theLocal);
transp (&theLocal);
printf("Want to see the result? o | 1 \n");
scanf("%i", &z);
if (z=1){
print (&theLocal);
}
return 0;
}
