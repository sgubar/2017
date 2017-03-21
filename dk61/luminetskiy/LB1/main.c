#include <stdio.h>

#include "dk_tool.h"
int main(void)
{

	
	int NumberIn16 = HEXtoDEC();
 int FirstDECnum = DECnumbers();
 int SecondDECnum =  DECnumbers();
int result = sum( NumberIn16, FirstDECnum,  SecondDECnum);


printf("result %d: ", result);



}

