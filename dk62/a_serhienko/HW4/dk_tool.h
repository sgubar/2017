

#ifndef dk_tool
#define dk_tool
#include <string.h>


typedef struct coord
{
	int x;
	int y;
	int z;
}point;
typedef struct pyramid
{
	point *points;
	
}pyramid;//struct that contains an array of points for each of pyramid


typedef struct optionPyramid
{
	pyramid *arrayofPyramids;
	int size;//size of our pyramid list
	int current_size;
	
}pyramidList;



pyramidList *createPyramidList(int size);//creating pyramids
void destroyAllPyramid(pyramidList *aPyramidList);//deleting pyramids




int addPyramid(pyramidList *aPyramidList);//adding pyramid to pyramidlist
int printPyramid(pyramid*thePyramid);//additional function for printing pyramids
int printPyramidList(pyramidList *aPyramidList);//printing pyramids

int square(pyramid*thePyramid);//calculating square for each pyramid

void writePyramid(FILE *aFile, pyramid*thePyramid);
void writePyramidList(FILE *aFile, pyramidList *aPyramidList);

void swap(pyramid *var1, pyramid *var2);
int num_scanf(void);//checking if our input is a num

#endif dk_tool















