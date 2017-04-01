int inputint(int input, int n)
{
    int max=n;
    n+=2;
    char string[n];
    fgets( string, n, stdin ); 
    int longstring =strlen(string)-1;


    input = atoi (string);
    for(int i=0;i<n-1;i++)
    {
        if(isalpha(string[i]))
        {
            printf("Ведіть число!!!\n");
            exit(0);
        }
    }
    printf("\ndebil");
    printf("\nmax=%i",max);
    printf("\nlongstring=%i\n",longstring);
    if(longstring>max)
    {
        printf("Введите меньше число!!!\n");
        exit(0);
    }

  return input;
}
/*{
    if(scanf("%i",&znachenie)!=1)
    {
        printf("Введите число!!!\n");
        exit(0);
    }
    if(znachenie>max||znachenie<0)
    {
        printf("Введите число A от 0 до %i!!!\n",max);
        exit(0);
    }
    return znachenie;
}*/
/////////////////////////
void generate(int kolslov,int kolelement,char slovoelement [kolslov][kolelement])
{
    for (int i=0; i<kolslov; i++) 
    {
        for (int j=0; j<kolelement; j++) 
        {
            slovoelement [i][j]= rand() % 10 + 48;
            
            printf("%c", slovoelement [i][j]);
            
        }
        printf(" ");
    }
    printf("\n"); 
}
//////////////////////

void pechat(int kolslov,int kolelement,char slovoelement [kolslov][kolelement])
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

void zmeshchenie (int kolslov,int kolelement,char slovoelement [kolslov][kolelement],int i)
 {
    int tmp [kolslov][kolelement];
    for(int k=0;k<kolelement; k++)
    {
        tmp [i][k] = slovoelement [i][k];
        slovoelement [i][k] = slovoelement [i-1][k];
        slovoelement [i-1][k] = tmp [i][k];
    }
 }

//////////////////////
void buble(int kolslov,int kolelement,char slovoelement [kolslov][kolelement])
{
    int j=0;
    for(int m=0;m<kolslov-1;m++)
    {
        for (int i=1; i<kolslov; i++) 
        {
            if(slovoelement [i][j]<slovoelement [i-1][j])
            {
                zmeshchenie (kolslov,kolelement,slovoelement,i);
            }
            else if (slovoelement [i][j] == slovoelement [i-1][j])
            {
                for (j=1; j<kolelement; j++)
                {
                    if(slovoelement [i][j]<slovoelement [i-1][j])
                    {
                        zmeshchenie (kolslov,kolelement,slovoelement,i);

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
