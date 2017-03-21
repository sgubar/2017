#ifndef dk_tool_h
#define dk_tool_h
typedef struct tagKol
{
	char pokr[10];
	char disk[10];
}Koleso;

typedef struct tagCar
{
	char *Name;
	Koleso *kolvo;
	int max;
	int curent;
}Car;

typedef struct tagGaraj
{
	Car *kolvo;
	int max;
	int curent;
}Garaj;


Garaj *CreateGaraj(int Size);
void AddCar (Garaj *PGar,char *InpName);
void AddKol (Car *PCar);
void DeleteKol (Car *PCar);
void DelCar(Car *PCar);
//void writeKol(FILE *aFile, Koleso *aKol);
//void writeCar(FILE *aFile, Car *PCar);
//void writeString(FILE *aFile, char *aKey, char *aString);
void sortCars(Garaj *PGar);
void bubbleSortCars(Garaj *PGar, int aSize);
#endif
