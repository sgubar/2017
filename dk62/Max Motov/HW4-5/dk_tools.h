#ifndef _dk_tools
#define _dk_tools
typedef struct{
    float x;
    float y;
    float z;
    float radius;
}tSphere;

typedef struct{
    tSphere *sphere;
    int size;
    int current_size;
}tListSp;

tListSp *CreateList(int arraySize);
void AddSphere(float x, float y, float z, float radius, tListSp *list);
void TotalSphereWorldDestruction(tListSp *list_of_spheres);
float SquareOfSphere(tSphere sphere);
void WriteToJson(tListSp *theList);
void Choose(tListSp *theList);
void ShellSort(tListSp *theList);
int BinarySearch(tListSp *theList, float radius);

#endif // _dk_tools
