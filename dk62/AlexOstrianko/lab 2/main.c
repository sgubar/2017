#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include "dk_tool.h"

int main(void){	
	int Lenth_of_Str;
	
	char *String = Transform_file_text_to_str (&Lenth_of_Str);
	printf("%i\n",Lenth_of_Str);
	selectionSort(Lenth_of_Str,String);
//	bubbleSort(Lenth_of_Str,String);
//	insertionSort(Lenth_of_Str,String);
	
	Vivod(Lenth_of_Str,String);	

	return 0;
}
