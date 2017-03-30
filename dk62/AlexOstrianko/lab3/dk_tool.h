#ifndef dk_tool_h
#define dk_tool_h

int BinarySearch(char *String, char toFind);
char *Transform_file_text_to_str (int *InpInt);
void Print_To_File (int Lenth_of_Str,char *PStr);
void m_manualSort(char *anArray, int aLeftIndex, int aRightIndex);
void quickSort2(char *anArray, int aLeftIndex, int aRightIndex);
int m_partitionIt(char *anArray, int aLeftIndex, int aRightIndex, char aPivot);
char mediana(char *anArray, int aLeftIndex, int aRightIndex);
void swap(char *anArray, int aLeftIndex, int aRightIndex);

#endif
