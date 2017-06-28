#include "dk_tool.h"


char ch;
char mas[Max];
int main()
{
	
	while (1)
	{
		system("cls");
		printf("-> 1. Open and read\n");
		printf("-> 2. QuikSort\n");
		printf("-> 3. Insertion sort\n");
		printf("-> 4. Find\n");
		printf("-> 5. Save\n");
		printf("-> 6. Quit\n\n");
		printf(">>");
		ch = getch();
		printf("\n");
		if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6')
			break;
		system("cls");
		printf("Error.\n\n");
		ch = getch();
	}
	switch (ch)
	{
	case '1': strcpy(mas, open());
		main();
		return 0;
	case '2': strcpy(mas, sort(mas));
		main();
		return 0;
	case '3': strcpy(mas, sort_1(mas));
		main();
		return 0;
	case '4': find(mas);
		main();
		return 0;
	case '5': save(mas);
		main();
		return 0;
	case '6':
		return 0;
	}
}
