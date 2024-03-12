/* Autor:Rothgerber, Benedikt
* Erstelldatum: 2016/05/15
* Beschreibung: Programm zur Simulation von Springerzuegen in einem Schachspiel
*/

#include <iostream>
using namespace std;

// vvv Klasssendefinitionen vvv

class cSchachfeld {
private:
	char spalte, spalteneu;
	int reihe, reiheneu;
	cSchachfeld * pprev; // Zeiger auf vorhergehendes Listenelement --> auf den vorhergehenden Zustand des Schachfeldes
	bool pruefung() { // Pruefung, ob der vom Benutzer gewuenschte Zug erlaubt ist
		if ((spalteneu >= 'a' && spalteneu <= 'h') && (reiheneu <= 8 && reiheneu >= 1)) {
			if (spalteneu - spalte == 1 || spalteneu - spalte == -1) {
				if (reiheneu - reihe == 2 || reiheneu - reihe == -2) {
					return true;
				}
				else {
					cout << "Fehler: Ungueltiger Zug!" << endl;
					return false;
				}
			}
			else if (spalteneu - spalte == 2 || spalteneu - spalte == -2) {
				if (reiheneu - reihe == 1 || reiheneu - reihe == -1) {
					return true;
				}
				else {
					cout << "Fehler: Ungueltiger Zug!" << endl;
					return false;
				}
			}
			else {
				cout << "Fehler: Ungueltiger Zug!" << endl;
				return false;
			}
		}
		else {
			cout << "Fehler: Eingabekoordinaten ausserhalb des zulaessigen Wertebereiches!" << endl;
			return false;
		}
		cout << "Fehler: This message should never show on screen!!!" << endl;
		return false;
	}
	
public:
	cSchachfeld(char spalte_in = 'e', int reihe_in = 6, cSchachfeld * p_in = (cSchachfeld *)0) { //Konstruktor fuer die Ausgangssituation des Schachfeldes(Springer auf e6)
		spalte = spalte_in;
		reihe = reihe_in;
		pprev = p_in;
	}

	cSchachfeld * newElem(char spalte_in, int reihe_in) {	// Neues Listenelement erstellen
		return new cSchachfeld(spalte_in, reihe_in, this);	// Nutz-Parameter an Konstruktor weiterreichen
	}

	bool isSchachmatt() { //Pruefung, ob der Springer auf dem Feld des weissen Koenigs landet und damit das 'Spiel' beendet
		if (spalte == 'c' && reihe == 1) return true;
		return false; 
	}

	void ausgabe(bool flag = true) { //Ausgabe der Schachzuege nach 'Schachmatt'
		cout << spalte << "/" << reihe;
		if (pprev && flag){
			cout << "Von ";
			pprev->ausgabe(false);
			cout << " auf ";
			ausgabe(false);
			cout << endl;
		}	}

	void wegAusgabe() { 
		if (pprev) {
			pprev->wegAusgabe();
			ausgabe();
		}

		
	}

	cSchachfeld * spiele() { //Benutzereingabe mit Aufruf der Pruefungen
		do {
			cout << "Bitte Koordinaten eingeben(erst Spalte[a-h], danach Reihe[1-8])" << endl;
			cout << "Spalte: ";
			cin >> spalteneu;
			cout << "Reihe: ";
			cin >> reiheneu;
		} while (!pruefung());
		return newElem(spalteneu, reiheneu);
	}
	
	~cSchachfeld() { //Deskonstruktor
		if (pprev != (cSchachfeld*)0) {
			delete pprev;	// rekursive Destruktion
		}
		cout << "Destruktor: <" << spalte << "|" << reihe << ">" << endl;
	}
};

// vvv Hauptprogramm vvv
//     --> Aufruf der Ein-/Ausgaben:

int main() {
	cSchachfeld * aktuell = new cSchachfeld;
	do { 
		cout << "Sie befinden sich bei ";
		aktuell->ausgabe();
		cout << endl;
		aktuell = aktuell->spiele();
	} while (!aktuell->isSchachmatt());

	cout << "'Schachmatt'!" << endl << "Hier noch die Liste der 'Schachzuege':" << endl;
	aktuell->wegAusgabe();
	delete aktuell;

	return 0;
}