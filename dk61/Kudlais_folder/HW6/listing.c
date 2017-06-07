#include <stdio.h>
#include <stdbool.h>
#include "listing.h"

void swap(char * a,char * b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
    }
struct node *NewNode (char let,struct node *prev){
    struct node *new;
    new->data = let;
    if(prev != NULL)
        prev->Next = new;
    return new;
}
list* fBuff(char *filename){
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        // printf("Error! File does not exist!\n");
        return NULL;
    }
    list* chain;
    int entermediary = fgetc(file);
    chain->Head = NewNode((char) entermediary, NULL);
    struct node *part;
    while ('\0' != (entermediary = fgetc(file))) {
        if (entermediary != '\n')
            part = NewNode((char) entermediary, part);
    }
    chain->Tail = part;
    part->Next = NULL;
    return chain;
}
void listsort(struct node* begin,struct node* end) {
    if (begin == end)
        return;
    struct node* wall = begin;
    for (struct node* here = begin; here != end; here = here->Next) {
        if(here->data < wall->data) {
            swap(&here->data, &wall->data);
            wall = wall->Next;
        }

    }
    listsort(begin,wall);
    listsort(wall->Next,end);
}
void Printlist(list* prt){
    for (struct node* scr = prt->Head; scr != NULL; scr = scr->Next) {
        printf(" %c ",scr->data);
    }
}