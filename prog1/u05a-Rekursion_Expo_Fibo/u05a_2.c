/*  
 * Beschreibung : u05a Rekursive Funktionen
 * Name         : MV
 */ 

#include <stdio.h>

/* Exponentialfunktion. Negative Exponenten werden stets wie positive behandelt.
 * Richtiges Ergebnis bei neg. Exp. mit 1/power(x, y)
 */
float power(int x, int y){

	if (y < 0)	/* Abfangen von negativen Exponenten */
		y *= -1;

	if (y == 0)
		return 1;
	else
		return power(x, --y) * x;
}

/* Berechne die n-te Stelle der Fibonacci-Folge */
int fibo(int n){
	if (n <= 1)
		return 1;
	else 
		return fibo(n-1) + fibo(n-2);
}

int main(){ 
	
	int base = 0;
	int exp = 0;
	int i;

	/* Basis und Exponent einlesen */
	printf("Potenzfunktion\n\nZur Berechnung Basis eingeben: \n");
	scanf("%i", &base);
	printf("Exponent eingeben: \n");
	scanf("%i", &exp);

	/* Berechnung */
	printf("Das ergebnis lautet: ");
	if (exp < 0)	/* Behandlung für Negative Exponenten */
		printf("%f\n\n\n", 1/power (base, exp));
	else 
		printf("%.00f\n\n\n", power (base, exp));

	printf("Fibonacci-Folge\n\nDie ersten 10 Ziffern der Fibonacci-Folge lauten: ");

	/* Berechnung und Ausgabe der ersten 10 Ziffern der Fibonacci-Folge */
	for (i = 0; i <= 9; i++){
		printf("%i ", fibo(i));
	}
	printf("\n");

	return 0;
}
