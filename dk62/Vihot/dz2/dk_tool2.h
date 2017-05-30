#ifndef dk_tool2_h
#define dk_tool2_h
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
spisok_figur *new_spisok_figur(int maxreal); 
int add_coord(spisok_figur *myfigura);	
void delete_spisok_figur(spisok_figur *myfigura);	
void print_figura(spisok_figur *myfigura);		
int inputint(int limit);	
#endif
