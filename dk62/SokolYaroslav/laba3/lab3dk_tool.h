#ifndef lab3dk_tool_h
#define lab3dk_tool_h
int razmerf();//дізнає кількість елементів в файлі(в рядку)
int kolslovf(int kel);//дізнає кількість слів в файлі(в рядку)
void filestingr(int kel,int ksl,char slovo[ksl] [kel]);//зчитування масиву з файлу
void printinf(int ksl,int kel,char str[ksl] [kel]);//друкує текст в файл
void printfile(int ksl,int kel,char str[ksl] [kel]);//друкує текс з файлу
void m_manualSort(int ksl,int kel,char str[ksl] [kel], int aleft, int aright);
#endif
