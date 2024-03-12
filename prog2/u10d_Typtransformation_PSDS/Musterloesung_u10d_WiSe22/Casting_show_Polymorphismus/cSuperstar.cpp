#include "cSuperstar.h"
#include "cKandidat.h"

cSuperstar::cSuperstar(int fanZAhl_in, int hitZahl_in)
{
	fanZahl = fanZAhl_in;
	hitZAhl = hitZahl_in;
	maxHiZahl = 0;
}

void cSuperstar::print()
{
	cout << "Superstart -> Anzahl von Fans: " << fanZahl;
	cout << ", Anzahl von Hits: " << hitZAhl << endl;
}

void cSuperstar::landeHit()
{
	hitZAhl += 1;
	if (maxHiZahl < hitZAhl) {
		maxHiZahl = hitZAhl;
	}
}

void cSuperstar::landeFlop()
{
	hitZAhl -= 1;
}

int cSuperstar::getHits()
{
	return hitZAhl;
}

cSuperstar::operator cKandidat()
{
	return cKandidat(maxHiZahl * 5.3, 0);
}
