#include <stdio.h>
#include "hw5.h"
#include <string.h>
#include <math.h>

int main()
{
	SphereList * Sphere = createSphereList(6);
	
	createnewSphere(Sphere, 2, 2, 2, 5);
	createnewSphere(Sphere, 3, 3, 3, 4);
	createnewSphere(Sphere, 5, 8, 5, 7);
	createnewSphere(Sphere, 1, 1, 0, 2);
	createnewSphere(Sphere, 6, 5, 4, 3);
	
	int i;
	printf("\tThe list of spheres before sorting:\n");
	for(i = 0; i < Sphere->currentSize; i++)
	{
		SpherePosition *firstSphere = &(Sphere->spheres[i]);
		printf("Figure #%i, X: %i, Y: %i, ", i, firstSphere->x, firstSphere->y);
		printf("Z: %i, Radius: %i, ", firstSphere->z, firstSphere->R);
		printf("Square of sphere: %.3f\n", Squareareas(firstSphere));
	}
	
	shellSort(Sphere);
	printf("\n\tThe list of spheres after sorting:\n");
	for(i = 0; i < Sphere->currentSize; i++)
	{
		SpherePosition *firstSphere = &(Sphere->spheres[i]);
		printf("Figure  X: %i, Y: %i, ", firstSphere->x, firstSphere->y);
		printf("Z: %i, Radius: %i, ", firstSphere->z, firstSphere->R);
		printf("Square of sphere: %.3f\n", Squareareas(firstSphere));
	}
	
	printf("\nEnter the radius of the sphere what area you want to find (you can choose 5, 4, 7, 2, 3):\n");
	int find;
	scanf("%i", &find);
	
	int result = binarySearch(Sphere, find);
	if(result == -1)
		printf("Don't found.\n");
	else
	{
		printf("Number of sphere in sorted array: %i\n",result+1);
		int t =Sphere->spheres[result].R;
		float s = 4*3.14*pow(t,2);
		printf("Area of sphere:%.3f\n", s);
		removeSphereList(Sphere);
	}
	return 0;
	
}
