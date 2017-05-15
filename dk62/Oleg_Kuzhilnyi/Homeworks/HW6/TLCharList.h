
#ifndef TLIntList_h
#define TLIntList_h

#include <stdio.h>

// Node description
typedef struct __tagIntNode CharNode;

struct __tagIntNode
{
    char value;
    CharNode *prev;
    CharNode *next;
};

// List description
typedef struct __tagIntList
{
	CharNode *head;
	CharNode *tail;
	int count;
}CharList;

// Interface


// -1 if the value was not added to the list
// otherwise 0
int TLAddCharSymbolToList(CharList *aList, char *anCharSymbol);



// Finding
char FindCharElementAtIndex(CharList *aList, int anIndex);
CharNode *FindNodeAtIndex(CharList *aList, int anIndex);

// Insert node at index
int TLInsertCharSymbolAtIndex(CharList *aList, char *anCharValue, int anIndex);

// Delete node at index
int LT_DeleteCharNode(CharList *aList,int anIndex);

// print list
void TLPrintList(CharList *aList);
CharNode *removeCharNodeAtIndex(CharList *aList, int anIndex);


#endif /* TLIntList_h */
