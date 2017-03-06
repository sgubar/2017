//  dk_tool.c
//  dz1
//  Created by Illia Protsenko on 3/1/17.

#include "dk_tool.h"

void filling_matrix(int x, int y, int arr[x][y], int arr2[x][y]){ //filling matrix//

    printf("- - - - -| First matrix |- - - - -\n");
	for (int i = 0; i < x; i++){  //i - rows//																								
		for (int j = 0; j < y; j++){ //j - columns//  //
			printf("Element [%i][%i]: ", i+1, j+1);	    //filling first matrix
			scanf("%i", &arr[i][j]);				            //
		}
	}
	
	printf("- - - - -| Second matrix |- - - - -\n");
	for (int i = 0; i < x; i++){        				  //
		for(int j = 0; j < y; j++){						      //filling second matrix
		 	printf("Element [%i][%i]: ", i+1, j+1);	  //
			scanf("%i", &arr2[i][j]);	
		}
	}
}

void display_matrix(int x, int y, int arr[x][y], int arr2[x][y]){ //display cell value of matrix//

	printf("- - - - -| First matrix |- - - - -\n");    
	for (int i = 0; i < x; i++){  //i - rows//		   																						
		for (int j = 0; j < y; j++){ //j - columns//   //
			printf("[%2i]", arr[i][j]);				           //printing first matrix
		}											                         //
	printf("\n");									   
	}
	
    printf("- - - - -| Second matrix |- - - - -\n");   
	for (int i = 0; i < x; i++){		   //   
		for(int j = 0; j < y; j++){	     // printing second matrix
		printf("[%2i]", arr2[i][j]);     //
		}											   
	printf("\n");									   
	}
}

void matrix_diff(int x, int y, int arr[x][y], int arr2[x][y], int diff[x][y]){
	
	for (int i = 0; i < x; i++){     //i - rows//		  //
		for(int j = 0; j < y; j++){	 //j - columns//   	//count matrix difference
		   diff[i][j]=arr[i][j]-arr2[i][j];				      //
		}
	}
	
	printf("- - - - -| Matrix difference |- - - - -\n");
	for (int i = 0; i < x; i++){        				//
		for(int j = 0; j < y; j++){						    //printing matrix difference
		   printf("[%2i]", diff[i][j]);					  //
		}
	printf("\n");	
	}	
}
