#include <stdio.h>

int main(void){
	int x, y, chislo; int arr1[x][y];
	printf("Enter rows and columns: ");
	scanf("%i""%i", &x, &y);
	printf("- - - - -| Matrix |- - - - -\n");
    int i=0;
    int j=0;
    int arr[i][j];
	for (i = 0; i < x; i++){  //i - rows//																								
		for ( j = 0; j < y; j++){ //j - columns//  
			scanf("%i", &arr[i][j]);				            
		}
	}
    for (i = 0; i < x; i++){  //i - rows//		   																						
		for (j = 0; j < y; j++){ //j - columns//  //printing first matrix//
			printf("[%2i]", arr[i][j]);	      
		}											                         
	printf("\n");									   
	}
	
	
	printf("Enter nubmer: ");
	scanf("%i", &chislo);
	for (i = 0; i < x; i++){  //i - rows//		   																						
		for (j = 0; j < y; j++){ //j - columns//  //printing first matrix//
			printf("[%2i]", chislo * arr[i][j]);	      
		}											                         
	printf("\n");									   
	}
}
