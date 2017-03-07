#include "perestanovka.h"

void perestanovka(int massiv[], int size)
{
	int t = 0;//counter for loop
	int f = size-1;
	
	int buffer = 0;
	
	
	for( ; t!=f; t++, f--)
	{
		buffer = massiv[t];
		massiv [t] = massiv [f];
		massiv [f] = buffer;
		
	}
	
	
}
