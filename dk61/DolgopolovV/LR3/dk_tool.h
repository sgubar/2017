#ifndef dk_tool_h
#include <stdio.h>
#include <time.h>
#include <string.h>
#define dk_tool_h

void bubbleSort(char *str, int string_lenght);
void selectionSort(char *str, int string_lenght);
int FileOpenCheck(FILE *file2, FILE *file);
int FileCloseCheck(FILE *file2, FILE *file);
void MoveArrayPoint(FILE *file);
void ShellSort(char *str, int string_lenght);
void LineSearch(FILE* file2, char key, char *str, int string_lenght);

#endif 
