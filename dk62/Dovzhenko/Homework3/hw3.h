#ifndef hw3_h
#define hw3_h

typedef struct position
{
	int x;
	int y;
	int z;
	int R;
}SpherePosition;

typedef struct List
{
	SpherePosition *spheres;
	int size;
	int currentSize;
	
}SphereList;

SphereList * createSphereList(int aSize);
void removeSphereList(SphereList *aSphere);
int createnewSphere(SphereList *aSphere, int x, int y, int z, int R);
float Squareareas(SpherePosition *theSphere);
void printSphere(SphereList *Sphere);

#endif
