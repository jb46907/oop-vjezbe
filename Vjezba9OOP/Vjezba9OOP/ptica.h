#pragma once
#include "animals.h"

//izvedena klasa ptica
class ptica : public Animals
{
public:
	int numbersOfLegs() { return 2; }
	string animalSpecies() { return "ptica"; }
	~ptica() { cout << "Destroy: Ptica" << endl; }
};

//izvedena klasa iz ptica
class vrabac : public ptica
{
	string name = "vrabac";
public:
	string getName() { return name; }
};