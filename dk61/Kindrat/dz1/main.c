#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int kol_b = 0; 
	int i = 0;
	int v = 0; 
	int counter = 0;
	
	char tekst[80]; 
	printf("vvedite svoi tekst:\n");
	gets(tekst);
	char slovo[80];
	printf("vvedite iskomoe slovo:\n");
	gets(slovo);
	while(slovo[kol_b]!='\0')
	{
		kol_b++;
	}
	while(tekst[i]!='\0')
		{
			if(tekst[i]==slovo[0])
				{
					while(tekst[i+v]==slovo[0+v] && v<kol_b)
						{
							v++;
							if(v==kol_b-1)
								{
								counter++;
								}
						}
				}
		i++;
		v = 0;
		}printf(" vstrechaetsia %d raz(a)",counter);
}
