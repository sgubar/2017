//
//  SortingList.h
//  HW6
//
//  Created by air on 16.05.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#ifndef SortingList_h
#define SortingList_h

#include "TLCharList.h"
#include <stdlib.h>

void bubbleSort(CharList *anArray);

void swap(CharList *aList, int aLeftIndex, int aRightIndex);

int partitionIt(CharList *aList, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(CharList *aList, int aLeftIndex, int aRightIndex);

void m_manualSort(CharList *aList, int aLeftIndex, int aRightIndex);

int mediana(CharList *aList, int aLeftIndex, int aRightIndex);


#include <stdio.h>

#endif /* SortingList_h */
