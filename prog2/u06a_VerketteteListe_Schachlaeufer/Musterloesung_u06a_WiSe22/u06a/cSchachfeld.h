#pragma once
#include <iostream>
using namespace std;

#define NIL (cSchachfeld*) 0		//Nullzeiger

class cSchachfeld
{
private:
	char x;
	int y;
	cSchachfeld* prev;

	bool testZug(char new_x, int new_y);
	bool testBlock(char new_x, int new_y);

	friend bool vergleichPos(const cSchachfeld& s1, const cSchachfeld& s2);
public:
	cSchachfeld(char, int, cSchachfeld* = NIL);
	~cSchachfeld();

	cSchachfeld* springerZug();
	void printSpiel();
};

