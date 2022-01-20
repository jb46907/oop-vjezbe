#pragma once
#include "animals.h"

//izvedena klasa kukac
class kukac : public Animals
{
public:
	int numbersOfLegs() { return 6; }
	string animalSpecies() { return "kukac"; }
	~kukac() { cout << "Destroy: Kukac" << endl; }
};

//izvedena klasa iz kukac
class zohar : public kukac
{
	string name = "zohar";
public:
	string getName() { return name; }
};