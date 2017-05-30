#ifndef dk_tool_h
#define dk_tool_h
#define Pi 3.14159
#include <stdbool.h>
typedef struct {
    int x;
    int y;
    int rad;
    double square;
} circle;

void NewCircle(circle *ptr);//adding fig to array
double Squareof(circle s);
void ShowTheFigures(circle ptr[],int n);
bool JSON(circle *ptr, int n, char *filename);
#endif //dk_tool_h
