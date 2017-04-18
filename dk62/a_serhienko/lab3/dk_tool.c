#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include <memory.h>
#include "sorting.h"
#define SSize 2001
#define MSize 5001
#define LSize 10001
#define MEGASize 25001

void PrintSortedArraytoFile(FILE *file, char *arrayforsorting)
{

	if (file == NULL) printf("error\n");
	//else printf("done\n");
	fputs(arrayforsorting, file);
	//printf("writing has been complete\n");

	// closing file
	fclose(file);
	//printf("file is closed\n");
}

void ReadingFromFile(FILE*file, char *arrayforsorting)
{


	// cheking if file is open
	if (file == NULL) { printf("error\n"); }
	//else printf("done\n");
	fgets(arrayforsorting, strlen(arrayforsorting), file);
	//Closing file
	//printf("\nClosing the file \n");
	if (fclose(file) == EOF) printf("error \n");
	//else printf("done\n");

}
void bubblesorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double *time)
{
	
	

	char BSsmall[SSize];
	char BSmedium[MSize];
	char BSlarge[LSize];
	char BSmega[MEGASize];

	strcpy_s(BSsmall, SSize, Sarray);
	strcpy_s(BSmedium, MSize, Marray);
	strcpy_s(BSlarge, LSize, Larray);
	strcpy_s(BSmega, MEGASize, MegAarray);

	clock_t start1 = clock();
	BubbleSort(BSsmall, SSize);
	clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	

	clock_t start2 = clock();
	BubbleSort(BSmedium, MSize);
	clock_t end2 = clock();
	double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

	clock_t start3 = clock();
	BubbleSort(BSlarge, LSize);
	clock_t end3 = clock();
	double time3 = (double)(end3 - start3) / CLOCKS_PER_SEC;

	clock_t start4 = clock();
	BubbleSort(BSmega, MEGASize);
	clock_t end4 = clock();
	double time4 = (double)(end4 - start4) / CLOCKS_PER_SEC;

	printf("Bubble sorting is done!\n");

	time[0] = time1;
	time[1] = time2;
	time[2] = time3;
	time[3] = time4;

	



}



void selectionsorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double*time)
{
	char SSsmall[SSize];
	char SSmedium[MSize];
	char SSlarge[LSize];
	char SSmega[MEGASize];

	strcpy_s(SSsmall, SSize, Sarray);
	strcpy_s(SSmedium, MSize, Marray);
	strcpy_s(SSlarge, LSize, Larray);
	strcpy_s(SSmega, MEGASize, MegAarray);

	clock_t start1 = clock();
	SelectionSort(SSsmall, SSize);
	clock_t end1 = clock();
	double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	

	clock_t start2 = clock();
	SelectionSort(SSmedium, MSize);
	clock_t end2 = clock();
	double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	

	clock_t start3 = clock();
	SelectionSort(SSlarge, LSize);
	clock_t end3 = clock();
	double time3 = (double)(end3 - start3) / CLOCKS_PER_SEC;


	clock_t start4 = clock();
	SelectionSort(SSmega, MEGASize);
	clock_t end4 = clock();
	double time4 = (double)(end4 - start4) / CLOCKS_PER_SEC;

	printf("Selection sorting is done!\n");

	time[0] = time1;
	time[1] = time2;
	time[2] = time3;
	time[3] = time4;

}
void insertionsorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double*time)
{
	char ISsmall[SSize];
	char ISmedium[MSize];
	char ISlarge[LSize];
	char ISmega[MEGASize];

	strcpy_s(ISsmall, SSize, Sarray);
	strcpy_s(ISmedium, MSize, Marray);
	strcpy_s(ISlarge, LSize, Larray);
	strcpy_s(ISmega, MEGASize, MegAarray);

	clock_t start1 = clock();
	InsertionSort(ISsmall, SSize);
	clock_t end1 = clock();
	double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;


	clock_t start2 = clock();
	InsertionSort(ISmedium, MSize);
	clock_t end2 = clock();
	double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

	clock_t start3 = clock();
	InsertionSort(ISlarge, LSize);
	clock_t end3 = clock();
	double time3 = (double)(end3 - start3) / CLOCKS_PER_SEC;

	clock_t start4 = clock();
	InsertionSort(ISmega, MEGASize);
	clock_t end4 = clock();
	double time4 = (double)(end4 - start4) / CLOCKS_PER_SEC;

	printf("Insertion sorting is done!\n");

	time[0] = time1;
	time[1] = time2;
	time[2] = time3;
	time[3] = time4;
}

void shellsorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double *time)
{


	clock_t start1 = clock();
	ShellSort(Sarray, SSize);
	clock_t end1 = clock();
	double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;


	clock_t start2 = clock();
	ShellSort(Marray, MSize);
	clock_t end2 = clock();
	double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

	clock_t start3 = clock();
	ShellSort(Larray, LSize);
	clock_t end3 = clock();
	double time3 = (double)(end3 - start3) / CLOCKS_PER_SEC;

	clock_t start4 = clock();
	ShellSort(MegAarray, MEGASize);
	clock_t end4 = clock();
	double time4 = (double)(end4 - start4) / CLOCKS_PER_SEC;

	
	printf("Shellsorting is done!\n");



	time[0] = time1;
	time[1] = time2;
	time[2] = time3;
	time[3] = time4;
}

