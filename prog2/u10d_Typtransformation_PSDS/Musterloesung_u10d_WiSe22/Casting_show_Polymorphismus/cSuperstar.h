#pragma once
#include <iostream>
using namespace std;
class cKandidat;

class cSuperstar
{
private:
	int fanZahl;
	int hitZAhl;
	int maxHiZahl;
public:
	cSuperstar(int fanZAhl_in = 0, int hitZahl_in = 0);
	void print();
	void landeHit();
	void landeFlop();
	int getHits();
	operator cKandidat();
};

