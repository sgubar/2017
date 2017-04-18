#ifndef _dk_tools
#define _dk_tools
typedef struct{
    float x;
    float y;
    float z;
}point_t;

typedef struct{
    float radius;
    point_t *center;
}sphere_t;

void AddSphere(float x, float y, float z, float radius);

void PrintElements(void);

void CalcSquare(int number);

void CleanUp(void);



#endif // _dk_tools

