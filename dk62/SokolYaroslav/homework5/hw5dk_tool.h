#ifndef hw5dk_tool_h
#define hw5dk_tool_h
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
void BubbleSort(spisok_figur *myfigura);
void swap(spisok_figur *myfigura, int aLeftIndex, int aRightIndex);
int BinarySearch(spisok_figur *myfigura); //function of binary searching;
int mediana(spisok_figur *myfigura, int aLeftIndex, int aRightIndex);
int m_partitionIt(spisok_figur *myfigura, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort2(spisok_figur *myfigura, int aLeftIndex, int aRightIndex);
void m_manualSort(spisok_figur *myfigura, int aLeftIndex, int aRightIndex);
#endif
