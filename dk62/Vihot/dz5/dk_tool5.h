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
spisok_figur *n_spisok_figur(int maxreal); 		
int add_coord(spisok_figur *mfigura);		
void delete_spisok_figur(spisok_figur *mfigura);		
void print_figura(spisok_figur *mfigura);		
void printinfile_spisok(FILE *file, spisok_figur *mfigura);		
void printinfile_figura(FILE *file, figura *mfigura);
int inputint(int limit);		
void BubbleSort(spisok_figur *mfigura);
void swap(spisok_figur *mfigura, int aLeftIndex, int aRightIndex);
int BinarySearch(spisok_figur *myfigura); 
int mediana(spisok_figur *mfigura, int aLeftIndex, int aRightIndex);
int m_partitionIt(spisok_figur *mfigura, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort2(spisok_figur *mfigura, int aLeftIndex, int aRightIndex);
void m_manualSort(spisok_figur *mfigura, int aLeftIndex, int aRightIndex);
#endif

