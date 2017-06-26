#include "List.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//взяття елементу
char pop(ptr *top) {
	if (*top == NULL) 
		return 0;
	char value = (*top)->value; 
	ptr tmp = *top;
	*top = (*top)->link; 
	free(tmp);
	return value; 
}

void push(ptr *top, char value) {
	//створення нового елементу
	ptr tmp = (ptr)malloc(sizeof(node)); 
	tmp->value = value;
	//новий елемент стає вершиною стеку
	tmp->link = *top; 
	*top = tmp;
	
}
//очистка
void empty(ptr *top) {
	while (pop(top)); 
}

void print(ptr top) {
	if (top == NULL) 
		return;
	print(top->link); 
	printf("%c",top->value);
}

ptr reverse(ptr top) {
	if (top == NULL) 
		return NULL;
	ptr *tmp = (ptr*)malloc(sizeof(ptr)); 
	*tmp = NULL;
	char value;
	while (value = pop(&top)) 
		push(tmp,value);
	return *tmp; 
}

void create(ptr *top, char from[]) {
	int len = strlen(from); 
	for (int i = 0; i < len; i++) { 
		push(top,from[i]);
	}
}

void create2(ptr *top, char* from) {
	if (from == NULL)
		return;
	int len = strlen(from);
	for (int i = 0; i < len; i++) {
		push(top,from[i]);
	}
}
