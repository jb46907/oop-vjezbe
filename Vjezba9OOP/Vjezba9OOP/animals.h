#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
#include <string>

using namespace std;

//interface - apstraktna klasa
class Animals
{
public:
	virtual int numbersOfLegs() = 0;	//Virtual Function
	virtual string animalSpecies() = 0;
	virtual ~Animals() = 0;				//Virtual Destructor
};

class Counter
{
	int num;
public:
	Counter() : num(0) {};

	int getCounter() { return num; };
	void add(Animals* animal);
};