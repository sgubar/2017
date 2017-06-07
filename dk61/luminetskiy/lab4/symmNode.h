#ifndef symNode_h
#define symNode_h



typedef struct charNodeTag charNode;

struct charNodeTag
{
    char value;
    charNode *prev;
    charNode *next;
};

charNode *createCharNode(char aChar);
void freeCharNode(charNode *theNode);

#endif //symNode_h
