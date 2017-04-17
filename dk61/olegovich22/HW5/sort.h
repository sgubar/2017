//
// Created by Oleh on 26.03.2017.
//

#ifndef LW2_SORT_H
#define LW2_SORT_H

#include "dk_tool.h"

//shell sort
void shellSort(circleList *aCirclelist);

//quick sort
void quickSort(circleList *aCirclelist, int aLeftIndex, int aRightIndex);

// get type of sort from user
int getTypeOfSort();

#endif //LW2_SORT_H
