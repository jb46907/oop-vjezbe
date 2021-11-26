#include "classWork.h"

//Funkciju za postavljanje vrijednosti clanova (treba imati pretpostavljene vrijednosti 0).

//dot::dot()
//{
//	x = 0.0;
//	y = 0.0;
//	z = 0.0;
//}

void dot::setValue(double a, double b, double c )
{
	x = a;
	y = b;
	z = c;
}

//Funkciju za postavljanje pseudorandom vrijednosti clanova (granice intervala su parametri funkcije).
void dot::setPseudorandom(int lowerInterval, int upperInterval)
{
	x = lowerInterval + rand() % (upperInterval - lowerInterval);
	y = lowerInterval + rand() % (upperInterval - lowerInterval);
	z = lowerInterval + rand() % (upperInterval - lowerInterval);
}

//Funkciju za dohvacanje vrijednosti clanova.
void dot::retrieval(double& pOne, double& pTwo, double& pThree) const
{
	pOne = x;
	pTwo = y;
	pThree = z;
}
//void dot::retrieval(double* pOne, double* pTwo, double* pThree) const
//{
//	*pOne = x;
//	*pTwo = y;
//	*pThree = z;
//}

//Funkciju koja racuna udaljenost do druge tocke u 2D ravnini (zanemarujuci z koordinatu).
double dot::distance2D(const dot& otherDot) const
{
	const double firstDot = otherDot.x - x;
	const double secondDot = otherDot.y - y;

	return sqrt(pow(firstDot, 2) + pow(secondDot, 2));
}

//Funkciju koja racuna udaljenost do druge tocke u 3D prostoru.
double dot::distance3D(const dot& otherDot) const
{
	const double firstDot = otherDot.x - x;
	const double secondDot = otherDot.y - y;
	const double thirdDot = otherDot.z - z;
	return sqrt(firstDot * firstDot + secondDot * secondDot + thirdDot * thirdDot);
}

double dot::getZ() const
{
	return z;
}

void target::generateTarget(const dot& first, const dot& second)
{
	double x, y, z;
	first.retrieval(x, y, z);
	lowerLeft.setValue(x, y, z);
	second.retrieval(x, y, z);
	upperRight.setValue(x, y, z);
	hit = false;
}

const dot& target::getLL()
{
	return lowerLeft;
}

const dot& target::getUR()
{
	return upperRight;
}

int target::hits()
{
	hit = true;
	return hit;
}

void weapon::shoot()
{
	currentBullets--;
}

void weapon::reload()
{
	currentBullets = bullets;
}

void weapon::generateShooter(const dot& shootPosition, int numBullets)
{
	double x, y, z;
	shootPosition.retrieval(x, y, z);
	position.setValue(x, y, z);
	
	bullets = numBullets;
	currentBullets = 0;
}

int weapon::rBullets()
{
	return bullets;
}

int weapon::cBullets()
{
	return currentBullets;
}

const dot& weapon::getPosition() const
{
	return position;
}
