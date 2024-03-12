#include "cBruch.h"

cBruch::cBruch(int z_in, int n_in): zaehler(z_in)
{
	nenner = n_in;
	kuerzen();
	if (nenner < 0) { // nenner muss nicht negativ bleiben
		nenner *= -1;
		zaehler *= -1;
	}
	else if (nenner == 0) {
		nenner = 1;
	}
}

void cBruch::kuerzen()
{
	int helfer;
	helfer = zaehler;
	zaehler /= ggT(zaehler, nenner);
	nenner /= ggT(helfer, nenner);
}

int cBruch::ggT(int z, int n) { // greoste gemeinsame Teiler von zwei Ganze Zahlen
	if (n == 0) {
		return z;
	}
	else {
		return(ggT(n, z % n));
	}
}

void cBruch::ausgabe() {
	cout << "Bruch: " << zaehler << "/" << nenner << " = " << (double)zaehler / (double)nenner << endl;
}

void tausch(cBruch& b1, cBruch& b2)
{
	cBruch helfer = b1;
	b1 = b2;
	b2 = helfer;
}

// Operatoren 
cBruch add(const cBruch b1, const cBruch b2)
{
	return cBruch((double)((b1.zaehler * b2.nenner) + (b1.nenner * b2.zaehler)), (b1.nenner * b2.nenner));
}

cBruch sub(cBruch b1, cBruch b2)
{
	return cBruch((((double)b1.zaehler * (double)b2.nenner) - ((double)b1.nenner * (double)b2.zaehler)), ((double)b1.nenner * (double)b2.nenner));
}

cBruch mult(cBruch b1, cBruch b2) {
	return cBruch((b1.zaehler * b2.zaehler), b1.nenner * b2.nenner);
}

cBruch div(cBruch b1, cBruch b2) {
	return cBruch(((b1.zaehler * b2.nenner), b1.nenner * b2.zaehler));
}

int vergleich(const cBruch& b1, const cBruch& b2) // als const definieren damit die parameter unveraendert bleiben
{
	double bruch1 = (double)b1.zaehler / (double)b1.nenner;
	double bruch2 = (double)b2.zaehler / (double)b2.nenner;
	if (bruch1 < bruch2)
		return - 1;
	if (bruch1 > bruch2)
		return 1;
	else
		return 0;
}


// sortier funktion

void sortier(cBruch elem[], int ANZ) {
	for (int n = ANZ; n > 1; n--) {
		for (int i = 0; i < n - 1; i++) {
			if (vergleich(elem[i], elem[i + 1]) == 1) { // Elemente vergleichen dank unsere funktion vergleich elem 1 > elem 2
				tausch(elem[i], elem[i + 1]); // Elemente tauschen
			}
		}
	}

}
