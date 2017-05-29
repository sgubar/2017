
#ifndef TESTTYMMETRICNODE_H_INCLUDED
#define TESTTYMMETRICNODE_H_INCLUDED

//#include "TestSymmetricList.h"

typedef struct charNodeTag charNode;

struct charNodeTag
{
    char value;
    charNode *prev;
    charNode *next;
};

charNode *createCharNode(char aChar);
void freeCharNode(charNode *theNode);

#endif //TESTTYMMETRICNODE_H_INCLUDED
