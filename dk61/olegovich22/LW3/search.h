//
// Created by Oleh on 10.04.2017.
//

#ifndef LW3_SEARCH_H
#define LW3_SEARCH_H

//line search
int line_find(int *anArray, int aSize, int aKey);

//binary search
int binary_find(int *anArray, int aSize, int aKey);

//get key
int getKey();

//print search result
void printSearchResult(double *timeSearch, int searchPosition);

#endif //LW3_SEARCH_H
