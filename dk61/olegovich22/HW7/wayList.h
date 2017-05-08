//
// Created by Oleg on 08.05.2017.
//

#ifndef HW7_WAYLIST_H
#define HW7_WAYLIST_H

//list way declaration
typedef struct __tagWayNode wayNode;

struct __tagWayNode
{
    int level;
    int value;
    char name[20];
    wayNode *next;
};

typedef struct __tagWayList
{
    wayNode *head;
    wayNode *tail;
    int count;

}wayList;


//create list
wayList *createWayList();

//desroy list
void destroyWayList(wayList *aList);

//add node to list
int addWayValueToList(wayList *aList, char aName[20], int level, int value);

//print list
void printList(wayList *aList);


#endif //HW7_WAYLIST_H
