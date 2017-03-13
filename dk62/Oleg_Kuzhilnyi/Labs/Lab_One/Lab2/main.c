//
//  main.c
//  Lab2
//
//  Created by air on 09.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "Sorting.h"

int main(int argc, const char * argv[])
{
    FILE *theFileForRandom = fopen("RandomNumber.txt","w");
    FILE *theFileForSort = fopen("SortedElemets.txt","w");
    
    int MassOfRandomNumber[10000];
    int SelectionSort = 0;
    int ForRandomCounter = 0;
    printf("Please Enter the '0' For generate Random array: ");
    
    scanf("%i", &ForRandomCounter);//for make a random array
    
    if(ForRandomCounter == 0)
    {
        Random(MassOfRandomNumber);
        Input(theFileForRandom,MassOfRandomNumber);
    }

     printf("-----------------------\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Select Sort\n");
    printf("3 - Quick Sort\n");
    printf("4 - Shell Sort\n");
    printf("Please select the Selection Sort: ");
    scanf("%i", &SelectionSort);//counter for select type of sort
    
     printf("-----------------------\n");
    printf("You can check the Results in SortedElemets.txt, RandomNumber.txt\n ");
     printf("-----------------------\n");
    
    switch(SelectionSort)
    {
        case 1:// Bubble Sort
            
            Output(theFileForRandom,MassOfRandomNumber);
            BubbleSort(MassOfRandomNumber);
            Input(theFileForSort,MassOfRandomNumber);
            break;
        case 2: // Select Sort
            
            Output(theFileForRandom,MassOfRandomNumber);
            SelectSort(MassOfRandomNumber);
            Input(theFileForSort,MassOfRandomNumber);
            break;
            
        case 3:// Quick Sort
            
            Output(theFileForRandom,MassOfRandomNumber);
            QuickSort(MassOfRandomNumber,0,ELEMENTS);
            Input(theFileForSort,MassOfRandomNumber);
            break;
            
        case 4:// Shell Sort
            
            Output(theFileForRandom,MassOfRandomNumber);
            ShellsSort(MassOfRandomNumber);
            Input(theFileForSort,MassOfRandomNumber);
            break;
            
        default:
            printf("I might select number from 1 to 4");

    }
    return 0;
}
