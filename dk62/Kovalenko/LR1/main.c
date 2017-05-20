#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
int main (char *argv[],int argc)
	{
		int A;
		int B;
		int C;
		printf("vvedi A:\n");
		scanf("%d",&A);
		printf("vvedi B:\n");
		scanf("%d",&B);
		printf("vvedi C:\n");
		scanf("%d",&C);
		peremennaya(A,B,C);
		return 0;
	}
