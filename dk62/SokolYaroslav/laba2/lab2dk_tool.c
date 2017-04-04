int inputint(int input, int limit)
{
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

void generatestring(int kolslov,int kolelement,char slovoelement [kolslov][kolelement])
{
    int ltime = time (NULL);
    int stime = ltime/2;
    srand(stime);
    for (int i=0; i<kolslov; i++) 
    {
        for (int j=0; j<kolelement; j++) 
        {
            slovoelement [i][j]= rand() % 26 + 65;
        }
    }
}

void print(int kolslov,int kolelement,char slovoelement [kolslov][kolelement])
{
    printf("\n"); 
    for (int i=0; i<kolslov; i++) 
    {
        for (int j=0; j<kolelement; j++) 
        {
            printf("%c", slovoelement [i][j]);
        }
        printf(" ");
    }
    printf("\n"); 
}

int razmerf(int kolelement)
{
    FILE * file = fopen("slova.txt" , "r");
    if (file == NULL) perror("Ошибка открытия файла");
    while ( !feof(file) )                          
    {
        fgetc(file);                                  
        kolelement++;
    }
    fclose (file);
    return kolelement;
}

int kolslovf(int kolelement,int kolslov)
{
    FILE * file = fopen("slova.txt" , "r");
    if (file == NULL) perror("Ошибка открытия файла");
    char string [kolelement];
    fseek(file,0,SEEK_SET);  
    if(fgets(string,kolelement,file)!=NULL)
    for(int k=0;k<kolelement;k++)
    {
        if(string[k]==' ')
        {
             kolslov++;    
        }
	}
	fclose (file);
	return kolslov;
}

void filestingr(int kolelement,int kolslov,char filestring [kolslov][kolelement])
{
    FILE * file = fopen("slova.txt" , "r");
    if (file == NULL) perror("Ошибка открытия файла");
    char string [kolelement]; int j=0;
    if(fgets(string,kolelement,file)!=NULL)
    for(int k=0,i=0;k<kolelement;k++,i++)
    {
        filestring [j][i]=string[k];
        if(string[k]==' ')
        {
            j++;
            i=-1;
        }
	
    }
}

void printinf(int kolslov,int kolelement,char filestring [kolslov][kolelement])
{
    FILE * file = fopen("slova.txt" , "r+");
    if (file == NULL) perror("Ошибка открытия файла");
    fseek( file , 0 , SEEK_END);  
    fprintf(file,"\n");

    for(int i=0,j=0;j< kolslov;i++)
    {

        fprintf(file,"%c",filestring [j][i]);
        if(filestring [j][i]==' ')
        {
            i=-1;
            j++;
        }
    }
    fclose (file);
}

void printfile(int kolslov,int kolelement,char filestring [kolslov][kolelement])
{
    printf("\n");
    for(int i=0,j=0;j< kolslov;i++)
    {

        printf("%c",filestring [j][i]);
        if(filestring [j][i]==' ')
        {
            i=-1;
            j++;
        }
    }
    printf("\n");
}

void obmenslov(int kolslov,int kolelement,char slovoelement [kolslov][kolelement],int i)
 {
    int tmp [kolslov][kolelement];
    for(int k=0;k<kolelement; k++)
    {
        tmp [i][k] = slovoelement [i][k];
        slovoelement [i][k] = slovoelement [i-1][k];
        slovoelement [i-1][k] = tmp [i][k];
    }
 }

void bublesort(int kolslov,int kolelement,char slovoelement [kolslov][kolelement])
{
    int j=0;
    for(int m=0;m<kolslov-1;m++)
    {
        for (int i=1; i<kolslov; i++) 
        {
            if(slovoelement [i][j]<slovoelement [i-1][j])
            {
                obmenslov (kolslov,kolelement,slovoelement,i);
            }
            else if (slovoelement [i][j] == slovoelement [i-1][j])
            {
                for (j=1; j<kolelement; j++)
                {
                    if(slovoelement [i][j]<slovoelement [i-1][j])
                    {
                        obmenslov (kolslov,kolelement,slovoelement,i);

                    }
                    if(slovoelement [i][j]>slovoelement [i-1][j])
                    {
                        j=kolelement;
                    }
                }
                
            }
            j=0;
        }
    }
}
