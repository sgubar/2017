#include <stdio.h>
#include <conio.h>
#include "list.h"

int main()
{
	

	Node* TheNode1 = createNodeWithfloatValue(5.325);
	Node* TheNode2 = createNodeWithfloatValue(54.323);
	Node* TheNode3 = createNodeWithfloatValue(22.236);
	Node* TheNode4 = createNodeWithfloatValue(1.33225);
	Node* TheNode5 = createNodeWithfloatValue(9.6643);
	Node* TheNode6 = createNodeWithfloatValue(64.3366);
	

	floatList *theList = CreatefloatList();
	if (NULL == theList)
	{
		return -1;
	}

	printf("number of elements: %d\n", CountList(theList));

	AddfloatValueToList(theList, TheNode1);
	printf("number of elements: %d\n", CountList(theList));

	AddfloatValueToList(theList, TheNode2);
	printf("number of elements: %d\n", CountList(theList));

	AddfloatValueToList(theList, TheNode3);
	printf("number of elements: %d\n", CountList(theList));

	AddfloatValueToList(theList, TheNode4);
	printf("number of elements: %d\n", CountList(theList));

	AddfloatValueToList(theList, TheNode5);
	printf("number of elements: %d\n", CountList(theList));




	PrintList(theList);
	Node*theIndex = floatValueAtIndex(theList, 3);
	printf("The value at index %d: %f\n", 3, theIndex->value);

	theIndex = floatValueAtIndex(theList, 1);
	printf("The value at index %d: %f\n", 1, theIndex->value);

	

	InsertfloatValueAtIndex(theList, TheNode6, 3);
	PrintList(theList);

	DeleteElementAtIndex(theList,5);
	PrintList(theList);

	DestroyfloatList(theList);


	_getch();

}