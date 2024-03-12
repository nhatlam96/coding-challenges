/* 2015-10-19_u02b.c
* Beschreibung:	Aufgabe u02b - Leerzeilenentfernung | Erkennung
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
int main() {

	/* Variablen initialisieren */
	char c;
	char speicher = ' ';


	do {

		printf("Eingabe: ");
	
		/* Benutzereingabe einlesen */
		c = getchar();
	
		printf("Ausgabe: ");
	
		switch(c){
		case '\n':
		if(speicher == '\n'){
			/* Leerzeile entdeckt --> Ueberspringen */
			continue;
		}
		break;
	
		case 'a':
		c = 'A';
		break;
	
		case 'e':
		c = 'E';
		break;
	
		case 'i':
		c = 'I';
		break;
	
		case 'o':
		c = 'O';
		break;
	
		case 'u':
		c = 'U';
		break;
	
		default:
		break;
	
		}
	
		/* Eingabe ausgeben */
		putchar(c);
	
		printf("\n");
	
		speicher = c;
	
	}while(getchar() != EOF);

	printf("Programmende");
	

	
	return 0;
}
