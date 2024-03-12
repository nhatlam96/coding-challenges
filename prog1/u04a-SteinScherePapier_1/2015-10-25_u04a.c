/* 2015-10-25_u04a.c
* Beschreibung:	Aufgabe u04a - enum und switch, Zufallszahlengenerator
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

/* Funktion um die Zuordnung von int:NameDerAuswahl zu vereinfachen.
 * Man koennte das auch im switch unten tun aber es wuerde unuebersichtlich werden.
 */
void ausgabeAuswahl(int state_random){

	switch(state_random){

	case 0:
		printf("Stein");
		break;
		
	case 1:
		printf("Schere");
		break;

	case 2:
		printf("Papier");
		break;

	case 3:
		printf("Echse");
		break;

	case 4:
		printf("Spock");
		break;

	default:
		/* Das sollte niemals passieren */
		printf("Ungueltiger Status");
		break;
	
	}

	printf("\n");	
	
}


int main() {

	enum states {stein, schere, papier, echse, spock};

	/* Variablen initialisieren */
	int p1;
	int p2;
	bool gleichstand = false;
	bool p1_wins = false;
	/* Zufallszahlengenerator initialisieren */
	srand(time(NULL));


	/* Do-While Schleife in Verwendung, da Ende nicht absehbar. */
	do{
		/* Neues Spiel neues 'Glueck' - Variablen zuruecksetzen */
		gleichstand = false;
		p1_wins = false;

		/* Den Spielern zufaellige int Werte zuweisen */
		p1 = rand() % 4;
		p2 = rand() % 4;

		printf("Spieler 1: ");
		ausgabeAuswahl(p1);
		printf("Spieler 2: ");
		ausgabeAuswahl(p2);

		if(p1 == p2){
			gleichstand = true;
			//continue;
		}

	/* Logik um den Gewinner zu ermitteln - bei Gleichstand wird diese auch durchlaufen, ist aber 		irrelevant, da die Ausgabe erst unten geschieht. */
	switch(p1){

	case 0:

		if(p2 == 1 || p2 == 3){
			p1_wins = true;
		}else{
			p1_wins = false;
		}
		
		break;
		
	case 1:
		if(p2 == 2 || p2 == 3){
			p1_wins = true;
		}else{
			p1_wins = false;
		}
		break;

	case 2:
		if(p2 == 0 || p2 == 4){
			p1_wins = true;
		}else{
			p1_wins = false;
		}
		break;

	case 3:
		if(p2 == 2 || p2 == 4){
			p1_wins = true;
		}else{
			p1_wins = false;
		}
		break;

	case 4:
		if(p2 == 0 || p2 == 1){
			p1_wins = true;
		}else{
			p1_wins = false;
		}
		break;

	default:
		/* Das sollte niemals passieren */
		printf("Ungueltiger Status");
		break;
	
	}

	if(gleichstand){
		printf("Gleichstand - neue Runde :)");
	}else if(p1_wins){
		printf("Spieler 1 gewinnt:\n");
		ausgabeAuswahl(p1);
		printf("vs\n");
		ausgabeAuswahl(p2);
	}else{
		printf("Spieler 2 gewinnt:\n");
		ausgabeAuswahl(p2);
		printf("vs\n");
		ausgabeAuswahl(p1);
	}
	
	printf("\n");





		/* Bei Gleichstand wiederholen */
	}while(gleichstand);

	printf("Programmende");
	

	
	return 0;
}
