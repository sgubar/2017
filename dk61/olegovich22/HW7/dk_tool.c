//
// Created by Oleg on 05.05.2017.
//

#include "dk_tool.h"
#include "dk_tree.h"
#include <stdio.h>

//declarations
int getAnswer();
int getIntFromUser();
int getTypeBypass();

//main function for tree
void tree()
{
    intTree *aTree=createIntTree();

    if(aTree==NULL)
    {
        printf("ERROR Your computer haven't enough memory or another error.\n");
        return;
    }

    printf("Please enter numb of your choice. From 1 to 10\n");
    printf("1 - insert int to tree\n");
    printf("2 - delete int from tree\n");
    printf("3 - search int in tree\n");
    printf("4 - print tree\n");
    printf("5 - exit\n");

    //declaration of variable
    int choice=0;

    do
    {
        choice=getAnswer();

        switch (choice)
        {
            case 1:
                printf("\nYou chose insert int to tree\n");

                int theInt=getIntFromUser();
                int check=insertIntValueToTree(aTree, theInt);

                if(check!=-1)
                {
                    printf("Inserted at ");
                    findNodeWithValue(aTree, theInt);
                    printTree(aTree, 1);
                }
                break;

            case 2:
                printf("\nYou chose delete int from tree\n");

                theInt=getIntFromUser();
                check=deleteNodeWithValue(aTree, theInt);

                if(check!=-1)
                {
                    printf("Successful deleted\n");
                    printTree(aTree, 1);
                }
                break;

            case 3:
                printf("You chose search int in tree\n");

                theInt=getIntFromUser();

                printf("Address your search node ");
                findNodeWithValue(aTree, theInt);
                break;

            case 4:
                printf("You chose print tree\n");

                theInt=getTypeBypass();
                printTree(aTree, theInt);
                break;

            default:
                break;
        }

        if(choice!=5)
            printf("\nChoose act from 1 to 5\n");

    }while(choice!=5);

    printf("Thanks for using this Tree!\n");
    printf("Final version your tree: \n");
    printTree(aTree, 1);

destroyIntTree(aTree);

}

//geting answer from user
int getAnswer()
{
    int answer=0;
    int chek=0;
    do
    {
        chek=scanf("%i", &answer);
        fflush(stdin);

        if(chek!=1 || answer>5 || answer<1)
        {
            printf("ERROR. Please enter numb of your choice. From 1 to 5\n");
        }

    }while (chek!=1 || answer>5 || answer<1);

    return answer;
}

int getIntFromUser()
{
    printf("Please enter int.\n");
    int chek=0;
    int answer=0;
    do
    {

        chek=scanf("%i", &answer);
        if (chek!=1)
        {
            printf("ERROR. Please enter int.\n");
        }
    }while(chek!=1);

    return answer;
}

int getTypeBypass()
{
    printf("Please enter numb of your choice(1 - 3)\n");
    printf("1 - print by symmetry bypass\n");
    printf("2 - print by direct bypass\n");
    printf("3 - print by reverse bypass\n");

    int chek=0;
    int answer=0;
    do
    {
        chek=scanf("%i", &answer);
        if (chek!=1 || answer<1 || answer>3)
        {
            printf("ERROR. Please enter int 1 - 3\n");
        }
    }while(chek!=1 || answer<1 || answer>3);

    return answer;
}