#ifndef LAB5_TREE_H
#define LAB5_TREE_H
#include <stdio.h>
#include <stdbool.h>

struct node{
    char value;
    struct node* Parent;
    struct node* Left_child;
    struct node* Right_child;
};
typedef struct{
    struct node* Root;
}tree;

void swap(char *s, char *i);
void PutData(char* buf);
bool check(char* arr,int N);
char* CutSpace(char* str,int n);
/*void Shellsort(char* mas, int n)*/
bool GetData(char* filename);
struct node *New_member(char val,struct node* parent);
struct node* New_family(struct node* child,struct node* parent,int gen_size, int child_number);
tree* New_tree();
struct node* Search(struct node* ptr, char value);
#endif //LAB5_TREE_H
