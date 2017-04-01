#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.h"
#include <memory.h>
#include "sorting.h"



pyramidList *createPyramidList(int size)
{
	pyramidList *aPyramidList = (pyramidList *)malloc(sizeof(pyramidList));//allocating memory for pyramids

	if (aPyramidList != NULL)
	{
		aPyramidList->arrayofPyramids = (pyramid *)malloc(size * sizeof(pyramid));
		aPyramidList->current_size = 0;
		aPyramidList->size = size;
	
		
	}
	return aPyramidList;
}

void destroyAllPyramid(pyramidList *aPyramidList)//deleting pyramids:(
{
	if (aPyramidList != NULL)
	{
		if (aPyramidList->arrayofPyramids != NULL)
			free(aPyramidList->arrayofPyramids);
		

		free(aPyramidList);
	}
	printf("All pyramids have been deleted");
}



/*void swap(pyramid *var1, pyramid *var2)
{
	pyramid temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}*/


int addPyramid(pyramidList *aPyramidList)
{
	if (NULL != aPyramidList)
	{
		if (aPyramidList->current_size < aPyramidList->size)//checking if we have free space for pyramid
		{
			
			pyramid *thePyramid = &(aPyramidList->arrayofPyramids[aPyramidList->current_size]);
			if (NULL != thePyramid)
			{
				thePyramid->points = (point *)malloc(sizeof(point) * 4);
				

				for (int i = 0; i < 4; i++)//inputing our points
				{
					printf("Type x, y, z for point# %i\n", i + 1);
					thePyramid->points[i].x = num_scanf();
					thePyramid->points[i].y = num_scanf();
					thePyramid->points[i].z = num_scanf();

				}
				
				
				
				aPyramidList->current_size++;// moving to the next position,because previous had been filled 


			}
			else
			{
				printf("\tError! PyramidList is already full.\n");
				return -2;
			}
		}
		else
		{
			return -1;
		}
		printf("The Pyramid has been successfully created!\n\n");
		return 0;
	}
}

		int printPyramidList(pyramidList *aPyramidList)
		{


			for (int i = 0; i < aPyramidList->current_size; i++)
			{
				pyramid *thePyramid = &(aPyramidList->arrayofPyramids[i]);

				printf("Pyramid #%d\n", i + 1);
				printPyramid(thePyramid);//calling function for print a pyramid
				printf("the square of that pyramid is %d\n\n", abs(square(thePyramid)));//printing the square of pyramid

			}
		
		}

		void writePyramid(FILE *aFile, pyramid*thePyramid) 
		{
		


			for (int i = 0; i < 3; i++) {
				fprintf(aFile, " \"point[%d]\"={%d,%d,%d},\n", i + 1, thePyramid->points[i].x, thePyramid->points[i].y, thePyramid->points[i].z);
				if (i == 2)
					fprintf(aFile, " \"point[%d]\"={%d,%d,%d}\n", i + 1, thePyramid->points[i+1].x, thePyramid->points[i+1].y, thePyramid->points[i+1].z);

			}
			
		}

		void writePyramidList(FILE *aFile, pyramidList *aPyramidList) 
		{
			fprintf(aFile, "{\n");
			fprintf(aFile, "  \"size\":%d;\n", aPyramidList->size);
			fprintf(aFile, "  \"current_size\":%d;\n\n", aPyramidList->current_size);
			fprintf(aFile, "\"Pyramids\":[\n");

			
			for (int i = 0; i < aPyramidList->current_size; i++)
			{
				pyramid *thePyramid = &(aPyramidList->arrayofPyramids[i]);
				
					fprintf(aFile, " \"Pyramid #%d\" :\n\n", i + 1);
					fprintf(aFile, "{\n");
					writePyramid(aFile, thePyramid);
					if (i < aPyramidList->current_size-1) {
						fprintf(aFile, "},\n\n");
					}
					else 
						if(i<=aPyramidList->current_size-1)
						fprintf(aFile, "}\n\n");
				
				

				
			}
			fprintf(aFile, "]\n");
			fprintf(aFile, "}\n");
		}

		

		int printPyramid(pyramid*thePyramid)
		{
			
			if (NULL == thePyramid)	
				printf("null");
			else				
			{

				
				for (int i = 0; i < 4; i++) {//printing all points of pyramid
					
					printf("point[%d]={%d, %d, %d}\n",i+1, thePyramid->points[i].x, thePyramid->points[i].y, thePyramid->points[i].z);
					
				}
			
			}
			return 0;
		}

		int square(pyramid*thePyramid)
		{
			
			double PA = 0;
			double PB = 0;
			double PC = 0;
			double AB = 0;
			double AC = 0;
			double BC = 0;
			//vectors
			

			double x, y, z, P, S1,S2,S3,S4,square;//points,half-perimeter,S1..S4 - squares of each of triangles, square - that we're needed to find
			square = 0;

			//calculating the length of vectors

			x = 0; y = 0; z = 0;
			x = (thePyramid->points[0].x) - (thePyramid->points[3].x);
			y = (thePyramid->points[0].y) - (thePyramid->points[3].y);
			z = (thePyramid->points[0].z) - (thePyramid->points[3].z);
			PA = sqrt((x*x) + (y*y) + (z*z));
			

			x = 0; y = 0; z = 0;

			x = (thePyramid->points[1].x) - (thePyramid->points[3].x);
			y = (thePyramid->points[1].y) - (thePyramid->points[3].y);
			z = (thePyramid->points[1].z) - (thePyramid->points[3].z);
			PB = sqrt((x*x) + (y*y) + (z*z));
			
			x = 0; y = 0; z = 0;
			x = (thePyramid->points[2].x) - (thePyramid->points[3].x);
			y = (thePyramid->points[2].y) - (thePyramid->points[3].y);
			z = (thePyramid->points[2].z) - (thePyramid->points[3].z);
			PC = sqrt((x*x) + (y*y) + (z*z));

			x = 0; y = 0; z = 0;
			x = (thePyramid->points[1].x) - (thePyramid->points[0].x);
			y = (thePyramid->points[1].y) - (thePyramid->points[0].y);
			z = (thePyramid->points[1].z) - (thePyramid->points[0].z);
			AB=sqrt((x*x) + (y*y) + (z*z));
			
			x = 0; y = 0; z = 0;
			x = (thePyramid->points[2].x) - (thePyramid->points[0].x);
			y = (thePyramid->points[2].y) - (thePyramid->points[0].y);
			z = (thePyramid->points[2].z) - (thePyramid->points[0].z);
			AC= sqrt((x*x) + (y*y) + (z*z));

			x = 0; y = 0; z = 0;
			x = (thePyramid->points[2].x) - (thePyramid->points[1].x);
			y = (thePyramid->points[2].y) - (thePyramid->points[1].y);
			z = (thePyramid->points[2].z) - (thePyramid->points[1].z);
			BC = sqrt((x*x) + (y*y) + (z*z));

			

			P = 0;
			P = (AB + AC + BC) / 2;//half-perimeter;
			S1 = sqrt(P*((P - AB)*(P - AC)*(P - BC)));//using Geron's formula
			
			P = 0;
			P = (PA + PB + AB) / 2;
			S2= sqrt(P*((P - PA)*(P - PB)*(P - AB)));

			P = 0;
			P = (PC + PA + AC) / 2;
			S3= sqrt(P*((P - PC)*(P - PA)*(P - AC)));

			P = 0;
			P = (PC + PB + BC) / 2;
			S4= sqrt(P*((P - PC)*(P - PB)*(P - BC)));

			square = S1 + S2 + S3 + S4;//adding all squares to one big square


				return square;
		

		
			
			
		}



		int num_scanf(void)//checking if our input is a num 
		{
			int num = 0, proof = 0;
			do
			{
				proof = scanf_s("%d", &num);
				if (proof == 1) break;
				printf("Incorrect input, try again");
				fflush(stdin);
			} while (1);
			return num;
		}
	
