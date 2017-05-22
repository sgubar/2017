#include "dk_tool.h"

int main() 
{
	int *array, n;
	clock_t time;
	array = (int*)malloc(10*sizeof(int));
	readNum("array.txt",&array,&n);

	time = sortBubble(&array, n);
	printf("sortBubble: time = %li tiks; %.2f seconds\n",time, (float)time / CLOCKS_PER_SEC);
	writeNum("sortBubble.txt",array,n);
	readNum("array.txt",&array,&n);

	time = sortInsert(&array, n);
	printf("sortInsert: time = %li tiks; %.2f seconds\n",time, (float)time / CLOCKS_PER_SEC);
	writeNum("sortInsert.txt",array,n);
	readNum("array.txt",&array,&n);

	time = sortSelect(&array, n);
	printf("sortSelect: time = %li tiks; %.2f seconds\n",time, (float)time / CLOCKS_PER_SEC);
	writeNum("sortSelect.txt",array,n);
}
