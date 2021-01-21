#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
# define maxsize 40
#include <mcheck.h>

struct fly {
	int number, cost;
	char destination[10];
	char time[9];
	char date[9];
	
};
char* filename="exemple.txt";  // строковая константа 
struct fly *str;
struct fly *table[50];
int iterator = 0;
struct fly* push() {
	str = (struct fly*)malloc(maxsize);
	printf("Enter number: ");
	scanf("%d", &str->number);
	printf("Enter destination: ");
	scanf("%s", &str->destination);
	printf("Enter time HH.MM.SS: ");
	scanf("%s", &str->time);
	printf("Enter date DD.MM.YY: ");
	scanf("%s", &str->date);

	printf("Enter cost:");
	scanf("%d", &str->cost);
	table[iterator] = str;
	iterator++;
	return str;
	
}
void output() {
	for (int i = 0;i < iterator;i++) {

		char c;
		printf("%d ", table[i]->number);
		printf("%s ", table[i]->destination);
		printf("%s ", table[i]->time);
		printf("%s ", table[i]->date);
		printf("%d ", table[i]->cost);
		printf("\n");
	}
}
void fileinput() {
	FILE *S1;
	if ((S1 = fopen(filename, "r")) == NULL) {
		printf("Eror file");
	}
	while (!feof(S1)) {
		str = (struct fly*)malloc(maxsize);

		fscanf(S1, "%d", &str->number);
		char sim = 0;
		int im = 0;
		fscanf(S1, "%s", &str->destination);
		fscanf(S1, "%s", &str->time);
		fscanf(S1, "%s", &str->date);
		
		fscanf(S1, "%d", &str->cost);
		table[iterator] = str;
		iterator++;
		while ((sim != '\n')&&(!feof(S1))) {
			fscanf(S1, "%c", &sim);
		}

	}
	fclose(S1);
}
void fileoutput() {
	FILE *S1;
	if ((S1 = fopen(filename, "w")) == NULL) {
		printf("Eror file");
	}
	for (int i = 0;i < iterator;i++) {

		char c;
		fprintf(S1, "%d ", table[i]->number);
		fprintf(S1, "%s ", table[i]->destination);
		fprintf(S1, "%s ", table[i]->time);
		fprintf(S1, "%s ", table[i]->date);
		fprintf(S1, "%d\n ", table[i]->cost);
		if(i!=(iterator-1))
{fprintf(S1, "\n");}
	}
	fclose(S1);
}
void sortirovka() {
	printf("Choose field sort 1-number, 2-destination, 3-time, 4-date, 5-cost ");
	int n = 0;
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		for (int i = 0;i < iterator;i++)
		{
			for (int j = iterator - 1;j > i;j--)
			{
				if (table[j]->number < table[i]->number)
				{
					str = table[i];
					table[i] = table[j];
					table[j] = str;

				}

			}
		}
		break;
	case 2:
		for (int i = 0;i < iterator;i++)
		{
			for (int j = iterator - 1;j > i;j--)
			{
				if (table[j]->destination[0] < table[i]->destination[0])
				{
					str = table[i];
					table[i] = table[j];
					table[j] = str;

				}

			}
		}
		break;
	case 3:
		for (int i = 0;i < iterator;i++)
		{
			for (int j = iterator - 1;j > i;j--)
			{
				if (table[j]->time[0] < table[i]->time[0])
				{
					str = table[i];
					table[i] = table[j];
					table[j] = str;

				}
				else {
					if (table[j]->time[0] == table[i]->time[0]) {
						if (table[j]->time[1] < table[i]->time[1])
						{
							str = table[i];
							table[i] = table[j];
							table[j] = str;

						}
						else {
							if (table[j]->time[1] == table[i]->time[1]) {
								if (table[j]->time[3] < table[i]->time[3])
								{
									str = table[i];
									table[i] = table[j];
									table[j] = str;

								}
								else {
									if (table[j]->time[3] == table[i]->time[3]) {
										if (table[j]->time[4] < table[i]->time[4])
										{
											str = table[i];
											table[i] = table[j];
											table[j] = str;

										}
										else {
											if (table[j]->time[4] == table[i]->time[4]) {
												if (table[j]->time[6] < table[i]->time[6])
												{
													str = table[i];
													table[i] = table[j];
													table[j] = str;

												}
												else {
													if (table[j]->time[6] == table[i]->time[6]) {
														if (table[j]->time[7] < table[i]->time[7])
														{
															str = table[i];
															table[i] = table[j];
															table[j] = str;

														}
													}
												}
											}

										}
									}


								}
							}
						}

					}
				}
			}
		}
		break;
	case 4:
		for (int i = 0;i < iterator;i++)
		{
			for (int j = iterator - 1;j > i;j--)
			{
				if (table[j]->date[6] < table[i]->date[6])
				{
					str = table[i];
					table[i] = table[j];
					table[j] = str;

				}
				else {
					if (table[j]->date[6] == table[i]->date[6]) {
						if (table[j]->date[7] < table[i]->date[7])
						{
							str = table[i];
							table[i] = table[j];
							table[j] = str;

						}
						else {
							if (table[j]->date[7] == table[i]->date[7]) {
								if (table[j]->date[3] < table[i]->date[3])
								{
									str = table[i];
									table[i] = table[j];
									table[j] = str;

								}
								else {
									if (table[j]->date[3] == table[i]->date[3]) {
										if (table[j]->date[4] < table[i]->date[4])
										{
											str = table[i];
											table[i] = table[j];
											table[j] = str;

										}
										else {
											if (table[j]->date[4] == table[i]->date[4]) {
												if (table[j]->date[0] < table[i]->date[0])
												{
													str = table[i];
													table[i] = table[j];
													table[j] = str;

												}
												else {
													if (table[j]->date[0] == table[i]->date[0]) {
														if (table[j]->date[1] < table[i]->date[1])
														{
															str = table[i];
															table[i] = table[j];
															table[j] = str;

														}
													}
												}
											}

										}
									}


								}
							}
						}

					}
				}
			}
		}
		break;
	case 5:
		for (int i = 0;i < iterator;i++)
		{
			for (int j = iterator - 1;j > i;j--)
			{
				if (table[j]->cost < table[i]->cost)
				{
					str = table[i];
					table[i] = table[j];
					table[j] = str;

				}

			}
		}
		break;
	default:
		printf("Eror choose");
		break;
	}
		
}
void delete() {
	output();
	printf("Enter number:");
	int number = 0;
	int fl = 0;
	scanf("%d",&number);
	for (int i = 0;i < iterator;i++)
	{
		if (fl == 0) {
			if (table[i]->number == number) {
				str = table[i];
				free(str);
				table[i] = table[i + 1];
				fl = 1;
				iterator--;
			}
		}
		else {
			table[i] = table[i + 1];
		}

	}
	table[iterator]=NULL;
	
}
void edit() {
	int r = 0;
	output();
	printf("Choose number:\n");
		scanf("%d", &r);
		int i = 0;
		while (table[i]->number != r) {
			i++;
			
		}
		free(table[i]);
		table[i]=push();
		iterator--;




	
}
int main()
{
	mtrace();
	int c = 0;
	while (1) {
		printf("Choose action: \n1- push; \n2- open table; \n3- load table from file; \n4- load table in file; \n5- sortirovka; \n6- delete element; \n7-editing table\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			push();
			break;
		case 2:
			output();
			break;
		case 3:
			fileinput();
			break;
		case 4:
			fileoutput();
			break;
		case 5:
			sortirovka();
			break;
		case 6:
			delete();
			break;
		case 7:
			edit();
			break;
		default:
			break;
		}
	}
	fileinput();
	//push();
	//push();
	output();
	sortirovka();
	output();
	fileoutput();
	//char str[LEN];
	//getData(str);
	//strPack(str);
	printf("Hello");
	return 0;
}
