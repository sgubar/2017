#include <stdio.h>
#include "area_tools.h"
#include "sort_tools.h"

int main(void)
{ 
	FILE *jsonn_before = fopen("jsonn_before.json", "w+");//create a .JSON file
	FILE *jsonn_after = fopen("jsonn_after.json", "w+");

	kvadrat();//printf an image of square
			
	SquareArray *ANarray = create_square_array(15);
	Square ANsquare;	 

	addSeveralSquaresToList(ANarray, &ANsquare);// fill an array with random coordinates
	
	area_square(ANarray);//count an AREA for each KVADRAT	

	json_write( jsonn_before, ANarray);// write ARRAY into .json file

	quickSort(ANarray, 0, ANarray->current_size - 1);// quick sort

//	chooseTheKindOfSort(ANarray);// simple sorts

	line_find(ANarray);// line find an AREA value in ARRAY

//	writeSquareArrayInConsole(ANarray);//write an ARRAY of KVADRATS in console
	json_write( jsonn_after, ANarray);// write ARRAY into .json file

//	destroySquareArray(ANarray);
		
}


