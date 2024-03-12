#pragma once
#include <iostream>
using namespace std;

class cPunkt
{
private:
	double x;
	double y;

	void korrektur();

public:
	cPunkt(double x_in = 0.0, double y_in = 0.0);	//Universelle Konstruktoren funktionieren wie Konstruktoren mit Parametern, der Unterschied ist, dass in der Headerdatei
	void ausgabe();									//in die Signatur des Konstruktors Standardwerte hinzugefügt werden

	double getX();	//get-Funktionen damit wir im Dreieck auf die Werte x und y zugreifen koennen
	double getY();
};

