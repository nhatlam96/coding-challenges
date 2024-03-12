/*
	u09a.c
	Name:	Linus Bleyl
	Datum:	29.11.2018
*/

#include <stdio.h>

struct menu
{
	int customers;
	double calories;
	char food[64];
};

void output(struct menu *menus, int size);
void sortCalories(struct menu *menus, int size);
void sortFood(struct menu *menus, int size);
void checkFood(struct menu *a, struct menu *b, int charPos);
void change(struct menu *a, struct menu *b);
void tolowercase(char *input);
void testmix(struct menu *menus, int size);
void minmax(struct menu *menus, struct menu **pmin, struct menu **pmax, int size);

int main()
{
	struct menu *pmin;
	struct menu *pmax;
	struct menu witcheskitchen[] =
	{
		{34, 812.3, "Fledermauszaehne in Aspik mit Algenglibber"},
		{13, 77.7, "ganzer Kuerbisgeist flambiert nach Tageslaune"},
		{57, 178.178, "Huettenzauber mit Baiserhaube im Sauerampferbett"},
		{42, 737.3, "Stinkmorchel im eigenen Saft mit Pantoffelpuffern"},
		{117, 123.55, "Teufelswurz im Marzipanmantel auf Blattspinat"},
		{12, 1024.7, "Fliegenpilz am feinen Rattengift im Schmalzbad"},
		{1, 13.08, "Knoblauchzehe gut gegart an einem Hauch von Panik"}
	};
	
	printf("––– Unsortierte ausgabe\n");
	output(witcheskitchen, 7);
	
	printf("––– Sortierung nach Kalorien\n");
	sortCalories(witcheskitchen, 7);
	output(witcheskitchen, 7);
	
	printf("––– Sortierung nach Gerichtsnamen\n");
	sortFood(witcheskitchen, 7);
	output(witcheskitchen, 7);
	
	printf("––– Austauschen von \"f\" <-> \"n\" und \"B\" <-> \"K\"\n");
	testmix(witcheskitchen, 7);
	output(witcheskitchen, 7);
	
	minmax(witcheskitchen, &pmin, &pmax, 7);
	
	printf("––– Gericht mit geringsten Kalorien\n");
	printf("Kunden: %3i \tKalorien: %.3lf \t Gericht: %s\n\n", 
			pmin->customers, pmin->calories, pmin->food);
	
	printf("––– Gericht mit den meisten Kaeufern\n");
	printf("Kunden: %3i \tKalorien: %.3lf \t Gericht: %s\n", 
			pmax->customers, pmax->calories, pmax->food);
	
	return 0;
}

/*
	Ausgabe eines "struct menu" arrays
*/
void output(struct menu *menus, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("Kunden: %3i \tKalorien: %.3lf \t Gericht: %s\n", 
			(menus + i)->customers, (menus + i)->calories, (menus + i)->food);
	}
	printf("\n");
}

/*
	Sortierung nach Kalorien
	Bubble sort algorithm
	"size" als Laufvariable	
*/
void sortCalories(struct menu *menus, int size)
{
	while(size--)
	{
		for(int i = 0; i < size; i++)
		{
			if ((menus + i)->calories > (menus + i + 1)->calories)
			{
				change(menus + i, menus + i + 1);
			}
		}
	}
}

/*
	Sortierung nach namen des Gerichts
	Bubble sort algorithm
	"size" als Laufvariable
*/
void sortFood(struct menu *menus, int size)
{
	while(size--)
	{
		for(int i = 0; i < size; i++)
		{
			checkFood(menus + i, menus + i + 1, 0);
		}
	}
}

/*
	Rekusive funktion zum sortieren der Gerichte nach namen
	Rekusiver aufruf nur wenn buchstaben an position "charPos"
	die selben sind, so lange bis eine position erreicht wurde
	in der unterschiedliche buchstaben stehen.
	
*/
void checkFood(struct menu *a, struct menu *b, int charPos)
{
	char food1Char = a->food[charPos]; // Zwischenspeichern des chars an position charPos
	char food2Char = b->food[charPos]; // um manipulationen zum vergleichen vorzunehmen
	tolowercase(&food1Char);	// Gross- zu Kleinbuchstaben umwandeln
	tolowercase(&food2Char);	// um richtig sortieren zu koennen
	if (food1Char == '\0' || food2Char == '\0')
	{
		return;
	}
	else if (food1Char == food2Char) 
		// Rekusiver aufruf sollte an aktueller position die selben buchstaben sein
	{
		checkFood(a, b, charPos + 1);
	}
	else if (food1Char > food2Char)
	{
		change(a, b);
	}
}

/*
	Tauscht die positionen der beiden gegebenen parameter aus
*/
void change(struct menu *a, struct menu *b)
{
	struct menu backup = *a;
	*a = *b;
	*b = backup;
}

/*
	Hilfsfunktion um Gross- in Kleinbuchstaben zu tauschen
*/
void tolowercase(char *input)
{
	if (*input >= 'A' && *input <= 'Z')
	{
		*input += ('a' - 'A');
	}
}

/*
	Austauschen von "n" <-> "f" und "B" <-> "K"
*/
void testmix(struct menu *menus, int size)
{
	while(size--)
	{
		for (int i = 0; (menus + size)->food[i] != '\0'; i++)
		{
			if (*((menus + size)->food + i) == 'f')
			{
				*((menus + size)->food + i) = 'n';
			}
			else if (*((menus + size)->food + i) == 'n')
			{
				*((menus + size)->food + i) = 'f';
			}
			else if (*((menus + size)->food + i) == 'B')
			{
				*((menus + size)->food + i) = 'K';
			}
			else if (*((menus + size)->food + i) == 'K')
			{
				*((menus + size)->food + i) = 'B';
			}
		}
	}
}

/*
	pmin = Raussuchen des gerichtes mit den wenigsten Kalorien
	pmax = Raussuchen des gerichtes mit den meisten Kaeufern
*/
void minmax(struct menu *menus, struct menu **pmin, struct menu **pmax, int size)
{
	*pmin = menus;
	*pmax = menus;
	for (; size > 0; size--)
	{
		for (int i = 0; i < size; i++)
		{
			/* 
				Bei "(*pmin)->" sind die Klammern wichtig
				da es sich um einen pointer handelt der auf einen
				pointer zeigt
			*/
			if ((menus + i)->calories < (*pmin)->calories)
			{
				*pmin = (menus + i);
			}
			if ((menus + i)->customers > (*pmax)->customers)
			{
				*pmax = (menus + i);
			}
		}
	}
}


