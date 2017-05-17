#ifndef dk_tool_h
#define dk_tool_h

typedef struct aCoordinates			
{
	float x;
	float y;
	float r;
}coordinates;						

typedef struct aList				
{
	int maxSize;					
	int currentSize;				
	coordinates *circle;			
}list;								

list *createList(int aSize);		
void destroyList(list *aList);		

void newCoordinate(list *aList);	
void print(list *aList);			
float square(coordinates *current);	

#endif
