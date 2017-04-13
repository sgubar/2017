#ifndef hw2dk_tool_h
#define hw2dk_tool_h
typedef struct coordinate
{
	int x;
	int y; 
}tochka;
typedef struct tochki
{
	tochka *tochki; 
}figura;
typedef struct spisok
{
	figura *quadrangle; 
	int N;
	int Flag;
}spisok_figur;
spisok_figur *new_spisok_figur(int N);	//створення структури
int addсoord(spisok_figur *spisok);	//додавання коодинат до структури
void printFigure(spisok_figur *aFigure);	//друк структури
void destroyFigureList(spisok_figur *aFigure);	//видалення структури
int inputint(int limit);	//введення та перевірка числа
#endif
