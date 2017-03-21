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
    
    int MassOfRandomNumbers[aSizeOf];
    int SelectorSort = 0;
    int ForRandomCounter = 0;
    printf("Please Enter the '0' For generate Random array: ");
    
    scanf("%i", &ForRandomCounter);//for make a random array
    
    if(ForRandomCounter == 0)
    {
        Random(MassOfRandomNumbers,aSizeOf);
        Input(theFileForRandom,MassOfRandomNumbers,aSizeOf);
    }else return -1;

     puts("-----------------------");
    puts("1 - Bubble Sort");
    puts("2 - Select Sort");
    puts("3 - Insert Sort");
    printf("Please select the Selection Sort: ");
    scanf("%i", &SelectorSort);//counter for select type of sort
    
     puts("-----------------------");
    puts("You can check the Results in SortedElemets.txt, RandomNumber.txt");
     puts("-----------------------");
    
    switch(SelectorSort)
    {
        case 1:// Bubble Sort
            
            Output(theFileForRandom,MassOfRandomNumbers,aSizeOf);
            BubbleSort(MassOfRandomNumbers,aSizeOf);
            Input(theFileForSort,MassOfRandomNumbers,aSizeOf);
            break;
        case 2: // Select Sort
            
            Output(theFileForRandom,MassOfRandomNumbers,aSizeOf);
            SelectSort(MassOfRandomNumbers,aSizeOf);
            Input(theFileForSort,MassOfRandomNumbers,aSizeOf);
            break;
            
        case 3:// Quick Sort
            
            Output(theFileForRandom,MassOfRandomNumbers,aSizeOf);
            InsertSort(MassOfRandomNumbers,aSizeOf);
            Input(theFileForSort,MassOfRandomNumbers,aSizeOf);
            break;
            
        default:
            printf("You might select number from 1 to 4");

    }
    return 0;
}
