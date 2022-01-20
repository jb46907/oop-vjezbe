#include "animals.h"
#include "kukac.h"
#include "ptica.h"
#include "pauk.h"

Animals::~Animals() {};					//Pure Virtual Destructor-definition

void Counter::add(Animals* animal)
{
	num += animal->numbersOfLegs();

	cout << "Dodano: " << animal->animalSpecies() << endl;
};