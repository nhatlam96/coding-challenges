#include <iostream>

using namespace std;

class cFahrzeug {

private:
	int AnzahlSitze;

public:

	cFahrzeug(int _AnzahlSitze = 4) {
		AnzahlSitze = _AnzahlSitze;
	}

	int nenneSitze() {
		return AnzahlSitze;
	}
};

class cWohnung {

private:
	int AnzahlBetten;

public:

	cWohnung(int _AnzahlBetten = 6) {
		AnzahlBetten = _AnzahlBetten;
	}

	int nenneBetten() {
		return AnzahlBetten;
	}

	void leereBriefKasten() {
		cout << "Die Post ist da" << endl;	
	}
};

class cWohnwagen : virtual public cFahrzeug, public cWohnung {
	
private:
	double ZugLast;

public:

	cWohnwagen(int _AnzahlSitze = 0, double _ZugLast = 0.92, double _AnzahlBetten = 0) : cWohnung(_AnzahlBetten), cFahrzeug(_AnzahlSitze) {
		ZugLast = _ZugLast;
	}

	double nenneZugLast() {
		return ZugLast;
	}

	void leereBriefKasten() {
	cout << "Keine Post, nur postlagernd" << endl;
	}
};

class cAutomobil : virtual public cFahrzeug {

private:
	double ZugKraft;

public:

	cAutomobil(double _ZugKraft = 1.32, double _AnzahlSitze = 5) : cFahrzeug(_AnzahlSitze) {
		ZugKraft = _ZugKraft;
	}

	bool ziehen(cWohnwagen w) { 
		if (ZugKraft >= w.nenneZugLast()){
			return true;
		}
		return false; 
	}
};

class cAppartement : public cWohnung {

public:
	cAppartement(double _AnzahlBetten = 2) : cWohnung(_AnzahlBetten) {
	}
};

class cWohnmobil : public cAutomobil, public cWohnwagen {

public:

	cWohnmobil(double _AnzahlSitze = 3, double _AnzahlBetten = 3, double _ZugKraft = 0.7, double _ZugLast = 0.0) : cAutomobil(_ZugKraft, _AnzahlSitze), cWohnwagen(_AnzahlSitze, _ZugLast, _AnzahlBetten), cFahrzeug(_AnzahlSitze) {
	
	}

	void nenneSitzeBetten(){
		cout << "Sitze: " << nenneSitze() << ", ";
		cout << "Betten: " << nenneBetten() << endl;
	}
};

 void main ()
 {
	cAutomobil Mustang;
	cWohnwagen WanderVogel;
	cWohnmobil UschiBus (2, 2);
	cAppartement MyStudio (1);

	cout << "Auto zieht Wohnwagen ? (0/1): " << Mustang.ziehen(WanderVogel) << endl;
	cout << "Wohnmobil zieht Wohnwagen ? (0/1): " << UschiBus.ziehen(WanderVogel) << endl << endl;
	cout << "Ausstattung UschiBus: "; UschiBus.nenneSitzeBetten();
	cout << "Briefkasten UschiBus: "; UschiBus.leereBriefKasten();
	cout << "Briefkasten MyStudio: "; MyStudio.leereBriefKasten();
	cout << "Das MyStudio hat " << MyStudio.nenneBetten() << " Betten." << endl << endl;
	cout << " *** ENDE *** " << endl << endl;
	
	system ("PAUSE");
 }