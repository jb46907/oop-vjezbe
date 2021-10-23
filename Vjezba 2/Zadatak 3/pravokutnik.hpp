#include <iostream>
#include <iomanip>
#include <cmath>

struct Tocka {
	double x;
	double y;
};

struct Kruznica {
	Tocka s;
	double radijus;
};

struct Pravokutnik {
	Tocka a;
	Tocka c;
};

int sFunkcija(const Pravokutnik(&p)[4], int n, const Kruznica& k);

