/* 2015-11-29_u08b.c
* Beschreibung:	Aufgabe u08b
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void replaceWord(char work [], char find [], char subst []){

	char helper [100];

	char temp1;
	char temp2;
	int counter1 = 0;
	int counter2 = 0;

	//int size_work = strlen(work);
	int size_find = strlen(find);
	int size_subst = strlen(subst);

	bool indexreplace_found = false;
	bool found_word = false;
	int indexreplace = 0;
	int indexreplace_length = 0;

	do{

		temp1 = work[counter1];
		temp2 = find[indexreplace_length];

		/* Ende eines Arrays erreicht? Stoppen! */
		if(temp1 == '\0' || temp2 == '\0'){
			break;
		}

		if(temp1 == temp2){
			if(indexreplace_found){
				/* Nix */
			} else {
				indexreplace = counter1;
				indexreplace_found = true;
			}
			indexreplace_length++;
		}else if(temp1 != temp2 && indexreplace_found){
			indexreplace = 0;
			indexreplace_length = 0;	
			indexreplace_found = false;
		}

		counter1++;


	}while(true); /* Fehlerbehandlung ist oben im Code. Alles hier abzufangen waere ggf zu fehleranfaellig. */
	
	/* Ueberpruefen, ob das zu ersetzende Wort ueberhaupt im Array 'work' existiert */
	found_word = (indexreplace_length == size_find);
	printf("\nGroesse: %i\n", size_find);

	/* Wort gefundne? Ersetzen durch zweites Wort! */
	if(found_word){
		/* Erstmal das Array fuellen bis eine Stelle vor dem zu ersetzenden Wort! */
		while(counter2 < indexreplace){
			temp1 = work[counter2];
			helper[counter2] = temp1;
			counter2++;
		}

		/* Jetzt das neue Wort einfuegen. */
		strcat(helper, subst);
		/* Jetzt den Rest von Quell-Array dahinter 'kleben' */
		/* Der Index des helper Arrays verschiebt sich durch das hinzugefuegte Wort. */
		counter2+= size_subst;
		do{
			temp1 = work[counter1];
			helper[counter2] = temp1;
			counter1++;
			counter2++;
		}while(temp1 != '\0');
	}else {
		/* Wort nicht gefunden? Nichts tun! */
	}

	printf("Die modifizierte Variable lautet:\n\n%s", helper);

	//pointerwork = &helper;


}


int main() {

	/* Variablen initialisieren */
	char arraywork [100] = {"Heute back ich, morgen schlaf ich, uebermorgen ...\0"};
	char arrayfind [] = {"schlaf\0"};
	char arraysubst [] = {"strick\0"};
	char arraywork2 [100] = {"Heute back ich, morgen strick ich, uebermorgen ...\0"};
	char arrayfind2 [] = {"strick\0"};
	char arraysubst2 [] = {"schlaf\0"};

	//char *pointer_arraywork = arraywork;

	replaceWord(arraywork, arrayfind, arraysubst);

	replaceWord(arraywork2, arrayfind2, arraysubst2);

	//printf("Geaenderter String: %s\n", pointer_arraywork);

	printf("\nProgrammende\n");

	return 0;
}
