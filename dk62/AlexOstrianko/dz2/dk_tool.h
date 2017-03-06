#ifndef dk_tool_h
#define dk_tool_h
typedef struct tagKol
{
	char *pokr;
	char disk[10];
}Koleso;

typedef struct tagCar
{
	Koleso *kolvo;
	int max;
	int curent;
}Car;

void AddKol (Car *PCar,char *InputPokr,char InputDisk[10]);
void DeleteKol (Car *PCar);
void DelCar(Car *PCar);
#endif
