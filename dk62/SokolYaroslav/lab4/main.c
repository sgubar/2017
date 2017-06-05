#include <stdio.h>
#include "list.h"

int main(void)
{
    CharList *theList=CreateCharList();
    if (NULL==theList)
    {
        return -1;
    }
    addCharElementToList(theList, "ABCDEF");
    addCharElementToList(theList, "ABC");
    addCharElementToList(theList, "ABCDE");
    addCharElementToList(theList, "ABCDEFG");
    addCharElementToList(theList, "ABCDEFGHI");
    addCharElementToList(theList, "ABCDEFGHIJK");
    addCharElementToList(theList, "ABCDEFGHIJ");
    addCharElementToList(theList, "AB");
    addCharElementToList(theList, "ABCDEFGH");
    printf("Razmer spiska: %d\n", theList->count);
    PrintList(theList);
    minimum(theList);

    DestroyCharList(theList);
    printf("Spisok udalen!");
}
