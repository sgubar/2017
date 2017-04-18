#ifndef dk_tool	
#define dk_tool	

void ReadingFromFile(FILE*file,char *arrayforsorting);
void PrintSortedArraytoFile(FILE *file, char *arrayforsorting);
void bubblesorting(char*Sarray, char*Marray, char*Larray, char*MegAarray,double *time);
void selectionsorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double *time);
void insertionsorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double *time);
void shellsorting(char*Sarray, char*Marray, char*Larray, char*MegAarray, double *time);
void writearraystofile(char*Sarray, char*Marray, char*Larray, char*MegAarray);
void readarraysfromfile(char*Sarray, char*Marray, char*Larray, char*MegAarray);
void printtable(double *bubbletime, double *insertiontime, double *selectiontime, double *shelltime);
int linear_search(char*Sarray, char*Marray, char*Larray, char*MegAarray);
void additionalsearching(char*array);


#endif

