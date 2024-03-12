/*
	p06.c
*/

#include <stdio.h>

int fakul(int fakultaet);

int main()
{
	int input;
	
	printf("Berechnung der Fakultaet.\n");
	printf("Eingabe: ");
	scanf("%i", &input);

	printf("Fakultaet von %i ist %i\n", input, fakul(input));

	return 0;
}

int fakul(int fakultaet)
{
	if (fakultaet == 0)
	{
		return 1;
	}
	else
	{
		return (fakultaet * fakul(fakultaet - 1));
	}
}

