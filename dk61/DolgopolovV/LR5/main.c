#include "dk_tool.h"


char ch;
b_tree* atree;
void main()
{
	while (1)
	{
		system("cls");
		printf("-> 1. Insert symbol to tree\n");
		printf("-> 2. Delete symbol from tree\n");
		printf("-> 3. Print tree\n");
		printf("-> 4. Destroy tree\n");
		printf("-> 5. Quit\n\n");
		printf(">>");
		ch = getch();
		printf("\n");
		if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5')
			break;
		system("cls");
		printf("Error.\n\n");
	}
	switch (ch)
	{
	case '1': atree = add(atree);
		main();
		return 0;
	case '2': atree = del(atree);
		main();
		return 0;
	case '3': print(atree);
		main();
		return 0;
	case '4': destr(atree);
		atree = NULL;
		main();
		return 0;
	case '5':
		return 0;
	}
}
