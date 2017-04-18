int razmerf(void)
{
    int kel=0;
    FILE * file = fopen("lab3.txt" , "r");
    if (file == NULL) perror("Ошибка открытия файла");
    while ( !feof(file) )                          
    {
        fgetc(file);                                  
        kel++;
    }
    fclose (file);
return kel;
}
int kolslovf(int kel)
{
    
    int ksl=0;
    FILE * file = fopen("lab3.txt" , "r");
    if (file == NULL) perror("Ошибка открытия файла");
    char string [kel];
    fseek(file,0,SEEK_SET);  
    if(fgets(string,kel,file)!=NULL)
    for(int k=0;k<kel;k++)
    {
        if(string[k]==' ')
        {
             ksl++;    
        }
	}
	fclose (file);
	return ksl;
}
void filestingr(int kel,int ksl,char slovo[ksl] [kel])
{
    FILE * file = fopen("lab3.txt" , "r"); 
    if(NULL != file)
    { 
        char *string = (char *)malloc(sizeof(char)*kel); 
        char *endslova =""; 
        int pos_e=0,pos_s=0, flag=0;
        for(int i=0;i<ksl;i++) 
        { 
            fseek(file,flag,SEEK_SET); 
            fgets(string,kel,file); 
            endslova=strchr (string,' '); 
            pos_e=strlen(endslova); 
            pos_s=strlen(string); 
            fseek(file,flag,SEEK_SET); 
            fgets(slovo[i],pos_s-pos_e+2, file); 
            flag=flag+pos_s-pos_e+1;
        } 
        fclose(file); 
        free(string); 
    } 
}
void printinf(int ksl,int kel,char str[ksl] [kel])
{
    FILE * file = fopen("lab3.txt" , "r+");
    if (file == NULL) perror("Ошибка открытия файла");
    fseek( file , 0 , SEEK_END);  
    fprintf(file,"\n");

    for(int i=0,j=0;j< ksl;i++)
    {

        fprintf(file,"%c",str[j] [i]);
        if(str[j] [i]==' ')
        {
            i=-1;
            j++;
        }
    }
    fclose (file);
}
void printfile(int ksl,int kel,char str[ksl] [kel])
{
    printf("\n");
    for(int i=0,j=0;j< ksl;i++)
    {

        printf("%c",str[j] [i]);
        if(str[j] [i]==' ')
        {
            i=-1;
            j++;
        }
    }
    printf("\n");
}
void swap(int ksl,int kel,char str[ksl] [kel],int i,int j)
 {
    int tmp [kel];
    for(int k=0;k<kel; k++)
    {
        tmp [k] = str[i] [k];
        str[i] [k] = str[j] [k];
        str[j] [k] = tmp [k];
    }
 }
void bublesort(int ksl,int kel,char str[ksl] [kel])
{
    int j=0;
    for(int m=0;m<ksl-1;m++)
    {
        for (int i=1; i<ksl; i++) 
        {
            if(strcmp (str[i],str[i-1])>0)
            {
                j=i-1;
                swap(ksl,kel,str,i,j);
                
            }
        }   
    }
}
int BinarySearch(int ksl,int kel,char str[ksl] [kel],char find [kel])
{
	int Left = 0;
	int Right = ksl;
	int middle = 0;
	int Result = 0;
	while(Left < Right+1)
	{
		middle = (Left + Right)/2;
		if(strcmp(str[middle],find)==0)
		{
			Result = middle;
			break;
		}
		else
		{
			if(strcmp (str[middle],find)>0)
			{
				Right = middle - 1;
			}
			else
			{
				Left = middle + 1;
			}
		}
	}
	return Result;	
}
char mediana(int ksl,int kel,char str[ksl] [kel], int aleft, int aright, char osnova [kel])
{
	int mid = (aleft + aright) / 2;
	if (strcmp(str[aleft],str[mid])>0)  
	{
		swap(ksl,kel,str, aleft, mid);
	}
	if (strcmp(str[aleft],str[aright])>0)
	{
		swap(ksl,kel,str, aleft, aright);
	}
	if (strcmp(str[mid],str[aright])>0) 
	{
		swap(ksl,kel,str, mid, aright);
	}
	swap(ksl,kel,str, mid, aright - 1);
	for(int k=0;k<kel; k++)
    {
        osnova [k] = str[aright - 1] [k];
    }
	return osnova [kel];
}
int rozdil(int ksl,int kel,char str[ksl] [kel], int aleft, int aright, char osnova [kel])
{
	int left = aleft;
	int right = aright - 1;
	while (1)
	{
		while (strcmp(str[++left],osnova)<0);
		while (strcmp(str[--right],osnova)>0);
		if (left >= right)
		{
			break;
		}
		else
		{
			swap(ksl,kel,str, left, right);
		}
	}
	swap(ksl,kel,str, left, aright - 1);
	return left;
}
void quickSort(int ksl,int kel,char str[ksl] [kel], int aleft, int aright)
{
	int razmer = aright - aleft+1;
	if (razmer <= 3)
	{
		m_manualSort(ksl,kel,str,aleft,aright);
	}
	else
	{
		char osnova [kel];
		mediana(ksl,kel,str, aleft, aright,osnova);
		int newleft = rozdil(ksl,kel,str, aleft, aright, osnova);
		quickSort(ksl,kel,str, aleft, newleft - 1);
		quickSort(ksl,kel,str, newleft + 1, aright);
	}
}
void m_manualSort(int ksl,int kel,char str[ksl] [kel], int aleft, int aright)
{
	int razmer = aright - aleft + 1;
	if (razmer <= 1)
	{
		return;
	}
	if (2 == razmer)
	{
		if (strcmp(str[aleft],str[aright])>0)
		{
			swap(ksl,kel,str, aleft, aright);
		}
		return ;
	}
	else
	{
		if (strcmp(str[aleft],str[aright - 1])>0)   
		{
			swap(ksl,kel,str, aleft, aright - 1);
		}
		if (strcmp(str[aleft],str[aright])>0)
		{
			swap(ksl,kel,str, aleft, aright);
		}
		if (strcmp(str[aright - 1],str[aright])>0)
		{
			swap(ksl,kel,str, aright - 1, aright);
		}
	}
}
