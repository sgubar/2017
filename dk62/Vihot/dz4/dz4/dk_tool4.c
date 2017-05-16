#include "dk_tool.h"
#include <stdlib.h>

int inputint(int limit)	
{
	int input=0;
    char string[limit+1];
    fgets( string, 2147483647, stdin ); 
    int longstring =strlen(string);
    input = atoi (string);
    for(int i=0;i<limit+1;i++)
    {
        if(isalpha(string[i]))
        {
            printf("Vodim chislo.\n");
            exit(0);
        }
    }
    if(longstring>limit+1)
    {
        printf("Vodim min chislo.\n");
        exit(0);
    }
    else if(input<1)
    {
        printf("Vodim max chislo.\n");
        exit(0);
    }
  return input;
}
float Ploshcha(figura *mfigura)
{
	int xa=figura->tochki[2].x - figura->tochki[1].x, ya=figura->tochki[2].y - figura->tochki[1].y;
    int xb=figura->tochki[3].x - figura->tochki[2].x, yb=figura->tochki[3].y - figura->tochki[2].y;
    int xc=figura->tochki[4].x - figura->tochki[3].x, yc=figura->tochki[4].y - figura->tochki[3].y;
    int xd=figura->tochki[1].x - figura->tochki[4].x, yd=figura->tochki[1].y - figura->tochki[4].y;
    float a=sqrt(xa*xa+ya*ya);
    float b=sqrt(xb*xb+yb*yb);
    float c=sqrt(xc*xc+yc*yc);
    float d=sqrt(xd*xd+yd*yd);
    float acosA= acos((xa*xd+ya*yd)/(sqrt(xa*xa+ya*ya)*sqrt(xd*xd+yd*yd))); 
    float acosB= acos((xb*xc+yb*yc)/(sqrt(xb*xb+yb*yb)*sqrt(xc*xc+yc*yc)));
    float cosfi= cos((acosA+acosB)/2);
    float p=(a+b+c+d)/2;
    float Ploshcha=sqrt((p-a)*(p-b)*(p-c)*(p-d)-a*b*c*d*cosfi*cosfi); 
    return Ploshcha;
}

spisok_figur *nspisok_figur(int maxreal) 
{
    spisok_figur *spisok = (nspisok_figur *)malloc(sizeof(nspisok_figur)); 
    if(spisok != NULL)
	{
		spisok->quadrangle = (mfigura *)malloc(maxreal * sizeof(mfigura)); 
		spisok->N = maxreal;    
		spisok->Flag = 0;	
	}
	return spisok;
}
int add_coord(nspisok_figur *mfigura)
{
	if(NULL != mfigura )
	{
		if(mfigura -> Flag < figura->N)
		{
			figura *theFigure = &(figura->quadrangle[mfigura->Flag]);
			if( NULL != theFigure)
			{ 
			    int i=0;
			    theFigure->tochki = (tochka *)malloc(sizeof(tochka)*4); 
				for(i=0; i<4; i++)
				{
				theFigure->tochki[i].x = rand()%100;
				theFigure->tochki[i].y = rand()%100;
			    }
			    myfigura->Flag ++;
			}
		}
		else{return 0;}
	}
	else{return 0;}
    return 0;
}
void delete_spisok_figur(nspisok_figur *mfigura) 
{
	if(NULL != mfigura)
	{
		if(NULL != mfigura-> quadrangle)
		{
			free(mfigura-> quadrangle);
		}
		free(mfigura);
	}
}
void print_figura(nspisok_figur *mfigura) 
{ 
    for (int i = 0; i < figura->Flag; i++) 
	{ 
		figura *theFigure = &(mfigura->quadrangle[i]); 
		printf("-----------------------------\n");  	
		printf("Vigura %i:\n", i + 1); 
		for (int j = 0; j < 4; j++) 
		{ 
			printf("Kordinati tochki %i:(%i;%i)\n", j+1, theFigure->tochki[j].x, theFigure->tochki[j].y); 
		} 
		printf("Plosha viguri:%f\n", Ploshcha(theFigure)); 
	}  
}
void printinfile_spisok(FILE *file, nspisok_figur *mfigura)
{
	if (NULL == mfigura->quadrangle)
    {
	    fprintf(file, "Null");
	}
	else
	{
	for (int i = 0; i < figura->Flag; i++)
		{
				fprintf (file, "Vigura %i:\n",i+1);
				figura *theFigure = &(mfigura->quadrangle[i]);
				printinfile_figura(file, theFigure);
				if (i < (figura->Flag - 1))
				{
			}
		}
	}

}
void printinfile_figura(FILE *file, figura *mfigura)
{
	
	for (int i = 0; i < 4; i++)
    {
	fprintf(file, " %i:(%i,%i)", i+1, myfigura->tochki[i].x, myfigura->tochki[i].y);
    fprintf(file, "Kordinati tochki\n");
    }
    fprintf(file,"Plosha viguri: %f\n", Ploshcha(mfigura)); 
    fprintf(file, "-----------------------------\n");
}
void BubbleSort(nspisok_figur *mfigura) 
{   
	for(int i=mfigura->Flag-1; i>1; i--) 
	{ 
		for(int j=0; j<i; j++) 
	{ 
		if(Ploshcha(&mfigura->quadrangle[j])>Ploshcha(&mfigura->quadrangle[j+1])) 
		{ 
		figura tmp=mfigura->quadrangle[j]; 
		mfigura->quadrangle[j]=mfigura->quadrangle[j+1]; 
		mfigura->quadrangle[j+1]=tmp; 
        } 
	} 
	} 
}
