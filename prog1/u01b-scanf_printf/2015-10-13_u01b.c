/* 2015-10-13_u01b.c
* Beschreibung:	Zweites C Programm
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
int main() {
	/*Variablen mit Initialisierung*/
	int variable_i = 0;
	long variable_l = 0;
	float variable_f = 0.0;
	double variable_d = 0.0;
	char variable_c = ' ';

	/*Inhalt der Variablen ausgeben*/
	printf("Ausgabe einer Variable vom Typ Integer: %i\n", variable_i);
	printf("Ausgabe einer Variable vom Typ Long: %li\n", variable_l);
	printf("Ausgabe einer Variable vom Typ Float: %f\n", variable_f);
	printf("Ausgabe einer Variable vom Typ Double: %lf\n",variable_d);
	printf("Ausgabe einer Variable vom Typ Char: %c\n", variable_c);

	printf("int Wert eingeben:\n");
	scanf("%i", &variable_i);

	printf("long Wert eingeben:\n");
	scanf("%li", &variable_l);

	printf("float Wert eingeben:\n");
	scanf("%f", &variable_f);

	printf("double Wert eingeben:\n");
	scanf("%lf", &variable_d);

	printf("char Wert eingeben:\n");
	scanf("%c", &variable_c);
	/*Zweite Abfrage = Workaround fuer line discipline Problem*/
	scanf("%c", &variable_c);
	// c = getchar();

	printf("Hallo Welt!\n");

	/*Inhalt der Variablen ausgeben*/
	printf("Ausgabe einer vom benutzer eingegebenen Variable vom Typ Integer: %i\n", variable_i);
	printf("Ausgabe einer vom benutzer eingegebenen Variable vom Typ Long: %li\n", variable_l);
	printf("Ausgabe einer vom benutzer eingegebenen Variable vom Typ Float: %f\n", variable_f);
	printf("Ausgabe einer vom benutzer eingegebenen Variable vom Typ Double: %lf\n",variable_d);
	printf("Ausgabe einer vom benutzer eingegebenen Variable vom Typ Char: %c\n", variable_c);
	
	return 0;
}
