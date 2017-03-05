/*
Created by Igor Bogolyubov DK-61
var. 3
*/


#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>
#include <math.h>
int input_a(int inp_a);
int input_b(int inp_b);
int input_c(int inp_c);
float block_fraction(int inp_a, int inp_b, int inp_c, float frac);
int block_fact(int inp_value, int cnt, unsigned long long fctrl, int inp_a, int const_d);
int block_sigma(int inp_c, unsigned long long fctrl, int summ);
float final_count(int inp_a, float frac, int summ, float q_final_res);
#endif
