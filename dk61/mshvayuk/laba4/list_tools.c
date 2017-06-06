#include "list_tools.h"
#include <stdio.h>
#include <stdlib.h>

nodeChar *CreateNodeWithCharValue( char aValue)
{
	nodeChar *theResult = (nodeChar *)malloc(sizeof(nodeChar));
	
	theResult->value = aValue;
//	theResult->prevNode = NULL;
	theResult->nextNode = NULL;
	
	return theResult;	
}

nodeChar FreeCharNode(nodeChar *aNode)
{
	if(NULL != aNode)
	{
		free(aNode);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////LIST

List *CreateList()//create a new LIST
{
	List *aList = (List *)malloc(sizeof(List));
	
	aList->head = NULL;
	aList->tail = NULL;
	aList->count = 0;
	
	return aList;
}

void FreeList(List *aList)// free a memory, occupied by LIST
{
	if(NULL == aList)
	{
		return;
	}

	nodeChar *theNode = aList->head;
	
	while (NULL != theNode)
	{
		nodeChar *NodeToBeFree = theNode;
		theNode = theNode->nextNode;
		
		free(NodeToBeFree);
	}
	
	free(aList);
}

nodeChar *addNodeToTheEndOfList(List *aList, nodeChar *aNewNode)//add node to the end of list
{
	if(NULL == aList || NULL == aNewNode)//check input parameters
	{
		return NULL;
	}
	
	// add new node to the end of the list
	
	if(NULL == aList->tail && NULL == aList->head)
	{
		//this LIST is empty
		aList->head = aList->tail = aNewNode; 
	}
	else
	{
		nodeChar *theTail = aList->tail;// theTail is TMP variable for saving last element of LIST
		aList->tail = aNewNode;
		
		if(NULL != theTail)
		{
			theTail->nextNode = aList->tail;//сейчас в theTail то значение, что было концом списка до добавления нового элемента
		}
	}
	
	aList->count += 1;
	
	return aNewNode;

}

int printTextFromFileBackToFront (List *aList, FILE *aFile_INPUT, FILE *aFile_OUTPUT)//print text from file into a console and return lenght of file
	{
		char letter ;
		nodeChar *theNode;// it forms our LIST
		int counter = 0;//counts a number of letters before new line symbol
		int memory = 0;// чтобы печатеть кажыдй раз только следующею строчку, а не весь предыдущий текст

		if(NULL == aList || NULL == aFile_INPUT)
		{
			return NULL;
		}
			
		// add new node to the end of the list
		
		while (letter != EOF)
		{
			letter = fgetc(aFile_INPUT);//read the text letter by letter from a FILE
			theNode = CreateNodeWithCharValue(letter);
			
			addNodeToTheEndOfList(aList, theNode);
			
			int detektNewLineSymbol = checkNewLineSymbol (theNode->value);
			
			if (detektNewLineSymbol == 1)
			{
				int i = counter;
				
				
				for (i; i>memory; i--)
				{
					nodeChar *showNode = ShowNodeAtIndex(aList, i);
					
					char showLetter = showNode->value;
					
					printf("%c", showLetter);//print a text to the console
					fprintf(aFile_OUTPUT, "%c", showLetter );
				}
				
				memory = counter;
			}
			
			counter ++;		
		}
	}
	
	int checkNewLineSymbol (char letter)// if letter is NEW LINE SYMBOL - return 1, if it isnt - return 0
	{
		int i = 0;
		
		if (letter == '\n')
		{
			i = 1;
		}
		
		return i;
	}

int CountList(List *aList)//return a lenght of LIST
{
	int lenghtOfList = 0;
	if(NULL != aList)
	{
	lenghtOfList = aList->count;
	}
	
	return lenghtOfList;
}

nodeChar *ShowNodeAtIndex(List *aList, int aIndex)//show a value of node, which stays at definite index in the LIST
{	
	nodeChar *theResult = NULL;

	if(NULL != aList && aIndex < aList->count)
	{
		int i = 0;
		nodeChar *theNode = aList->head;
		
		do
		{
			if (i == aIndex)//<!- index was found
			{
				theResult = theNode;//<! - our node
				break;
			}
			
		i++;// increase index
		theNode = theNode->nextNode;//<! - go to next node
			
		}
		while(theNode != NULL);
	
	}
	
	return theResult;
	
}

void printListToFILE(FILE *aFile, List *aList)//printf a linked LIST to the console
{
	int i = 0;
	int lenght = CountList(aList);//lenght of LIST
	for (i;i<lenght;i++)
	{
	nodeChar *actually_node = ShowNodeAtIndex(aList, i);
		
		if (actually_node != NULL)
		{
			fprintf(aFile, "node[%i].value = %c\n", i, actually_node->value);
		}
	}
}

void doTestList()
{
		printf("Start to demo a single-linked list using reading from file ...\n");
		
		nodeChar *first_node = CreateNodeWithCharValue('a');
		nodeChar *second_node = CreateNodeWithCharValue('b');
		nodeChar *third_node = CreateNodeWithCharValue('c');
		nodeChar *fourth_node = CreateNodeWithCharValue('d');

		List *test_list = CreateList();
		printf("number of elements: %i\n", CountList(test_list));

		addNodeToTheEndOfList(test_list, first_node);
		printf("number of elements: %i\n", CountList(test_list));

		addNodeToTheEndOfList(test_list, second_node);
		printf("number of elements: %i\n", CountList(test_list));

		addNodeToTheEndOfList(test_list, third_node);
		printf("number of elements: %i\n", CountList(test_list));
		
		addNodeToTheEndOfList(test_list, fourth_node);
		printf("number of elements: %i\n", CountList(test_list));


		printListToConsole(test_list);
		
		FreeList(test_list);	
		
		printf("Done.\n");

}




















