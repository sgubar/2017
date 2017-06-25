#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

int main(void)
{

 Tree *tagTree = NULL;
 Tree *tmp;
 double val;

 for (int i = 0; i < 10; i++)
 {
  printf("Enter [%i] element: ", i+1);
  scanf("%lf", &val);
  AddNode(&tagTree, val);
 }

 printf("\nElements: ");
 TreePrint(tagTree);
 printf("\n");
 
 
 printf("\nEnter the element you want to add: ");
 scanf("%lf", &val);
 AddNode(&tagTree, val); // func add vals
 printf("\nNow the tree looks like this: ");
 TreePrint(tagTree);
 
 printf("\nROOT of tree: %i\n", tagTree->data);
 
 printf("Enter val that you want to find: ");
 scanf("%lf", &val);
 tmp = Search(&tagTree, val);


if (tmp)
 {
  printf("Searched element is: [%lf]\n", tmp->data);
 }
 else
 {
  printf("The [%lf] is absent in the tree\n", val);
 }

 DestroyTree(tagTree);

 return 0;
}
