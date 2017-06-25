#include "Proc.h"

#include <stdlib.h>
#include <stdio.h>
//максимальна довжина рядка для обробки
#define LEN 255


//читання цілого числа з клавіатури
int readInt() {
	char in;
	scanf("%d",&in);
	return in;
}

int main() {
	int choice; //обраний пункт меню
	ptr top = NULL; //вказівник на вершину стеку
	char *str; //рядок, що обробляється
	do {
		printf("\n1: Append to list\n2: Print list\n3: Process\n4: Delete list\n5: Exit\n");
		choice = readInt();
		switch(choice) {
			case 1:
				//введення рядка
				str = (char*)malloc(LEN+1);
				printf("Type line to check (no more than %d characters): ",LEN);
				getc(stdin);
				fgets(str,LEN,stdin);
				
				create(&top,str); //додавання рядка до стеку
				free(str); //очистка пам'яті під рядок
				break;
			case 2:
				//друк
				print(top);
				printf("\n");
				break;
			case 3:
				show(process(reverse(top))); //обробка рядка (автоматично очищує стек)
				top = NULL; //гарантія коректної роботи
				break;
			case 4:
				printf("Deleting list\n");
				empty(&top); //очистка стеку
				top = NULL; //гарантія коректної роботи
				break;
			case 5:
				empty(&top); //очистка стеку перед завершенням програми
				break;
			default:
				printf("Wrong command\n");
				break;
		}
	} while (choice != 5);
	return 0;
}
