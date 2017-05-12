#include "laba3.h"

void swap(char *line, int LeftElem, int RightElem)
{
	int tmp = line[LeftElem];
	line[LeftElem] = line[RightElem];
	line[RightElem] = tmp;
}

int BinarySearch(char *line, char find)
{
	int middle, Left = 0;
	int Right = strlen(line) - 1;
	
	while(Left <= Right)
	{
		middle = (Left + Right) / 2;
		
		if(line[middle] == find)
		{
			return middle;
		}
		else if(line[middle] > find)
		{
			Right = middle - 1;
		}
		else
		{
			Left = middle + 1;
		}
	}
	return -1;
}

void quicksort(char *line, int LeftElem, int RightElem)
{
	int i = LeftElem, j = RightElem, counter = line[(LeftElem + RightElem) / 2];
	do{
		while(line[i] < counter)
			i++;
    	while(line[j] > counter)
			j--;
		
		if(i <= j)
		{
			if(line[i] > line[j])
				swap(line, i, j);
			
			i++;
			j--;
		}
	}while(i <= j);

	if(i < RightElem)
		quicksort(line, i, RightElem);
	if(LeftElem < j)
		quicksort(line, LeftElem, j);
}

void ReadFile(FILE *afile, char *line)
{
	int i = 0, c;
	while(c != EOF)			//end of file
	{
		c = fgetc(afile);	//take value of element 
		if(c =='\n')
			c = ' ';
		line[i] = c;
		i++;
	}
}

int LookFile(FILE *afile)
{
	int i = 0, c;
	while(c != EOF)
	{
		c = getc(afile);
		i++;
	}
	rewind (afile);
	return i;
}
