#include "dk_tool.h"
#include <stdlib.h>



float firststage(int A, int B, int C)
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





int mypow(int A)
{
	return 1 << A;
}

int secondstage(int A)
{
	int rez = 0;
	for (int i = 0; i < A; i++) {
		rez += mypow(i);// 
	}
	return rez;
}




