//
// Created by Oleh on 22.04.2017.
//
#ifndef HW6_DKLIST_H
#define HW6_DKLIST_H


// Node description
typedef struct __tagIntNode intNode;

struct __tagIntNode
{
    int value;
    intNode *prev;
    intNode *next;
};

// List description
typedef struct __tagIntList
{
    intNode *head;
    intNode *tail;
    int count;
}intList;

// Interface
intList *createIntList();
void destroyIntList(intList *aList);

// -1 if the value was not added to the list
// otherwise 0
int addIntValueToList(intList *aList, int anIntValue);

// -1 if the value was not inserted to the list
// otherwise 0
int insertIntValueAtIndex(intList *aList, int anIntValue, int anIndex);

// -1 if the value was not inserted to the list
// otherwise 0
void deleteIntValueAtIndex(intList *aList, int anIndex);

// -1 if the value was not inserted to the list
// otherwise 0
int deleteIntValue(intList *aList, int key);

// -1 if value is not found
// otherwise 'int' value
int intValueAtIndex(intList *aList, int anIndex);

// print list
void printList(intList *aList);

//search node
intNode *intNodeAtIndex(intList *aList, int anIndex);

//create node
intNode *createIntNodeWithValue(int anIntValue);

// -1 if value is not found
// otherwise index of value
int searchKeyPosition(intList *aList, int key);


#endif