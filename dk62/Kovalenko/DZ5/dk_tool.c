#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>



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
void filespace (FILE *file, list *Tlist)
{

	if(Tlist != NULL)
	{
		fprintf(file,"{");
		fprintf(file, " \"size\":%d,\n" ,Tlist->mtriangle);
		fprintf(file, " \"current_size\":%d,\n", Tlist->CurrentTtriangle);
		fprintf(file, "\"triangle\": \n" );
		fprintf(file,"\t");
		int i=0;
		for(i=0; i<Tlist -> CurrentTtriangle; i++)
		{
			triangle *Ttriangle=&(Tlist->Ttriangle[i]);
			fprintf(file,"\n\t{");
			trianglespace(file ,Ttriangle);
			if(i<Tlist -> CurrentTtriangle-1);
			{
				fprintf(file,"\n\t},");
			} 
		}	
		
	}
	else
	{
			fprintf(file,"\n","\"NULL\"");
	}
		fprintf(file,"\n}");
}
void trianglespace(FILE *file, triangle* Ttriangle)
{
    
	fprintf(file,"\n\t\t\"Spot A\":");
	
	fprintf(file, "{\"Coord X\": %d, ", Ttriangle->A->X);
	fprintf(file, "\"Coord Y\": %d},", Ttriangle->A->Y);
	
	fprintf(file,"\n\t\t\"Spot B\":");
	
	fprintf(file,"{\"Coord X\": %d, ",Ttriangle->B->X);
	fprintf(file,"\"Coord Y\": %d}," ,Ttriangle->B->Y);
	
	fprintf(file,"\n\t\t\"Spot C\":");
	
	fprintf(file,"{\"Coord X\": %d, ", Ttriangle->C->X);
	fprintf(file,"\"Coord Y\": %d}", Ttriangle->C->Y);
 
}
void InsertionSorT(list *Tlist)
{
	int i;
    for(i=1; i<Tlist->CurrentTtriangle; i++)
    {
        triangle tmp=Tlist->Ttriangle[i];
        int j=i;
        while(j>0&&area(&Tlist->Ttriangle[j-1])>=area(&tmp))
        {
            Tlist->Ttriangle[j]=Tlist->Ttriangle[j-1];
            --j;
        }
        Tlist->Ttriangle[j]=tmp;
    }
}
void shellSort(list *Tlist)
{
    int theIn=0;
    int theOut=0;
    int theH=1;
    while(theH<=((Tlist->CurrentTtriangle)/3))
    {
        theH=theH*3+1;
    }
    while(theH>0)
    {
        for(theOut=theH; theOut<Tlist->CurrentTtriangle; theOut++)
        {
            triangle theTmp=Tlist->Ttriangle[theOut];
            theIn=theOut;
            while(theIn>theH-1&&area(&Tlist->Ttriangle[theIn-theH])>=area(&theTmp))
            {
                Tlist->Ttriangle[theIn]=Tlist->Ttriangle[theIn-theH];
                theIn-=theH;
            }
            Tlist->Ttriangle[theIn]=theTmp;
        }
        theH=(theH-1)/3;
    }
}

int linefind(list *Tlist, int aKey)
{
	int i;
    int Result=0;
    for(i=0; i<Tlist->CurrentTtriangle; i++)
    {
        if(area(&Tlist->Ttriangle[i])==aKey)
        {
            Result=i;
            break;
        }
    }
    return Result;
}
