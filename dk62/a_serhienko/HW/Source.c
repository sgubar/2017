#include <stdio.h>
#include "dk_tool.h"
#include <conio.h>

int main()
{ //initiliazation our arrays and variables;
	char string[101];
	char search[100];
	int res = 0;
	//initiliazation pointers for arrays;
	char *str1;	
	char *str2;
	//asking user for printing strings;
	printf("print your string(not bigger than 100 symbols)\n");
	str1=gets(string,100,stdin);//used "gets" instead "scanf" because "gets" can get strings with spaces f.e.:"DK KPI";
	printf("print what do you want to find in that string(not bigger than 99 symbols)\n");
	str2=gets(search,99,stdin);
	
	




	res=strings(str1, str2);//calling our func and sending the arrays;
	printf("if entry point is -1, it means that the program doesn't find something\n");
	printf("the entry point is: %d\n", res);//display our result


	_getch();//freezing the program for catching results



}