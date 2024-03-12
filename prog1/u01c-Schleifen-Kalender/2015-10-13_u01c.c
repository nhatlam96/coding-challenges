/* 2015-10-13_u01c.c
* Beschreibung:	Drittes C Programm - Anmerkung - in der PDF der Aufgabe u01b ist ein Fehler "Farmatstring" statt "Formatstring".
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
int main() {
	/*Variablen ohne Initialisierung*/
	int monat;
	int anzahl_tage;
	int tag_current;

	for(monat = 1;monat <=12;monat++){

	if(monat == 4 || monat == 6 || monat == 9 || monat == 11){
	/*In einigen Faellen haben wir 30 Tage*/
		anzahl_tage = 30;

	} else if(monat == 2){

		/*Februar - der Spezialfall, den es nur 1x gibt*/
		anzahl_tage = 28;
	} else {
		/*Meistens haben wir 31 Tage*/
		anzahl_tage = 31;

	}

	printf("Momentaner Monat: %i\n", monat);
	for(tag_current = 1;tag_current <= anzahl_tage;tag_current++){

		/*Den Wert + TAB damit es schoen aussieht*/
		printf("%i	", tag_current);

	}

	printf("\n");

	}
	
	return 0;
}
