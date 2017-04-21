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



void greetings() 
{
	printf("Hello! This program is sorting  symbols by different sortings, from files,and comparing sorting time.\n");
	printf("If you want you can find some symbols using linear search.\n");
	printf("Good luck! :)\n\n");

}

void PrintSortedArraytoFile(FILE *file, char *arrayforsorting,int size)
{

	if (file == NULL) printf("error\n");
	//else printf("done\n");
	fwrite(arrayforsorting, sizeof(char), size, file);
	//printf("writing has been complete\n");

	// closing file
	fclose(file);
	//printf("file is closed\n");
}

void ReadingFromFile(FILE*file, char *arrayforsorting,int size)
{


	// cheking if file is open
	if (file == NULL) { printf("error\n"); }
	//else printf("done\n");
	//fgets(arrayforsorting,size, file);
	memset(arrayforsorting, 0, size);
	fread(arrayforsorting, sizeof(char), size, file);
	//Closing file
	//printf("\nClosing the file \n");
	if (fclose(file) == EOF) printf("error \n");
	//else printf("done\n");

}

void bubblesorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double *time)
{
	printf("\nSTARTING THE SORTING..\n\n");
	

	char BSsmall[SSize];
	char BSmedium[MSize];
	char BSlarge[LSize];
	char BSmega[MEGASize];

	memcpy(BSsmall,Sarray, SSize);
	memcpy(BSmedium, Marray, MSize);
	memcpy(BSlarge, Larray, LSize);
	memcpy(BSmega, MegAarray, MEGASize);
	

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

	memcpy(SSsmall, Sarray, SSize);
	memcpy(SSmedium, Marray, MSize);
	memcpy(SSlarge, Larray, LSize);
	memcpy(SSmega, MegAarray, MEGASize);

	

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

	memcpy(ISsmall, Sarray, SSize);
	memcpy(ISmedium, Marray, MSize);
	memcpy(ISlarge, Larray, LSize);
	memcpy(ISmega, MegAarray, MEGASize);

	
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


void quicksorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double *time)
{
	char QSsmall[SSize];
	char QSmedium[MSize];
	char QSlarge[LSize];
	char QSmega[MEGASize];

	memcpy(QSsmall, Sarray, SSize);
	memcpy(QSmedium, Marray, MSize);
	memcpy(QSlarge, Larray, LSize);
	memcpy(QSmega, MegAarray, MEGASize);


	clock_t start1 = clock();
	quickSort(QSsmall,0, SSize-1);
	clock_t end1 = clock();
	double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;


	clock_t start2 = clock();
	quickSort(QSmedium, 0, MSize-1);
	clock_t end2 = clock();
	double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

	clock_t start3 = clock();
	quickSort(QSlarge, 0, LSize-1);
	clock_t end3 = clock();
	double time3 = (double)(end3 - start3) / CLOCKS_PER_SEC;

	clock_t start4 = clock();
	quickSort(QSmega, 0, MEGASize-1);
	clock_t end4 = clock();
	double time4 = (double)(end4 - start4) / CLOCKS_PER_SEC;

	printf("Quick sorting is done!\n");



	time[0] = time1;
	time[1] = time2;
	time[2] = time3;
	time[3] = time4;



}

void shellsorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double *time)
{

	//printArray(Sarray, SSize);
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

	
	printf("Shellsorting is done!\n\n");

	printf("SORTING HAS BEEN COMPLETED\n");


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

	ReadingFromFile(file2000, Sarray,SSize);
	ReadingFromFile(file5000, Marray,MSize);
	ReadingFromFile(file10000, Larray,LSize);
	ReadingFromFile(file25000, MegAarray,MEGASize);

}
writearraystofile(char*Sarray, char*Marray, char*Larray, char*MegAarray)
{
	FILE * sfile2000;
	fopen_s(&sfile2000, "S2000.txt", "w");
	FILE * sfile5000;
	fopen_s(&sfile5000, "S5000.txt", "w");
	FILE * sfile10000;
	fopen_s(&sfile10000, "S10000.txt", "w");
	FILE * sfile25000;
	fopen_s(&sfile25000, "S25000.txt", "w");


	PrintSortedArraytoFile(sfile2000, Sarray,SSize);
	PrintSortedArraytoFile(sfile5000, Marray,MSize);
	PrintSortedArraytoFile(sfile10000, Larray,LSize);
	PrintSortedArraytoFile(sfile25000, MegAarray,MEGASize);

}

