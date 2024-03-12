#include "cPrimzahl.h"

cPrimzahl::cPrimzahl(int prim_in){
	if (prim_in < 1 || prim_in > maxprim) {
		cout << "Initialisierung der Primzahl fehlgeschlagen. Standardwert wird verwendet" << endl;
		aktprim = 2;
	}
	else {
		if (isPrim(prim_in)) {
			aktprim = prim_in;
		}
		else {
			aktprim = prim_in;
			++aktprim;	//Es wird auf die naechste hoehere Primzahl korrigiert
		}
	}
}

cPrimzahl cPrimzahl::operator++(void){
	if (nextPrim(aktprim) > maxprim) {
		aktprim = prevPrim(maxprim);
	}

	aktprim = nextPrim(aktprim);

	return *this;
}

cPrimzahl cPrimzahl::operator--(void){
	if (prevPrim(aktprim) <= 2) {
		aktprim = 2; //Standardwert
	}

	aktprim = prevPrim(aktprim);

	return *this;
}

int& cPrimzahl::operator[](const int& index){
	
	static int prim_index = index;
	if (index <= 0) {
		return aktprim;
	}
	else if (isPrim(index)) {
		return prim_index;
	}
	else {
		static int tmp;
		if (nextPrim(index) > maxprim) {
			tmp = prevPrim(maxprim);
			return tmp;
		}
		else {
			tmp = nextPrim(index);
			return tmp;
		}
	}
}

int cPrimzahl::nextPrim(int start){
	start += 1;

	while (!isPrim(start)) {
		start++;
	}
	
	return start;
}

int cPrimzahl::prevPrim(int start) {
	start -= 1;

	if (start > 2) {				//Vermeiden von Endlosschleife beim Suchen einer Primzahl unter 2
		while (!isPrim(start)) {
			start--;
		}
	}
	else {
		return 2;
	}
	
	return start;
}

bool cPrimzahl::isPrim(int n) {
	if (n <= 1) {	// 1 und <1 sind keine Primzahlen.
		return false;
	}

	for (int i = 2; i <= n / 2; i++) {
		if (n % i) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& o, const cPrimzahl& zahl){
	o << zahl.aktprim;	//Ausgeben der aktuellen Primzahl, kein endl um die Zahl in einer cout-Kette verwendet werden kann
	return o;			//Ausgabeoperator am besten so kurz wie moeglich halten
}
