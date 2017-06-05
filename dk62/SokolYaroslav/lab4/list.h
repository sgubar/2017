#ifndef list_h
#define list_h
#include<stdio.h>

typedef struct __tagCharNode CharNode;
struct __tagCharNode
{
    char* value;
    CharNode *prev;
    CharNode *next;
};
typedef struct __tagCharList
{
    CharNode *head;
    CharNode *tail;
    char* count;
}CharList;
CharList *CreateCharList();
void DestroyCharList(CharList *aList);
char* addCharElementToList(CharList *aList, char* anCharElement);
CharNode *CharElementAtIndex(CharList *aList, int anIndex);
void PrintList(CharList *aList);
char* InsertCharElementAtIndex(CharList *aList, char* anCharElement, char* anIndex);
void DeleteCharElementAtIndex(CharList *aList, char* anIndex);
void minimum(CharList *aList);
#endif
