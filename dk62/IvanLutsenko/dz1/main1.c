#include "dk_tool.h"

int main(int argc, char **argv) 
{
	int n, m, p;
	printf("Set matrix size (n m): ");
	scanf("%i %i", &n, &m);
	init(n, m);
	fill(n, m);
	printf("Base matrix:\n");
	show(n, m);
	printf("Set integer to produce: ");
	scanf("%i", &p);
	printf("Result matrix:\n");
	product(n, m, p);
	show(n, m);
	delete(n, m);
	return 0;
}
