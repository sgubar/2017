#include <stdio.h>

#include "tools.h"
#include "malloc.h"

//id-A; (id+1)-B; (id+2)-C

int main() {
    int *mas;
    mas=scan_data();
    float rez=calc_main(mas);
    printf("Rezalt: %f",rez);
    free(mas);
    return 0;
}