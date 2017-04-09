//
// Created by maksi on 4/9/2017.
//

#include <stdio.h>

void lion_search(int *darray, int elem_sercth, int dsize)
{
    for (int i = 0; i < dsize || darray[i]>elem_sercth; ++i) {
        if (darray[i] == elem_sercth)
        {
            printf("Element search: %i\n", i);
            if (darray[i] > elem_sercth) return;
        }
    }
    printf("No have element");
    return;
}