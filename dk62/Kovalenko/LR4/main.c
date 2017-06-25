#include <stdio.h>
#include "dk_tool.h"

int main(void)
{
    IntList *theList=CreateIntList();
    if (NULL==theList)
    {
        return -1;
    }
    AddIntValueToList(theList, 9);
    AddIntValueToList(theList, 4);
    AddIntValueToList(theList, 3);
    AddIntValueToList(theList, 2);
    AddIntValueToList(theList, 1);
    AddIntValueToList(theList, 9);
    AddIntValueToList(theList, 7);
    AddIntValueToList(theList, 8);
    AddIntValueToList(theList, 2);
    PrintList(theList);
    printf("The count of value in the list: %d\n", theList->count);
    DestroyIntList(theList);
    return 0;
}
