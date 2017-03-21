#include <stdio.h>
#include <stdlib.h>

int main(void)
{


        int rozmir = 0;
        int matrix1[10][10];
        int matrix2[10][10];
        int i=0;
        int j=0;
        int w=0;
        int a=0;
        int b=0;



        printf("Enter dimension of matrix\n");
        scanf("%i", &rozmir);

            printf("Enter matrix values\n");
            for(i = 0; i < rozmir; i++){

               for(j = 0; j < rozmir; j++){

                 scanf("%i", &w);
                 matrix1[i][j]=w;
           }
        }

        printf("Enter matrix values\n");
        for(a = 0; a < rozmir; a++){

           for(b = 0; b < rozmir; b++){

               scanf("%i", &matrix2[a][b]);
           }
        }
       MulMatrix( matrix1,  matrix2,  rozmir);


}


