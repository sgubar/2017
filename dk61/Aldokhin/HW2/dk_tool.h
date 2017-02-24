//
// Created by maksi on 2/24/2017.
//

#ifndef HW2_DK_TOOL_H
#define HW2_DK_TOOL_H

#endif //HW2_DK_TOOL_H

typedef struct coordinates
{
    float x_coor;
    float y_coor;
}DK_coor;

DK_coor *CreateCoor(int Size_c);

float tru_scan();

void import(DK_coor *rTriangle);

float calculate(DK_coor *RCTriangle);