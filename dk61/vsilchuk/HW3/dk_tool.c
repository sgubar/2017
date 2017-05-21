#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include "dk_tool.h"

int NumInput()
{
	int Num;
	int Proof;							
	while(1)
	{						
		Proof = scanf("%d", &Num);
		if ( Proof == 1)		 		
			{
				break;
			}
		printf("Please enter another number:\n");
		fflush (stdin); 				
	}
	return Num;
}

pyramidsList *createPyramidsList(int aSize)									
{	
	pyramidsList *aPyramidsList = (pyramidsList *) malloc(sizeof(pyramidsList));	
	
	if (aPyramidsList != NULL)
	{
		aPyramidsList -> pyramids = (pyramid *) malloc(aSize * sizeof(pyramid));		
			
		memset(aPyramidsList -> pyramids, 0, aSize * sizeof(pyramid));				
				
		aPyramidsList -> maxSize = aSize;											
		aPyramidsList -> pyramidsCounter = 0;										
			
		printf("\naPyramidsList was successfully created!\n");
	}

	return aPyramidsList;
}

void destroyAPyramidsList(pyramidsList *aPyramidsList)
{
	if (NULL != aPyramidsList)
	{
		if(NULL != aPyramidsList -> pyramids)
		{		
			free(aPyramidsList->pyramids);
		}
		
		free(aPyramidsList);
	}
}


int addPyramid (pyramidsList *aPyramidsList )
{
	if (NULL != aPyramidsList )
	{
		if (aPyramidsList->pyramidsCounter < aPyramidsList -> maxSize)
		{
			pyramid *aPyramid = &(aPyramidsList -> pyramids[aPyramidsList -> pyramidsCounter]);		
				
			if (NULL != aPyramid)
			{
				aPyramid -> vertices = (vertex *) malloc(sizeof(vertex) * 4);
				
				int i; 
				for (i = 0; i < 4; i++ )
				{
					printf("\nType x, y, z for vertex #%i\n", i+1);
					
					aPyramid -> vertices[i].x = NumInput();
					aPyramid -> vertices[i].y = NumInput();
					aPyramid -> vertices[i].z = NumInput();		
				}
				
				aPyramidsList -> pyramidsCounter ++;				
			}
		}
		
		else
		{
			return -2;
		}
	}
	
	else 
	{
		return -1;
	}
	
	printf("\nYour Pyramid was successfully created!\n\n");
	return 0; 
}


void printPyramidsList(pyramidsList *aPyramidsList)
{
	if (NULL != aPyramidsList)
	{	
		printf("{");
		printf("\n");
		printf("[\n");
		int i;
		for(i = 0; i < aPyramidsList->pyramidsCounter; i++)
		{
			pyramid *aPyramid = &(aPyramidsList -> pyramids[i]);
			
			printPyramid(aPyramid);										
			
			if (i < aPyramidsList -> pyramidsCounter - 1) 		
			{
				printf(",\n");
			}
			
		}
		printf("\n]");
		printf("\n");
		printf("}");
	}
}


int printPyramid(pyramid *aPyramid)
{
	if (NULL == aPyramid)	
	{
		printf("null");
	}
		
	else					
	{
		int i; 
		for (i = 0; i < 4; i++)
		{
			printf ("\n\t\t{");
			printf ("\n\t\t\"Vertex #%i\"", i+1);
			printf ("\n\t\t\"x\": %d", aPyramid -> vertices[i].x);
			printf (",\n\t\t\"y\": %d", aPyramid -> vertices[i].y);
			printf (",\n\t\t\"z\": %d", aPyramid -> vertices[i].z);
			printf ("\n\t\t}\n\n");
		}
	}
	return 0;	
}

void printSquare(pyramidsList *aPyramidsList) 
{
    int i;
    for (i = 0; i < aPyramidsList -> pyramidsCounter; i++)
    {
        pyramid *aPyramid = &(aPyramidsList -> pyramids[i]);

        printf("\n\nThe area of the pyramid #%d = %.4f", i+1, pyramidSquare(aPyramid));
    }
}


