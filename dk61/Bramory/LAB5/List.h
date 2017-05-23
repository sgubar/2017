#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

// Node description
typedef struct tagNode LinkNode;

struct tagNode
{
	LinkNode *prev;
	LinkNode *next;
	int value;
	int mark;
};

// List description
typedef struct tagList
{
	LinkNode *head;
	LinkNode *tail;
	int count;
}IntList;


IntList *CreateIntList( void );
void DestroyIntList(IntList *aList);

int AddIntValueToList(IntList *aList, int anIntValue);
LinkNode *FindTheNodeAtIndex(IntList *aList, int anIndex);
int IntValueAtIndex(IntList *aList, int anIndex);
int InsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex);
int DeleteIntValueAtIndex(IntList *aList, int anIndex);
void PrintList(IntList *aList);


void MarkIndexToDelete(IntList *aList, int MultipleIndex, bool markFirst);
//return 0 if sucsess
//otherwsise -1
int DeleteMarksElements( IntList *aList );
int DeleteValueFromIntList(IntList *aList, int aValue);
IntList *getIntListWithRandValues( int amount, bool state );





#endif // LIST_H_INCLUDED
