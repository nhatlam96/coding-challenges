/*
 * Erstellt ein zufaelliges Array und sucht auf diesem
 *
 * 25.11.12 -- Robin Eschbach
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void ausgabe(int * intArr, int arrSize) {
	printf("\nDas Array ist:\n");
	for(int i = 0; i < arrSize; i++) {
		printf("%5i ", *(intArr + i));
		if(i % 10 == 9) {
			printf("\n");
		}
	}
}

void init(int * intArr, int arrSize) {
	static bool ranInit = false;

	if(!ranInit) {
		srand(time(NULL));
		ranInit = true;
	}

	for(int i = 0; i < arrSize; i++) {
		*(intArr + i) = (rand() % 10000) + 1;
	}
}

int suche(int * intArr, int arrSize, int zuSuchen) {
	for(int i = 0; i < arrSize; i++) {
		if(*(intArr + i) == zuSuchen) {
			return i;
		}
	}
	return -1;
}

int main() {
	int intArr[1000];
	init(intArr, 1000);
	ausgabe(intArr, 1000);

	printf("\nGib eine Zahl ein, die gesucht werden soll: ");
	int zuSuchen = 0;
	scanf("%i", &zuSuchen);
	int pos = suche(intArr, 1000, zuSuchen);
	if(pos == -1) {
		printf("\nDeine Zahl wurde nicht gefunden.\n");
	} else {
		printf("\nDeine Zahl wurd an Position %i gefunden.\n", pos);
	}
}
