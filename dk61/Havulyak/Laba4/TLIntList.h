#ifndef TLIntList_h
#define TLIntList_h

#include <stdio.h>
typedef struct __tagIntNode IntNode;    //Базовый тип списка
struct __tagIntNode						//Структура элемента списка
{
	int value;            				// поле данных
	IntNode *prev;        				// указатель на предыдущий элемент
	IntNode *next;        				// указатель на следуйщий элемент
};

typedef struct __tagIntList				// Дескриптор
{
	IntNode *head;						// Указатель на первый элемент
	IntNode *tail;						// Указатель на предыдущий элемент
	int count;
}IntList;

IntList *TLCreateIntList();				// Выделение памятии под корень списка
void TLDestroyIntList(IntList *aList);  // Удали 
int TLAddIntValueToList(IntList *aList, int anIntValue);
void TLPrintList1(IntList *aList);
void TLPrintList2(IntList *aList);		
IntNode *createIntNodeWithValue(int anIntValue);
#endif /* TLIntList_h */
