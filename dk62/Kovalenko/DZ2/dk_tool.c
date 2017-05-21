#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

list *create(int size)
{
    list *Tlist=(list *)malloc(sizeof(list));
    if(Tlist!=NULL)                                           
    {
        Tlist->Ttriangle=(triangle *)malloc(size*(sizeof(triangle)));
        Tlist->CurrentTtriangle=0;
        Tlist->mtriangle=size;
    }
    return Tlist;
}
int scan_f(void)
	{
     int num = 0;
			
     scanf("%d", &num);

	return num;
    }
int data(list *Tlist, int X1, int Y1, int X2, int Y2, int X3, int Y3)
{
    if(Tlist->CurrentTtriangle<Tlist->mtriangle)
    {
        triangle *Ttriangle=&(Tlist->Ttriangle[Tlist->CurrentTtriangle]);  
        
		if (Ttriangle!=NULL)
        {
            Ttriangle->A=(point *)malloc(sizeof(point));
            Ttriangle->B=(point *)malloc(sizeof(point));
            Ttriangle->C=(point *)malloc(sizeof(point));
            Ttriangle->A->X=X1;
            Ttriangle->A->Y=Y1;
            Ttriangle->B->X=X2;
            Ttriangle->B->Y=Y2;
            Ttriangle->C->X=X3;
            Ttriangle->C->Y=Y3;
            Tlist->CurrentTtriangle++;

        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}
void space_size(list *Tlist)
{
    if(Tlist!=NULL)
    {
        if(Tlist->Ttriangle!=NULL)
        {
        	int i=0;
            for(i=0; i<Tlist->CurrentTtriangle; i++)
            {
                triangle *Ttriangle=&(Tlist->Ttriangle[i]);
                if (Ttriangle->A!=NULL&&Ttriangle->B!=NULL&&Ttriangle->C!= NULL)
                {
                    free(Ttriangle->A);
                    free(Ttriangle->B);
                    free(Ttriangle->C);
                }
            }
            free(Tlist->Ttriangle);
        }
        free(Tlist);
    }
}
int area(triangle *Ttriangle)
{
    int Area=abs((Ttriangle->A->X-Ttriangle->C->X)*(Ttriangle->B->Y-Ttriangle->C->Y)-(Ttriangle->B->X-Ttriangle->C->X)*(Ttriangle->A->Y-Ttriangle->C->Y));
    return Area;
}

void Print(list *Tlist)
{
	int i=0;
    for(i=0; i<Tlist->CurrentTtriangle; i++)
    {
    triangle *Ttriangle=&(Tlist->Ttriangle[i]);
        printf("triangle #%d:\n", i);
        printf("place A={%d,%d}\n", Ttriangle->A->X, Ttriangle->A->Y);
        printf("place B={%d,%d}\n", Ttriangle->B->X, Ttriangle->B->Y);
        printf("place C={%d,%d}\n", Ttriangle->C->X, Ttriangle->C->Y);
        printf("area=%d\n", area(Ttriangle));
    }
}
