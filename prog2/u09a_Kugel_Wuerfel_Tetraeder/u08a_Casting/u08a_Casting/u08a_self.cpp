/*
 * u08a.cpp
 * Hausaufgabe u08a - Casting zwischen geometrischen Figuren
 * Sebastian Fuhrmann
 * 2016-06-13
 */

#define PI 3.14159
#define drittwurz(i) exp(log(i)/3.0)
#include <iostream>
using namespace std;

/* Prototypen */
class cKugel;
class cWuerfel;

/* Klasse cKugel mit privater Mitgliedsvariable radius */
class cKugel {
private:
    double radius;
    friend ostream& operator << (ostream& o, cKugel k);
public:
    /* Universal-Konstruktor */
    cKugel(double radius = 1.0) {
        this->radius = radius;
    }
    /* Gibt das Volumen der Kugel zur�ck */
    double getVolumen() {
        return (4.0 / 3.0)*radius*radius*radius*PI;
    }
    /* Signatur des Casting-Operators */
    operator cWuerfel(void);
};

/* Klasse cWuerfel mit privater Mitgliedsvariable kante */
class cWuerfel {
private:
    double kante;
    friend ostream& operator << (ostream& o, cWuerfel w);
public:
    /* Universal-Konstruktor */
    cWuerfel(double kante = 1.0) {
        this->kante = kante;
    }
    /* Gibt das Volumen des W�rfels zur�ck */
    double getVolumen() {
        return kante*kante*kante;
    }
    /* Signatur des Casting-Operators */
    operator cKugel(void);
};

/*
	FRAGE:
	Gibt es eine sch�nere Variante, diese Casting-Operatoren zu implementieren?
	Beim Integrieren dieser in die normale Klassedefinition (oben) war immer eine Klasse unbekannt, da diese ja noch nicht deklariert war.
	Wenn ich sie durch einen Prototypen bekannt gemacht habe, warf mir Visual Studio den Fehler, dass kein Konstruktor existiert.
*/

/* Casting-Operator (cKugel)w */
cWuerfel::operator cKugel(void) {
    /*
        v = (4 / 3)*radius�*PI;  |:(4/3)
        (3/4)*V = radius^3*PI	| : PI
        ((3/4)*v)/PI = radius^3	| 3sqrt();
        radius = dritteWurzel(((3/4)*v)/PI);
    */
    return cKugel(drittwurz((3.0 / 4.0)*getVolumen() / PI));
}
/* Casting-Operator (cWuerfel)k */
cKugel::operator cWuerfel(void) {
    /* erstellen eines cWuerfels mit der Kantenl�nge */
    /* v = kante^3 ==> kante = 3sqrt(v) */
    return cWuerfel(drittwurz(getVolumen()));
}

/* Ausgabe-Operator f�r eine cKugel */
ostream& operator << (ostream& o, cKugel k) {
    o << "r = " << k.radius << ", V = " << k.getVolumen();
    return o;
}
/* Ausgabe-Operator f�r einen cWuerfel */
ostream& operator << (ostream& o, cWuerfel w) {
    o << "l = " << w.kante << ", V = " << w.getVolumen();
    return o;
}

/* Hauptprogramm */
int main() {
    cKugel k1(17.42);
    cWuerfel w1(22.50);
    cout << "Kugel: " << k1 << endl;
    cout << "Wuerfel: " << w1 << endl;
    k1 = (cKugel)w1;
    cout << "Kugel nach Zuweisung aus Wuerfel: " << k1 << endl;
    w1 = (cWuerfel)k1;
    cout << "Wuerfel nach Zuweisung aus Kugel: " << w1 << endl;
    return 0;
}