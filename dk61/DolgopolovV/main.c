#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"


char ch;
Node *head = NULL;
int main(void)
{
	while (1)
	{
		system("cls");
		printf("1. Create.\n");
		printf("2. Add.\n");
		printf("3. Del.\n");
		printf("4. Long.\n");
		printf("5. Destroy.\n");
		printf("6. Show.\n");
		printf("7. Exit.\n\n");
		printf(">>");
		ch = getch();
		printf("\n");
		if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7')
			break;
		system("cls");
		printf("Error.\n\n");
	}
	switch (ch)
	{
	case '1': 
		head = create();
		main();
		return 0;
	case '2':
		head = add(head);
		main();
		return 0;
	case '3':
		head = del(head);
		main();
		return 0;
	case '4':
		longe(head);
		main();
		return 0;
	case '5':
		destr(head);
		main();
		return 0;
	case '6':
		show(head);
		main();
		return 0;
	case '7':
		return 0;
	}
}
