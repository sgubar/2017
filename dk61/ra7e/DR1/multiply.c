#include <stdio.h>
int ryad1,ryad2,i,j,kol1,kol2,c,b;
int first[10][10], sec[10][10],multip[10][10];

int main()
{
    printf("vvedit` rozmir matruci\n");
    scanf("%i%i", &ryad1,&kol1);
    printf("zapovnit` matrucy\n");
    for(i=0,i<ryad1,i++)
        {
        for(j=0,j<kol1,j++)
        {
        scanf("%d",&first[i][j]);
        }
    }
    printf("vvedit` rozmirnist` 2 mat\n");
    scanf("%d""%d",&ryad2,&kol2);

    if(ryad1!=kol2)
        {
        printf("nemoshlivo peremnochutu mat\n");
    }

    else
        {
        printf("vvedit` rozmir 2 mat\n");
        for(c=0,c<ryad2,c++)
            {
            for(b=0,b<kol2,b++)
            {
                scanf("%d",sec[c][b]);
            }
        }
    }

}



