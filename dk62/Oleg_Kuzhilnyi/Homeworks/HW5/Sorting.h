//
//  Sorting.h
//  HW5
//
//  Created by air on 16.04.17.
//  Copyright © 2017 Kuzhinlyi Oleg. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h

#include <stdio.h>

#include "DK_Figure.h"

#ifndef Sort_h
#define Sort_h

void shellSort(DK_Figures *anArray);


void bubbleSort(DK_Figures *FigureList); // Bubble sort


void selectionSort(DK_Figures *FigureList); // Selection sort


void insertionSort(DK_Figures *FigureList); //Insertion sort

unsigned line_find(DK_Figures *FigureList, int aKey);


#endif /* Sort_h */

#endif /* Sorting_h */
