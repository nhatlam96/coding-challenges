/* 2015-12-13_u09a.c
* Beschreibung:	Aufgabe u09a
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
#include <stdlib.h>

void ausgabe(int * pointer_array, int count){

	printf("DEBUG_count: %i\n", count);

	int i;
	for(i =0;i<count;i++){
		printf("DEBUG_i: %i\n", i);
		printf("%i\n", *(pointer_array + i));
	}


}

void tausche(int * pointer_1, int * pointer_2){

	int wert = *pointer_1;

	*pointer_1= *pointer_2;
	
	*pointer_2 = wert;


}

void sortiere(int * pointer_array, int count){

	int n;
	int i;

	/* Bubblesort Algorithmus (unoptimiert) */
	for(n = count; n>1;n--) {
		for(i = 0; i<n-1; i++){
			if(*(pointer_array+i) > * (pointer_array+i+1)){
				tausche(pointer_array+i, pointer_array+i+1);
			}

		}
		
	}

}


int main() {

	/* Variablen initialisieren */
	int *pointer_array;
	int array [10] = {119, 61, 0, 32, 7, 42, 243, 8329, 32, 78};

	/* Ich verstehe nicht, warum nicht nur 'sizeof(array)' reicht. */
	int array_size = sizeof(array) / sizeof(array[0]);

	pointer_array = (int *) malloc(array_size * 10);
	pointer_array = array;

	/* Array sortieren */
	sortiere(pointer_array, array_size);
	/* Sortiertes Array ausgeben */
	ausgabe(pointer_array, array_size);

	printf("\nProgrammende\n");

	return 0;
}
