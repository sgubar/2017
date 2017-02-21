#include <stdio.h>
#include "dk_tool.h"

int main(int argc, const char * argv[])
{
    
    int height=0,width=0;
    printf("Enter the size of the matrix\n");
    do{
    printf("Enter the number of rows:");
    scanf("%i",&height);
    if(height<0)
        printf("Error\n");
    }while(height<0);
    do{
    printf("Enter the number of columns:");
    scanf("%i",&width);
    if(width<0)
        printf("Error\n");
    }while(width<0);
    int minusmatr [height][width];
    int matr1 [height][width];   
    printf("Enter the elements of the first matrix\n"); 
    int i,n;//peremennie dla forov, kompilyator po drugomu ne ponimaet
    
    for( i=0;i<height;i++)
    {
        for( n=0;n<width;n++)
        {
            scanf("%i",&matr1[i][n]);
        }
    }
    int matr2 [height][width];
    printf("Enter the elements of the second matrix\n");
    for( i=0;i<height;i++)
    {
        for( n=0;n<width;n++)
        {
            scanf("%i",&matr2[i][n]);
        }
    }
    printf("The first matrix\n");
    printfunction(height,width,matr1);   
	printf("The second matrix\n"); 
    printfunction(height,width,matr2);
    minus(height,width,matr1,matr2,minusmatr);
    printf("The result of subtraction\n");
    printfunction(height,width,minusmatr);
}

