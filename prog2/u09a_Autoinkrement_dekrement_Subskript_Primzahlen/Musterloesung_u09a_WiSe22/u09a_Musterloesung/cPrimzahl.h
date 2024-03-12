#pragma once
#include <iostream>
using namespace std;

#define maxprim 10000	//Globale Konstante Maxprim

class cPrimzahl
{
private:
	int aktprim;

	int nextPrim(int);	//Hilfsmethoden
	int prevPrim(int); 
	bool isPrim(int);
public:
	cPrimzahl(int prim_in = 2);		//1 keine Primzahl, deswegen geeigneter Standardwert = erste Primzahl = 2

	cPrimzahl operator ++ (void);
	cPrimzahl operator -- (void); 
	int& operator [] (const int& index);

	friend ostream& operator << (ostream& o, const cPrimzahl&);
};

