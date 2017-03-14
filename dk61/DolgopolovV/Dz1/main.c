#include "dk_tool.h"

int main(void) 
{ 
int size;
printf("Size massiva = ");
scanf("%d",&size);
int mas[size], obmen;

reading(size, mas);
swap(size, mas, obmen);
print_m(size, mas);
}
