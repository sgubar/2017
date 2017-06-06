#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tool.h"

void ShellSort(int n, char str[])
{
    int tmp, j;
	int step;
	int i;
    for (step = n / 2; step > 0; step /= 2)
    {
        for (i = step; i < n; i++)
        {
            tmp = str[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < str[j - step])       //change here to sort from max to min
                    str[j] = str[j - step];
                else
                break;
            }
            str[j] = tmp;
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%c ", str[i]);
    }
    printf("\n");
}


int BinarySearch(char str[], char searched_element, int counter)
{
    int first_element_index = 0;
    int last_element_index = counter - 1;
    int middle_element_index = (last_element_index + first_element_index) / 2;

    while(first_element_index <= last_element_index)
    {
        if(str[middle_element_index] < searched_element)
        {
            first_element_index = middle_element_index + 1;
        }
        else if(str[middle_element_index] == searched_element)
        {
            return middle_element_index;
        }
        else
        {
            last_element_index = middle_element_index - 1;
        }

        middle_element_index = (last_element_index + first_element_index) / 2;
    }

    return -1;
}
