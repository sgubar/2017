#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tool.h"

void BubbleSort(char str[], int counter)
{
  int k;
  for(k=0; k < counter - 1; k++)
  {
    int i;

    for(i=0; i < counter - 1 - k; i++)
    {
        if(str[i] > str[i+1])
        {
          int temp = str[i+1];
          str[i+1] = str[i];
          str[i] = temp;
        }
      }
  }
}

void SelectionSort(char str[], int counter)
{
	int i;
    for(i = 0; i < counter; i++)
    {
        int min = i;
        int j;
        for(j = i; j < counter; j++)
        {
            if(str[j] < str[min])
            {
                min = j;
            }
        }
        int temp = str[i];
        str[i] = str[min];
        str[min] = temp;
    }
}

void InsertionSort(char str[], int counter)
{

  int i;
  for (i=1; i < counter; i++)
  {
    int value = str[i]; 
    int index = i;     
    while ((index > 0) && (str[index - 1] > value))
    {  
      str[index] = str[index - 1];
      index--;   
    }
    str[index] = value; 
  }
}
