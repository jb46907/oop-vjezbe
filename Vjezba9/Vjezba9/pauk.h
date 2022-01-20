#pragma once
#include "animals.h"


//izvedena klasa pauk
class pauk : public Animals
{
public:
	int numbersOfLegs() { return 10; }
	string animalSpecies() { return "pauk"; }
	~pauk() { cout << "Destroy: Pauk" << endl; }
};

//izvedena klasa iz pauk
class tarantula : public pauk
{
	string name = "tarantula";
public:
	string getName() { return name; }
};
