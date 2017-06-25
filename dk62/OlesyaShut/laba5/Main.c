#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//читання рядка з клавіатури, переведення в число 
//(перший параметр - тип числа, другий - літера для стандартної функціїї переведення)
//0 - неможливе значення

//читання цілого числа з клавіатури
int readInt() {
	int in;
	scanf("%d",&in);
	return in;
}

int main()
{
	srand(time(NULL)); //створення "зерна" генератора випадкових чисел
	int choice; //обраний пункт меню
	ptr root = NULL; //корінь дерева
	do {
		printf("\n1: Create tree\n2: Print tree\n3: Add node\n4: Find node\n5: Remove node\n6: Delete tree\n7: Exit\n");
		choice = readInt();
		switch(choice) {
			case 1:
				printf("Tree size: ");
				if (root) //дерево вже існує
					erase(&root); //видаляємо попереднє
				root = create(readInt()); //створення нового дерева
				break;
			case 2:
				print(root,0); //друк з кореня
				break;
			case 3:
				printf("Node value (integer value, except zero): ");
				//додавання вузла. вивід залежить від наявності вузла з заданим ключем
				printf("%s\n", add(&root,readInt()) ? "Creating new node" : "Replacing node"); 
				break;
			case 4:
				printf("Node value (integer value, except zero): ");
				//пошук вузла. вивід залежить від наявності вузла з заданим ключем
				printf("%s\n", find(root,readInt()) ? "Element exists" : "No node found");
				break;
			case 5:
				printf("Node value (integer value, except zero): ");
				int value = readInt();
				if (find(root,value) == NULL) //елемент відсутній, в видаленні немає необхідності
					printf("No element to remove\n");
				else { //видаляємо елемент
					rem(&root,value);
					printf("Removing node\n");
				}
				break;
			case 6:
				//видалення дерева
				printf("Deleting tree\n");
				erase(&root);
				root = NULL;
				break;
			case 7:
				erase(&root); //видалення дерева перед завершенням програми
				break;
			default:
				printf("Wrong command\n");
				break;
		}
	} while (choice != 7);
	return 0;
}
