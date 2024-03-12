#pragma once

#include <iostream>
using namespace std;

class cBruch
{
private:
	int zaehl;
	int nenn;
	int ggT(int x, int y);
	void kuerzen();
	friend cBruch& add(const cBruch&, const cBruch&);	// Freund-Funktion add()
	friend cBruch& operator + (const cBruch&, const cBruch&);	// Freund-Operator +
	friend ostream& operator << (ostream& o, const cBruch&);
public:
	cBruch(int = 0, int = 1);
	cBruch(const cBruch&);
	~cBruch();
	void print();
	cBruch& operator - (const cBruch&) const;	// Operator - als Methode
	cBruch& operator * (const cBruch&) const;	// Operator * als Methode

	cBruch& operator ++ (void);	// Praefix-Inkrement (++x) als Methode
	cBruch& operator ++ (int);	// Postfix-Inkrement (x++) als Methode
};
