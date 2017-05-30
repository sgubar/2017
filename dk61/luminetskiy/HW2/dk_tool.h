#ifndef dk_tool_h
#define dk_tool_h
#define Pi 3.14159

typedef struct {
    int x;
    int y;
    int rad;
    double square;
} circle;

void NewCircle(circle *ptr);//adding fig to array
double Square(circle s);
void ShowTheFigures(circle ptr[],int n);
#endif //dk_tool_h
