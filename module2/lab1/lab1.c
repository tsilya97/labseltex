
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <locale.h>
#define len1 40

int len = 40;
int brecket(char* input, char* output, int len)


{
	int indexout = 0;

	int maxnumber = 0;        
	int number = 0;            
	int indexprev = 0;           
	int index = 0;

	indexout = 0;
	int flag = 0;
	for (int i = 0; i < len;i++) {
		if (input[i] == '{') {

			number = number + 1;
			if (number > maxnumber) {
				maxnumber = number;
				index = i;
				flag = 1;
			}

		}
		if (input[i] == '}')
		{
			if (number == maxnumber && flag == 1)
			{
				indexprev = i - index + 1;
				flag = 0;
				number = number - 1;
			}
			else {
				number = number - 1;
			}
		}
		if (input[i] == '\0') {
			break;
		}
	}
	while (output[indexout] != '\0') {
		indexout++;

	}
	if (maxnumber == 0) {
		indexprev = len;

		index = 0;
		output[indexout] = ' ';
		while (index != len)
		{

			indexout++;

			output[indexout] = input[index];
			index++;

		}
		output[indexout] = '\0';
	}

	else {
		output[indexout] = ' ';
		indexout++;
		index++;
		while (input[index] != '}')
		{

			output[indexout] = input[index];
			index++;
			indexout++;
		}
		output[indexout] = '\0';
		index++;
	}



	while (input[index] != '\0') {

		input[index - indexprev] = input[index];
		index++;

	}
	len = index;
	for (index = index - indexprev;index < len;index++) {
		input[index] = '\0';

	}
	len = index - indexprev + 1;





	if (len > 1) { 


		brecket(input, output, len);
		return 1;
	}
	else {
		for (indexout;indexout < len1;indexout++) {
			output[indexout] = '\0';
		}
		for (index = 0;index < len1;index++) {
			input[index] = '\0';
		}
		return 0;
	}
}

int main(void)
{
	setlocale(LC_ALL, "Rus");
	char inputstr[len1];
	char outputstr[len1];

	printf("Enter string:");
	fgets(inputstr, len1, stdin);
	printf("click entert");
	fgets(outputstr, len1, stdin);
	brecket(inputstr, outputstr, len);
	printf("Edit string %s\n", outputstr);
	

	scanf("%s", outputstr);
	return 0;
}


