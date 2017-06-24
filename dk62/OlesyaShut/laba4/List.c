#include "List.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//взяття елементу
char pop(ptr *top) {
	if (*top == NULL) //пустий стек
		return 0;
	char value = (*top)->value; //збереження значення
	ptr tmp = *top; //збереження адреси елементу
	*top = (*top)->link; //переміщення вказівника вершини стеку на наст. елемент
	free(tmp); //очистка пам'яті під поточний елемент
	return value; 
}
//додавання елементу
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
	while (pop(top)); //доки повертається не нуль (нуль - ознака пустого стеку) - виштовшується вершина стеку
}
//друк (зворотній)
void print(ptr top) {
	if (top == NULL) //умова закінчення рекурсії
		return;
	print(top->link); //спускаємось до останнього елементу
	printf("%c",top->value); //на поверненні друкуємо елемент 
}
//створення "зворотнього" стеку
ptr reverse(ptr top) {
	if (top == NULL) //пустий стек
		return NULL;
	ptr *tmp = (ptr*)malloc(sizeof(ptr)); //вказівник на вершину нового стеку
	*tmp = NULL;
	char value;
	while (value = pop(&top)) //перезаписуємо елементи поточного стеку в новий
		push(tmp,value);
	return *tmp; //повертаємо вершину нового стеку
}
//стек з масиву символів
void create(ptr *top, char from[]) {
	int len = strlen(from); //розмір самиву
	for (int i = 0; i < len; i++) { //додаємо в стек поточний символ
		push(top,from[i]);
	}
}
//стек з рядка, реазізація аналогічна
void create2(ptr *top, char* from) {
	if (from == NULL)
		return;
	int len = strlen(from);
	for (int i = 0; i < len; i++) {
		push(top,from[i]);
	}
}
