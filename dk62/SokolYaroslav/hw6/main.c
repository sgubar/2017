#include <stdio.h>
#include "list.h"

int main(void)
{
    CharList *theList=CreateCharList();
    if (NULL==theList)
    {
        return -1;
    }
    addCharElementToList(theList, 'G');
    addCharElementToList(theList, 'F');
    addCharElementToList(theList, 'B');
    addCharElementToList(theList, 'C');
    addCharElementToList(theList, 'E');
    addCharElementToList(theList, 'A');
    addCharElementToList(theList, 'D');
    addCharElementToList(theList, 'H');
    addCharElementToList(theList, 'I');
    printf("Razmer spiska: %d\n", theList->count);
    PrintList(theList);
    
    char vstavka='M';
    int index=2;
    InsertCharElementAtIndex(theList, vstavka, index);
    printf("Vstavka elementa %c po indexu %i...\n",vstavka,index);
    PrintList(theList);
    
    printf("Sortirovka spiska...\n");
    quickSort(theList, 0, theList->count-1);
    PrintList(theList);
    
    int inex_for_delete=2;
    printf("Udalenie elementa po indexu %i...\n",inex_for_delete);
    DeleteCharElementAtIndex(theList, inex_for_delete);
    PrintList(theList);
    
    DestroyCharList(theList);
    printf("Spisok udalen!\n");
}
