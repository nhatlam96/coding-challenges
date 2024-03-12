#include <iostream>
#include <string>

using namespace std;

class cSchienenfahrzeug {
public:
	cSchienenfahrzeug() {

	}
};

class cLok : cSchienenfahrzeug {
private:
public:
	cLok() {

	}
	void ausgabe() {
		cout << "Ich bin die Lok!" << endl;
	}
};

class cWaggon : cSchienenfahrzeug {
private:
	cWaggon* pprev;
	string name;
public:
	cWaggon(string name = "unbenannt", cWaggon* pprev = (cWaggon*)0) {
		this->pprev = pprev;
		this->name = name;
	}
	void ausgabe() {
		if (pprev) {
			pprev->ausgabe();
		}
		cout << "Ich bin einer von vielen Waggons und hei" << (char)225 << "e " << name << "!" << endl;
	}
	~cWaggon (){
		if (pprev) delete pprev;
		cout << "Ich bin die " << name << " und werde jetzt gel" << (char)148 << "scht!" << endl;
	}
};

class cZug {
private:
	cLok lok;
	cWaggon* waggon;
	int c; 
public:
	cZug() {
		cout << "ZUGKONSTRUKTOR" << endl;
	}
	void kuppleWagenAn(string name) {
		waggon = new cWaggon(name, waggon);
		c++;
	}
	void ausgabe() {
		lok.ausgabe();
		waggon->ausgabe();
	}
	cZug& operator ++ (void) {
		kuppleWagenAn("Kuchen");
		return *this; 
	}
	~cZug() {
		delete waggon;
	}
};

ostream & operator << (ostream& o, cZug zug) {
	// hier fehlt Ausgabe
	return o;
}


int main() {
	cZug zug;
	zug.kuppleWagenAn("Berta");
	zug.kuppleWagenAn("Sally");
	zug.kuppleWagenAn("Baerbel");
	zug.ausgabe();
	cout << "=========================" << endl;
	++zug;
	zug.ausgabe();
	//zug.gehweg();
	//cout << zug << endl;
	return 0;
}