/* 
 * Dateiname:		obase.c
 * Beschreibung:	Rechner fuer diverse Zahlensysteme
 * Datum:			29.05.2016, 11.06.2016 (bearbeitet).
 * Ersteller:		Arthur Baer
*/

#include <stdio.h>
#include <stdlib.h>

/* Berechnung Dezimal zu Binaer (rekursiv). */
void bin (int dez){
	if (dez != 0 && dez != 1){
		bin(dez/2);
	}
	printf("%i", dez%2);
}

/* Berechnung Dezimal zu Hexadezimal (rekursiv). */
void hex (int dez){
	if (dez != 0 && !(dez <= 15)){
		hex(dez/16);
	}
	if (dez%16 < 10) printf("%i", dez%16);
	if (dez%16 > 9) printf("%c", dez%16 + 55);
}

/* Berechnung Dezimal zu Octal (rekursiv). */
void oct (int dez){
	if (dez != 0 && !(dez <= 7)){
		oct(dez/8);
	}
	printf("%i", dez%8);
}


int main(){
	int dez;
	char c;
	/* Menueausgabe und Nutzerabfrage. */
	system("clear");
	printf("Zum Beenden 'q' eingeben.\n\n");
	printf("Geben Sie eine Dezimalzahl ein: ");
	scanf("%i", &dez);
	/* Abfangen von negativen Zahlen. */
	if(dez < 0) dez *= -1;
	/* Nutzerabfrage bis Nutzer 'q' eingibt. */
	do{
		c = getchar();
		system("clear");
		if(c == 'q') break;
		/* Aufrufen der Funktionen und Ausgabe der Berechnungen. */
		printf("Dezimal '%i' ergibt:\n", dez);
		printf("Binaer: ");
		bin(dez);
		printf("\nHexadezimal: ");
		hex(dez);
		printf("\nOctal: ");
		oct(dez);
		/* Nutzerabfrage. */
		printf("\nGeben Sie eine Dezimalzahl ein: ");
		scanf("%i", &dez);
		/* Abfangen von negativen Zahlen. */
		if(dez < 0) dez *= -1;
	}while(c != 'q');
	return 0;
}
