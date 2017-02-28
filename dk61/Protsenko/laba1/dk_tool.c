//  dk_tool.c
//  laba1 variant 2
//  Created by Illia Protsenko 2/28/17.

#include "dk_tool.h"

int module(int A, int B, int C){       //це ми разуємо 
	int module_result;
	module_result = fabs(((A*C)-B));
	//printf("Module result: %i\n", module_result);//
	return module_result;
}

int power(int D){
	int power_result;
	power_result = pow(2, D);
	return power_result;
	
}

int sum(int A){
	int power_A = power(0);
	for(int i = 0; i < A; i++){
		power_A++;
	}
	//printf("Sum result: %i\n", power_228-1);//
	return power_A-1;
}
