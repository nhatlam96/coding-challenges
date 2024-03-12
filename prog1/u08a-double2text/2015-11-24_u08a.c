/* 2015-11-24_u08a.c
* Beschreibung:	Aufgabe u08a
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void double2text(float floatvar, char *charzeiger){

	/* float --> Char als Einzeiler - NICHT DIE VOM PROF ERWARTETE LÖSUNG!! */
	sprintf(charzeiger, "%f", floatvar);

	//return charzeiger;
	
}

/* Text zu double */
void text2double(char array[], float *floatzeiger){

	/* CharArray --> Double Wert */
	int index = strlen(array);
	bool positive = false;
	bool after_comma = false;
	char char_tmp;
	int int_temp = 0;
	int int_temp_after_comma = 0;
	double double_ergebnis = 0;

	do{
		char_tmp = array[index];
		/* Minus-Erkennung */
		if(char_tmp == '-'){
			positive = false;
			index--;
			continue;
		}else if(char_tmp == '+'){
			/* Plus-Erkennung */
			positive = true;
			index--;
			continue;
		}else if(char_tmp == '.'){
			/* Koma-Erkennung */
			after_comma = true;
			index--;
			continue;
		}
		int_temp = char_tmp - '0';
		if(after_comma){
			/* Zahl vor dem Komma (da wir von "hinten" anfangen quasi NACH dem Komma) */
			int_temp_after_comma *= 10;
			int_temp_after_comma += int_temp;
		}else{
			/* Die eigentliche Kommazahl */
			if(double_ergebnis != 0){
				double_ergebnis = double_ergebnis / 10;
			}
			double_ergebnis += (double) int_temp / 10;
		}
		index--;
	}while(index > -1);

	/*Double Wert vervollständigen*/
	double_ergebnis += int_temp_after_comma;
	/* Negative Zahl? --> Negativ machen! */
	if(!positive) double_ergebnis = double_ergebnis * (-1);

	*floatzeiger = double_ergebnis;
	
}


int main() {

	/* Variablen initialisieren */
	char zeichenkette [11];
	char zeichenkette2 [11];
	char *pointer_zeichenkette = zeichenkette;
	float floatvar;
	float floatvar2;
	float *pointer_floatvar2 = &floatvar2;
	

	/* Benutzereingaben einlesen */
	printf("Bitte geben Sie einen double Wert ein:\n");
	scanf("%f", &floatvar);
	/* Berechnungen durchführen */
	double2text(floatvar, pointer_zeichenkette);
	/* Ergebnisse Ausgeben */
	printf("Double als Text: %s\n", pointer_zeichenkette);

	/* Benutzereingaben einlesen */
	printf("Text eingeben:\n");

	scanf("%s", zeichenkette2);
	/* Berechnungen durchführen */
	text2double(zeichenkette2, pointer_floatvar2);
	/* Ergebnisse Ausgeben - Ausgabe wird ca ab der fünften Stelle ungenau. */
	printf("Text als double: %f", *pointer_floatvar2);


	


	printf("\nProgrammende\n");

	return 0;
}
