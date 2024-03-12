/*
 * u04b.cpp / u06a.cpp / u06b.cpp
 * Sebastian Fuhrmann
 * 2016-06-02
 */

#include <iostream>
using namespace std;

class cBruch {
private:
    int zaehler, nenner;


    /* Friend-Funktionen */
    /* Operatoren */
    friend cBruch &operator + (const cBruch&, const cBruch&);
    friend cBruch &operator - (const cBruch &bruch1, const cBruch &bruch2);
    friend cBruch &operator * (const cBruch &bruch1, const cBruch &bruch2);
    friend cBruch &operator / (const cBruch &bruch1, const cBruch &bruch2);

    friend ostream& operator << (ostream& o, cBruch b1);

    friend int vergleich(const cBruch &bruch1, const cBruch &bruch2);
public:
    /* Universal-Konstruktor */
    cBruch(int zaehler = 0, int nenner = 1) {
        this->zaehler = zaehler;
        this->nenner = nenner;
        if (this->nenner < 0) {
            this->zaehler *= -1;
            this->nenner *= -1;
        }
    }

    /* Kopier-Konstruktor  b1 = b2*/
    cBruch(const cBruch& b1) {
        zaehler = b1.zaehler;
        nenner = (b1.nenner != 0) ? b1.nenner : 1;	// Nulldivision abfangen
        if (nenner < 0) {
            nenner *= -1;
            zaehler *= -1;
        }
        //cout << "Kopier-Konstruktor des Bruches " << zaehler << " / " << nenner << endl;
    }

    ~cBruch() {
        //	cout << "Destruktor des Bruches " << zaehler << " / " << nenner << endl;
    }

    /* K�rzt mit gr��tm�glicher Zahl */
    void kuerzen() {
        bool gekuerzt = false;
        for (int i = this->nenner-1; i > 1; i--) {
            if (this->nenner%i == 0 && this->zaehler%i == 0) {
                this->zaehler /= i;
                this->nenner /= i;
                gekuerzt = true;
                break;
            }
        }
    }

    /* Gibt den Wert des Bruches dezimal zur�ck */
    double toDec() {
        return ((double)this->zaehler / (double)this->nenner*1.0);
    }

    /* Ausgabe-Funktion */
    void ausgabe() {
        kuerzen();
        cout << this->zaehler << "/" << this->nenner << " = " << toDec() << endl;
    }
};

/* Operand +: Addiert zwei Br�che und gibt eine Referenz auf das Ergebnis als Bruch zur�ck. */
cBruch& operator + (const cBruch &lhs, const cBruch &rhs) {
    // Addition von Bruechen: Nenner = Nenner1 * Nenner2
    // Zaehler = (Zaehler1 * Nenner2) + (Zaehler2 * Nenner1)
    static cBruch helper;		// Hilfsobjekt

    helper.zaehler = lhs.zaehler * rhs.nenner + rhs.zaehler * lhs.nenner;
    helper.nenner = lhs.nenner * rhs.nenner;

    return helper;
}

/* Subtrahiert zwei Br�che und gibt eine Referenz auf das Ergebnis als Bruch zur�ck. */
cBruch& operator - (const cBruch &bruch1, const cBruch &bruch2) {
    // (a/b) - (c/d) = (a*d-c*b)/(b*d)
    static cBruch helper;
    helper.zaehler = bruch1.zaehler*bruch2.nenner - bruch2.zaehler*bruch1.nenner;
    helper.nenner = bruch1.nenner*bruch2.nenner;

    return helper;
}

/* Multipliziert zwei Br�che und gibt eine Referenz auf das Ergebnis als Bruch zur�ck. */
cBruch& operator * (const cBruch &bruch1, const cBruch &bruch2) {
    // (a/b) * (c/d) = (a*c)/(b*d)
    static cBruch helper;

    helper.zaehler = bruch1.zaehler*bruch2.zaehler;
    helper.nenner = bruch1.nenner*bruch2.nenner;

    return helper;
}

