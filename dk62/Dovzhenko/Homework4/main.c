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
	
	int a;
	printf("\t The list of spheres before sorting:\n\n");
	for(a=0; a<5; a++)
	{	
		SpherePosition firstSphere = Sphere ->spheres[a];
		printf("Coordinate %i sphere -  [%i] [%i] [%i] and radius is: %i;\n",a+1,firstSphere.x ,firstSphere.y ,firstSphere.z,firstSphere.R);
		printf("The area of sphere is: %.3f;\n",  Squareareas(&firstSphere));
		printf("\n\n");
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
	 	for(a=0; a<5; a++)
	{	
		SpherePosition firstSphere = Sphere ->spheres[a];
		printf("Coordinate  sphere -  [%i] [%i] [%i] and radius is: %i;\n",firstSphere.x ,firstSphere.y ,firstSphere.z,firstSphere.R);
		printf("The area of sphere is: %.3f;\n",  Squareareas(&firstSphere));
		printf("\n\n");
	}
	removeSphereList(Sphere);
	
	return -1;
	
}
