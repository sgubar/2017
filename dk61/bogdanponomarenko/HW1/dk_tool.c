#include "dk_tool.h"

void display_first_matrix(int row, int col, int first_matrix[10][10]) {
    int i , j;
    printf("Elements of first_matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%i", &first_matrix[i][j]);
        }
    }
    printf("first_matrix\n");
    i=0,j=0;
    while(i<row)
    {
        while(j<col)
        {
            printf("%4d",first_matrix[i][j]);
            j++;
        }
        printf("\n");
        j=0;
        i++;
    }
}
    void display_second_matrix(int row, int col, int second_matrix[20][20]) {

        int i , j;


        printf("Elements of second_matrix:\n");
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                scanf("%i", &second_matrix[i][j]);
            }
        }
        printf("second_matrix\n");
        i=0,j=0;
        while(i<row)
        {
            while(j<col)
            {
                printf("%4d",second_matrix[i][j]);
                j++;
            }
            printf("\n");
            j=0;
            i++;
        }

    }
    void sum(int row, int col, int first_matrix[10][10], int second_matrix[20][20]) {


        int summ[row][col];
        int i , j;
        printf("Sum of first_matrix and second_matrix:\n");

            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    summ[i][j] = first_matrix[i][j] + second_matrix[i][j];

                }
            }
        i=0,j=0;
        while(i<row)
        {
            while(j<col)
            {
                printf("%4d",summ[i][j]);
                j++;
            }
            printf("\n");
            j=0;
            i++;
        }
    }

