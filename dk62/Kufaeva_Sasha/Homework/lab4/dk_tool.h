#ifndef dk_tool_h
#define dk_tool_h

typedef struct aNode
{
    int value;				//÷èñëî
    struct aNode *next;		//ñëåäóþùèé
    struct aNode *prev;		//ïðåäûäóùèé
}Node;

typedef struct aList
{
	int amount;				//êîëè÷åñòâî
	struct aNode *head;		//ïåðâûé
	struct aNode *tail;		//ïîñëåäíèé
}List;

List *createList();

void createFirstElement(List *aList, int val);				//ñîçäà¸ò ïåðâûé ýëåìåíò
void createNextElement(List *aList, int val);			//ñîçäà¸ò ïîñëåäíèé ýëåìåíò

void printList(List *aList);							//ïå÷àòàåò ñïèñîê
void deleteList(List *aList);							//óäàëÿåò ñïèñîê

void fillElements(List *aList);
void rePrintList(List *aList);

#endif
