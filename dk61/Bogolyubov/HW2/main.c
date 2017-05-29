#include <stdio.h>

typedef struct tagcoord
{
	int x;
	int y;
}coord;


typedef struct tagList
{
coord *A;
coord *B;
coord *C;
coord *D;
}list;


//list ArrayList[2];
int main(void){

list *ArrayList = (list *)malloc(2 * sizeof(list)); //create array + malloc

{
ArrayList[0].A = (coord *) malloc(sizeof(coord)); 
ArrayList[0].A->x = 1;
ArrayList[0].B = (coord *) malloc(sizeof(coord));
ArrayList[0].B->x = 2;
ArrayList[0].C = (coord *) malloc(sizeof(coord));
ArrayList[0].C->x = 3;
ArrayList[0].D = (coord *) malloc(sizeof(coord));
ArrayList[0].D->x = 4;

ArrayList[0].A->y = 5;
ArrayList[0].B->y = 6;
ArrayList[0].C->y = 7;
ArrayList[0].D->y = 8;

}

int area =  ((ArrayList[0].A->x * ArrayList[0].B->y)-(ArrayList[0].A->y * ArrayList[0].B->x)+ //calculate area
            (ArrayList[0].B->x * ArrayList[0].C->y)-(ArrayList[0].B->y * ArrayList[0].C->x) + 
            (ArrayList[0].C->x * ArrayList[0].D->y)-(ArrayList[0].D->x * ArrayList[0].C->y) + 
            (ArrayList[0].D->x * ArrayList[0].A->y)-(ArrayList[0].D->y * ArrayList[0].A->x))/2;
            
            printf("AREA 1 : %i\n", area);

ArrayList[1].A = (coord *) malloc(sizeof(coord));
ArrayList[1].A->x = 12;
ArrayList[1].B = (coord *) malloc(sizeof(coord));
ArrayList[1].B->x = 24;
ArrayList[1].C = (coord *) malloc(sizeof(coord));
ArrayList[1].C->x = 65;
ArrayList[1].D = (coord *) malloc(sizeof(coord));
ArrayList[1].D->x = 32;

ArrayList[1].A->y = 91;
ArrayList[1].B->y = 17;
ArrayList[1].C->y = 34;
ArrayList[1].D->y = 37;

area =  ((ArrayList[1].A->x * ArrayList[1].B->y)-(ArrayList[1].A->y * ArrayList[1].B->x)+ 
             (ArrayList[1].B->x * ArrayList[1].C->y)-(ArrayList[1].B->y * ArrayList[1].C->x) + 
             (ArrayList[1].C->x * ArrayList[1].D->y)-(ArrayList[1].D->x * ArrayList[1].C->y) + 
             (ArrayList[1].D->x * ArrayList[1].A->y)-(ArrayList[1].D->y * ArrayList[1].A->x))/2;
            
            printf("AREA 2 : %i\n", area);


ArrayList[2].A = (coord *) malloc(sizeof(coord));
ArrayList[2].A->x = 43;
ArrayList[2].B = (coord *) malloc(sizeof(coord));
ArrayList[2].B->x = 35;
ArrayList[2].C = (coord *) malloc(sizeof(coord));
ArrayList[2].C->x = 23;
ArrayList[2].D = (coord *) malloc(sizeof(coord));
ArrayList[2].D->x = 11;

ArrayList[2].A->y = 9;
ArrayList[2].B->y = 56;
ArrayList[2].C->y = 21;
ArrayList[2].D->y = 7;

area =  ((ArrayList[0].A->x * ArrayList[0].B->y)-(ArrayList[0].A->y * ArrayList[0].B->x)+ 
            (ArrayList[0].B->x * ArrayList[0].C->y)-(ArrayList[0].B->y * ArrayList[0].C->x) + 
            (ArrayList[0].C->x * ArrayList[0].D->y)-(ArrayList[0].D->x * ArrayList[0].C->y) + 
            (ArrayList[0].D->x * ArrayList[0].A->y)-(ArrayList[0].D->y * ArrayList[0].A->x))/2;
            
            printf("AREA 3 : %i\n", area);
            
            
/*
printf("X0: %i\n ", ArrayList[0].A->x);
printf("Y0: %i\n", ArrayList[0].A->y);

printf("X1: %i\n ", ArrayList[1].A->x);
printf("Y1: %i\n", ArrayList[1].A->y);
printf("X2: %i\n ", ArrayList[2].A->x);
printf("Y2: %i\n", ArrayList[2].A->y);
*/

/*int mem = sizeof(ArrayList)/ sizeof(ArrayList[0]);
printf("mem: %i", mem);

for(int i=0;i < sizeof(ArrayList)/ sizeof(ArrayList[0]);i++){
            printf("kek");
			}
*/
return 0;
}
