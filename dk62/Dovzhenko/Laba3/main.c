#include "laba3.h"

int main()
{
	char find;
	
	FILE *file = fopen("file.txt", "r");
	if(file == NULL)
	{
		printf("Sorry, but file not found.\n");
		return 1;
	}
	FILE *ffile = fopen("data.txt", "w");
	if(ffile == NULL)
	{
		printf("Sorry, but file not created/found.\n");
		fclose(file);
		return 1;
	}
	
	int check = LookFile(file);
	if(check == 0)
	{
		printf("Empty file.\n");
		fclose(ffile);
		fclose(file);
		return 1;
	}
	else
	{
		printf("Symbols: %i\n", check);
		check++;
	}
	
	char *line = (char *) calloc(check, sizeof(char));
	if(line == 0)
	{
		printf("Error!\n");
		fclose(ffile);
		fclose(file);
		return 1;
	}
	ReadFile(file, line);
	fclose(file);
	
	printf("String of the file:\n%s\n", line);
	
	int counter = strlen(line) - 1, f;
	float time;
	
	time = clock();
	quicksort(line, 0, counter);
	time = clock() - time;
	printf("Time of Quicksort: %.4f\n\n", time / CLOCKS_PER_SEC);
	fprintf(ffile, "Time of Quicksort: %.4f\n", time / CLOCKS_PER_SEC);
	
	printf("Sorted string:\n");
	for(f = 0; f <= counter; f++)
	{
		if(line[f] != 32)					
		printf("%c", line[f]);
	}
	printf("\n\nPlease, enter the symbol what you want to find: ");
	scanf("%c", &find);
	
	time = clock();
	int finding = BinarySearch(line, find);
	time = clock() - time;
	
	printf("Time of search: %.4f\n", time / CLOCKS_PER_SEC);
	fprintf(ffile, "Time of search: %.4f\n", time / CLOCKS_PER_SEC);
	
	if(finding == -1)
		printf("This element is not found.\n");
	else
		printf("Found in the %i position.\n", finding );
	
	fflush(ffile);
	fclose(ffile);
	free(line);
	return 0;
}
