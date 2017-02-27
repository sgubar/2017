#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        //Объявляем переменные

        int dimension = 0;
        int **matrix1;
        int **matrix2;
        int **resultMatrix;

        //Пользователь вводит размер квадратной матрицы

        printf("Enter dimension of matrix\n");
        scanf("%i", &dimension);

        //Выделяем память

        matrix1 = (int**) malloc(dimension * sizeof(int*));
        matrix2 = (int**) malloc(dimension * sizeof(int*));
        resultMatrix = (int**) malloc(dimension * sizeof(int*));



        for(int i = 0; i < dimension; i++)
        {
            matrix1[i] = (int*) malloc(dimension * sizeof(int));
            matrix2[i] = (int*) malloc(dimension * sizeof(int));
            resultMatrix[i] = (int*) malloc(dimension * sizeof(int));
        }

        printf("Enter matrix values\n");
        EnterMatrixValues(matrix1, dimension);
        printf("Enter matrix values\n");
        EnterMatrixValues(matrix2, dimension);

        MulMatrix(matrix1, matrix2, resultMatrix, dimension);

        MatrixOut(resultMatrix, dimension);

        getchar();
}
