#pragma once
#include <iostream>
using namespace std;

class cKinoPlatz {
	int art;		// 1 = Parkett, 2 = Loge
	bool status;	// frei/belegt
public:
	cKinoPlatz();
	friend ostream& operator << (ostream&, const cKinoPlatz&);
};
