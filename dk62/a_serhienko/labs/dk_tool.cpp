#include "dk_tool.h"
#include <stdlib.h>



float firststage(float A, float B, float C)
{
	

	float znamennik;
	float vuraz;
	float chiselnik;

	chiselnik = (A + B + C);
	znamennik = (100 - B - C);
	vuraz = chiselnik / znamennik;
	if (chiselnik == 0) {
		exit(1);
	}
	if (znamennik == 0) {
		exit(1);
         
	}
	


	return vuraz;

}





int secondstage(float A, int D)
{
	
	
	D = 0; 
	while (A > 0) 
	{
		D = D + A;
		A--;
	}
	return D;

}

int thirdstage(int A, int rez,int m)
{

	return 1<<A;
}



