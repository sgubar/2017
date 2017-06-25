void copyMas(char *a, char *b, int n)
{
    int i;
    for (i = 0; i < n; i++)\
        a[i] = b[i];
}

void sortBubble(char *a, int n)
 {
    int i, j;
    char t;
    for (i = n - 1; i > 0; i--)
        for (j = 1; j <= i; j++)
             if (a[j] > a[j-1])
             {
                 t = a[j];
                 a[j] = a[j-1];
                 a[j-1] = t;
             }
 }


void sortInsertion(char *a, int n)
{
    int item, i;
    char t;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        item = i-1;
        while(item >= 0 && a[item] < t)
        {
            a[item + 1] = a[item];
            a[item] = t;
            item--;
        }
    }
}

void sortSelection(char *a, int n)
{
    int i, j, imax;
    char t;
    for (i = 0; i < n - 1; i++)
    {
        imax = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[imax])
            {
                imax = j;
            }
        }
        if (imax != i)
        {
            t = a[i];
            a[i] = a[imax];
            a[imax] = t;
        }
    }
}
