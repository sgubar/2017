#ifndef dk_tool_h
#define dk_tool_h
typedef struct coordinate
{
	
	int xCoordinate;
	int yCoordinate;
	int zCoordinate;
	
}ParpipedCoordinate;

typedef struct position
{
	ParpipedCoordinate *coordinates;
	
}ParpipedPoints;

typedef struct List
{
	ParpipedPoints *parpipeds;
	int size;
	int current_size;
	
}ParpipedList;

ParpipedList * createParpipedList(int aSize);
void destroyParpipedList(ParpipedList *aParpiped);
int addParpipedCoordinates(ParpipedList *aParpiped);
void printParpipedList(ParpipedList *aParpiped);
int areaCalculation(ParpipedPoints * aParpiped);
int enterParametersOfSphere(void);
void bubbleSort(ParpipedList *aParpiped);
void selectionSort(ParpipedList *aParpiped);
void insertionSort(ParpipedList *aParpiped);

#endif
