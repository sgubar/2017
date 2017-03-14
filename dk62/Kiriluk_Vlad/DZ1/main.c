#include <stdio.h>
#include <stdlib.h>


int main(void)
{

    int  k , x;
    int matr[100][100];

    printf("Enter the number of rows < 100:\n ");
    scanf("%i" , &k);

    printf("Enter the number of columns < 100:\n ");
    scanf("%i" , &x);

    EnterMatrix (k , x , &matr);
    MatrRemoval (k , x , &matr);
    return 0;

}
