#ifndef dk_tool_h
#define dk_tool_h


typedef struct position
{
	int xPosition;
	int yPosition;
	int zPosition;
	int radius;
}SpherePosition;

typedef struct List
{
	SpherePosition *spheres;
	int size;
	int current_size;
	
}SphereList;

SphereList * createSphereList(int aSize);
void destroySphereList(SphereList *aSphere);
int addSphere(SphereList *aSphere, int x,int y,int z , int radius);

float areaCalculation(SpherePosition * theSphere);

int enterParametersOfSphere(void);

void writeInFile(FILE *aFile, SphereList *aSphere);
void writeList(FILE * aFile ,SpherePosition *aSphere);

void writeListOnScreen(SphereList *aSphere);

#endif


