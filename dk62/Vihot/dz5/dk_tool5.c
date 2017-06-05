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
            printf("Vedit chislo!!!\n");
            exit(0);
        }
    }
    if(longstring>limit+1)
    {
        printf("Vedit max!!!\n");
        exit(0);
    }
    else if(input<1)
    {
        printf("vedit min!!!\n");
        exit(0);
    }
  return input;
}
float Ploshcha(figura *figura)	
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

spisok_figur *n_spisok_figur(int maxreal) 
{
    spisok_figur *spisok = (spisok_figur *)malloc(sizeof(spisok_figur)); 
    if(spisok != NULL)
	{
		spisok->quadrangle = (figura *)malloc(maxreal * sizeof(figura)); 
		spisok->N = maxreal;    
		spisok->Flag = 0;	
	}
	return spisok;
}
int add_coord(spisok_figur *mfigura)
{
	if(NULL != myfigura )
	{
		if(myfigura -> Flag < mfigura->N)
		{
			figura *theFigure = &(mfigura->quadrangle[mfigura->Flag]);
			if( NULL != theFigure)
			{ 
			    int i=0;
			    theFigure->tochki = (tochka *)malloc(sizeof(tochka)*4); 
				for(i=0; i<4; i++)
				{
				theFigure->tochki[i].x = rand()%100;
				theFigure->tochki[i].y = rand()%100;
			    }
			    mfigura->Flag ++;
			}
		}
		else{return 0;}
	}
	else{return 0;}
    return 0;
}
void delete_spisok_figur(spisok_figur *mfigura) 
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
void print_figura(spisok_figur *mfigura) 
{ 
    for (int i = 0; i < mfigura->Flag; i++) 
	{ 
		figura *theFigure = &(mfigura->quadrangle[i]); 
		printf("-----------------------------\n");  	
		printf("Vigure %i:\n", i + 1); 
		for (int j = 0; j < 4; j++) 
		{ 
			printf("Kordinati tichki %i:(%i;%i)\n", j+1, theFigure->tochki[j].x, theFigure->tochki[j].y); 
		} 
		printf("Plosha vigure:%f\n", Ploshcha(theFigure)); 
	}  
}
void printinfile_spisok(FILE *file, spisok_figur *mfigura)
{
	if (NULL == mfigura->quadrangle)
    {
	    fprintf(file, "Null");
	}
	else
	{
	for (int i = 0; i < mfigura->Flag; i++)
		{
				fprintf (file, "Vigure %i:\n",i+1);
				figura *theFigure = &(mfigura->quadrangle[i]);
				printinfile_figura(file, theFigure);
				if (i < (mfigura->Flag - 1))
				{
			}
		}
	}

}
void printinfile_figura(FILE *file, figura *mfigura)
{
	
	for (int i = 0; i < 4; i++)
    {
	fprintf(file, "Kordinati tochki %i:(%i,%i)", i+1, mfigura->tochki[i].x, mfigura->tochki[i].y);
    fprintf(file, "\n");
    }
    fprintf(file,"plosha figure: %f\n", Ploshcha(mfigura)); 
    fprintf(file, "-----------------------------\n");
}
void BubbleSort(spisok_figur *mfigura) 
{   
	for(int i=mfigura->Flag-1; i>1; i--) 
	{ 
		for(int j=0; j<i; j++) 
	{ 
		if(Ploshcha(&mfigura->quadrangle[j])>Ploshcha(&mfigura->quadrangle[j+1])) 
		{ 
		figura tmp=myfigura->quadrangle[j]; 
		mfigura->quadrangle[j]=mfigura->quadrangle[j+1]; 
		mfigura->quadrangle[j+1]=tmp; 
        } 
	} 
	} 
}
int BinarySearch(spisok_figur *mfigura)
{
	int Value =0;// scan_f();
	int Left = 0;
	int Right = myfigura->Flag;
	int middle = 0;
	
	while(Left < Right)
	{
		middle = (Left + Right)/2;
		if (Ploshcha(&mfigura->quadrangle[middle]) == Value)
		{
			int Result = middle;
			return Result+1;
		}
		else
		{
			if (Ploshcha(&mfigura->quadrangle[middle]) > Value)
			{
				Right = middle - 1;
			}
			else
			{
				Left = middle + 1;
			}
		}
	}
	return -1;	
}

void swap(spisok_figur *mfigura, int aLeftIndex, int aRightIndex)
{
	figura theTmp = mfigura->quadrangle[aLeftIndex];
	mfigura->quadrangle[aLeftIndex] = mfigura->quadrangle[aRightIndex];
	mfigura->quadrangle[aRightIndex] = theTmp;
}
int mediana(spisok_figur *mfigura, int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;
	
	
	if (Ploshcha(&myfigura->quadrangle[aLeftIndex]) > Ploshcha(&myfigura->quadrangle[theCenter]))
	{
		swap(figura, aLeftIndex, theCenter);
	}

	if (Ploshcha(&mfigura->quadrangle[aLeftIndex]) > Ploshcha(&mfigura->quadrangle[aRightIndex]))
	{
		swap(mfigura, aLeftIndex, aRightIndex);
	}

	if (Ploshcha(&mfigura->quadrangle[theCenter]) > Ploshcha(&mfigura->quadrangle[aRightIndex]))
	{
		swap(mfigura, theCenter, aRightIndex);
	}
	
	swap(mfigura, theCenter, aRightIndex - 1);
	
	
	return Ploshcha(&mfigura->quadrangle[aRightIndex-1]);;
}

int m_partitionIt(spisok_figur *mfigura, int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex-1;
	
	while (1)
	{
		// search the bigest element
		while (Ploshcha(&yfigura->quadrangle[++theLeft]) < aPivot);
	
		// search the lowest element
		while (Ploshcha(&mfigura->quadrangle[--theRight]) > aPivot);
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			swap(mfigura, theLeft, theRight);
		}
	}

	//lets to swap elements
	swap(mfigura, theLeft, aRightIndex-1);

	return theLeft; // return break position
}

void quickSort2(spisok_figur *mfigura, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	if (theSize <= 3)
	{
		m_manualSort(mfigura, aLeftIndex, aRightIndex);
	}
	else
	{
		int thePivot = mediana(mfigura, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(mfigura, aLeftIndex, aRightIndex, thePivot);
		
		//left part sorting
		quickSort2(mfigura, aLeftIndex, thePartitionIndex - 1);
		
		//right part sorting
		quickSort2(mfigura, thePartitionIndex + 1, aRightIndex);
	}
}

void m_manualSort(spisok_figur *mfigura, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	
	if (theSize <= 1)
	{
		return;
	}
	
	if (2 == theSize)
	{
		if (Ploshcha(&mfigura->quadrangle[aLeftIndex]) > Ploshcha(&mfigura->quadrangle[aRightIndex]))
		{
			swap(mfigura, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{
		// 3 elementes
		if (Ploshcha(&myfigura->quadrangle[aLeftIndex]) > Ploshcha(&myfigura->quadrangle[aRightIndex-1]))
	     {
		swap(mfigura, aLeftIndex, aRightIndex-1);
	     }
	
		if (Ploshcha(&mfigura->quadrangle[aLeftIndex]) > Ploshcha(&mfigura->quadrangle[aRightIndex]))
		{
			swap(mfigura, aLeftIndex, aRightIndex);
		}

		if (Ploshcha(&mfigura->quadrangle[aRightIndex - 1]) > Ploshcha(&mfigura->quadrangle[aRightIndex]))
		{
			swap(mfigura, aRightIndex - 1, aRightIndex);
		}
	}
}
