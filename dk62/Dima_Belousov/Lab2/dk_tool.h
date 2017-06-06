#ifndef dk_tool_h
#define dk_tool_h

#endif

void generation(int *darray, int dsize);

void bubbleSort(int *darray, int dsize);

void selectionSort(int *darray, int dsize);

void insertSort(int *darray, int dsize);

void shellSort(int *darray, int dsize);

void quickSort(int *darray, int dfirst, int dlast);

int scanSize();

void overstoreArray(int *array_A, int *array_B, int dsize);

void makeHeaderFile(FILE *d_f_save);

void writeTime(FILE *d_f_save, int x, int time);

void makeFutterFile(FILE *d_f_save);

void writeInFile(FILE *d_f_save, int x, int dsize, int *d_array);
