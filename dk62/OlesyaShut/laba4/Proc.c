#include "Proc.h"

#include <stdio.h>
//обробка стеку, аналіз балансу дужок
char process(ptr top) {
	char value; //значення поточного елементу стеку
	char result = 0; //стан рядка
	char sc; //лічильник квадратних дужок
	char rc; //лічильник круглих дужок
	char fc; //лічильник фігурних дужок
	sc = rc = fc = 0; //початкова установка
	while (value = pop(&top)) { //поки поточний елемент не нуль (ознака пустого стеку)
		switch (value) { //аналіз поточного символу
			case '[':
				sc++;
				break;
			case ']':
				if (--sc < 0)
					result |= SB_U; //помилка. встановлення другого біту стану в 1
				break;
			case '(':
				rc++;
				break;
			case ')':
				if (--rc < 0)
					result |= RB_U; //помилка. встановлення четвертого біту стану в 1
				break;
			case '{':
				fc++;
				break;
			case '}':
				if (--fc < 0)
					result |= FB_U; //помилка. встановлення шостого біту стану в 1
				break;
		}
	}
	if (sc) //лічильник не дорівнює нулю - кількість дужок невірна
		result |= SB_M; //помилка. встановлення першого біту стану в 1
	if (rc)
		result |= RB_M; //помилка. встановлення третього біту стану в 1
	if (fc)
		result |= FB_M; //помилка. встановлення п'ятого біту стану в 1
	return result;
}
//виведення результату аналізу
/*
 * послідовно перевіряється встановлення бітів змінної стану в 1 - ознака помилки
 * в разі нульвого значення - відсутність помилок, стан відповідає збалансованому рядку
 */
void show(char state) {
	if (state & SB_M) printf("Square brackets unbalanced (wrong amount)\n");
	if (state & SB_U) printf("Square brackets unbalanced (wrong order)\n");
	if (state & RB_M) printf("Round brackets unbalanced (wrong amount)\n");
	if (state & RB_U) printf("Round brackets unbalanced (wrong order)\n");
	if (state & FB_M) printf("Figure brackets unbalanced (wrong amount)\n");
	if (state & FB_U) printf("Figure brackets unbalanced (wrong order)\n");
	if (!state) printf("Line is balanced\n");
}
