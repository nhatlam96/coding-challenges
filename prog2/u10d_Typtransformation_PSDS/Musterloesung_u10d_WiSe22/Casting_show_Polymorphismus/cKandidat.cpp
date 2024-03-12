#include "cSuperstar.h"
#include "cKandidat.h"

cKandidat::cKandidat(double talent_in, int tedStimmen_in)
{
	talent = talent_in;
	TEDstimmen = tedStimmen_in;
	punkte = 0;
}

void cKandidat::print()
{
	cout << "Kandidat -> Talent = " << talent;
	cout << ", Telefonabstimmung = " << TEDstimmen << ", Punkte: " << punkte <<endl;

}

void cKandidat::werteTED(int neuStimmen)
{
	TEDstimmen += neuStimmen;
	punkte += neuStimmen * talent;
}

double cKandidat::getTalent()
{
	return talent;
}

double cKandidat::getPunkte()
{
	return punkte;
}

cKandidat::operator cSuperstar()
{
	return cSuperstar(TEDstimmen * 0.2, 3);
}
