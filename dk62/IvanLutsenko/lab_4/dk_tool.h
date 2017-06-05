#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
	int value; 
	struct node *link; 
} Node;

int get();
void push(Node **ptr);
int pop(Node **ptr);
void empty(Node *ptr);
void show(Node *ptr);
int find(Node *ptr);
void replace(Node *top);