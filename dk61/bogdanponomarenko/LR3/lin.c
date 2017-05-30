#include "lin.h"

void linear(int anArray[], int Asize)


{
	int key;
	printf("Linear Search\n");
	printf("key \t");
	scanf("%d",&key);
	 for (int i = 0; i < Asize; i++)
       {
           
		   if (anArray[i] == key)
               {
                
                    printf("the searched number  [%d] is located on [%i] position\n",anArray[i],i+1);
               }
    
       }
	return -1;
}


