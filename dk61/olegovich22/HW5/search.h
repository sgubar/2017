//
// Created by Oleh on 10.04.2017.
//

#ifndef LW3_SEARCH_H
#define LW3_SEARCH_H

#include "dk_tool.h"

//line search
int line_find(circleList *aCircleList, float aKey);

//binary search
int binary_find(circleList *aCircleList, float aKey);

// get type of search from user
int getTypeOfSearch();

//get search key
float getKey();

//print search result
void printSearchResult(circleList *aCircleList, int searchPosition);

#endif //LW3_SEARCH_H
