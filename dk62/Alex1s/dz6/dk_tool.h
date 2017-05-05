#ifndef dk_tool_h
#define dk_tool_h

typedef struct aNode
{
    int value;
    struct aNode *next;
}Node;

int *getVal_list(Node *head);							//create array from list
void crLast_el(Node *head, int value);					//create element in end of list	|| doesn't work in empty list
void crFirst_push(Node **head, int val);				//create element on first position
void getVal_arr(Node **head, int *anArray, int size);	//create list from array

void change_el(Node *head, int num, int val);			//change element on num position by val value
void insert_el(Node *head, int num, int val);			//insert element on num position with val value

int delLast_pop(Node **head);							//delete last element, return value of last element
int delFirst_pop(Node **head);							//delete element with head pointer, return value of this element
int del_el(Node **head, int num);						//delete nth element, return value of this element
void delList(Node **head);								//delete all elements in list

int length(Node *head);									//return length of list
int get_num(Node *head, Node *tmp);						//return number of tmp
int getVal_num(Node *head, int num);					//return value of element || use number in list
Node *getLast_el(Node *head);							//return pointer on last element
Node *getPre_last(Node *head);							//return prelast element
Node *get_el(Node *head, int num);						//return pointer on num element
Node *getPre_el(Node *head, Node *tmp);					//return previous element

void printList(Node *head);								//print elements in list

void qSortList(Node *left, Node *right);				//sorting list like quicksort
void swap_el(Node *a, Node *b);							//replace two elements

#endif
