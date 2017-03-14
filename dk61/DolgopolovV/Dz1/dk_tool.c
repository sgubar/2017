#include <stdio.h> 

void reading(int size, int mas[size]){
	int i = 0;
	for (i = 0; i < size; i++) 
	{ 
	printf("Vvedite %i nomer massiva: ", i + 1); 
	scanf("%i", &mas[i]); 
	} 
}

void swap(int size, int mas[size], int obmen){
	int j = 0;
	for (j = 0; j < size / 2; j++) 
	{ 
	obmen = mas[j]; 
	mas[j] = mas[size - j - 1]; 
	mas[size - j - 1] = obmen; 
	} 
}

void print_m(int size, int mas[size]){
	int i = 0;
	for ( i = 0; i < size; i++) 
	{ 
	printf("%i ", mas[i]); 
	}
}

