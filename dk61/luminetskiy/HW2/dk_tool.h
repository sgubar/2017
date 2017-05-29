#ifndef dk_tool_h
#define dk_tool_h

#define Pi 3.141592654

typedef struct {
    int x;
    int y;
    int rad;
    long double square;
} circle;
circle * CreateList(int size);//creating array of circles
void NewCircle(circle *ptr);//adding fig to array
long double square(circle s);

void PrintFigures(circle mass[],int n);

#endif //dk_tool_h
