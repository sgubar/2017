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
spisok_figur *nspisok_figur(int maxreal); 		
int add_ñoord(nspisok_figur *mfigura);		
void delete_spisok_figur(nspisok_figur *figura);	
void print_figura(nspisok_figur *figura);		
void printinfile_spisok(FILE *file, nspisok_figur *figura);		
void printinfile_figura(FILE *file, nfigura *figura);
int inputint(int limit);		
void BubbleSort(nspisok_figur *figura);
#endif
