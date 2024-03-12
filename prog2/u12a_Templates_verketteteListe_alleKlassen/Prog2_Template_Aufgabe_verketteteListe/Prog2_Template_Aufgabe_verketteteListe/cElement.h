#pragma once

#include <iostream>
using namespace std;

#define NIL (cElement*)0

template <class T>
class cElement {
	T item;			// "Nutzlast-Attribut" Objekt bel. Klasse

	cElement* prev;		// Zeiger auf das Vorgaengerelement in der Liste
public:
	template <class T> cElement(T t_in, cElement* prev_in = NIL) : item(t_in), prev(prev_in) {
		cout << "Konstruktor: item = " << item << endl;
	}

	template <class T> cElement* newEl(T t_in) { return new cElement(t_in, this); } // sich selbst als Vorgaenger eintragen lassen

	void printList() {	// rekursive Ausgabe der Liste
		//cout << "Listenelement: a = " << a << ", x = " << x << endl;
		if (prev != NIL) {
			prev->printList();
		}
		cout << "Listenelement: item = " << item << endl;

	}

	~cElement() {		// rekursive Destruktion der Liste
		if (prev != NIL) {
			delete prev;
		}
		cout << "Destruktor: item = " << item << endl;

	}
};
