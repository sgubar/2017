/*
Created by Igor Bogolyubov DK-61
var. 3
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int input_a(int inp_a){
	
		do{
				printf("PLease, enter an integer (not 0 or negative)\n");
				printf("Enter A here: "); 			//vvod inta inp_a
				scanf("%i", &inp_a);
				}
				
					while(inp_a == 0 || inp_a < 0);{ 	//protverka na naturalnost
				}
		return inp_a;
		
}

	
	
	int input_b(int inp_b){
		
		do{
				printf("Enter B here: ");  	//vvod inta inp_b
				scanf("%i", &inp_b);
				}
				
				
				
				while(inp_b == 0 || inp_b < 0);{ 	//protverka na duraka => znamenatel ne mozhet bit 0
				}
				
				return inp_b;
}



int input_c(int inp_c){


				do{
				printf("Enter C here: ");  					//vvod inta inp_c
				scanf("%i", &inp_c);
				}
				
					while(inp_c == 0 || inp_c < 0);{ 	//protverka na naturalnost
				}
				
				return inp_c;
}

float block_fraction(int inp_a, int inp_b, int inp_c, float frac){ 

frac = (sqrt(inp_b+inp_c))/inp_b; //block drobi 
printf("Frac is %.2f\n", frac);

return frac;
}


int block_fact(int inp_value, int cnt, unsigned long long fctrl, int inp_a, int const_d){ 	//block factoriala
    
	inp_value = inp_a + const_d;

    for(cnt=1; cnt<=inp_value;cnt++)
        {
            fctrl *= cnt;
        }
        printf("%d! = %i\n", inp_value, fctrl);
        
    return fctrl;
    
}
    

int block_sigma(int inp_c, unsigned long long fctrl, int summ){ 							//block sigmi
	
summ = fctrl*(inp_c+1);
printf("Result of sigma: %i \n", summ);

return summ;
}

float final_count(int inp_a, float frac, int summ, float q_final_res){ 						//block konechnogo podcheta

q_final_res = inp_a * frac + summ;
printf("Answer Q = %.2f\n", q_final_res);

return q_final_res;
}
