#include "dk_tool.h"

int main() 
{
	Node *top = NULL; //вершина стеку
	char str[10]; 
	int stack_size;
	do 
	{ //зчитуємо розмір стеку
		printf("Set stack size: ");
		scanf("%s",str);
		stack_size  = atoi(str);
	} while (stack_size == 0); 
	for (char i = 0; i < stack_size; i++)  //заповнення стеку
		push(&top);
	//початковий стек
	printf("Stack before replace:\n");
	show(top);
	//обробка стеку
	printf("Stack after replace:\n");
	replace(top);
	show(top);
	//очистка пам'яті
	empty(top);
	return 0;
}
