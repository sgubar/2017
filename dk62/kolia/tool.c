#include "tool.h"



void sum_matr (int x, int y,  int first [20][20], int second [20][20]) {
int c, d;
int q = 0;
 for(c=0;c<x;c++){
         for(d=0;d<y;d++){
q = first[c][d]+second[c][d];
printf("   %i   ", q);}
           printf("\n \n");
           }

}
