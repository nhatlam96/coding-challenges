/* 2015-11-03_u05a.c
* Beschreibung:	Aufgabe u05a - Rekursive Funktionen, Fibonacci Zahlenfolge
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
#include <stdbool.h>

/* Fibonacci Wert für Parameter berechnen.  */
int fibo(int n){

	if(n == 0){
		/* Vordefinierter Fall. */
		return 0;
	}else if(n == 1){
		/* Vordefinierter Fall. */
		return 1;
	}else if(n > 1){
		/* Rekursiv unser Ergebnis berechnen. */
		return fibo(n-1)+ fibo(n - 2);
	}else {
		/* Vordefinierter Fall. */
		return 0;
	}

}



/* Rekursive Funktion zur Potenzbildung */
int power(int x, int y, int ergebnis){
	/* Exponent um 1 dekrementieren */
	y--;
	if(x < 0){
		/* Handling fuer negative Zahlen */
		ergebnis = ergebnis * (-x);
	}else {
		/* Handling fuer positive Zahlen */
		ergebnis = ergebnis * x;
			
	}

	/* Pruefung, ob wir fertig sind. */
	if(y == 1){
		/* Fertig? Ergebnis zurueckgeben - Rekursion beenden! */
		return ergebnis;	
	}else {
		/* Nicht fertig? Mit Rekursion fortfahren! */
		return power (x, y, ergebnis);
	}

}



int main() {

	/* Variablen initialisieren */
	int x;
	int y;
	double ergebnis;
	int counter;
	bool exponent_negativ = false;

	/* Benutzereingaben einlesen*/

	printf("x eingeben\n");
	scanf("%i", &x);
	printf("y eingeben\n");
	scanf("%i", &y);

	if(y < 0){
		/* Handling für negtiven Exponent - wir machen ihn einfach positiv */
		exponent_negativ = true;
		y = y * (-1);
	}

	/* Ergebnis berechnen - ab hier bereits double verwenden fuer Ergebnisse negativer Exponenten */
	ergebnis = (double) power(x, y, x);

	if(exponent_negativ){
		/* Ergebnis fuer negativen Exponenten korrigieren */		
		ergebnis = 1 / ergebnis;
	}

	/* Ergebnis ausgeben */
	printf("Ergebnis: %lf\n", ergebnis);

	/* Fibonacci Reihenfolge berechnen- und ausgeben - stoppen bei 55 */
	for(counter = 0;counter<=10;counter++){

		ergebnis = (double) fibo(counter);
		printf("fibonacci von %i ist %lf\n", counter, ergebnis);
		
	}

	


	printf("\nProgrammende\n");
	

	
	return 0;
}
