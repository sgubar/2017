//Функция ввода матрицы

void EnterMatrixValues(int **matrix, int dimension){
        for(int i = 0; i < dimension; i++)
        {
           for(int j = 0; j < dimension; j++)
           {
               scanf("%i", &matrix[i][j]);
           }
        }


}

//Функция умножения двух квадратных матриц

void MulMatrix(int **matrix1, int **matrix2, int **resultMatrix, int dimension)
    {
        for(int i = 0; i < dimension; i++)
        {
            for(int j = 0; j < dimension; j++)
            {
                resultMatrix[i][j] = 0;
                for(int k = 0; k < dimension; k++)
                {
                    resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }


//Функция вывода матрицы на экран

void MatrixOut(int **matrix, int dimension)
{
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}
