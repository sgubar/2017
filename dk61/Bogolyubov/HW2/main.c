#include <stdio.h> 
#include <math.h> 

typedef struct { 
int x; 
int y;  
}coord; 


void main(void) {
coord A; coord B; coord C; coord D;
int value_of_squares;
printf("Please, enter the number of pieces here: ");
scanf("%i", &value_of_squares);
float area;

for(int i=0;i<value_of_squares;i++){
printf("Enter x and y for point A here: "); // priem znacheniy x i y 
scanf("%i" "%i", &A.x, &A.y);
printf("Enter x and y for point B here: "); // dlya kazhdoi tochki
scanf("%i" "%i", &B.x, &B.y);
printf("Enter x and y for point C here: ");
scanf("%i" "%i", &C.x, &C.y);
printf("Enter x and y for point D here: ");
scanf("%i" "%i", &D.x, &D.y);
area =((A.x*B.y)-(A.y*B.x)+(B.x*C.y)-(B.y*C.x)+(C.x*D.y)-(D.x*C.y)+(D.x*A.y)-(D.y*A.x))/2; // calculate area
	if(area < 0){ // proverka na otricaelnuyu ploshad 
	area *=(-1);
	printf("Area of the polygon: %.2f\n", area);
	printf("\n\n\n");
}
else {
printf("Area of the polygon: %.2f\n", area);
printf("\n\n\n");
}
}
}
