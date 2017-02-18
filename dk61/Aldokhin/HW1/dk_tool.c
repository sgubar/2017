//
// Created by maksi on 2/18/2017.
//

#include "stdio.h"
#include "string.h"
#include "dk_tool.h"

void read_mas(int x, int y, int pmas[x][y])
{
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            //printf("i: %i, j: %i\n", i, j);
            scanf("%i", &pmas[i][j]);
        }
    }
}

void print_mas(int x, int y, int pmas[x][y])
{
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            //printf("i: %i, j: %i\n", i, j);
            printf("%i ", pmas[i][j]);
        }
        printf("\n");
    }
}

void multi_mas(int x, int y, int pmas[x][y], int k)
{
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            pmas[i][j]=pmas[i][j]*k;
        }
    }
}

void save_mas(int x, int y, int mas1[x][y], int mas2[x][y])
{
    //memcpy(mas2, mas1, sizeof(mas2));
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            mas2[i][j]=mas1[i][j];
        }
    }
}