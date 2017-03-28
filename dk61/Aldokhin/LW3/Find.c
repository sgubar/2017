//
// Created by maksi on 3/28/2017.
//

#include <stdio.h>

void lion_search(int *darray, int elem_sercth, int dsize)
{
    for (int i = 0; i < dsize || darray[i]>elem_sercth; ++i) {
        if (darray[i] == elem_sercth)
        {
            printf("Element search: %i", i);
            return;
        }
    }
    printf("No have element");
    return;
}