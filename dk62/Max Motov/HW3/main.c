#include "dk_tools.h"
#include "stdlib.h"
#include "stdio.h"

int main(void)
{
    float x, y, z, radius;
    tListSp *myList = CreateList(10);
    int index;



    while(1)
    {
        Display();
        int command;
        printf("Enter command: ");
        scanf("%d", &command);
        switch(command)
        {
            case 1:
            printf("Enter x, y, z and radius\n");
            scanf("%f", &x);
            scanf("%f", &y);
            scanf("%f", &z);
            scanf("%f", &radius);
            printf("%.3f, %.3f, %.3f, %.3f\n", x, y, z, radius);
            AddSphere(x, y, z, radius, myList);
            break;

            case 2:
            printf("Current amount of spheres: %i\n", myList->current_size);
            printf("Enter index of sphere ");
            scanf("%i", &index);
            printf("Square: %f\n", SquareOfSphere(myList->sphere[index-1]));
            break;

            case 3:
            TotalSphereWorldDestruction(myList);
            break;

            case 4:
            WriteToJson(myList);
            break;

            case 5:
            exit(0);
            default:
            printf("No such command\n");
            break;



        }
        system("pause");
        system("cls");
    }


}


void Display()
{
    printf("[1] -> Add Sphere;\n[2] -> Calculate square;\n[3] -> Destruction;\n[4] -> Write to file;\n[5] -> Exit.\n");
}
