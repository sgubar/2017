// transponirovanie matrici
#include <stdio.h>
#include <conio.h>

int main()
{
    int size_x = 0, size_y = 0 ;

    do
    {
        printf("Matrix size, please {[x],[y]} > 0: ");
        scanf("%i %i", &size_x, &size_y);
    }
    while (size_x < 1 || size_y < 1);

    printf("Type %i numbers, please: ", size_x * size_y);
    int i,j, A[size_x][size_y];
    for(i = 0; i < size_x ; i++)
    {
        for(j = 0; j < size_y ; j++)
        {
            scanf("%i", &A[i][j]);
        }
    }

    for(i = 0; i < size_y ; i++)
    {
        for(j = 0; j < size_x ; j++)
        {
            printf("%i ", A[j][i]);
        }
        printf("\n");
    }


    getch();
    return 0;
}


