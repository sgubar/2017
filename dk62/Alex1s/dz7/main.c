#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dk_tool.h"
#include "cor_types.h"

int main(int argc, const char *argv[])
{
printf("Greetings! The program is designed to test a binary tree of integer elements.\n");
printf("Program works in 2 modes:\n1) Testing mode;\n2) Normal mode;\n\n");

Tree *theTree = createTree();
if(!theTree)
	exit(99);

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
		printf("\nProgram works in loop by 3 steps:\n1) Create element;\n");
		printf("2) Delete element;\n3) Change element;\n");
		
		int i, j = 0, k, val, type;
		Node *tmp = NULL;
		
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
						k++;
					}
				do{
					printf("\nEnter value to add.\nEnter: ");
					fflush(stdin);
					val = gint();
					tmp = search_v(theTree->root, val);
				}while(tmp);
				
				insert_el(theTree, val);
				printf("Value added!\n");
					
				printf("\nEnter \"y\" to add more element, or else for next step.\nEnter: ");
				fflush(stdin);
				arg = gch();
			}while(arg == 'y' || arg == 'Y');
			
			do{
				printf("\nEnter number of printing tree.\n1 - preorder;");
				printf("\n2 - inorder;\n3 - postorder;\n\nEnter: ");
				type = gint();
			}while(type < 1 || type > 3);
			
			print(theTree, type);
			
			if(theTree->root)
				{
				printf("\n\nEnter \"d\" to delete anyone element.\nEnter: ");
				fflush(stdin);
				arg = gch();
				if(arg == 'd' || arg == 'D')
					{
					do{
						printf("\nEnter value of element to delete.\nEnter: ");
						do{
							fflush(stdin);
							i = gint();
							tmp = search_v(theTree->root, i);
							if(!tmp)
								printf("No such element.\nRetry: ");
						}while(!tmp);
						
						delVal_el(theTree, theTree->root, i);
						printf("Value deleted!\n");
						
						if(!theTree->root)
							{
							printf("No one element.\n");
							break;
							}
						
						printf("\nEnter \"d\" to delete one more element.\nEnter: ");
						fflush(stdin);
						arg = gch();
					}while(arg == 'd' || arg == 'D');
					}
				
				print(theTree, type);
				}
			
			if(theTree->root)
				{
				printf("\n\nEnter \"c\" to change any value.\nEnter: ");
				fflush(stdin);
				arg = gch();
				if(arg == 'c' || arg == 'C')
					{
					int val;
					do{
						printf("\nEnter value of element to change.\nEnter: ");
						do{
							fflush(stdin);
							i = gint();
							tmp = search_v(theTree->root, i);
							if(!tmp)
								printf("No such element.\nRetry: ");
						}while(!tmp);
						
						printf("\nEnter new value.\nEnter: ");
						fflush(stdin);
						val = gint();
						
						delVal_el(theTree, theTree->root, i);
						insert_el(theTree, val);
						printf("Value changed!\n");
						
						printf("\nEnter \"c\" to change one more element.\nEnter: ");
						fflush(stdin);
						arg = gch();
					}while(arg == 'c' || arg == 'C');
					}
				
				print(theTree, type);
				}
			
			if(theTree->root)
				{
				printf("\n\nEnter \"s\" to search any value.\nEnter: ");
				fflush(stdin);
				arg = gch();
				if(arg == 's' || arg == 'S')
					do{
						printf("\nEnter value of element to search.\nEnter: ");
						fflush(stdin);
						i = gint();
						tmp = search_v(theTree->root, i);
						
						if(!tmp)
							printf("No such element.\n");
						else
							printf("Finded!\n");
						
						printf("\nEnter \"s\" to search one more element.\nEnter: ");
						fflush(stdin);
						arg = gch();
					}while(arg == 's' || arg == 'S');
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
		int i, type = 2;
		printf("\nCreating linked list...\n");
		
		srand(time(NULL));
		for(i = 0; i < 16; i++)
			insert_el(theTree, rand());
		
		print(theTree, type);
		
		printf("\n\nDeleting root element...\n");
		printf("Previous value: %i", theTree->root->value);
		delVal_el(theTree, theTree->root, theTree->root->value);
		printf("\nNew value: %i\n", theTree->root->value);
		
		print(theTree, type);

		printf("\n\nCreating element with value 5151...\n");
		insert_el(theTree, 5151);
		
		print(theTree, type);
		printf("\n");
		
		break;
		}
	}

printf("\nDeleting binary tree...\n\nAmount of elements: 0\n\n");
destroyTree(theTree);

system("pause");
return 0;
}
