#include <stdio.h>
#include <malloc.h>
#include "Tool.h"

int main() {
    IntList *theList = TLCreateIntList();

    if (NULL == theList)
    {
        return -1;
    }

    int instant_element;

    int longlist;

    printf("Enter long of the list: ");
    longlist = read_tru(0, 10000);
    printf("\n");
    for (int i = 0; i < longlist; ++i) {
        printf("Enter element number(%i): ", i);
        instant_element = read_tru(-100000,100000);
        TLAddIntValueToList(theList, instant_element);
        printf("\n");
    }

    TLPrintList(theList);
    int i, k, p;
    do {
        printf("Select an operation:\n 1-Add item\n 2-Inserting an element by index\n 3-Deleting an element by index\n"
                       " 4-List size\n 5-Sort\n 0-Exit\n");
        i=read_tru(0,5);
        switch (i) {
            case 0:
                TLDestroyIntList(theList);
                printf("Bye\n");
                return 0;
            case 1:
                printf("Enter element number(%i): ", theList->count+1);
                instant_element = read_tru(-100000,100000);
                TLAddIntValueToList(theList, instant_element);
                printf("\n");
                break;
            case 2:
                printf("Enter the element number and values");
                k = read_tru(0, theList->count-2);
                int elem = read_tru(-100000,100000);
                TLInsertIntValueAtIndex(theList, elem, k);
                break;
            case 3:
                printf("Enter the element number");
                k = read_tru(0, theList->count-1);
                TLDeliteIntValueAtIndex(theList, k);
                theList->count--;
                break;
            case 4:
                printf("List size: %i\n", theList->count);
                break;
            case 5:
                TLPrintList(theList);
                QuickSort1(theList, (theList->head), (theList->tail));
                break;
        }
        TLPrintList(theList);
    }
    while (1);



    return 0;
}