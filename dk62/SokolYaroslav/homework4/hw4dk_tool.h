#ifndef hw4dk_tool_h
#define hw4dk_tool_h
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
void printinfile_spisok(FILE *file, spisok_figur *myfigura);		//друк списка в файл JSON
void printinfile_figura(FILE *file, figura *myfigura);
int inputint(int limit);		//введення та перевірка числа
float Ploshcha(figura *figura);		//знаходження площі чотирикутника
void BubbleSort(spisok_figur *myfigura);
#endif
