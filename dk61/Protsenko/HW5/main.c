#include "dk_tool.h"

int main(void)
{   
    printf("Hello. Programm won't work if you create more then 10 triangles \n");
    printf("How many triangles to create? : ");
	
	int Size;
	int check = scanf("%i", &Size);
	
	while (Size > 10 || check == 0)
		{
		 printf("\nInncorect value. \n");
		 return 0;
		}
	
		while (Size <= 10)
		{
		FigureList *List=createFigureList(10);
	
		for(int i=0; i<Size; i++)
   			 {
    		  FillCoord(List);
    		 }
    		 
    	printf("\n	- - - - - - - List of triangles before sorting - - - - - - -\n\n");
		PrintList(List);
		ShellSort(List);
		
		printf("\n	- - - - - - - List of triangles after sorting - - - - - - -\n\n");
		PrintList(List);
		int key=0;
		BinarySearch(List, key);
		break;
		}
}

