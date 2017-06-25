#include <stdio.h>
#include "dk_tool.h"

int main(void)
{
    IntList *theList=CreateIntList();
    if (NULL==theList)
    {
        return -1;
    }
    
    AddIntValueToList(theList, 1);
    AddIntValueToList(theList, 2);
    AddIntValueToList(theList, 3);
    AddIntValueToList(theList, 4);
    AddIntValueToList(theList, 5);
    AddIntValueToList(theList, 6);
    AddIntValueToList(theList, 7);
    AddIntValueToList(theList, 8);
    AddIntValueToList(theList, 9);

    PrintList(theList);

    printf("The count of value in the list: %d\n", theList->count);

    InsertIntValueAtIndex(theList, 123456, 3);
    
    quickSort(theList, 0, theList->count-1);

    PrintList(theList);

    DeleteIntValueAtIndex(theList, 0);

    PrintList(theList);

    DestroyIntList(theList);

    return 0;
}
