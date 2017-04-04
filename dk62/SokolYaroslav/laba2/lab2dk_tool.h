#ifndef lab2dk_tool_h
#define lab2dk_tool_h
int inputint(int input, int limit);//введення та перевірка числа
void generatestring (int kolslov,int kolelement,char slovoelement [kolslov][kolelement]);//генерація слів
void print(int kolslov,int kolelement,char slovoelement [kolslov][kolelement]);//друкує згенерований текст
void printfile(int kolslov,int kolelement,char filestring [kolslov][kolelement]);//друкує текс з файлу
void printinf(int kolslov,int kolelement,char filestring [kolslov][kolelement]);//друкує текст в файл
int razmerf(int kolelement);//дізнає кількість елементів в файлі(в рядку)
int kolslovf(int kolelement,int kolslov);//дізнає кількість слів в файлі(в рядку)
void obmenslov (int kolslov,int kolelement,char slovoelement [kolslov][kolelement],int i);//обмін розташувань двох сусідніх слів
void bublesort(int kolslov,int kolelement,char slovoelement [kolslov][kolelement]);//сортування бульбашкою
void filestingr(int kolelement,int kolslov,char filestring [kolslov][kolelement]);//зчитування масиву з файлу
#endif
