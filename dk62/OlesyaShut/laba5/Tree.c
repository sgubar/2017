#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>

/* PRIVATE */
//повертає випадкове число [1..99]
int rnd() {
	return rand() % 99 + 1;
}

/* PUBLIC */
//друк дерева
/*
 * параметр глибини depth визначає рівень рекурсії і відповідає за відступ при друку поточного вузла
 */
void print(ptr root, int depth) {
	if (root == NULL) //кінець піддерева
		return;
	for (int i = 0; i < depth; i++) //відступ
		printf("\t");
	printf("%d\n",root->value); //друк поточного елементу
	print(root->left,depth+1); //обхід лівого піддерева з збільшеною глибиною
	print(root->right,depth+1); //обхід правого піддерева з збільшеною глибиною
}

//створення дерева з n вузлів з випадковими ключами. повертає вказівник на корінь
ptr create(int n) {
	ptr *root = (ptr*)malloc(sizeof(ptr)); //вказівник на корінь нового дерева
	*root = NULL;
	for (int i = 0; i < n; i++) //додаємо новий випадковий елемент
		add(root, rnd());
	return *root; //повертаємо корінь
}

//додавання елементу. повертає 1 в разі успішного створення, 0 - в разі наявності елемента
char add(ptr *root, int value) {
	if (*root == NULL) { //пусте дерево
		//створення нового елементу
		*root = (ptr)malloc(sizeof(root));
		(*root)->value = value;
		(*root)->left = (*root)->right = NULL; //обнуляємо вказівники на піддерева
		return 1;
	} else if (value < (*root)->value) //значення поточного вузла більше, ніж шуканого
		if ((*root)->left) //ліве піддерево існує
			return add(&(*root)->left,value); //додаємо елемент в ліве піддерево
		else { //ліве піддерево відсутнє
			//створюємо елемент в лівому піддереві
			ptr tmp = (ptr)malloc(sizeof(root));
			tmp->value = value;
			tmp->left = tmp->right = NULL;
			(*root)->left = tmp;
			return 1;
		}
	else if (value > (*root)->value) //аналогічно попереньому, робота з правим піддеревом
		if ((*root)->right)
			return add(&(*root)->right,value);
		else {
			ptr tmp = (ptr)malloc(sizeof(root));
			tmp->value = value;
			tmp->left = tmp->right = NULL;
			(*root)->right = tmp;
			return 1;
		}
	else {//поточний елемент співпадає з новим
		return 0;
	}
	
}

//видалення елементу
char rem(ptr *root, int value) {
	if ((*root)->value > value) {
			if (rem(&(*root)->left,value) == 2) {
				free((*root)->left);
				(*root)->left = NULL;
				return 1;
			}
		} else if ((*root)->value < value) {
			if (rem(&(*root)->right,value) == 2) {
				free((*root)->right);
				(*root)->right = NULL;
				return 1;
			}
		} else if ((*root)->left == (*root)->right) {
			return 2;
		} else if ((*root)->left == NULL) {
			ptr tmp = (*root)->left;
			(*root)->value = (*root)->right->value;
			(*root)->left = (*root)->right->left;
			(*root)->right = (*root)->right->right;
			free(tmp);
			return 1;
		} else if ((*root)->right == NULL) {
			ptr tmp = (*root)->right;
			(*root)->value = (*root)->left->value;
			(*root)->left = (*root)->left->left;
			(*root)->right = (*root)->left->right;
			free(tmp);
			return 1;
		} else if ((*root)->right->left == NULL) {
			ptr tmp = (*root)->right;
			(*root)->value = (*root)->right->value;
			(*root)->right = (*root)->right->right;
			free(tmp);
			return 1;
		} else {
			ptr tmp = (*root)->right;
			while (tmp->left != NULL) {
				tmp = tmp->left;
			}
			(*root)->value = tmp->value;
			return rem(&(*root)->right,tmp->value);
		}
		return 0;
}

//пошук елементу. повертає вказівник на вузол в разі наявності, інакше - NULL
ptr find(ptr root, int value) {
	if (root == NULL) //кінець обходу
		return NULL;
	if (value < root->value) //значення поточного вузла більше, ніж шуканого
		return find(root->left,value); //пошук в лівому піддереві
	else if (value > root->value) //значення поточного вузла менше, ніж шуканого
		return find(root->right, value); //пошук в правому піддереві
	else //елемент знайдено
		return root;
}

//видалення дерева
void erase(ptr *root) {
	if (*root == NULL) //пусте дерево
		return;
	erase(&(*root)->left); //видаляємо ліве піддерево
	erase(&(*root)->right); //видаляємо праве піддерево
	free(*root); //звільняємо пам'ять під праве піддерево
}
