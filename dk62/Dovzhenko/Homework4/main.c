#include <stdio.h>
#include "hw4.h"
#include <string.h>

int main()
{
	SphereList * Sphere = createSphereList(7);
	
	createnewSphere(Sphere, 2, 2, 2, 5);
	createnewSphere(Sphere, 3, 3, 3, 4);
	createnewSphere(Sphere, 5, 8, 5, 7);
	createnewSphere(Sphere, 1, 1, 0, 2);
	createnewSphere(Sphere, 6, 5, 4, 3);
	
	int i;
	printf("\t The list of spheres before sorting:\n\n");
	for(i = 0; i < Sphere->currentSize; i++)
		{
			SpherePosition *firstSphere = &(Sphere->spheres[i]);
			printf("Figure #%i, X: %i, Y: %i, ", i, firstSphere->x, firstSphere->y);
			printf("Z: %i, Radius: %i, ", firstSphere->z, firstSphere->R);
			printf("Square of sphere: %.3f\n", Squareareas(firstSphere));
		}
	printf("What sotr do you choose?\n 1.Bubble \n 2.Insert \n 3.Choise \n");
	int m;
	scanf("%i", &m);
	
	switch(m)
        {
            case 1:
            bubble_Sort(Sphere);
            break;

            case 2:
            sorting_Inserts(Sphere);
            break;

            case 3:
           selection_Sort(Sphere);
            break;
            return 0;
        }

	printf("\t The list of spheres before sorting:\n\n");
	 for(i = 0; i < Sphere->currentSize; i++)
		{
			SpherePosition *firstSphere = &(Sphere->spheres[i]);
			printf("Figure  X: %i, Y: %i, ", firstSphere->x, firstSphere->y);
			printf("Z: %i, Radius: %i, ", firstSphere->z, firstSphere->R);
			printf("Square of sphere: %.3f\n", Squareareas(firstSphere));
		
		}
	removeSphereList(Sphere);
	
	return -1;
	
}
