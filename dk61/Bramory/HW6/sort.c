#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "sort.h"
#include "List.h"

void QuickSort_NodeList(IntList *aList, int b0, int e0)
{
	if (NULL == aList || aList->count <= 1)
	{
		return;
	}
	
	int aLeftIn = b0;	// begin index
	int aRightIn = e0;	// end index
	IntNode *aLeftNode = FindTheNodeAtIndex(aList, aLeftIn);
	IntNode *aRightNode = FindTheNodeAtIndex(aList, aRightIn);
	int key = aRightNode->value; //last value
		
	do
	{
		while(aLeftNode->value < key)
		{
			aLeftNode = aLeftNode->next;	
			++aLeftIn;	
		}
		
		while(aRightNode->value > key)
		{
			aRightNode = aRightNode->prev;
			--aRightIn;	
		}
		
		if ( aLeftIn <= aRightIn )
		{
//			swap(aLeftNode, aRightNode); //only value

			swapAddress(aList, aLeftNode, aRightNode, aLeftIn, aRightIn);
			aLeftIn++;
			aRightIn--;
			aRightNode = FindTheNodeAtIndex(aList, aRightIn);
			aLeftNode  = FindTheNodeAtIndex(aList, aLeftIn);
		}
	}
	while(aLeftIn <= aRightIn); //begin <= end 
	
	if (aRightIn > b0)
		QuickSort_NodeList(aList, b0, aRightIn); //left part
	if (aLeftIn < e0)
		QuickSort_NodeList(aList, aLeftIn, e0); //right part
}

void Shell_Sort_NodeList( IntList *aList )
{
	if (NULL == aList || aList->count <= 1)
	{
		return;
	}
	
	int i, step = aList -> count / 2;
	
	while (step > 0)
    {
      for (i = 0; i < (aList->count - step); i++)
        {
      	  int j = i;
      	  IntNode *aLeftNode  = FindTheNodeAtIndex(aList, j);
      	  IntNode *aRightNode = FindTheNodeAtIndex(aList, j + step);
      	  
          while (j >= 0 && aLeftNode->value > aRightNode->value)   // "<" - [9..1]    ">" - [1..9]              
            {
            	swapAddress(aList, aLeftNode, aRightNode, j, j+step );
                j--;
				aLeftNode  = FindTheNodeAtIndex(aList, j);
      	  		aRightNode = FindTheNodeAtIndex(aList, j + step); 
            }
		}
    step /= 2; 
	} 
}

void swap (IntNode *var1, IntNode *var2)
{
//	if (var1 != NULL && var2 != NULL)
	{
		int temp = var1->value;
		var1->value = var2->value;
		var2->value = temp;
	}
}


void swapAddress(IntList *aList, IntNode *aNodeC, IntNode *aNodeB, int aLeftIn, int aRightIn)	
{
	if(NULL == aList || aLeftIn == aRightIn )
	{
		return;
	}
	IntNode *aLeftNext = aNodeC->next;	//[C] [L-Next]   {..}
	IntNode *aRightPrev = aNodeB->prev; //	              	 [R-Prev] [B]
	
	aNodeC->next = aNodeB->next;		//	C-> ( B->{..} )
	aNodeB->prev = aNodeC->prev;		//	( {..}<-C ) <-B
	
	if(aNodeB->next == NULL)
		aList->tail = aNodeC;			//{..} ... C ->NULL
	else
		aNodeC->next->prev = aNodeC;		// {..}  B  {..}  C	<- {..}	 
		
	if (aNodeC->prev == NULL)
		aList->head = aNodeB;			//NULL <- B  {..} 
	else
		aNodeB->prev->next = aNodeB;		// {..} -> B  {..}   C  {..}
	
	// a [c] ...... [b] e  (sort) = a (b) {..} (c) e
	if ( (aRightIn - aLeftIn) > 1 )	
	{
		aNodeB->next = aLeftNext; 			// {..} B -> {(LN)..()} C {..}
		aLeftNext -> prev = aNodeB;			// {..} B <- {(LN)..()} C {..}
			
		aNodeC->prev = aRightPrev; 			// {..} B  {()..(RP)} <- C {..}
		aRightPrev -> next = aNodeC;		// {..} B  {()..(RP)} -> C {..}
	}
	
	// a [c] [b] d (sort) = a b c d
	else
	{
		aNodeB->next = aNodeC; 		// {..} B -> C {..}
		aNodeC->prev = aNodeB; 		// {..} B  <- C {..}
	}
}

int fileWrite(char *name_of_sort, int aSize, IntList *aList)
{
	int i;
	char *path_of_file = (char *)malloc (sizeof(char) * 200);
	memset(path_of_file, 0, sizeof(char) * 200);
	getcwd(path_of_file, 100);
	strcat(path_of_file, "\\TL_NodeList\\"); //new dir
	strcat(path_of_file, name_of_sort);
	strcat(path_of_file, ".txt");
	FILE *aFile = fopen(path_of_file, "w");
	if (NULL != aFile)
	{
		IntNode *theNode;
		for(theNode = aList->head; theNode != NULL; theNode = theNode->next  )
		fprintf (aFile, "%d ",  theNode->value);
			
		free(path_of_file);	
		fflush(aFile);
		fclose(aFile);
		return 0;
	}
	else 
	{
		free(path_of_file);
		printf("Couldn't create output file..\n");
		return -1;
	}
}
