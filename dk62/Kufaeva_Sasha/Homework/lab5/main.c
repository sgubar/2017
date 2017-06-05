#include <stdio.h>
#include <stdlib.h>

#include "dk_tool.h"

int main()
{
	//создаём дерево
	Tree *theTree = createTree();
	
	if(theTree != NULL)
	{
		//заполняем дерево элементами
		fillElements(theTree);
		
		//выводим дерево
		print(theTree);
		
		//удаление корневого элемента дерева
		deleteRootElement(theTree);
		
		//ещё раз печатаем. поменяли же))
		print(theTree);
		
		//создаём новый элемент, чтобы не повторялся
		createNotSameElement(theTree);
		
		//и ещё раз...
		print(theTree);
		
		//поиск случайной буквы. она всегда разная
		searchRandomChar(theTree);
		
		//удаление всего дерева
		destroyTree(theTree);
		
		//если в самом начале создало дерево
		//и прога отработала, то закончит здесь
		return 0;
	}
	
	//выход из программы с числом 1, если не создало дерево
	return 1;
}
