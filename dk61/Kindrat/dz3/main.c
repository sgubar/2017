#include "dk_tool.h"

int main()
{
	Rack *thePolka = createPolka(20);
	
	addBookToPolka(thePolka, "Rei Bredberi", "451 po Farengeitu");
	addBookToPolka(thePolka, "Rei Bredberi", "Vino iz Oduvanchikov");
	addBookToPolka(thePolka, "Antuan de Sent-Ekzuperi", "Malenki princ");
	addBookToPolka(thePolka, "Lev Tolstoi", "Anna Karenina");
	addBookToPolka(thePolka, "Fedor Mihalovich Dostoevski", "Prestuplenie i nakazanie");
	
	printPolka(thePolka);
	printPolkaJson(thePolka);
	
}
