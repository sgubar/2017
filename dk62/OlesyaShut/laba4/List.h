#ifndef _LIB_LIST_H_
#define _LIB_LIST_H_
//елемент стеку
typedef struct _node {
	char value;
	struct _node* link;
} node;
//вказівник на елемент
typedef node* ptr;

//взяття елементу
char pop(ptr *top);
//додавання елементу
void push(ptr *top, char value);
//очистка стеку
void empty(ptr *top);
//друк (в зворотньому порядку)
void print(ptr top);
//створення стеку з оберненим порядом елементів
ptr reverse(ptr top);
//додавання в стек рядку з масиву
void create(ptr *top, char from[]);
//додавання в стек рядку 
void create2(ptr *top, char* from);
#endif
