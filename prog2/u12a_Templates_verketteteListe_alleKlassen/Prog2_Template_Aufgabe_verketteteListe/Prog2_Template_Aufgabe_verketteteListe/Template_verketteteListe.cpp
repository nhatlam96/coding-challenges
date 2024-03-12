// C++-Demprogramm fuer die verkettete Liste aus Objekten

#include "cElement.h"
#include "cT1.h"
#include "cBruch.h"

int main() {
	cElement<int>* p_act = new cElement <int>(42);		// Zeiger auf das aktuelle Listenelement (Listenende)

	p_act = p_act->newEl(27);				// Mit dem aktuell letzten Objekt das neue starten und Listenende weiterschalten
	p_act = p_act->newEl(-54325);			// Mit dem aktuell letzten Objekt das neue starten und Listenende weiterschalten
	p_act = p_act->newEl(1);					// Mit dem aktuell letzten Objekt das neue starten und Listenende weiterschalten

	p_act->printList();								// Liste rekursiv ausgeben

	delete p_act;									// Liste rekursiv loeschen

	// nun mit Klasse cT1

	cElement<cT1>* p_act2 = new cElement <cT1>(42);		// Zeiger auf das aktuelle Listenelement (Listenende)

	p_act2 = p_act2->newEl(27);				// Mit dem aktuell letzten Objekt das neue starten und Listenende weiterschalten
	p_act2 = p_act2->newEl(-54325);			// Mit dem aktuell letzten Objekt das neue starten und Listenende weiterschalten
	p_act2 = p_act2->newEl(1);					// Mit dem aktuell letzten Objekt das neue starten und Listenende weiterschalten

	p_act2->printList();								// Liste rekursiv ausgeben

	delete p_act2;									// Liste rekursiv loeschen

	// nun mit Klasse cBruch

	cElement<cBruch>* p_act3 = new cElement <cBruch>(cBruch(42, 17));		// Zeiger auf das aktuelle Listenelement (Listenende)

	p_act3 = p_act3->newEl(cBruch(27, 3));				// Mit dem aktuell letzten Objekt das neue starten und Listenende weiterschalten
	p_act3 = p_act3->newEl(cBruch(13, -54325));			// Mit dem aktuell letzten Objekt das neue starten und Listenende weiterschalten
	p_act3 = p_act3->newEl(1);					// Mit dem aktuell letzten Objekt das neue starten und Listenende weiterschalten

	p_act3->printList();								// Liste rekursiv ausgeben

	delete p_act3;									// Liste rekursiv loeschen

	return 0;
}