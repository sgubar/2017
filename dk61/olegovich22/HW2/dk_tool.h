//
// Created by Олег on 27.02.2017.
//

#ifndef HW2_DK_TOOL_H
#define HW2_DK_TOOL_H
#include <string.h>

//circle size
typedef struct circle
{
    float centerX;
    float centerY;
    float radius;
    float square;
}circle;

//circle options
typedef struct optionCircle
{
    circle *sizeCircle;
    int size;
    int current_size;
}optionCircle;

//count square
float theSquare(optionCircle *mainCircle, int numbOfCircle);

//main create an delete
optionCircle *createCircle(int size);
void destroyAllCircle(optionCircle *mainCircle);

//interface
int addToCircle(optionCircle *mainCircle, float centerX, float centerY, float radius);

#endif //HW2_DK_TOOL_H
