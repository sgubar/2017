
#include "dk_list.h"
#include "stdio.h"
#include "sortPointers.h"
#include "sortValues.h"
/*
#define errorEmptyList printf("U can't do any act when list is empty. Add values to list!\n")

//declarations
int getAnswer();
int getIntFromUser();
int getIndexFromUser(intList *aList);
int getFromUser1or2();

//list
void list()
{
    intList *aList=createIntList();

    int choice=0;

    printf("Please enter numb of your choice. From 1 to 8\n");
    printf("1 - add int to list\n");
    printf("2 - delete int from list at index\n");
    printf("3 - delete int from list\n");
    printf("4 - insert int in list at index\n");
    printf("5 - show int value at index\n");
    printf("6 - search int in list\n");
    printf("7 - print list\n");
    printf("8 - sort list by shell sort\n");
    printf("9 - sort list by quick sort\n");
    printf("10 - exit\n");

    do
    {
        choice=getAnswer();
        switch (choice)
        {
            case 1:
                addIntValueToList(aList, getIntFromUser());
                printList(aList);
                break;

            case 2:
                aList->count==0 ?errorEmptyList :deleteIntValueAtIndex(aList, getIndexFromUser(aList)), printList(aList);
                break;

            case 3:

                if(aList->count==0)
                {
                    errorEmptyList;
                }
                else
                {
                    int chek= deleteIntValue(aList, getIntFromUser());
                    if (chek==-1)
                    {
                        printf("This list hasn't this value\n");
                    }
                    printList(aList);
                }
                break;

            case 4:

                aList->count==0 ?errorEmptyList :insertIntValueAtIndex(aList, getIntFromUser(), getIndexFromUser(aList)), printList(aList);
                break;

            case 5:

                if(aList->count==0)
                {
                    errorEmptyList;
                }
                else
                {
                    int theInt=intValueAtIndex(aList, getIndexFromUser(aList));
                    printf("On this index value=%i\n", theInt);
                }
                break;

            case 6:

                if(aList->count==0)
                {
                    errorEmptyList;
                }
                else
                {
                    int result=searchKeyPosition(aList, getIntFromUser());
                    if (result==-1)
                    {
                        printf("This list hasn't this value\n");
                    }
                    else
                    {
                        printf("The value has been found on %i position\n", result);
                    }
                }
                break;

            case 7:

                aList->count==0 ?errorEmptyList :printList(aList);
                break;

            case 8:

                if(aList->count==0)
                {
                    errorEmptyList;
                }
                else
                {
                    int answer=getFromUser1or2();
                    if(answer==1)
                    {
                        shellSortPointers(aList);
                    }
                    else if(answer==2)
                    {
                        shellSortValues(aList);
                    }
                    printList(aList);
                }
                break;

            case 9:

                if(aList->count==0)
                {
                    errorEmptyList;
                }
                else
                {
                    int answer=getFromUser1or2();
                    if(answer==1)
                    {
                        quickSortPointers(aList, 0, aList->count-1);
                    }
                    else if(answer==2)
                    {
                        quickSortValues(aList, 0, aList->count-1);
                    }
                    printList(aList);
                }
                break;

            default:
                break;
        }


        if(choice!=10)
            printf("\nChoose act from 1 to 10\n");



    }while (choice!=10);


    printf("Thanks for using this List!\n");
    if (aList->count!=0)
    {
        printf("End version of your list \n");
        printList(aList);
    }

    destroyIntList(aList);

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

        if(chek!=1 || answer>10 || answer<1)
        {
            printf("ERROR. Please enter numb of your choice. From 1 to 10\n");
        }

    }while (chek!=1 || answer>10 || answer<1);

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

int getIndexFromUser(intList *aList)
{
    printf("Please enter int from 0 to %i\n", aList->count-1);
    int chek=0;
    int answer=0;
    do
    {

        chek=scanf("%i", &answer);
        if (chek!=1 || answer>aList->count-1 || answer<0)
        {
            printf("ERROR. Please enter int from 0 to %i\n", aList->count-1);
        }
    }while(chek!=1 || answer>aList->count-1 || answer<0);

    return answer;
}

int getFromUser1or2()
{
    printf("Please enter numb of your choice(1 or 2)\n");
    printf("1 - sort pointers(if u have big value)\n");
    printf("2 - sort values\n");

    int chek=0;
    int answer=0;
    do
    {
        chek=scanf("%i", &answer);
        if (chek!=1 || answer<1 || answer>2)
        {
            printf("ERROR. Please enter int 1 or 2\n");
        }
    }while(chek!=1 || answer<1 || answer>2);

    return answer;
}*/