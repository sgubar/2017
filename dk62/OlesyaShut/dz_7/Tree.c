#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>


int rnd() {
	return rand() % 99 + 1;
}

void print(ptr root, int depth) {
	if (root == NULL) 
		return;
	for (int i = 0; i < depth; i++) 
		printf("\t");
	printf("%d\n",root->value); 
	print(root->left,depth+1); 
	print(root->right,depth+1); 
}


ptr create(int n) {
	ptr *root = (ptr*)malloc(sizeof(ptr)); 
	*root = NULL;
	for (int i = 0; i < n; i++) 
		add(root, rnd());
	return *root; 
}


char add(ptr *root, int value) {
	if (*root == NULL) { 
		
		*root = (ptr)malloc(sizeof(root));
		(*root)->value = value;
		(*root)->left = (*root)->right = NULL;
		return 1;
	} else if (value < (*root)->value) 
		if ((*root)->left) 
			return add(&(*root)->left,value); 
		else { 
			
			ptr tmp = (ptr)malloc(sizeof(root));
			tmp->value = value;
			tmp->left = tmp->right = NULL;
			(*root)->left = tmp;
			return 1;
		}
	else if (value > (*root)->value) 
		if ((*root)->right)
			return add(&(*root)->right,value);
		else {
			ptr tmp = (ptr)malloc(sizeof(root));
			tmp->value = value;
			tmp->left = tmp->right = NULL;
			(*root)->right = tmp;
			return 1;
		}
	else {
		return 0;
	}
	
}


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


ptr find(ptr root, int value) {
	if (root == NULL) 
		return NULL;
	if (value < root->value) 
		return find(root->left,value);
	else if (value > root->value) 
		return find(root->right, value); 
	else 
		return root;
}


void erase(ptr *root) {
	if (*root == NULL) 
		return;
	erase(&(*root)->left); 
	erase(&(*root)->right); 
	free(*root); 
}
