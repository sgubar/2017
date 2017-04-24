#ifndef dk_tool_h
#define dk_tool_h
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
spisok_figur *spisok_figur(int maxreal); 		
int add_ñoord(spisok_figur *figura);		
void delete_spisok_figur(spisok_figur *figura);	
void print_figura(spisok_figur *figura);		
void printinfile_spisok(FILE *file, spisok_figur *figura);		
void printinfile_figura(FILE *file, figura *figura);
int inputint(int limit);		
void BubbleSort(spisok_figur *figura);
#endif
