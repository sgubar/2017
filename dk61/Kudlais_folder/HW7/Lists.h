#ifndef HW7_LISTS_H
#define HW7_LISTS_H
#include <stdbool.h>
struct node{
    float value;
    struct node* Parent;
    struct node* Left_child;
    struct node* Right_child;
};
typedef struct{
    struct node* Root;
}tree;
void swap(float *s, float *i);
void Shellsort(float mas[], int n);
bool check(float arr[], int N);
void GetData(float habra[],int nmb);
struct node* New_member(float val,struct node* parent);
struct node* New_family(struct node* child,struct node* parent,int gen_size, int child_number);
tree* New_tree(void);
struct node* Search(struct node* ptr, float value);
void PrintTree(tree* ptr);
void FreeTree(tree* ptr);
#endif //HW7_LISTS_H
