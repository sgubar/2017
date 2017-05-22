#include "dk_tool.h"

int main() 
{
	int *array, n, x, i;
	clock_t time;
	array = (int*)malloc(10*sizeof(int));
	readNum("array.txt", &array, &n);

	time = sortShell(array, n);
	printf("sortShell: time = %li tiks; %.2f seconds\n", time, (float)time / CLOCKS_PER_SEC);
	writeNum("sortShell.txt", array, n);
	
	printf("Element to find: ");
	scanf("%d", &x);
	time = find(array, n, x, &i);
	printf("Search: time = %li tiks; %.2f seconds\n", time, (float)time / CLOCKS_PER_SEC);
	if (i != -1)
		printf("Element %d has index %d\n", x, i);
	else
		printf("No element %d in array\n", x);
}
