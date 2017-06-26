#ifndef ROMA_CIRCLING_H
#define ROMA_CIRCLING_H
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

#endif //ROMA_CIRCLING_H
