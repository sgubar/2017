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
spisok_figur *new_spisok_figur(int maxreal); 		//створення структури
int add_сoord(spisok_figur *myfigura);		//додавання коодинат до структури
void delete_spisok_figur(spisok_figur *myfigura);		//видалення структури
void print_figura(spisok_figur *myfigura);		//друк структури
int inputint(int limit);		//введення та перевірка числа
float Ploshcha(figura *figura);		//знаходження площі чотирикутника
#endif
