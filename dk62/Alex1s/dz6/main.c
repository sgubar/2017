#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
#include "cor_types.h"

int main(int argc, const char *argv[])
{
printf("Greetings! The program is designed to test a linked list of integer elements.\n");
printf("Program works in 2 modes:\n1) Testing mode;\n2) Normal mode;\n\n");

Node *head = NULL;
Node *last = NULL;

char arg;

do{
	printf("Enter \"w\" to work in normal mode, or \"t\" to test program.\nEnter: ");
	fflush(stdin);
	arg = gch();
}while(arg != 'w' && arg != 'W' && arg != 't' && arg != 'T');

switch(arg)
	{
	case 'w':
		{
		}
	case 'W':
		{
		printf("\nProgram works in loop by 4 steps:\n1) Create element;\n");
		printf("2) Delete element;\n3) Change element;\n4) Sorting list;\n");
		int i, j = 0, k;
		while(true)
			{
			do{
				if(j && !k)
					{
					printf("\nEnter \"v\" to add value.\nEnter: ");
					fflush(stdin);
					arg = gch();
					if(arg != 'v' && arg != 'V')
						break;
					else
						k = 1;
					}
				do{
					printf("\nChoose position of element:\n1 - first element;");
					printf("\n2 - last element;\n3 - other position;\n\nEnter: ");
					fflush(stdin);
					i = gint();
				}while(i < 1 || i > 3);
				
				switch(i)
					{
					case 1:
						{
						printf("\nEnter value to add.\nEnter: ");
						fflush(stdin);
						int val = gint();
						crFirst_push(&head, val);
						printf("Value added!\n");
						break;
						}
					case 2:
						{
						int val;
						if(!head)
							{
							printf("\nEmpty list.\nEnter value to add.\nEnter: ");
							fflush(stdin);
							val = gint();
							crFirst_push(&head, val);
							printf("Value added!\n");
							}
						else
							{
							printf("\nEnter value to add.\nEnter: ");
							fflush(stdin);
							val = gint();
							crLast_el(head, val);
							printf("Value added!\n");
							}
						break;
						}
					case 3:
						{
						int val;
						if(!head)
							{
							printf("\nEmpty list.\nEnter value to add.\nEnter: ");
							fflush(stdin);
							val = gint();
							crFirst_push(&head, val);
							printf("Value added!\n");
							}
						
						else
							{
							int index;
							do{
								printf("\nEnter number of element to insert (0 - %i).\nEnter: ", getLength(head));
								fflush(stdin);
								index = gint();
							}while(index < 0 || index > getLength(head));
							printf("\nEnter value to add.\nEnter: ");
							fflush(stdin);
							val = gint();
							insert_el(head, index, val);
							printf("Value added!\n");
							}
						break;
						}
					}
				printf("\nEnter \"y\" to add more element, or else for next step.\nEnter: ");
				fflush(stdin);
				arg = gch();
			}while(arg == 'y' || arg == 'Y');
			
			printf("\nAmount of elements: %i\n", getLength(head));
			if(head)
				{
				printf("Linked list:\n");
				printList(head);
				}
			
			if(head)
				{
				printf("\nEnter \"d\" to delete anyone element.\nEnter: ");
				fflush(stdin);
				arg = gch();
				if(arg == 'd' || arg == 'D')
					{
					int tmp = getLength(head) - 1;
					do{
						do{
							printf("\nEnter number of element to delete (0 - %i).\nEnter: ", tmp);
							fflush(stdin);
							i = gint();
						}while(i < 0 || i > tmp);
						
						if(!i)
							delFirst_pop(&head);
						
						else if(i == tmp)
							delLast_pop(&head);
						
						else
							del_el(&head, i);
						
						printf("Value deleted!\n");
						
						if(!head)
							break;
						
						printf("\nEnter \"d\" to delete one more element.\nEnter: ");
						fflush(stdin);
						arg = gch();
					}while(arg == 'd' || arg == 'D');
					}
				
				printf("\nAmount of elements: %i\n", getLength(head));
				if(head)
					{
					printf("Linked list:\n");
					printList(head);
					}
				}
			
			if(head)
				{
				printf("\nEnter \"c\" to change any value.\nEnter: ");
				fflush(stdin);
				arg = gch();
				if(arg == 'c' || arg == 'C')
					{
					int val, tmp = getLength(head) - 1;
					do{
						do{
							printf("\nEnter number of element to change (0 - %i).\nEnter: ", tmp);
							fflush(stdin);
							i = gint();
						}while(i < 0 || i > tmp);
						
						printf("\nEnter new value.\nEnter: ");
						fflush(stdin);
						val = gint();
						change_el(head, i, val);
						printf("Value changed!\n");
						
						printf("\nEnter \"c\" to change one more element.\nEnter: ");
						fflush(stdin);
						arg = gch();
					}while(arg == 'c' || arg == 'C');
					}
				
				printf("\nAmount of elements: %i\n", getLength(head));
				if(head)
					{
					printf("Linked list:\n");
					printList(head);
					}
				}
			
			if(getLength(head) > 1)
				{
				printf("\nEnter \"s\" to sort linked list.\nEnter: ");
				fflush(stdin);
				arg = gch();
				if(arg == 's' || arg == 'S')
					{
					last = getLast_el(head);
					qSortList(head, last);
					}
				
				printf("\nAmount of elements: %i\n", getLength(head));
				if(head)
					{
					printf("Linked list:\n");
					printList(head);
					}
				}
			
			k = 0;
			j++;
			printf("\nEnter \"e\" to stop working, or else to continue.\nEnter: ");
			fflush(stdin);
			arg = gch();
			if(arg == 'e' || arg == 'E') 
				break;
			}
		break;
		}
	case 't':
		{
		}
	case 'T':
		{
		int i;
		printf("\nCreating linked list...\n");
		srand(time(NULL));
		for(i = 0; i < 21; i++)
    		crFirst_push(&head, rand());
		
		printf("\nAmount of elements: %i\n", getLength(head));
		printf("Linked list:\n");
		printList(head);
		
		printf("\nSorting linked list...\n");
		last = getLast_el(head);
		qSortList(head, last);
		
		printf("\nAmount of elements: %i\n", getLength(head));
		printf("Linked list:\n");
		printList(head);
		break;
		}
	}

printf("\nDeleting linked list...\n\nAmount of elements: 0\n\n");
delList(&head);
last = NULL;

system("pause");
return 0;
}
