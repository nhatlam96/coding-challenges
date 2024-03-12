/*
 * Verschiedene Methoden zur Arbeit auf
 * Integer-Arrays
 *
 * 19.11.18 -- Robin Eschbach
 */

#include <stdio.h>

void ausgabe(int *array, int length) {
	printf("\nDas Array ist: {");
	int *pointer = array;
	/* Der Esthetik wegen wird nur bis zum Vorletzten gelaufen */
	while(pointer - array < length -1) {
		printf("%i, ", *pointer);
		pointer++;
	}
	printf("%i}\n", *pointer);
}

void tausche(int *pointer1, int *pointer2) {
	/* Tauschen der Werte ohne Hilfsvariable */
	/* bsp:
 	 * a = 5
 	 * b = 7
	 */
	*pointer1 = *pointer1 + *pointer2;	/* a = 5 + 7 = 12 */
	*pointer2 = *pointer1 - *pointer2;	/* b = 12 - 7 = 5 */
	*pointer1 = *pointer1 - *pointer2;	/* a = 12 - 5 = 7 */
}

void umkehren(int *array, int length) {
	int counter = 0;
	/* Nur bis zur Haelfte laufen, danach ist umgekehrt */
	while(counter < length / 2) {
		tausche(array + counter, array + length - counter - 1);
		counter++;
	}
}

int mini(int *array, int length) {
	int min = *array;
	for(int i = 0; i < length; i++) {
		/* Tenaryoperator fuer verkuerztes if */
		min = *array < min ? *array : min;
		array++;
	}
	return min;
}

int maxi(int *array, int length) {
	int max = *array;
	for(int i = 0; i < length; i++) {
		/* Tenaryoperator fuer verkuerztes if */
		max = *array > max ? *array : max;
		array++;
	}
	return max;
}

int main() {
	int intArr[10] = {113, 22, 75, 43, 3, 42, 243, 8764, 32, 11};

	ausgabe(intArr, 10);
	umkehren(intArr, 10);
	ausgabe(intArr, 10);

	printf("\nDer kleinste Wert ist: %i\n", mini(intArr, 10));
	printf("\nDer groesste Wert ist: %i\n", maxi(intArr, 10));

	tausche(&intArr[0], &intArr[5]);

	return 0;
}
