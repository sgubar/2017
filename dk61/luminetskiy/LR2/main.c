#include "alg.h"


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
    char a[NMAX];
    char t;
    while ((t = fgetc(f))!=EOF)
    {
        a[n] = t;
        n++;
    }
    fclose(f);
    f = fopen("out.txt","w");
    int i;
    fprintf(f,"First mas\n");
    for (i = 0; i < n; i++)
        fprintf(f,"%c ", a[i]);
    fprintf(f, "\n");
    int startTime = clock();
    sortShell(a, n);
    int endTime = clock();
    fprintf(f,"Second mas\n");
    for (i = 0; i < n; i++)
        fprintf(f, "%c ", a[i]);
    fprintf(f,"\n");
    fprintf(f, "Time run = %.4f\n", (endTime - startTime) / 1000.0);
    startTime = clock();
    int res = lineFind(a, n, '-');
    endTime = clock();
    if (res == -1) fprintf(f, "Key not found\n");
        else fprintf(f,"Key index = %d\n", res);
    fclose(f);
    printf("Result in file 'out.txt'\n");
    system("pause");
    return 0;
}
