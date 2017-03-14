void EnterMatrix (int k , int x , int *matr)
{
    printf("Enter the elements of matrix:\n ");
    for(int i = 0; i < k * x; i++)
    {
        scanf("%i" , &matr[i]);
    }
    printf("Matrix:\n");
    for (int i = 0; i < k; i++)
    {
        for (int j =0; j < x; j++)
        {
            printf("%i %s", matr[i * x + j], " ");
        }
        printf("\n");
    }
}

void MatrRemoval (int k , int x , int *matr)
{
    int itemp1;

    for(int i = 0; i<k; i++)
    {
        itemp1 = matr[i * x + x - 1];
        for (int j = x - 1; j > 0; j--)
        {
            matr[i * x + j ] = matr[i * x + j-1];
        }
        matr[i * x] = itemp1;
    }
    printf("New Matrix:\n");
    for (int i = 0; i < k; i++)
    {
        for (int j =0; j < x; j++)
        {
            printf("%d %s", matr[i * x + j], " ");
        }
        printf("\n");
    }
}
