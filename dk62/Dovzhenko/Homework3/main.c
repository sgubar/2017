#include "hw3.h"
#include <stdio.h>
#include <string.h>

int main()
{
	SphereList *Sphere = createSphereList(5);
	
	createnewSphere(Sphere, 2, 4, 9, 5);
	createnewSphere(Sphere, 5, 3, 3, 4);
	createnewSphere(Sphere, -2, 8, 5, 7);
	createnewSphere(Sphere, 1, -1, 0, 2);
	createnewSphere(Sphere, 6, -5, 4, 1); 
	
	printSphere(Sphere);
	removeSphereList(Sphere);
	return 0;
}
