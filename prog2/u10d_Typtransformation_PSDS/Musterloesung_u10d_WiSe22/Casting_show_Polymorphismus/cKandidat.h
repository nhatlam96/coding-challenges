#pragma once
#include <iostream>
using namespace std;

class cSuperstar;

class cKandidat
{
private:
	double talent;
	int TEDstimmen;
	double punkte;
public:
	cKandidat(double talent_in = 10.0, int tedStimmen_in = 0);
	void print();
	void werteTED(int neuStimmen);
	double getTalent();
	double getPunkte();
	operator cSuperstar();

};

