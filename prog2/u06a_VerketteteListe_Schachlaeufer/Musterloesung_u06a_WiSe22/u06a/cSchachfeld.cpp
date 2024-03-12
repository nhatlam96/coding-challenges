#include "cSchachfeld.h"

cSchachfeld::cSchachfeld(char x_in, int y_in, cSchachfeld* prev_in) : x(x_in), y(y_in), prev(prev_in)
{
	cout << "Konstruktion eines Schachfeldes mit den Koordinaten: " << x << y << endl;
}

cSchachfeld::~cSchachfeld() 
{
	if (prev != NIL) {	//Rekursives Abbauen der verketteten Liste
		delete prev;
	}

	cout << "Destruktor: " << x << y << endl;
}

bool cSchachfeld::testBlock(char new_x, int new_y){
	char block_spalte_upper[] = { 'A','A','C','D','E','E','F','G','H' };
	int block_reihe[] = { 2,3,6,8,8,6,6,1,8 };
	
	for (int i = 0; i < 9; i++) {
		if (new_y == block_reihe[i] && new_x == block_spalte_upper[i]) {
			cout << "Ihr Zug landet auf einem blockierten Feld" << endl;
			return false;
		}
	}
	return true;
}

bool cSchachfeld::testZug(char new_x, int new_y){
	int betrag;
	int diff_x;
	int diff_y;

	diff_x = x - new_x;
	diff_y = y - new_y;

	diff_x = diff_x < 0 ? diff_x *= -1 : diff_x;
	diff_y = diff_y < 0 ? diff_y *= -1 : diff_y;

	if (diff_x == diff_y) {
		return true;
	}
	else {
		cout << "Ihr Zug entspricht nicht der korrekten Differenz" << endl;
		return false;
	}
}

cSchachfeld* cSchachfeld::springerZug(){
	char new_x = 0;
	int new_y = 0;
	
	while (1) {
		cout << "Geben Sie einen neuen Zug ein: " << endl;
		cin >> new_x >> new_y;

		if ((new_x >= 'A' && new_x <= 'H') && (new_y >= 1 && new_y <= 8)) {	//Testen des Gueltigkeitesbereiches
			if (testZug(new_x, new_y) && testBlock(new_x, new_y)) {
				return new cSchachfeld(new_x, new_y, this);
			}
			else {
				cout << "Ihr Zug ist ungueltig, versuchen sie es nochmal" << endl;
			}
		}
		else {
			cout << "Ihre Koordinate ist ungueltig, versuchen sie es nochmal" << endl;
		}
	}
}

void cSchachfeld::printSpiel(){

	if (prev != NIL) {	//Rekursives Ausgeben der verketteten Liste
		prev->printSpiel();
	}
	cout << "Ausgabe eines Schachfeldes mit den Koordinaten: " << x << y << endl;	//Umgedrehte Ausgabe

}

bool vergleichPos(const cSchachfeld& s1, const cSchachfeld& s2) {	//Call-By-Reference, da wir ansonsten beim destruieren der Kopie den Speicher von prev deallokieren
	if (s1.x == s2.x && s1.y == s2.y)
		return true;
	else
		return false;
}