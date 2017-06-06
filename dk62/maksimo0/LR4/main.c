//
//  main.c
//  LR4
//
//  Created by Maxim Salim on 05.06.17.
//  Copyright © 2017 Maxim Salim. All rights reserved.
//

#include <stdio.h>
#include "list.h"

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