float pyramidSquare(pyramid *aPyramid)
{
	float PA, PB, PC, AB, AC, BC;
	float halfPerimeter;
	float PABsquare, PBCsquare, PACsquare, ABCsquare; 
	float pyramidSquare;
	
	PA = sqrt(	pow(aPyramid -> vertices[0].x - aPyramid -> vertices[1].x , 2) + 
	
		        pow(aPyramid -> vertices[0].y - aPyramid -> vertices[1].y , 2) + 
				    
			 pow(aPyramid -> vertices[0].z - aPyramid -> vertices[1].z , 2)	);
		 		
	PB = sqrt(	pow(aPyramid -> vertices[0].x - aPyramid -> vertices[2].x , 2) + 
	
		        pow(aPyramid -> vertices[0].y - aPyramid -> vertices[2].y , 2) + 
				    
			 pow(aPyramid -> vertices[0].z - aPyramid -> vertices[2].z , 2)	);
				 
	PC = sqrt(	pow(aPyramid -> vertices[0].x - aPyramid -> vertices[3].x , 2) + 
	
		      	pow(aPyramid -> vertices[0].y - aPyramid -> vertices[3].y , 2) + 
				    
			 pow(aPyramid -> vertices[0].z - aPyramid -> vertices[3].z , 2)	);			 	 		
					
	AB = sqrt(	pow(aPyramid -> vertices[1].x - aPyramid -> vertices[2].x , 2) + 
	
		      	pow(aPyramid -> vertices[1].y - aPyramid -> vertices[2].y , 2) + 
				    
		 	pow(aPyramid -> vertices[1].z - aPyramid -> vertices[2].z , 2)	);
		 		
	AC = sqrt(	pow(aPyramid -> vertices[1].x - aPyramid -> vertices[3].x , 2) + 
	
		      	pow(aPyramid -> vertices[1].y - aPyramid -> vertices[3].y , 2) + 
				    
		 	pow(aPyramid -> vertices[1].z - aPyramid -> vertices[3].z , 2)	);	 
				 
	BC = sqrt(	pow(aPyramid -> vertices[2].x - aPyramid -> vertices[3].x , 2) + 
	
		      	pow(aPyramid -> vertices[2].y - aPyramid -> vertices[3].y , 2) + 
				    
		 	pow(aPyramid -> vertices[2].z - aPyramid -> vertices[3].z , 2)	);	
				 
	halfPerimeter = (PA + PB + AB) / 2;
	PABsquare = sqrt( halfPerimeter * ((halfPerimeter - PA)*(halfPerimeter - PB)*(halfPerimeter - AB)) );
	
	halfPerimeter = (PB + PC + BC) / 2;	
	PBCsquare = sqrt( halfPerimeter * ((halfPerimeter - PB)*(halfPerimeter - PC)*(halfPerimeter - BC)) );
			 		 		
	halfPerimeter = (PA + PC + AC) / 2;
	PACsquare = sqrt( halfPerimeter * ((halfPerimeter - PA)*(halfPerimeter - PC)*(halfPerimeter - AC)) );
	
	halfPerimeter = (AC + AB + BC) / 2;
	ABCsquare = sqrt( halfPerimeter * ((halfPerimeter - AC)*(halfPerimeter - AB)*(halfPerimeter - BC)) );
	
	pyramidSquare = PABsquare + PBCsquare + PACsquare + ABCsquare;
	
	return pyramidSquare;
}

void FilePrintPyramidsList(pyramidsList *aPyramidsList)
{
	FILE * ptrFile = fopen("aPyramidsList.json", "w");
	if (ptrFile != NULL)
  	{
    	if(NULL != aPyramidsList)
		{
			int i;
			fprintf (ptrFile,"{");
			fprintf (ptrFile,"\n");
			fprintf (ptrFile,"[\n");
			for(i = 0; i < aPyramidsList->pyramidsCounter; i++)
			{
				pyramid *aPyramid = &(aPyramidsList -> pyramids[i]);
				
				FilePrintPyramid(aPyramid, ptrFile);										
		
				if (i < aPyramidsList -> pyramidsCounter - 1) 	
				{
					fprintf (ptrFile,",\n");
				}	
			}
			fprintf (ptrFile,"\n]");
			fprintf (ptrFile,"\n");
			fprintf (ptrFile,"}");
		}
	
		fclose (ptrFile);
  	}	
}


int FilePrintPyramid(pyramid *aPyramid, FILE *ptrFile)
{

	if (NULL == aPyramid)	
		printf("null");
		
	else					
	{
		int i; 
		for (i = 0; i < 4; i++ )
		{
			fprintf (ptrFile,"\n\t\t{");
			fprintf (ptrFile,"\n\t\t\"Vertex #%i\"", i+1);
			fprintf (ptrFile,"\n\t\t\"x\": %d", aPyramid -> vertices[i].x);
			fprintf (ptrFile,",\n\t\t\"y\": %d", aPyramid -> vertices[i].y);
			fprintf (ptrFile,",\n\t\t\"z\": %d", aPyramid -> vertices[i].z);
			fprintf (ptrFile,"\n\t\t}\n\n");
		}
	}
return 0;	
}

void FilePrintSquare(pyramidsList *aPyramidsList) 
{
	FILE * ptrFile = fopen("aPyramidsList.json", "a");
	if (ptrFile != NULL)
	{
	    int i;
	    for (i = 0; i < aPyramidsList -> pyramidsCounter; i++)
	    {
	        pyramid *aPyramid = &(aPyramidsList -> pyramids[i]);
	
	        fprintf (ptrFile,"\n\nThe area of the pyramid #%d = %.4f", i+1, pyramidSquare(aPyramid));
	    }
	    
	    fclose (ptrFile);
	}
}