void printtable(double *bubbletime, double *insertiontime, double *selectiontime, double *shelltime,double *quicktime)
{   
	printf("\n\n");
	printf("___________________________TIME OF SORTING______________________________________\n\n");
	printf("# Arrays # BubbleSort # InsertionSort # SelectionSort # ShellSort # QuickSort  #\n");
	printf("################################################################################\n");
	printf("#        #            #               #               #           #            #\n");
	printf("# small  #  %.3lfs    #    %.3lfs     #    %.3lfs     #   %.3lfs  #   %.3lfs   #\n", bubbletime[0], insertiontime[0], selectiontime[0], shelltime[0],quicktime[0]);
	printf("#________#____________#_______________#_______________#___________#____________#\n");
	printf("#        #            #               #               #           #            #\n");
	printf("# medium #  %.3lfs    #    %.3lfs     #    %.3lfs     #   %.3lfs  #   %.3lfs   #\n", bubbletime[1], insertiontime[1], selectiontime[1], shelltime[1],quicktime[1]);
	printf("#________#____________#_______________#_______________#___________#____________#\n");
	printf("#        #            #               #               #           #            #\n");
	printf("# large  #  %.3lfs    #    %.3lfs     #    %.3lfs     #   %.3lfs  #   %.3lfs   #\n", bubbletime[2], insertiontime[2], selectiontime[2], shelltime[2],quicktime[2]);
	printf("#________#____________#_______________#_______________#___________#____________#\n");
	printf("#        #            #               #               #           #            #\n");
	printf("# mega   #  %.3lfs    #    %.3lfs     #    %.3lfs     #   %.3lfs  #   %.3lfs   #\n", bubbletime[3], insertiontime[3], selectiontime[3], shelltime[3],quicktime[3]);
	printf("#________#____________#_______________#_______________#___________#____________#\n");
	printf("#        #            #               #               #           #            #\n");
	printf("################################################################################\n");

	printf("P.S Arrays have that amount of symbols:\n\n");
		printf("small - 2000\n");
		printf("medium - 5000\n");
		printf("large - 10000\n");
		printf("mega - 25000\n\n");

		




}

int additionalsearching(char*array)
{
	fflush(stdin);
	char key[500];
	
	printf("print what do you want to find\n");

	gets(key);
	gets(key);
	
	int j = 0;
	int k = 0;
	int i = 0;

	for (i = 0; i < strlen(array); i++)
	{
		for (j = i, k = 0; key[k] != '\0' && array[j] == key[k]; j++, k++);// check if our second array also has something; and if their symbols are matched, do iteration;

		if (k > 0 && key[k] == '\0'){// checking if we get the end of "key"
			printf("the entry point is: %d \n", i);
			     return i;
			}

			}
	return -1;

		}

		
 
int linear_search(char*Sarray, char*Marray, char*Larray, char*MegAarray)
{ 

	char choosing;
	printf("do you want to use linear search? type (Y)-for accepting, (N)-for declining\n");
	scanf_s("%c", &choosing);
	while (!strchr("nNyY", choosing)) {
		printf("Please enter either 'Y' or 'N': ");
		scanf_s(" %c", &choosing);

	}

	if (choosing == 'Y' || choosing == 'y') {
		
		
		char switcher;
		fflush(stdin);

	

		printf("choose the array\n");
		printf("1 - small\n");
		printf("2 - medium\n");
		printf("3 - large\n");
		printf("4 - mega\n");

		scanf_s(" %c", &switcher);

		while (!strchr("1234", switcher)) {
			printf("Please enter number from 1 to 4 \n");
			scanf_s(" %c", &switcher);
		}



		switch (switcher)
		{

		case '1':
			
			if (additionalsearching(Sarray) == -1)
				printf("Nothing has been found,sorry!\n");

			break;


		case '2':
			
			if (additionalsearching(Marray) == -1)
				printf("Nothing has been found,sorry!\n");
			break;



		case '3':
			
			if (additionalsearching(Larray) == -1)
				printf("Nothing has been found,sorry!\n");
			break;



		case '4':
			
			if (additionalsearching(MegAarray) == -1)
				printf("Nothing has been found,sorry!\n");
			break;





		//default:
			//printf("slomali progu?\n\n");
			
		}
		return 0;
	}

	else
		return -1;

	return 0;
}




void goodbye() 
{
	printf("Thank you for using this programm, have a nice day!\n");
}

