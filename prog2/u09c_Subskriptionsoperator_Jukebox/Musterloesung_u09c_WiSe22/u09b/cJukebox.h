#pragma once

#include <iostream>
#include <sstream>
using namespace std;

class cJukebox
{
private:
	//Keine privaten Attribute
public:
	cJukebox();
	~cJukebox();
	int operator [] (istream&);
};

