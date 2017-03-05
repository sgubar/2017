/*
Created by Igor Bogolyubov DK-61
var. 3
*/


#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, const char *argv[]){

	int inp_a=0, inp_b=0, inp_c=0, const_d = 0, summ,inp_value, cnt;  	// all int's in the code                              
		float frac,q_final_res; 										// drob i konechniy resultat (floating point) 
    		unsigned long long fctrl = 1; 								//  tip dlinnogo dlinnogo celogo chisla bez ucheta znaka

inp_a =input_a(inp_a); // vvod znacheniy dlya A B C
inp_b =input_b(inp_b);
inp_c =input_c(inp_c);
		
	frac = block_fraction(inp_a, inp_b, inp_c, frac); 						// funckiya vichisleniya drobi


		fctrl = block_fact(inp_value, cnt, fctrl, inp_a, const_d);			// funckiya vichisleniya factoriala


			summ = block_sigma( inp_c, fctrl, summ);						// funckiya vichisleniya sigmi


				q_final_res = final_count(inp_a, frac, summ, q_final_res);	// funckiya konechnogo podscheta


}
