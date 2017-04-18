#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

int main()
{
    char command;
    float x, y, z, radius;
    int number;

    while(1)
    {
        printf("Enter command. List:\n a -> AddSphere;\n p -> PrintElements;\n s -> CalcSquare,\n e -> CleanUp\n");
        scanf ("%c", &command);

        switch(command)
        {
            case 'a':
            printf("Enter coordinates x, y, z\n");
            scanf("%f", &x);
            scanf("%f", &y);
            scanf("%f", &z);
            printf("Enter radius\n");
            scanf("%f", &radius);

            AddSphere(x, y, z, radius);
            break;


            case 'p':
            PrintElements();
            break;


            case 's':
            printf("Enter number of sphere\n");
            scanf("%i", &number);
            CalcSquare(number);
            break;


            case 'e':
            CleanUp();
            return 0;
            break;

  }
 }




}
