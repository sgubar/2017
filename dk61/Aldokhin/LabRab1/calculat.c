//
// Created by maksim on 2/20/2017.
//

#include "stdio.h"

#include "tools.h"

float calc_main(int *id)
{
    float Q=(*id) * *(id+1);
    float i=(*(id+1) + *(id+2) * *(id+2));
    Q= Q/i + (float)sum_q(id);
    return Q;
}

int sum_q(int *id)
{
    int sum, f;
    for (int i = 0; i < *(id+1); ++i) {
        f=fact(i, f);
        sum=sum+f;
    }
}

int fact(int num, int end)
{
    end=end*num;
    return end;
}