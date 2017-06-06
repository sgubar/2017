#include <stdio.h>
#include <stdlib.h>
#include "circling.h"
#include "sort.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int size;
    printf("Write number of figures: \n");
    scanf("%i",&size);
    circle *mass =(circle *) malloc(sizeof(circle)*size);//dinamicly giving memory to array
    for (int i = 0; i < size; ++i) {
        NewCircle(&mass[i]);
        mass[i].square = Square(mass[i]);
    }
    ShowTheFigures(mass,size);
    printf("Press 1 for sorting by Bubble sort\nPress 2 for sorting by Shell sort\nPress 3 for search the number\nPress something else to free the memory and exit");
    int c;
    do
    {
        c = getchar();
        switch(c)
        {
            case '1':
            {
                bubble(mass,size);
                break;
            }
            case '2':
            {
                shell(mass,size);
                break;
            }
            case '3':
            {
                double srch;
                do
                {
                    printf("Enter the square which you want to find.\n");
                    scanf("%f",srch);
                    srch = linear(mass, size,srch);
                    if(srch == -1)
                    {
                        printf("Value did not found. Try again\n");
                    }
                }while(srch == -1.0);

            }
            default:
                continue;
        }
    }while(c != '1' && c != '2' && c != '3');
    free(mass);
    return 0;
}
