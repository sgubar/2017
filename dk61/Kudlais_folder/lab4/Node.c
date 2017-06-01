#include <stdio.h>
#include <stdbool.h>
#include "Node.h"

struct node *NewNode (char let,struct node *pre, struct node *nxt){
    struct node *new;
    new->letter = let;
    new->prev = pre;
    new->next = nxt;
    pre->next = new;
    return new;
}
bool fBuff(char *filename,list *chain){
    FILE * file = fopen(filename,"w");
    if(file == NULL){
        printf("Error! File does not exist!\n");
        return false;
    }
    int entermediary = fgetc(file);
    chain->head = NewNode((char)entermediary,NULL,NULL);
    struct node *part;
    while('\0' != (entermediary = fgetc(file))){
        part = NewNode((char)entermediary,part,NULL);
    }
    chain->tail = part;
    return true;
}
bool ISsymetry(list *chain){
    struct node *left = chain->head;
    struct node *right = chain->tail;
    while(left->next != right->prev && left->next != right){
        if(left->letter != right->letter){
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}