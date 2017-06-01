#include "alg.h"

void sortShell(char *a, int n)
{
    int i,j,k;
	char t;
	for(k = n/2; k > 0; k /=2)
        for(i = k; i < n; i++)
        {
            t = a[i];
            for(j = i; j>=k; j-=k)
            {
                if(t > a[j-k])
                    a[j] = a[j-k];
                else
                    break;
            }
            a[j] = t;
        }
}

int lineFind(char *a, int n, char key)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}
