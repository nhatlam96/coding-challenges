/* 2015-10-27_u04b.c
* Beschreibung:	Aufgabe u04b - enum und switch, Zufallszahlengenerator, Funktionen
* Info: Habe darauf im bewerteten Praktikum 17 / 20 Punkten bekommen
* Die auswert() Funktion sollte wohl wirklich den spiele-Mechanismus beinhalten,
* den Zufallsgenerator hatte ich in spiel() initialisiert statt in der main() und
* die enums hatte ich zwar definiert aber nicht genutzt.
* Ich habe alles ausgebessert außer die auswert() Funktion außerdem gibt es die enums 2x - ich weiß nicht, ob das okay ist.	
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
	/* Variablen initialisieren bzw vorab besetzen */
	enum states {stein, schere, papier, echse, spock};

	switch(state_random){

	case stein:
		printf("Stein");
		break;
		
	case schere:
		printf("Schere");
		break;

	case papier:
		printf("Papier");
		break;

	case echse:
		printf("Echse");
		break;

	case spock:
		printf("Spock");
		break;

	default:
		/* Das sollte niemals passieren - für den Fall trotzdem eine Ausgabe zur einfacheren Fehlersuche. */
		printf("Ungueltiger Status");
		break;
	
	}

	printf("\n");	
	
}

	/* Funktion, die die Entscheidung ausgibt - entschieden wird in 'spiel()' */
int entscheid(bool gleichstand, bool p1_wins, int p1, int p2){

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

	return 0;
}

	/* Zeigt die Statistik der gezaehlten Werte an */
void auswert(int p1_wins_counter, int p2_wins_counter, int counter_stein, int counter_schere, int counter_papier, int counter_echse, int counter_spock){

	printf("Auswertung:\n");

	printf("Anzahl Spieler 1 gewonnen: %i\n", p1_wins_counter);
	printf("Anzahl Spieler 2 gewonnen: %i\n", p2_wins_counter);
	printf("Anzahl Stein: %i\n", counter_stein);
	printf("Anzahl Schere: %i\n", counter_schere);
	printf("Anzahl Papier: %i\n", counter_papier);
	printf("Anzahl Echse: %i\n", counter_echse);
	printf("Anzahl Spock: %i\n", counter_spock);

}


void spiel(){

	/* Variablen initialisieren bzw vorab besetzen */
	enum states {stein, schere, papier, echse, spock};

	int p1;
	int p2;
	int p1_wins_counter = 0;
	int p2_wins_counter = 0;
	int counter_stein = 0;
	int counter_schere = 0;
	int counter_papier = 0;
	int counter_echse = 0;
	int counter_spock = 0;
	bool gleichstand = false;
	bool p1_wins = false;


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

		/* Gleichstand Ueberpruefung */
		if(p1 == p2){
			gleichstand = true;
		}

	/* Logik um den Gewinner zu ermitteln - bei Gleichstand wird diese auch durchlaufen, ist aber irrelevant, da die Ausgabe erst unten geschieht. */
	switch(p1){

	case stein:

		if(p2 == schere || p2 == echse){
			p1_wins = true;
		}else{
			p1_wins = false;
		}

		counter_stein++;
		
		break;
		
	case schere:
		if(p2 == papier || p2 == echse){
			p1_wins = true;
		}else{
			p1_wins = false;
		}
		
		counter_schere++;

		break;

	case papier:
		if(p2 == stein || p2 == spock){
			p1_wins = true;
		}else{
			p1_wins = false;
		}

		counter_papier++;

		break;

	case echse:
		if(p2 == stein || p2 == spock){
			p1_wins = true;
		}else{
			p1_wins = false;
		}

		counter_echse++;

		break;

	case spock:
		if(p2 == stein || p2 == schere){
			p1_wins = true;
		}else{
			p1_wins = false;
		}

		counter_spock++;

		break;

	default:
		/* Das sollte niemals passieren */
		printf("Ungueltiger Status");
		break;
	
	}

	entscheid(gleichstand, p1_wins, p1, p2);

	if(p1_wins){
		p1_wins_counter++;	
	}else{
		p2_wins_counter++;	
	}
	
	printf("\n");





	/* Bei Gleichstand wiederholen - abbrechen sobald Spieler eins 5x gewonnen hat. */
	}while(gleichstand || p1_wins_counter < 5);

	/* Auswert-Funktion aufrufen */
	auswert(p1_wins_counter, p2_wins_counter, counter_stein, counter_schere, counter_papier, counter_echse, counter_spock);

}


int main() {
	/* Zufallszahlengenerator initialisieren */
	srand(time(NULL));
	/* Funktion "Spiel"  aufrufen*/
	spiel();
	printf("Programmende\n");
	

	
	return 0;
}
