#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

int main(void)
{

 Tree *tagTree = NULL;
 Tree *tmp;
 int val;

 for (int i = 0; i < 10; i++)
 {
  printf("Enter [%i] element: ", i+1);
  scanf("%i", &val);
  AddNode(&tagTree, val);
 }

 printf("\nElements: ");
 TreePrint(tagTree);
 printf("\n");
 
 
 printf("\nEnter the element you want to add: ");
 scanf("%i", &val);
 AddNode(&tagTree, val); // func add vals
 printf("\nNow the tree looks like this: ");
 TreePrint(tagTree);
 
 printf("\nROOT of tree: %i\n", tagTree->data);
 
 printf("Enter val that you want to find: ");
 scanf("%i", &val);
 tmp = Search(&tagTree, val);


if (tmp)
 {
  printf("Searched element is: [%d]\n", tmp->data);
 }
 else
 {
  printf("The [%d] is absent in the tree\n", val);
 }

 DestroyTree(tagTree);

 return 0;
}
