
#ifndef ROM3_DK_TOOL_H
#define ROM3_DK_TOOL_H
#define Pi 3.14159
#include <stdbool.h>
typedef struct {
    int x;
    int y;
    int rad;
    double square;
}circle;

void NewCircle(circle *ptr);//adding fig to array
double Squareof(circle s);
void ShowTheFigures(circle ptr[],int n);
bool output(char *filename, circle *ptr, int n);
#endif //ROM3_DK_TOOL_H
