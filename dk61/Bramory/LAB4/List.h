#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

// Node description
typedef struct tagNode IntNode;

struct tagNode
{
	IntNode *prev;
	IntNode *next;
	int value;
	int mark;
};

// List description
typedef struct tagList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;


IntList *CreateIntList( void );
void DestroyIntList(IntList *aList);

int AddIntValueToList(IntList *aList, int anIntValue);
IntNode *FindTheNodeAtIndex(IntList *aList, int anIndex);
int IntValueAtIndex(IntList *aList, int anIndex);
int InsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex);
int DeleteIntValueAtIndex(IntList *aList, int anIndex);
void PrintList(IntList *aList);


void MarkIndexToDelete(IntList *aList, int MultipleIndex, bool markFirst);
//return 0 if sucsess
//otherwsise -1
int DeleteMarksElements( IntList *aList );
IntList *getIntListWithRandValues( int amount, bool state );
int randomIntFromRange (int min, int max);





#endif // LIST_H_INCLUDED
