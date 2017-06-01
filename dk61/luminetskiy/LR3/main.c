#include "alg.h"

//максимально возможное количество элементов
#define NMAX 10000

int main()
{
    FILE *f;
    f = fopen("in.txt", "r");
    if (!f)
    {
        printf("File not found\n");
        system("pause");
        return 0;
    }
    int n = 0;
    char a[NMAX], b[NMAX];
    char t;
    while ((t = fgetc(f))!=EOF)
    {
        a[n] = t;
        n++;
    }
    fclose(f);

    copyMas(b, a, n);
    f = fopen("out.txt","w");
    int i;
    fprintf(f,"First mas\n");
    for (i = 0; i < n; i++)
        fprintf(f,"%c ", a[i]);
    fprintf(f, "\n\n");

    int startTime = clock();
    sortBubble(a, n);
    int endTime = clock();
    fprintf(f,"Second mas Bubble\n");
    for (i = 0; i < n; i++)
        fprintf(f, "%c ", a[i]);
    fprintf(f,"\n");
    fprintf(f, "Time run Bubble = %.4f\n\n", (endTime - startTime) / 1000.0);

    copyMas(a, b, n);
    startTime = clock();
    sortInsertion(a, n);
    endTime = clock();
    fprintf(f,"Second mas Insertion\n");
    for (i = 0; i < n; i++)
        fprintf(f, "%c ", a[i]);
    fprintf(f,"\n");
    fprintf(f, "Time run Insertion = %.4f\n\n", (endTime - startTime) / 1000.0);

    copyMas(a, b, n);
    startTime = clock();
    sortSelection(a, n);
    endTime = clock();
    fprintf(f,"Second mas Selection\n");
    for (i = 0; i < n; i++)
        fprintf(f, "%c ", a[i]);
    fprintf(f,"\n");
    fprintf(f, "Time run Selection = %.4f\n", (endTime - startTime) / 1000.0);

    fclose(f);
    printf("Result in file 'out.txt'\n");
    system("pause");
    return 0;
}
