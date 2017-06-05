#ifndef dk_tool_h
#define dk_tool_h

typedef struct aNode
{
    int value;				
    struct aNode *next;		
    struct aNode *prev;		
}Node;

typedef struct aList
{
	int amount;				
	struct aNode *head;		
	struct aNode *tail;		
}List;

List *createList();

void createFirstElement(List *aList, int val);				
void createNextElement(List *aList, int val);			

void printList(List *aList);							
void deleteList(List *aList);							

void fillElements(List *aList);
void rePrintList(List *aList);

#endif
