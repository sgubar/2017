#include "Lists.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
static int size;
static float data[100];
void swap(float *s, float *i){
    float tmp = *s;
    *s = *i;
    *i = tmp;
}
void Shellsort(float mas[], int n){ //sort array mas with size n by the method of Shell
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; ++i) {
            for (int j = i-gap; j >= 0 && mas[j] > mas[j+gap]; j -=gap)
                swap(&mas[j],&mas[j+gap]);
        }
    }
}
bool check(float arr[], int N){
    while(N > 0){
        if(arr[N] < arr[N-1]){
            return false;
        }
        N--;
    }
    return true;
}
void GetData(float habra[],int nmb){
    size = nmb;
    for (int i = 0; i < size; ++i) {
        data[i] = habra[i];
    }
    Shellsort(data,size);
}
struct node* New_member(float val,struct node* parent){
    struct node* kid;
    kid->value = val;
    kid->Parent = parent;
    return kid;
}
struct node* New_family(struct node* child,struct node* parent,int gen_size, int child_number){
    int current = size*child_number/(2*gen_size);
    if (current < 0 && current >= size && data[current] == ~0)
        return NULL;
    child = New_member(data[current],parent);
    data[current] = ~0;
    parent->Right_child = New_family(parent->Right_child,parent,gen_size * 2, child_number * 2 + 1);
    parent->Left_child = New_family(parent->Left_child,parent, gen_size * 2, child_number * 2 - 1);
}
tree* New_tree(void){
    if(size && check(data,size))
        return NULL;
    tree *new;
    new->Root = New_member(data[size / 2], NULL);
    struct node *curr = new->Root;
    curr->Left_child = New_family(curr->Left_child,curr,2,1);
    curr->Right_child = New_family(curr->Right_child,curr,2,2);
    return new;
}
struct node* Search(struct node* ptr, float value){
    struct node* fnd = ptr;
    if(fnd == NULL)
        return NULL;
    if(value < ptr->value)
        Search(ptr->Left_child,value);
    else if(value > ptr->value)
        Search(ptr->Right_child,value);
    else
        return ptr;
}
void PrintTree(tree* ptr){
    struct node* begin = ptr->Root;
    while (begin->Left_child != NULL){
        begin = begin->Left_child;
    }
    struct node* tmp;
    for (tmp = begin; tmp != NULL ; tmp = tmp->Parent) {
        printf("%f",tmp->Left_child->value);
        printf("%f",tmp->value);
        printf("%f",tmp->Right_child->value);
    }
    while (tmp != NULL){
        printf("%f",tmp->Left_child->value);
        printf("%f",tmp->value);
        printf("%f",tmp->Right_child->value);
        tmp = tmp->Right_child;
    }
}
void FreeTree(tree* ptr){
    struct node* begin = ptr->Root;
    while (begin->Left_child != NULL){
        begin = begin->Left_child;
    }
    struct node* tmp;
    for (tmp = begin->Parent; tmp != NULL ; tmp = tmp->Parent) {
    free(begin->Left_child);
    free(begin->Right_child);
    }
    while (tmp != NULL){
        free(tmp->Parent);
        free(tmp->Left_child);
        tmp = tmp->Right_child;
    }
    free(tmp);
}