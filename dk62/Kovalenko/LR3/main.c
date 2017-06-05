#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dk_tool.h"


int main(int argc, const char * argv[])
{
    int LengthOfStr=dlinnateksta("File.txt");

    char *Str1=FileToStr();
    if(NULL!=Str1)
    {
        clock_t start1=clock();
        bubbleSort(Str1, LengthOfStr);
        clock_t end1=clock();
        printf("vremya sortirovki:%f\n", (float)(end1-start1)/CLOCKS_PER_SEC);
    }
    free(Str1);

    char *Str2=FileToStr();
    if(NULL!=Str2)
    {
        clock_t start2=clock();
        selectionSort(Str2, LengthOfStr);
        clock_t end2=clock();
        printf("vremya sortirovki:%f\n", (float)(end2-start2)/CLOCKS_PER_SEC);
    }
    free(Str2);

    char *Str3=FileToStr();
    if(NULL!=Str3)
    {
        clock_t start3=clock();
        insertionSort(Str3, LengthOfStr);
        clock_t end3=clock();
        printf("vremya sortirovki:%f\n", (float)(end3-start3)/CLOCKS_PER_SEC);
    }
    free(Str3);
	
	char *Str4=FileToStr();
	if(NULL!=Str4)
	{
		clock_t start4=clock();
		shellSort(Str4, LengthOfStr);
		clock_t end4=clock();
		printf("vremya sortirovki:%f\n",(float)(end4-start4)/CLOCKS_PER_SEC);
	}
	PrintToFile(Str4);
    char search;
    printf("vvedi simvol kotoruy nada nayti:");
    scanf("%c", &search);
    int result = binarySearch(Str4, LengthOfStr, search);
    printf("poziciya simvola:%d", result); 
    free(Str4);	
    return 0;
}
