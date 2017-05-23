#ifndef dk_tool_h
#define dk_tool_h

typedef struct aCoordinates			//структура содержит только 2 КООРДИНАТЫ точки и радиус
{
	float x;
	float y;
	float r;
}coordinates;						//это структура кругов

typedef struct aList				//структура содержит
{
	int maxSize;					//максимальное количество кругов
	int currentSize;				//текущее количество кругов
	coordinates *circle;			//указатель на первый круг (на все сразу т.к.
}list;								//они расположены подряд одним блоком памяти)

list *createList(int aSize);		//создает одну вторую структуру и aSize первой
void destroyList(list *aList);		//освобождает память

void newCoordinate(list *aList);	//вводит знаения x, y, radius.
void printArea(list *aList);		//печатает на экране параметры кругов (x y r S)
void printJson(list *aList);		//печатает в файл параметры кругов
float square(coordinates *current);	//считает площадь круга

#endif
