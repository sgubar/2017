#ifndef LAB4_NODE_H
#define LAB4_NODE_H
struct node{
    char letter;
    struct node *next;
    struct node *prev;
};
typedef struct{
    struct node *head; //first
    struct node *tail;//last
    char *name;
} list;

struct node *NewNode (char let,struct node *pre, struct node *nxt);
bool fBuff(char *filename,list *chain);
bool ISsymetry(list *chain);
#endif //LAB4_NODE_H
