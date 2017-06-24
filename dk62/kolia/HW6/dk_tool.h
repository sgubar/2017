#ifndef dk_tool_h
#define dk_tool_h
#include <stdio.h>


typedef struct tagFloatNode FloatNode;

struct tagFloatNode
{
	float value;
	FloatNode *prev;
	FloatNode *next;
};


typedef struct tagFloatList
{
	FloatNode *head;
	FloatNode *tail;
	int count;
}FloatList;


FloatList *CreateFloatList();
void DeleteFloatList(FloatList *aList);
int AddFloatValue(FloatList *aList, float anFloatValue);
int InsertFloatValueIndex(FloatList *aList, float anFloatValue, int anIndex);
float FloatValueIndex(FloatList *aList, int anIndex);
FloatNode *FindFloatValueIndex(FloatList *aList, int anIndex);
void PrintList(FloatList *aList);
void shellSort(FloatList *aList);
void swap(FloatList *aList, int firstIndex, int secondIndex);
int DeleteFloatValueIndex(FloatList *aList, int anIndex);

#endif
