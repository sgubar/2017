/*
 * tool.h
 *
 *  Created on: 16 ìàÿ 2017 ã.
 *      Author: Yaroslav Hordiienko
 */

#ifndef TOOL_H_
#define TOOL_H_

typedef struct figure
{
int x;
int y;
int r;
}kolo;

typedef struct list
{
	kolo *kolas;
	int size;
	int current_size;
}spisok;


spisok *new_spisok ( int aSize);

int new_kolo (spisok *theList, int x, int y, int r);
int print_kolo(kolo *nove_kolo);
float print_nomer_kolo(spisok *the_spisok, int i);
int print_spisok(spisok *the_spisok);
void sad (void);
void kick_spisok (spisok *the_spisok);
int zapis (spisok *the_spisok, int i);
float Square (kolo *aCircle);
void peremen (kolo *var1, kolo *var2);
void Selection_Sort_List(spisok *the_spisok);
#endif
