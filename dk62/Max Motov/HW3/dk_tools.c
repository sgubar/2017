#include "stdio.h"
#include "stdlib.h"
#include "dk_tools.h"


tListSp * CreateList(int arraySize)
{
    tListSp *myList = (tListSp *)malloc(sizeof(tListSp));

	if(myList != NULL)
	{
		myList->sphere = (tListSp *)malloc(arraySize * sizeof(tListSp));
		memset(myList->sphere, 0 , arraySize * sizeof(tListSp));

		myList->size = arraySize;
		myList->current_size = 0;
	}
	printf("Ok, ok, I'll do it for u.\n");
	return myList;
}




void AddSphere(float x, float y, float z, float radius, tListSp *list)
{
    if(list->current_size < list->size)
    {
        list->sphere[list->current_size].x = x;
        list->sphere[list->current_size].y = y;
        list->sphere[list->current_size].z = z;
        list->sphere[list->current_size].radius = radius;
        list->current_size++;
        printf("Added\n");
    }
    else
    {
        printf("Guy, something wrong with your life\n");
    }



}


void TotalSphereWorldDestruction(tListSp *list_of_spheres)
{
    if(list_of_spheres != NULL)
	{
		if(list_of_spheres->sphere != NULL)
		{
			free(list_of_spheres->sphere);
		}
		free(list_of_spheres);
	}
	printf("POTRACHENO\n");
}


float SquareOfSphere(tSphere sphere)
{
    return 4 * 3.14 * sphere.radius * sphere.radius;
}



void WriteToJson(tListSp *theList)
{
    FILE *theFile = fopen("file.json", "a+");
    fprintf(theFile, "{\n");
    fprintf(theFile, " \"size\": %d,\n", theList->size);
    fprintf(theFile, " \"current size\": %d,\n", theList->current_size);
    fprintf(theFile, " \"spheres\":\n");
    fprintf(theFile, "\t[\n");
    fprintf(theFile, "\t {\n");

    for(int i = 0; i < theList->current_size; i++)
    {
        fprintf(theFile, "\t\t \"Point[%d]\": {\"X\": %f, \"Y\": %f, \"Z\": %f, \"radius\": %f}\n", i+1, theList->sphere[i].x, theList->sphere[i].y, theList->sphere[i].z, theList->sphere[i].radius);
    }

    fprintf(theFile, "\t }\n");
    fprintf(theFile, "\t]\n");
    fprintf(theFile, "}\n");
    fclose(theFile);

}
