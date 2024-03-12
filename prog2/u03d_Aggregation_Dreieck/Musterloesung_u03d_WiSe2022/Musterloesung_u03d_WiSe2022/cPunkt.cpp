#include "cPunkt.h"

void cPunkt::korrektur()
{
	if (x > 10.0) {
		x = 10.0;
	} 
	else if (x < -10.0) {	//Bei diesen Kontrollstruktoren benoetigen wir kein else, da wir lediglich bei den beiden Bedingungen -10 und 10 handeln
		x = -10.0;			//Wenn der Wert im Bereich von -10 und 10 ist, macht diese Methode einfach nichts
	}
	
	if (y > 10.0) {
		y = 10.0;
	}
	else if (y < -10.0) {
		y = -10.0;
	}
}

cPunkt::cPunkt(double x_in, double y_in)
{
	x = x_in;	//Da die Werte durch die Korrektur im Konstruktor korrigiert werden, ist es nicht schlimm,
	y = y_in;	//x und y ohne vorherige Ueberprüfung einfach zu beschreiben

	korrektur();	//Diese Methode hätte man auch mit Parametern machen können um so x_in und y_in vor der Ueberschreibung zu ueberpruefen, jedoch
					//arbeiten wir in der OOP bei solchen Aufgaben lieber mit den Attributen selbst
}

void cPunkt::ausgabe()
{
	cout << "(" << x << "/" << y << ")";	//An dieser Stelle fuege ich kein endl hinzu, sodass die Ausgabe auch "mitten im Satz" erfolgen kann, jedoch
}											//ist dies normalerweise nicht zu empfehlen und wir lernen mehr darueber bei der Ueberladung des Ausgabeoperators

double cPunkt::getX()
{
	return x;
}

double cPunkt::getY()
{
	return y;
}
