/*
	u07a.c
	Name: 	Linus Bleyl
	Datum: 	13.11.2018
*/

#define MaxInput 32 // Setzt die maximale Anzahl an Zeichen für den input 

#include <stdio.h>
#include <string.h>

int xstrnlen(char s[], int n);
char * xstrncpy(char destination[], char source[], int n);
char * xstrncat(char destination[], char source[], int n);
int xstrncmp(char a[], char b[], int n);

int main()
{
	char input[MaxInput], comp[MaxInput];
	char cpy[MaxInput], cpy2[MaxInput], cpy3[MaxInput], cpy4[MaxInput];
	char cat[MaxInput * 2], cat2[MaxInput * 2], cat3[MaxInput * 2], cat4[MaxInput * 2];
	
	int maxN = 0;

	// ––– Sorgt fuer gleiche Bedingungen bei allen Funktionstests
	for(int i = 0; i < MaxInput; i++)
	{
		cpy[i] = cpy2[i] = cpy3[i] = cpy4[i] = '\0';
	}
	for(int x = 0; x < MaxInput * 2; x++)
	{
		cat[x] = cat2[x] = cat3[x] = cat4[x] = '\0';
	}
	// –––

	printf("Bitte nachfolgend zwei Woerter mit maximal %i Zeichen eingeben.\n", MaxInput);
	printf("Eingabe a: ");
	scanf("%s", input);
	printf("Eingabe b: ");
	scanf("%s", comp);
	
	printf("\nBitte maximale Anzahl an zu bearbeitende Zeichen angeben. (0 < n < %i)\n", MaxInput);
	printf("Eingabe n: ");
	scanf("%i", &maxN);
	
	// ––– Sicherstellen das maxN den bedingungen (0 < n < MaxInput) entspricht.
	if (maxN < 0)
	{
		maxN = 0;
	}
	else if (maxN > MaxInput)
	{
		maxN = MaxInput;
	}
	// –––
	
	xstrncpy(cpy, input, maxN);
	xstrncpy(cpy2, input, sizeof(cpy));
	strncpy(cpy3, input, maxN);
	strncpy(cpy4, input, sizeof(cpy));
	
	// ––– Kopien zum testen von xstrncat() und strncat()
	xstrncpy(cat, input, sizeof(cpy));
	xstrncpy(cat2, input, sizeof(cpy));
	xstrncpy(cat3, input, sizeof(cpy));
	xstrncpy(cat4, input, sizeof(cpy));
	// –––
	
	xstrncat(cat, input, maxN);
	xstrncat(cat2, input, sizeof(cat2));
	strncat(cat3, input, maxN);
	strncat(cat4, input, sizeof(cat4));

	printf("\n");
	printf("Punkt 1) ist jeweils die selbst erstellte Funktion mit n = %i.\n", maxN);
	printf("Punkt 2) ist jeweils die selbst erstellte Funktion mit sizeof(array).\n");
	printf("Punkt 3) ist jeweils die in string.h verfügbaren Funktionen mit n = %i.\n", maxN);
	printf("Punkt 4) ist jeweils die in string.h verfügbaren Funktionen mit sizeof(array).\n");
	printf("\n");

	printf("––– Laenge | xstrnlen() –––\n");
	printf("Eingabe a: \t%s\n", input);
	printf("1) xstrnlen: \t%i\n", (int)xstrnlen(input, maxN));
	printf("2) xstrnlen: \t%i\n", (int)xstrnlen(input, sizeof(input)));
	printf("3) strnlen: \t%i\n", (int)strnlen(input, maxN));
	printf("4) strnlen: \t%i\n", (int)strnlen(input, sizeof(input)));
	
	printf("\n––– Kopien | xstrncpy –––\n");	
	printf("Eingabe a: \t|%s|\n", input);
	printf("1) xstrncpy: \t|%s|\n", cpy);	
	printf("2) xstrncpy: \t|%s|\n", cpy2);
	printf("3) strncpy: \t|%s|\n", cpy3);
	printf("4) strncpy: \t|%s|\n", cpy4);

	printf("\n––– Zusammenfuegen | xstrncat –––\n");	
	
	printf("1) xstrncat: \t|%s|\n", cat);
	printf("2) xstrncat: \t|%s|\n", cat2);
	printf("3) strncat: \t|%s|\n", cat3);
	printf("4) strncat: \t|%s|\n", cat4);

	printf("\n––– Vergleicht Eingabe a und b | xstrncmp() –––\n");
	printf("0 →  Gleich | a < b →  negativ | a > b →  positiv\n");
	printf("1) xstrncmp: \t%i\n", xstrncmp(input, comp, maxN));
	printf("2) xstrncmp: \t%i\n", xstrncmp(input, comp, sizeof(input)));
	printf("3) strncmp: \t%i\n", strncmp(input, comp, maxN));
	printf("4) strncmp: \t%i\n", strncmp(input, comp, sizeof(input)));
	
	return 0;
}

int xstrnlen(char s[], int n)
{
	int length = 0;

	for(; length < n; length++)
	{
		if (s[length] == '\0')
		{
			break;
		}
	}

	return length;
}

char * xstrncpy(char destination[], char source[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((destination[i] = source[i]) == '\0')
		{
			break;
		}
	}
	
	return destination;
}

char * xstrncat(char destination[], char source[], int n)
{
	int i = 0, x = 0;

	for (; destination[x] != '\0'; x++);

	for (; i < n; i++)
	{
		if (source[i] == '\0')
		{
			break;
		}
		destination[x + i] = source[i];
	}
	
	destination[x + i] = '\0'; // Nullbyte am Ende anfuegen

	return destination;
}

int xstrncmp(char a[], char b[], int n)
{
	int i = 0;

	for (; i < n; i++)
	{
		if (a[i] != b[i])
		{
			return a[i] - b[i];
		}

		if (a[i] == '\0')
		{
			return 0;
		}
	}
	/*
		Dieser Punkt wird nur bei Ueberlauf (i >= n) erreicht.
		Da ab diesem Punkt (i == n) ist muss i um 1 reduziert werden.
	*/
	i--;
	
	return a[i] - b[i];
}

