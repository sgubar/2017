

#include "List.h"
#include <limits.h>
#include <stdlib.h>

IntNode *createIntNodeWithValue(int anIntValue);//створюєм вузол інт значень
IntNode *FindTheNodeAtIndex(IntList *aList, int anIndex); //пошук вузла 

IntList *CreateIntList( void )//виділяє пам'ять і очищує її
{
	IntList *theList = (IntList *)malloc(sizeof(IntList));//sizeof повертає значення в байтах
	
	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}
	
	return theList;
}

void DestroyIntList(IntList *aList)// видаляє  список
{
	if (NULL == aList)//чи aList не порожній
	{
		return;
	}

	if (NULL != aList->head)
	{
		int anIndex = aList->count - 1;
		
		do
		{
		IntNode *theNodeToDelete = FindTheNodeAtIndex(aList, anIndex);
		free (theNodeToDelete);
		anIndex--;		
		}while (anIndex >= 0);
	
		free(aList);
	}
}

IntNode *FindTheNodeAtIndex(IntList *aList, int anIndex)//знаходить ноду за індексом
{
	if(aList == NULL || anIndex < 0 || aList->count < anIndex )
	{
		return;
	}
	
	int i = 0;
	IntNode *theNode = aList->head;
	do
	{
		if (i == anIndex)
		{
			break;
		}
	
		theNode = theNode->next;
		i++;
	
	}while (theNode != aList->head);
	
	return theNode;
}


int AddIntValueToList(IntList *aList, int anIntValue)//додаєм значення до списку
{
	int theResult = -1;
	
	if (NULL != aList)
	{
		IntNode *theNode = createIntNodeWithValue(anIntValue);
	
		if (NULL != theNode)
		{
		
			//1. список порожній
			if (NULL == aList->head)
			{
				aList->head = theNode;
				aList->head->next = aList->head->prev = aList->head; //голова зациклюється сама на собі
			}
			else
			{
				//2. якщо 2 або більше елементів
				if (aList->head->next != aList->head)
				{
					// (head) a b(tail)  + c => (head) a b c (tail)
					aList->tail->next = theNode; // b->c
					theNode->prev = aList->tail; // b<-c
					
					aList->tail = theNode;	// новий хвіст
					
					aList->tail->next = aList->head; // c->a
					aList->head->prev = aList->tail; // c<-a
				}
				else
				{
					//3. якщ
					// (head) a  +  b  =>  (head) a b (tail)
					aList->tail = theNode;
					aList->head->next = aList->head->prev = aList->tail;
					aList->tail->next = aList->tail->prev = aList->head;	
				}
			}
		
			aList->count ++;
			theResult = 0;
		}
	}
	return theResult;
}


void PrintList(IntList *aList) //друк отриманих значень
{
	printf("List with count (%d):   ", aList->count);
	IntNode *theNode = aList->head;
	do
	{
		printf("(%d) ", theNode->value);
		theNode = theNode->next;
	
	}while (aList->head != theNode);
	
	printf ("\n");
}




IntNode *createIntNodeWithValue(int anIntValue)//виділяє пам'ять і задає значення ноді
{
	IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
		theNode->prev = NULL;
		theNode->value = anIntValue;
	}
	
	return theNode;
}


// видалення  елемента для голови хвоста і середини кільцевого списку
int DeleteIntValueAtIndex(IntList *aList, int anIndex)
{
	int theResult = -1;
	
	if (NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}
	
	IntNode *theNodeToDelete = FindTheNodeAtIndex(aList, anIndex);
	
	//1. якщо в списку 1 елемент {a} => {empty}
	if (aList->count == 1)	
	{
		free(theNodeToDelete);
		aList->count = 0;
		aList->head = NULL;
		aList->tail = NULL;
		theResult = 0;
		return theResult;
	}
	
	//2. для голови: {a, b, c} => {b, c}
	if (theNodeToDelete == aList->head)	
	{
		IntNode *theNextNode = aList->head->next;
		aList->head = theNextNode; 		//зміна голови
		aList->head->next = theNextNode->next; 
		aList->head->prev = aList->tail;
		
		aList->tail->next = aList->head;
		theResult = 0;
	}
	else
	//3. для хвоста {a, b, c} => {a, b}
	if (theNodeToDelete == aList->tail)	
	{
		aList->tail = aList->tail->prev; //зміна хвоста
		aList->tail->next = aList->head;
		aList->head->prev = aList->tail;
		theResult = 0;
	}
	else
	//3. для видалення з середини {a, b, c} => {a, c} 
	{
		theNodeToDelete->prev->next = theNodeToDelete->next;
		theNodeToDelete->next->prev = theNodeToDelete->prev;
		theResult = 0;
	}
	
	free(theNodeToDelete);
	aList->count--;;
	return theResult;
}

void DeleteMultiplesElements(IntList *aList, int N)//видаляє Nний елмент
{
	if (NULL == aList || N > aList->count - 1 || N < 1)//провірка на те чи в списку елементів більше аніж N
	{
		return;
	}
	
	int step;					 
	int IndexToDelete, iteration;
	
	while (aList->count >= N )//доки кількість елементів більше N виконуємо видалення
	{
		printf("\nAfter %d iteration:\n", iteration);
		PrintList (aList);
		step = 0;
		
		//видаляє третій елемент
		do
		{
			IndexToDelete = N * (step+1) - step - 1;//знаходим індекс коли знач змістились
			DeleteIntValueAtIndex(aList, IndexToDelete ); //видалили
			step ++;
			
		}	while( aList->count - 1 >= IndexToDelete );
		
		iteration ++;
	}
		printf("\nAfter %d iteration:\n", iteration); 
		PrintList (aList); //кінцевий результат
}

