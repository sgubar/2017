#include "dk_tool.h"

int main()
{
	char aValue;
	
	Rack *thePolka = createPolka(20);
	
	addBookToPolka(thePolka, "Rei Bredberi", "451 po Farengeitu");
	addBookToPolka(thePolka, "Rei Bredberi", "Vino iz Oduvanchikov");
	addBookToPolka(thePolka, "Antuan de Sent-Ekzuperi", "Malenki princ");
	addBookToPolka(thePolka, "Lev Tolstoi", "Anna Karenina");
	addBookToPolka(thePolka, "Fedor Mihalovich Dostoevski", "Prestuplenie i nakazanie");
	
	printPolka(thePolka);
	
	printf("Its Shell sort\n");

    shellSort(thePolka);
	printf (" Array is sorted!!! ");
	printPolka(thePolka);

	binarySearch (aPolka, aValue, size);
	printPolka(thePolka);
}
