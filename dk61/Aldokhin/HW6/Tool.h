//
// Created by maksi on 5/12/2017.
//

#ifndef HW6_TOOL_H
#define HW6_TOOL_H

// Node description
typedef struct __tagIntNode IntNode;

struct __tagIntNode
{
    int value;
    IntNode *next;
};

// List description
typedef struct __tagIntList
{
    IntNode *head;
    IntNode *tail;
    int count;
}IntList;

// Interface
IntList *TLCreateIntList();
void TLDestroyIntList(IntList *aList);

// -1 if the value was not added to the list
// otherwise 0
int TLAddIntValueToList(IntList *aList, int anIntValue);

// -1 if the value was not added to the list
// otherwise 0
int TLInsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex);

// MaxInteger if value is not found
// otherwise 'int' value
int TLIntValueAtIndex(IntList *aList, int anIndex);

// print list
void TLPrintList(IntList *aList);

int read_tru(int min_s, int max_s);

//void sort_QuickSort(IntNode **darray, int dfirst, int dlast);

void QuickSort(IntList *aList, IntNode *pbeg, IntNode *pend );

void QuickSort1(IntList *aList, IntNode *pbeg, IntNode *pend);
//
//void trans_array_to_List(IntList *aList, IntNode **array);
//
//void trans_List_to_array(IntList *aList, IntNode **array);
//
int TLDeliteIntValueAtIndex(IntList *aList, int anIndex);

#endif //HW6_TOOL_H