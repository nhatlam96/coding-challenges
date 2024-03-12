#include "cBruch.h"

int cBruch::ggT(int x, int y) {				// Wiederverwendung aus Prog1
	if (x == y) {
		return x;
	}
	else {
		if (x > y) {
			return ggT(x - y, y);
		}
		else {
			return ggT(x, y - x);
		}
	}
}

void cBruch::kuerzen() {
	int ggt = zaehl != 0 ? ggT(zaehl > 0 ? zaehl : zaehl * -1, nenn > 0 ? nenn : nenn * -1) : 1;
	// hier waere ein Kommentar schoen!
	// Vielleicht dass der ggt nur von natuerlichen Zahlen gemacht wird,
	// und das Vorzeichen keine Rolle spielt. Aber dazu fehlt die Zeit ...
	zaehl /= ggt; nenn /= ggt;
}

cBruch::cBruch(int z, int n) {		// universeller Konstruktor
	zaehl = z;
	nenn = (n == 0) ? 1 : n;		// Nulldivision vermeiden: Ausweichaktion: auf 1 setzen
	if (nenn < 0) {					// negative Nenner durch Erweitern mit -1 umdrehen
		zaehl *= -1;
		nenn *= -1;
	}
	kuerzen();
	cout << "Konstruktion des Bruchs: " << zaehl << " / " << nenn << endl;
}

cBruch::cBruch(const cBruch& b) {		// Kopier-Konstruktor
	zaehl = b.zaehl;
	nenn = (b.nenn == 0) ? 1 : b.nenn;	// Nulldivision vermeiden: Ausweichaktion: auf 1 setzen
	if (nenn < 0) {						// negative Nenner durch Erweitern mit -1 umdrehen
		zaehl *= -1;
		nenn *= -1;
	}
	kuerzen();
	cout << "Kopierkonstruktion des Bruchs: " << zaehl << " / " << nenn << endl;
}

cBruch::~cBruch() {
	cout << "Destruktion des Bruchs: " << zaehl << " / " << nenn << endl;
}

void cBruch::print() {
	cout << "Werte des Bruchs: " << zaehl << " / " << nenn << endl;
}

cBruch& cBruch::operator - (const cBruch& rhs) const {	// Operator - als Methode
	static cBruch bsum;		// Hilfsobjekt statisch machen, damit es nach dem Return noch exisitiert

	bsum.zaehl = zaehl * rhs.nenn - rhs.zaehl * nenn;
	bsum.nenn = nenn * rhs.nenn;

	// zaehl += 2;		// provozierter Fehler wird verhindert

	bsum.kuerzen();
	return bsum;
}

cBruch& cBruch::operator * (const cBruch& rhs) const {	// Operator * als Methode
	static cBruch bsum;		// Hilfsobjekt statisch machen, damit es nach dem Return noch exisitiert

	bsum.zaehl = zaehl * rhs.zaehl;
	bsum.nenn = nenn * rhs.nenn;

	bsum.kuerzen();
	return bsum;
}


cBruch& cBruch::operator ++ (void) { // Praefix-Inkrement (++x) als Methode
	zaehl += nenn;	// Gesamtwert des Bruchs um den Betrag einer Ganzzahl erhoehen
	return *this;
}

cBruch& cBruch::operator ++ (int) {	// Postfix-Inkrement (x++) als Methode
	static cBruch helpme = *this;	// Kopierkonstruktion des statischen Hilfsobjekts
	zaehl += nenn;	// Gesamtwert des Bruchs um den Betrag einer Ganzzahl erhoehen
	return helpme;
}

// Freundfunktionen, keine Methoden

cBruch& add(const cBruch& lhs, const cBruch& rhs) {	// Addition von 2 Bruechen
	static cBruch bsum;		// Hilfsobjekt statisch machen, damit es nach dem Return noch exisitiert

	bsum.zaehl = lhs.zaehl * rhs.nenn + rhs.zaehl * lhs.nenn;
	bsum.nenn = lhs.nenn * rhs.nenn;

	bsum.kuerzen();
	return bsum;
}

cBruch& operator +(const cBruch& lhs, const cBruch& rhs) {	// Addition von 2 Bruechen als Operator
	static cBruch bsum;		// Hilfsobjekt statisch machen, damit es nach dem Return noch exisitiert

	bsum.zaehl = lhs.zaehl * rhs.nenn + rhs.zaehl * lhs.nenn;
	bsum.nenn = lhs.nenn * rhs.nenn;

	bsum.kuerzen();
	return bsum;
}

ostream& operator << (ostream& o, const cBruch& b) {
	o << b.zaehl << " / " << b.nenn;
	return o;
}