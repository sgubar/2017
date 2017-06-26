#include "Proc.h"

#include <stdio.h>

char process(ptr top) {
	char value; 
	char result = 0; //стан рядка
	char sc; //лічильник квадратних дужок
	char rc; //лічильник круглих дужок
	char fc; //лічильник фігурних дужок
	sc = rc = fc = 0; 
	while (value = pop(&top)) { 
		switch (value) {
			case '[':
				sc++;
				break;
			case ']':
				if (--sc < 0)
					result |= SB_U; 
				break;
			case '(':
				rc++;
				break;
			case ')':
				if (--rc < 0)
					result |= RB_U; 
				break;
			case '{':
				fc++;
				break;
			case '}':
				if (--fc < 0)
					result |= FB_U; 
				break;
		}
	}
	if (sc) 
		result |= SB_M; 
	if (rc)
		result |= RB_M; 
	if (fc)
		result |= FB_M; 
	return result;
}

void show(char state) {
	if (state & SB_M) printf("Square brackets unbalanced (wrong amount)\n");
	if (state & SB_U) printf("Square brackets unbalanced (wrong order)\n");
	if (state & RB_M) printf("Round brackets unbalanced (wrong amount)\n");
	if (state & RB_U) printf("Round brackets unbalanced (wrong order)\n");
	if (state & FB_M) printf("Figure brackets unbalanced (wrong amount)\n");
	if (state & FB_U) printf("Figure brackets unbalanced (wrong order)\n");
	if (!state) printf("Line is balanced\n");
}
