#pragma once

#include "cKinoPlatz.h"

class cClassArr
{
	class cKinoPlatz* p;			// Zeiger auf den Speicherbereich fuer das Array
	int anz;				// Anzahl der Array-Elemente
public:
	cClassArr(int);
	class cKinoPlatz& operator [] (const int&);
	~cClassArr();
};