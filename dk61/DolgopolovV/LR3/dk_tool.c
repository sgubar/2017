#include "dk_tool.h"


char *sort(char *mas)
{
	system("cls");
	int longe = (strlen(mas)) / 2;
	char buf;
	float ttime = clock();
	while (longe >= 1)
	{
		for (int i = longe; i < strlen(mas); i++)
		{
			int j = i;
			while (j >= longe)
			{
				if (mas[j] < mas[j - longe])
				{
					buf = mas[j];
					mas[j] = mas[j - longe];
					mas[j - longe] = buf;
				}
				else
					break;
				j -= longe;
			}
		}
		longe = (longe) / 2;
	}
	printf("Time %.2f\n", (clock() - ttime));
	printf("%s", mas);
	getch();
	return mas;
}

char *sort_1(char *mas)
{
	system("cls");
	char buf;
	int min;
	float ttime = clock();
	for (int j = 0; j < strlen(mas); j++)
	{
		min = j;
		for (int k = j; k < strlen(mas); k++)
		{
			if (mas[k] < mas[min])
				min = k;
		}
		buf = mas[j];
		mas[j] = mas[min];
		mas[min] = buf;
	}
	printf("Time %.2f\n", (clock() - ttime));
	printf("%s", mas);
	getch();
	return mas;
}

char *open(void)
{
	system("cls");
	char file_name[100], text[Max];
	printf("Enter a file name: ");
	scanf("%s", file_name);
	while (getchar() != '\n');
	FILE *fp = fopen(file_name, "r");

	fgets(text, sizeof(text), fp);
	fclose(fp);
	printf("%s", &text);
	getch();
	return &text;
}

void save(char text[Max])
{
	system("cls");
	char file_name[100];
	printf("Enter a file name: ");
	scanf("%s", file_name);
	while (getchar() != '\n');
	FILE *fp = fopen(file_name, "w");
	if (fp == NULL)
		printf("error");
	int z = fputs(text, fp);
	fclose(fp);
	return;
}

void find(char *mas)
{
	char a;
	system("cls");
	printf("Enter symbol: \n");
	a = getch();
	int low, high, middle;
	low = 0;
	high = strlen(mas) - 1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (a < mas[middle])
			high = middle - 1;
		else if (a > mas[middle])
			low = middle + 1;
		else
		{
			printf("%i", middle);
			getch();
			return;
		}
	}
	printf("No symbol");
	getch();
	return;
}
