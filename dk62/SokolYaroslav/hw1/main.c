#include <stdio.h> 
#include "dk_tool.h"

int main(void) 
{ 
//////////////////////////////////////////vvodim razmer massiva  
    int razmer = 0; //razmer massiva

    printf("Vvedite razmer massiva: ");
    if(scanf("%i", &razmer)!=1)
    {
        printf("Vvedite chislo!!!\n");
        return 0;
    }
    if(razmer>100||razmer<=0)
    {
        printf("Vvedite razmer ot 1 do 100!!!\n");
        return 0;
    }
////////////............... 
    int massive [razmer];
    int newmassive[razmer];
//////////////////////vvodim element massiva and proverka na bukvy
	int i=0;
    for(i=0; i<razmer; i++)
    {
        printf("Vvedite element massiva: ");
        if(scanf("%i", &massive[i])!=1)
        {
            printf("Vvedite chislo!!!\n");
            return 0;
        }
        if(massive[i]>1000||massive[i]<-1000)
        {
            printf("Vvedite drugoi massiv!!!\n");
            return 0;
        }
    }
    printfmassiv (razmer, massive);     ///////pechataet massiv
    zmeshchenie(razmer,massive, newmassive);     //////zmeshchaet massiv
    printfmassiv (razmer, newmassive);      ///////pechataet newmassiv

}

