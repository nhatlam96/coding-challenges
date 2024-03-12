/* 2015-11-23_u07a.c
* Beschreibung:	Aufgabe u07a - CharArrays Palindrome Quersumme
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>

/* Bestimmt die laenge eines CharArrays */
int mystrlen(char array[]){

	int laenge = 0;
	char charcurrent;
	do{
		charcurrent = array[laenge];
		laenge++;
	}while(charcurrent != '\0');

	return laenge;
}

/* Bildet das Palindrom zum Inhalt eines CharArrays */
char* palindrom(char array_source[], char array_pali[]){
		/* Variablen initialisieren bzw besetzen */
		int counter_total = 0;
		int counter = 0;
		int size_source = mystrlen(array_source);
		char char_tmp;

		/* Array in anderes Array 'kopieren' */
		do{
			char_tmp = array_source[counter];

			/* Handling fuer Ende des Quell-Arrays */
			/* Nur mit Ueberpruefung auf EOF klappte es nicht. */
			if(char_tmp == EOF || char_tmp == '\0'){
				break;
			}

			array_pali[counter] = char_tmp;
			counter++;
			counter_total++;
					
		}while(counter < size_source);

		/* Wir sind oben beim EOF stehen geblieben --> Brauchen wir an dieser Stelle nicht im anderen Array */
		counter--;

		/* Nun das Quell array 'falsch herum' in das neue Array einfuegen */
		do{
			char_tmp = array_source[counter];

			array_pali[counter_total] = char_tmp;
			counter--;
			counter_total++;
					
		}while(counter > -1);
		/* Ende des Palindrom-Arrays mit Nullbyte bestimmen */
		array_pali[counter_total] = '\0';
		
		return array_pali;
	}

/* Bildet das Palindrom zum Inhalt eines CharArrays */
int quersumme(char array_zahlen[]){
		/* Variablen initialisieren bzw besetzen */
		int counter = 0;
		short quersumme_summe = 0;
		int size_source = mystrlen(array_zahlen);
		int int_temp = 0;
		char char_tmp;

		do{
			char_tmp = array_zahlen[counter];

			/* Handling fuer Ende des Quell-Arrays */
			/* Nur mit Ueberpruefung auf EOF klappte es nicht. */
			if(char_tmp == EOF || char_tmp == '\0'){
				break;
			}
			int_temp = (int) char_tmp - '0';
			printf("\ndebug_int%i\n", int_temp);
			printf("\ndebug_char%c\n", char_tmp);
			quersumme_summe += int_temp;

			counter++;
					
		}while(counter <= size_source);
		
		return quersumme_summe;
	}



int main() {

	/* Variablen initialisieren */
	/* Als 'ausreichende' Array Groeße nehmen wir 6, da damit die Beispiele in der Aufgabenstellung funktionieren */
	int arraySize_part_a = 6;
	int arraySize_part_b = 11;
	char array1 [arraySize_part_a];
	/* array2 ehthaelt spaeter unser Palindrom, muss also ggf doppelt
	 * so viele Zeichen fassen koennen als der Benutzer maximal eingeben darf. */
	char array2 [arraySize_part_a * 2];
	char array3 [arraySize_part_b];
	char eingabe;
	int counter = 0;
	int quersumme_ergebnis;


	/* Aufgabe Teil a */
	/* Benutzereingabe einlesen */
	printf("Bitte geben Sie das Wort zur Palindrombildung ein:\n");
	do{
		eingabe = getchar();
		array1[counter] = eingabe;
		counter++;
	}while(counter < arraySize_part_a);

	/* Nullbyte korrekt setzen */
	array1[arraySize_part_a - 1] = '\0';
	/* Palindrom mit der Funktion erzeugen und 'abholen'. */
	char* arrayreturn = palindrom(array1, array2);	
	printf("Das Palindrom lautet: %s\n", arrayreturn);



	/* Aufgabe Teil b */
	/* Wir recyclen Variablen --> Diese Zuruecksetzen */
	counter = 0;
	/* Benutzereingabe einlesen */
	printf("Bitte geben Sie 10 Zahlen zur Quersummenbildung ein:\n");
	do{
		eingabe = getchar();
		/* Hier oder spaeter in der Quersummenberechnung koennte man noch 
		 * Fehlerbehandlung fuer Zeichen einbauen, die eben keine Ziffern sind.
		 */
		array3[counter] = eingabe;
		counter++;
	}while(counter <= arraySize_part_b);

	/* Nullbyte korrekt setzen */
	array3[arraySize_part_b - 1] = '\0';
	quersumme_ergebnis = quersumme(array3);	

	printf("Die Quersumme lautet: %i\n", quersumme_ergebnis);

	


	printf("\nProgrammende\n");

	return 0;
}
