#include "tree.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
static char data[100];
static int size;
void swap(char *s, char *i){
    char tmp = *s;
    *s = *i;
    *i = tmp;
}
void Shellsort(char* mas, int n){ //sort array mas with size n by the method of Shell
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; ++i) {
            for (int j = i-gap; j >= 0 && mas[j] > mas[j+gap]; j -=gap)
                swap(&mas[j],&mas[j+gap]);
        }
    }
}
bool check(char* arr, int N){
    while(N > 0){
        if(arr[N] < arr[N-1]){
            return false;
        }
        N--;
    }
    return true;
}
bool GetData(char* filename){
    FILE* file = fopen(filename,"r");
    if (file == NULL)
        return false;
    char c;
    int i = 0;
    while( (c = fgetc(file))!= '\0'){
        if (c != '\0' && c != '\n' && c != ' '){
            data[i] = c;
        }
    }
    size = strlen(data);
    if(!check(data,size))
        Shellsort(data,size);
    return true;
}
struct node* New_member(char val,struct node* parent){
    struct node* kid;
    kid->value = val;
    kid->Parent = parent;
    return kid;
}
struct node* New_family(struct node* child,struct node* parent,int gen_size, int child_number){
    int current = size*child_number/(2*gen_size);
    if (current < 0 && current >= size && data[current] == EOF)
        return NULL;
    child = New_member(data[current],parent);
    data[current] = EOF;
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
struct node* Search(struct node* ptr, char value){
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