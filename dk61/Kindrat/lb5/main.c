#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"


int main(void)
{

 Tree *thisTree = NULL;
 Tree *tmp;
 int chislo, command;

 for (int i = 0; i < 9; i++)
 {
  printf("Enter chislo: ");
  scanf("%i", &chislo);
  AddNode(&thisTree, chislo);
 }

 printf("Elements: ");
 PrintTree(thisTree);
 printf("\n");

 do
 {
  printf("[1] -> Add Node;\n[2] -> Print Tree;\n[3] -> Exit to search.\n");
  printf("Enter command: ");
  scanf("%d", &command);
  switch (command)
  {
  case 1:
   printf("Enter chislo: ");
   scanf("%i", &chislo);
   AddNode(&thisTree, chislo);
   break;

  case 2:
   printf("Elements: ");
   PrintTree(thisTree);
   printf("\n");
   break;
  
  case 3:
   printf("Head: %i\n", thisTree->data);
   printf("Enter chislo that you want to find: ");
   break;

  default:
   printf("No such command\n");
   break;
  }
 } while (command != 3);
 
 
 scanf("%i", &chislo);
 tmp = Search(&thisTree, chislo);
 if (tmp)
 {
  printf("Searched node = %d\n", tmp->data);
 }
 else
 {
 	 printf("Element was not found in you tree.\n");
 }

 DeleteElements(thisTree);

 return 1;
}
