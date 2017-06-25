#ifndef dk_tool_h
#define dk_tool_h
#include<stdio.h>

typedef struct __tagCharNode CharNode;
struct __tagCharNode
{
    char value;
    CharNode *prev;
    CharNode *next;
};
typedef struct __tagCharList
{
    CharNode *head;
    CharNode *tail;
    char count;
}CharList;
CharList *CreateCharList();
void DestroyCharList(CharList *aList);
char addCharElementToList(CharList *aList, char anCharElement);
CharNode *CharElementAtIndex(CharList *aList, char anIndex);
void PrintList(CharList *aList);
char InsertCharElementAtIndex(CharList *aList, char anCharElement, char anIndex);
void DeleteCharElementAtIndex(CharList *aList, char anIndex);
void quickSort(CharList *aList, char aLeftIndex, char aRightIndex);
void m_manualSort(CharList *aList, char aLeftIndex, char aRightIndex);
char mediana(CharList *aList, char aLeftIndex, char aRightIndex);
char m_partitionIt(CharList *aList, char aLeftIndex, char aRightIndex, char aPivot);
void swap(CharList *aList, char aLeftIndex, char aRightIndex);
#endif
