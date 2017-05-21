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
        fprintf(theFile, "\t\t \{\"X\": %f, \"Y\": %f, \"Z\": %f, \"radius\": %f}\n", i+1, theList->sphere[i].x, theList->sphere[i].y, theList->sphere[i].z, theList->sphere[i].radius);
    }

    fprintf(theFile, "\t }\n");
    fprintf(theFile, "\t]\n");
    fprintf(theFile, "}\n");
    fclose(theFile);

}





void Choose(tListSp *theList)
{
    for(int i = 0; i < theList->current_size; i++)
    {
        int min = i;
        for(int j = i; j < theList->current_size; j++)
        {
            if(theList->sphere[j].radius < theList->sphere[min].radius)
            {
                min = j;
            }
        }
        tSphere tmpList = theList->sphere[i];
        theList->sphere[i] = theList->sphere[min];
        theList->sphere[min] = tmpList;
    }
    printf("Your spheres sorted\n");
}



void ShellSort(tListSp *theList)
{
    tSphere tmp;
    int j;
    for (int step = theList->current_size / 2; step > 0; step /= 2)
    {
        for (int i = step; i < theList->current_size; i++)
        {
            tmp = theList->sphere[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp.radius < theList->sphere[j - step].radius)
                    theList->sphere[j] = theList->sphere[j - step];
                else
                break;
            }
            theList->sphere[j] = tmp;
        }
    }
}

int BinarySearch(tListSp *theList, float radius)
{
    int first_element_index = 0;
    int last_element_index = theList->current_size - 1;
    int middle_element_index = (last_element_index + first_element_index) / 2;

    while(first_element_index <= last_element_index)
    {
        if(theList->sphere[middle_element_index].radius < radius)
        {
            first_element_index = middle_element_index + 1;
        }
        else if(theList->sphere[middle_element_index].radius == radius)
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
