
#include <stdio.h>
#include "tool.h"
int main()
{
    int m,n,c,d;
    int first[20][20];
    int second[20][20];

    printf("vvedit' rayd and stovp\n");
    scanf( "%i %i",&m,&n);

    printf("vvedit' elementi first matr\n");
    for(c=0;c<m;c++){
         for(d=0;d<n;d++){
           scanf("%i",&first[c][d]);}}

    printf("vvedit' elementi second matr\n");
    for(c=0;c<m;c++){
        for(d=0;d<n;d++){
        scanf("%i",&second[c][d]);}}

     printf("Summa matr\n");
     sum_matr (m, n, first, second);
}
