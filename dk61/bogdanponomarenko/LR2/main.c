#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "t.h"
#include <time.h>

int main()
{


	FILE *sorted_massiv  = fopen("result.txt", "w+");//create a .txt file, where we write an array after sorting

	float Time = 0; 

	int SizeOfArray;
	
	printf("what is the size of your array? (within 1 ... 10000) = ");
	
	scanf("%d",&SizeOfArray);
	 
	int *AnArray =	createArray(SizeOfArray);

	fillingArray(AnArray, SizeOfArray);

  	Sort(AnArray,SizeOfArray);

	WriteToFile(sorted_massiv, AnArray, SizeOfArray, Time);//after sort

fclose(sorted_massiv);
	




/*int b;
    	printf("\n\n What do you want to do?\n");
    	printf("\n 1 -- Fill massiv with numbers from file with unsorted numbers\n");
    	printf("\n 2 -- Fill massiv with random numbers\n");
    	printf("\n Enter number\n");
	int num = scan(1,2);
	
	if (num !=1 && num !=2 )
	{
		printf ("Enter correct number");
		return 0;
	}


		
	int n=5000;
	int i;
	int j;
	int a[5000];
     
	

    FILE *unsorted = fopen("unsorted.txt","rt+");
    for (i=0; i<n; i++)
        fscanf(unsorted, " %d ", &a[i]);
    fclose(unsorted);

    
	printf("\n\n A kind of sort  \n\n   1 -- bubble \n\t  2 -- selection \n\t3 -- insertion \n\n  = ");
	int num2 = scan(1,3);
	
	if (num2 !=1 && num2 !=2 && num2 !=3)
	{
		printf ("Enter correct number");
		return 0;
	}
	
	if(num2 == 1)
	{
		float start, end;
		start = clock();
		printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
  		bubbleSort(a[i], 5000);
  		end = clock();
  		float Time = ((end - start)/CLOCKS_PER_SEC);
  		return Time;
	}
	if(num2 == 2)
	{
		float start, end;
		start = clock();
		printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
	    selectionSort(a[i], 5000);
	    end = clock();
  		float Time = ((end - start)/CLOCKS_PER_SEC);
  		return Time;

	}
	if(num2 == 3)
	{
		float start, end;
		start = clock();
		printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
		insertionSort(a[i],5000);
		end = clock();
  		float Time = ((end - start)/CLOCKS_PER_SEC);
  		return Time;
	}
	
	
	
	
	
	/*for (i=0; i<n; i++)
    {
        for (j=0; j<n-i-1; j++)
        { if (a[j]<a[j+1])
            { int temp=a[j]; a[j]=a[j+1]; a[j+1]=temp;
            }
        }
    }

    FILE *result = fopen("result.txt","w+");
    for (i=0; i<n; i++)
		fprintf(result, " Number[%i] %d \n", i+1,a[i]);

printf("\n Sorting is completed. You can see sorted massiv in result.txt\n\n\n ");
    return 0;
  
  } 
    
*/

	



}


	
	