/* Dividiert zwei Br�che und gibt eine Referenz auf das Ergebnis als Bruch zur�ck. */
cBruch& operator / (const cBruch &bruch1, const cBruch &bruch2) {
    // (a/b) : (c/d) = (a*d)/(b*c)
    static cBruch helper;

    helper.zaehler = bruch1.zaehler*bruch2.nenner;
    helper.nenner = bruch1.nenner*bruch2.zaehler;

    return helper;
}

/* Vergleichsoperanden */
bool operator < (const cBruch &b1, const cBruch &b2) {
    return vergleich(b1, b2) == -1;
}

bool operator > (const cBruch &b1, const cBruch &b2) {
    return vergleich(b1, b2) == 1;
}

bool operator == (const cBruch &b1, const cBruch &b2) {
    return !vergleich(b1, b2);
}

/* Vergleicht zwei Br�che */
int vergleich(const cBruch &bruch1, const cBruch &bruch2) {
    if ((double)bruch1.zaehler / (double)bruch1.nenner < (double)bruch2.zaehler / (double)bruch2.nenner) return -1;
    if ((double)bruch1.zaehler / (double)bruch1.nenner > (double)bruch2.zaehler / (double)bruch2.nenner) return 1;
    return 0;
}

/* tauscht zwei Instanzen von cBruch */
void tausche(cBruch &b1, cBruch &b2) {
    static cBruch temp;
    temp = b1;
    b1 = b2;
    b2 = temp;
}

void sortiere(cBruch *Brueche) {
    int i, j;
    cBruch temp;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8 - 1; j++) {
            if (Brueche[j + 1] < Brueche[j]) {
                temp = Brueche[j];
                Brueche[j] = Brueche[j + 1];
                Brueche[j + 1] = temp;
            }
        }
    }
}

// cout << "Addition der ersten beiden Br" << (char)129 <<"che: " << b << endl;
ostream& operator << (ostream& o, cBruch b1) {
    o << b1.zaehler << "/" << b1.nenner << " = " << (double)b1.zaehler/(double)b1.nenner << endl;
    return o;
}

int main() {
    int vergleichsergebnis;

    cBruch b;
    cBruch Brueche[8] = {
            cBruch(3, 4),
            cBruch(21, -7),
            cBruch(8, -12),
            cBruch(-2, 3),
            cBruch(-8, 13),
            cBruch(2, 5),
            cBruch(21, 49),
    };

    /* Geben Sie in einer Schleife die Werte aller 8 Br�che aus. */
    for each (cBruch bruch in Brueche) {
        bruch.ausgabe();
    }

    /* Addieren Sie die ersten beiden Br�che und geben Sie das Ergebnis aus mit der Funktion ausgabe() */
    b = Brueche[0] + Brueche[1];
    cout << "Addition der ersten beiden Br" << (char)129 <<"che: " << b << endl;
    cout << endl;

    /* Subtrahieren Sie die n�chsten beiden Br�che und geben Sie das Ergebnis aus mit der Funktion ausgabe() */
    cout << "Subtraktion der n" << (char)132 << "chsten beiden Br" << (char)129 << "che: ";
    b = Brueche[2] - Brueche[3];
    b.ausgabe();
    cout << endl;

    /* Multiplizieren Sie die n�chsten beiden Br�che und geben Sie das Ergebnis aus mit der Funktion ausgabe() */
    cout << "Multiplikation der n" << (char)132 << "chsten beiden Br" << (char)129 << "che: ";
    b = Brueche[4] * Brueche[5];
    b.ausgabe();
    cout << endl;

    /* Dividieren Sie die n�chsten beiden Br�che und geben Sie das Ergebnis aus mit der Funktion ausgabe() */
    cout << "Division der n" << (char)132 << "chsten beiden Br" << (char)129 << "che: ";
    b = Brueche[6] / Brueche[7];
    b.ausgabe();
    cout << endl;

    /* Paarweiser Vergleich der Br�che */
    for (int i = 0; i < 8; i += 2) {
        vergleichsergebnis = vergleich(Brueche[i], Brueche[i + 1]);
        cout << "Bruch " << (i + 1) << " ist " << (vergleichsergebnis?(vergleichsergebnis>0?"groesser als":"kleiner als"):"gleich") << " Bruch " << (i + 2) << endl;
    }

    sortiere(Brueche);

    return 0;
}