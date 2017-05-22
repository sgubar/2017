#ifndef dk_tool_h
#define dk_tool_h

typedef struct tagKoleso
{
	char *pokrishka;
	char disk[10];
}Koleso;

typedef struct tagCar
{
	Koleso *kolvo;
	int max;
	int curent;
}Car;

void AddKoleso (Car *PointerCar,char *InputPokrishka,char InputDisk[10]);
void DeleteKoleso (Car *PointerCar);
void DeleteCar(Car *PointerCar);
#endif
