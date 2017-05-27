#ifndef dk_tool_h
#define dk_tool_h

typedef struct aNode
{
    int value;
    struct aNode *next;
}Node;

int *listToArray(Node *head);							//create array from list
void createLastElement(Node *head, int val);			//create element in end of list	|| doesn't work in empty list
void createFirstPush(Node **head, int val);				//create element on first position
void arrayToList(Node **head, int *anArray, int aSize);	//create list from array

void changeElement(Node *head, int num, int val);		//change element on num position by val value
void insertElement(Node *head, int num, int val);		//insert element on num position with val value

void deleteList(Node **head);							//delete all elements in list
int deleteLastPop(Node **head);							//delete last element, return value of last element
int deleteFirstPop(Node **head);						//delete element with head pointer, return value of this element
int deleteElement(Node **head, int num);				//delete nth element, return value of this element

int getLength(Node *head);								//return length of list
int getNumber(Node *head, Node *tmp);					//return number of tmp
int getValueNumber(Node *head, int num);				//return value of element || use number in list
Node *getLsatElement(Node *head);						//return pointer on last element
Node *getPreLastElement(Node *head);					//return prelast element
Node *getElement(Node *head, int num);					//return pointer on num element
Node *getPreElement(Node *head, Node *tmp);				//return previous element

void printList(Node *head);								//print elements in list

void quickSortList(Node *left, Node *right);			//sorting list like quicksort
void swapElement(Node *a, Node *b);							//replace two elements

#endif
