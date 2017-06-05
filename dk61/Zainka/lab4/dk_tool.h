

#ifndef dk_tool_h
#define dk_tool_h
#include "list.h"
typedef struct charListTag charList;


typedef struct charListTag
{
    charNode *left;
    charNode *right;
    int count;
}charList;

charList *CreateList(); //create interface

 //destroy interface

charNode *NodeTolist(charList *inputList, charNode *NewNode);




int Simetrija(charList *inputList);

//do list
int ListFile();

#endif 
