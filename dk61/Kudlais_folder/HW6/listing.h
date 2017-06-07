#ifndef HW6_LISTING_H
#define HW6_LISTING_H
#include <stdbool.h>
struct node{
    char data;
    struct node* Next;
};
typedef struct{
    struct node* Head;
    struct node* Tail;
}list;
void swap(char* a, char* b);
struct node *NewNode (char let,struct node *prev);
list* fBuff(char *filename);
void listsort(struct node* begin,struct node* end);
void Printlist(list* prt);
#endif //HW6_LISTING_H
