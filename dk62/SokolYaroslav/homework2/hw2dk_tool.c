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
            printf("Ведіть число!!!\n");
            exit(0);
        }
    }
    if(longstring>limit+1)
    {
        printf("Ведіть меньше число!!!\n");
        exit(0);
    }
    else if(input<1)
    {
        printf("Ведіть більше число!!!\n");
        exit(0);
    }
  return input;
}
float S4kytnika(figura *figura)	//знаходження площі чотирикутника
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
    float S4kytnika=sqrt((p-a)*(p-b)*(p-c)*(p-d)-a*b*c*d*cosfi*cosfi); 
    return S4kytnika;
}
////////////struct/////////////////////////////////////////////////
spisok_figur *new_spisok_figur(int End) 
{
    spisok_figur *spisok = (spisok_figur *)malloc(sizeof(spisok_figur)); 
    if(spisok != NULL)
	{
		spisok->quadrangle = (figura *)malloc(End * sizeof(figura)); 
		spisok->N = End;    
		spisok->Flag = 0;	
	}
	return spisok;
}
int addсoord(spisok_figur *aFigure)
{
	if(NULL != aFigure )
	{
		if(aFigure -> Flag < aFigure->N)
		{
			figura *theFigure = &(aFigure->quadrangle[aFigure->Flag]);
			if( NULL != theFigure)
			{ 
			    int i=0;
			    theFigure->tochki = (tochka *)malloc(sizeof(tochka)*4); 
				for(i=0; i<4; i++)
				{
				theFigure->tochki[i].x = rand()%100;
				theFigure->tochki[i].y = rand()%100;
			    }
			    aFigure->Flag ++;
			}
		}
		else{return 0;}
	}
	else{return 0;}
    return 0;
}
void destroyFigureList(spisok_figur *aFigure) 
{
	if(NULL != aFigure)
	{
		if(NULL != aFigure-> quadrangle)
		{
			free(aFigure-> quadrangle);
		}
		free(aFigure);
	}
}
void printFigure(spisok_figur *aFigure) 
{ 
    for (int i = 0; i < aFigure->Flag; i++) 
	{ 
		figura *theFigure = &(aFigure->quadrangle[i]); 
		printf("-----------------------------\n");  	
		printf("Фігура %d:\n", i + 1); 
		for (int j = 0; j < 4; j++) 
		{ 
			printf("Точка %d має координати (%d;%d)\n", j+1, theFigure->tochki[j].x, theFigure->tochki[j].y); 
		} 
		printf("Площа чотирикутника: %f\n", S4kytnika(theFigure)); 
	}  
}
