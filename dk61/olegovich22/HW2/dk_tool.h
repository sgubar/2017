//
// Created by Олег on 27.02.2017.
//

#ifndef HW2_DK_TOOL_H
#define HW2_DK_TOOL_H
#include <string.h>

typedef struct circle //circle size
{
    float centerX;
    float centerY;
    float radiusX;
    float radiusY;
    float square;
}circle;

typedef struct optionCircle //circle options
{
    circle *sizeCircle;
    int size;
    int current_size;
}optionCircle;

float theSquare(float centerX, float centerY, float radiusX, float radiusY);

//main create an delete
optionCircle *createCircle(int size);
void destroyAllCircle(optionCircle *mainCircle);

//interface
int addToCircle(optionCircle *mainCircle, float centerX, float centerY, float radiusX, float radiusY);

#endif //HW2_DK_TOOL_H