void readarraysfromfile(char*Sarray, char*Marray, char*Larray, char*MegAarray)
{
	FILE * file2000;
	fopen_s(&file2000, "2000.txt", "r");
	FILE * file5000;
	fopen_s(&file5000, "5000.txt", "r");
	FILE * file10000;
	fopen_s(&file10000, "10000.txt", "r");
	FILE * file25000;
	fopen_s(&file25000, "25000.txt", "r");

	ReadingFromFile(file2000, Sarray);
	ReadingFromFile(file5000, Marray);
	ReadingFromFile(file10000, Larray);
	ReadingFromFile(file25000, MegAarray);

}

void writearraystofile(char*Sarray, char*Marray, char*Larray, char*MegAarray)
{
	FILE * sfile2000;
	fopen_s(&sfile2000, "S2000.txt", "w");
	FILE * sfile5000;
	fopen_s(&sfile5000, "S5000.txt", "w");
	FILE * sfile10000;
	fopen_s(&sfile10000, "S10000.txt", "w");
	FILE * sfile25000;
	fopen_s(&sfile25000, "S25000.txt", "w");


	PrintSortedArraytoFile(sfile2000, Sarray);
	PrintSortedArraytoFile(sfile5000, Marray);
	PrintSortedArraytoFile(sfile10000, Larray);
	PrintSortedArraytoFile(sfile25000, MegAarray);

}

void printtable(double *bubbletime, double *insertiontime, double *selectiontime, double *shelltime)
{
	printf("\n\n");
	printf("___________________________TIME OF SORTING_________________________\n\n");
	printf("# Arrays # BubbleSort # InsertionSort # SelectionSort # ShellSort #\n");
	printf("###################################################################\n");
	printf("#        #            #               #               #           #\n");
	printf("# small  #  %.3lfs    #   %.3lfs      #    %.3lfs     #   %.3lfs  #\n", bubbletime[0], insertiontime[0], selectiontime[0], shelltime[0]);
	printf("#________#____________#_______________#_______________#___________#\n");
	printf("#        #            #               #               #           #\n");
	printf("# medium #  %.3lfs    #   %.3lfs      #    %.3lfs     #   %.3lfs  #\n", bubbletime[1], insertiontime[1], selectiontime[1], shelltime[1]);
	printf("#________#____________#_______________#_______________#___________#\n");
	printf("#        #            #               #               #           #\n");
	printf("# large  #  %.3lfs    #   %.3lfs      #    %.3lfs     #   %.3lfs  #\n", bubbletime[2], insertiontime[2], selectiontime[2], shelltime[2]);
	printf("#________#____________#_______________#_______________#___________#\n");
	printf("#        #            #               #               #           #\n");
	printf("# mega   #  %.3lfs    #   %.3lfs      #    %.3lfs     #   %.3lfs  #\n", bubbletime[3], insertiontime[3], selectiontime[3], shelltime[3]);
	printf("#________#____________#_______________#_______________#___________#\n");
	printf("#        #            #               #               #           #\n");
	printf("###################################################################\n");

	printf("P.S Arrays have that amount of symbols:\n\n");
		printf("small - 2000\n");
		printf("medium - 5000\n");
		printf("large - 10000\n");
		printf("mega - 25000\n");

		




}

void additionalsearching(char*array)
{
	fflush(stdin);
	char key[100];
	printf("print what do you want to find\n");

	gets(key);
	//gets(key);
	
	int j = 0;
	int k = 0;
	int i = 0;
	for (i = 0; i<strlen(array); i++)
	{
		for (j = i, k = 0; key[k] != '\0' && array[j] == key[k]; j++, k++);// check if our second array also has something; and if their symbols are matched, do iteration;
																				  
		if (k > 0 && key[k] == '\0')// checking if we get the end of "key"
			printf("the entry point is %d\n", i);
		
	}
	printf("nothing has been found\n");

	

	
	}
	


int linear_search(char*Sarray, char*Marray, char*Larray, char*MegAarray)
{
	char small[SSize];
	char medium[MSize];
	char large[LSize];
	char mega[MEGASize];

	strcpy_s(small, SSize, Sarray);
	strcpy_s(medium, MSize, Marray);
	strcpy_s(large, LSize, Larray);
	strcpy_s(mega, MEGASize, MegAarray);


	char choosing;
	printf("do you want to use linear search? type (Y)-for accepting, (N)-for declining\n");
	scanf_s("%c", &choosing);
	while (!strchr("nNyY", choosing)) {
		printf("Please enter either 'Y' or 'N': ");
		scanf_s(" %c", &choosing);

	}

	if (choosing == 'Y' || choosing == 'y') {
		
		
		int switcher;
		int theResult = 0;
		fflush(stdin);

	

		printf("choose the array\n");
		printf("1 - small\n");
		printf("2 - medium\n");
		printf("3 - large\n");
		printf("4 - mega\n");

		scanf_s("%d", &switcher);

		switch (switcher)
		{

		case 1:
			additionalsearching(small);
			break;


		case 2:
			additionalsearching(medium);
			break;



		case 3:
			additionalsearching(large);
			break;



		case 4:
			additionalsearching(mega);
			break;





		default:
			return -1;

		}
		return 0;
	}

	else
		return -1;

	return 0;
}






