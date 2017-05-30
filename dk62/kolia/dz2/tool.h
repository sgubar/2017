

#ifndef TOOL_H_
#define TOOL_H_

typedef struct
{
char name;
char avtor;
}kniga;

typedef struct
{
	kniga *knigi;
	int size;
	int current_size;
}polka;


int new_kniga(polka *new_polka, char a, char b);
polka *new_polka ( int aSize);
int print_kniga(kniga *nove_kniga);
	int print_polka(polka *the_polka);
		void sad (void);
		void kick_polka (polka *the_polka);

//int zapis (spisok *the_spisok, int i);
#endif
