#pragma once
#include <iostream> 
using namespace std;
class cBruch
{
private:
	int zaehler;
	int nenner;
public:
	cBruch(int z_in = 0, int n_in = 1);
	void kuerzen();
	int ggT(int z, int n);
	void ausgabe();
	//friend funktionen für unsere addition, substraktion, multiplication, und division
	friend cBruch add(const cBruch b1, const cBruch b2);
	friend cBruch sub(cBruch b1, cBruch b2);
	friend cBruch mult(cBruch b1, cBruch b2);
	friend cBruch div(cBruch b1, cBruch b2);
	friend void tausch(cBruch& b1, cBruch &b2);

	friend void sortier(cBruch ar[], int ANZ);

	friend int vergleich(const cBruch & b1, const cBruch& b2);
};

