#ifndef _LIB_TREE_H_
#define _LIB_TREE_H_
//вузол дерева
typedef struct _node {
	int value;
	struct _node* left;
	struct _node* right;
} node;
//вказівник на вузол
typedef node* ptr;

//друк дерева
void print(ptr root,int depth);
//створення дерева з n вузлів з випадковими ключами. повертає вказівник на корінь
ptr create(int n);
//додавання елементу. повертає 1 в разі успішного створення, 0 - в разі наявності елемента
char add(ptr *root, int value);
//видалення елементу
char rem(ptr *root, int value);
//пошук елементу. повертає вказівник на вузол в разі наявності, інакше - NULL
ptr find(ptr root, int value);
//видалення дерева
void erase(ptr *root);
#endif
