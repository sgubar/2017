#include <stdio.h>

#include "dk_tool.h"

int main() {
    DK_coor *Triangle = CreateCoor(3);
    import(Triangle);
    float S=calculate(Triangle);
    printf("Rezalt: %f", S);
    if (NULL != Triangle) {
        free (Triangle);
    }
    return 0;
}
