#include "cLageSkala.h"

cLageSkala::cLageSkala(double unterGrenze_in, double oberGrenze_in, double aktVal_in) : unterGrenze(unterGrenze_in), oberGrenze(oberGrenze_in), aktVal(aktVal_in)
{
	//Durch Kaskade initialisiert
}

void cLageSkala::ausgabe() 
{
	cout << "Ausgabe der Werte: " << endl;
	cout << "Untere Grenze: " << unterGrenze << ", Obere Grenze: " << oberGrenze << ", Aktueller Wert: " << aktVal << endl;
}

double cLageSkala::getSegments() const {
	return ((oberGrenze - unterGrenze) / SEGMENTS);
}

cLageSkala& cLageSkala::operator ++(void) {

	if (aktVal + 3 * getSegments() <= oberGrenze) {
		aktVal = aktVal + 3 * getSegments();
	}
	else {
		cout << "Fehler: Ueberlauf beim Inkrementieren" << endl;
		exit(-1);
	}

	return *this;
}

cLageSkala& cLageSkala::operator --(void) {
	
	if (aktVal - 3 * getSegments() >= unterGrenze) {
		aktVal = aktVal - 3 * getSegments();
	}
	else {
		cout << "Fehler: Unterlauf beim Dekrementieren" << endl;
		exit(-1);
	}

	return *this;
}

ostream& operator << (ostream& out, const cLageSkala& obj) {

	double intervall = obj.unterGrenze;

	out << "|";

	for (; intervall <= obj.oberGrenze; intervall += obj.getSegments()) {
		if (obj.aktVal > intervall && obj.aktVal <= intervall + obj.getSegments())
			out << "*";
		else
			out << "-";
	}

	out << "|";

	return out;
}

istream& operator >> (istream& in, cLageSkala& obj) {
	double new_ug = 0.0, new_og = 0.0, new_av = 0.0;

	cout << "Geben Sie eine Untergrenze ein: ";
	in >> new_ug;
	cout << endl << "Geben Sie eine Obergrenze ein: ";
	in >> new_og;
	cout << endl << "Geben Sie den aktuellen Wert ein: ";
	in >> new_av;
	cout << endl;

	if (new_og <= new_ug) {
		cout << "Fehler: Die Untergrenze liegt ueber der Obergrenze" << endl;
		exit(-1);
	}

	if (new_av >= new_ug && new_av <= new_og) {
		obj.unterGrenze = new_ug;
		obj.oberGrenze = new_og;
		obj.aktVal = new_av;
	}
	else {
		cout << "Fehler: Der aktuelle Wert befindet sich nicht innerhalb der Grenzen" << endl;
		exit(-1);
	}

	return in;
}