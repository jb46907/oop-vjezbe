#ifndef classWork
#define classWork
#include <iostream>
#include <cstdlib>

using namespace std;

//prvi zadatak || Napisati klasu za poziciju tocke u prostoru koja ima tri double podatka: duzinu, sirinu i visinu(x, y, z koordinate). U main funkciji postavite vrijednost za dvije tocke u prostoru i ispisite obe udaljenosti.
class dot {
	double x, y, z;
	
public:
	//dot();
	void setValue(double a = 0.0, double b = 0.0, double c = 0.0);
	void setPseudorandom(int lowerInterval, int upperInterval);
	void retrieval(double& pOne, double& pTwo, double& pThree) const;
	//void retrieval(double* pOne, double* pTwo, double* pThree) const;
	double distance2D(const dot& otherDot) const;
	double distance3D(const dot& otherDot) const;
	double getZ() const;

};

//drugi zadatak || Napisati klasu koja predstavlja oruzje. Oruzje ima svoj polozaj u prostoru (jednatocka u prostoru), broj metaka koji stanu u jedno punjenje i trenutni broj metaka upunjenju. Može pucati(shoot) i ponovo se puniti(reload).
class weapon {
	dot position;
	int bullets;
	int currentBullets;

public:
	void shoot();
	void reload();
	void generateShooter(const dot& shootPosition, int numBullets);
	int rBullets();
	int cBullets();
	const dot& getPosition() const;
	

};

//treci zadatak || Napisati klasu koja predstavlja metu. Meta je oblika kvadra i zadana je donjom lijevom i gornjom desnom tockom. Ima dva stanja : pogodena i nepogodena.
class target {
	dot lowerLeft;
	dot upperRight;
	bool hit;

public:
	void generateTarget(const dot& first, const dot& second);
	const dot& getLL();
	const dot& getUR();
	int hits();


};

//cetvrti zadatak || Napisati program koji ce generirati n meta i jednog pucaca (oruzje). Uz pretpostavku da je polozaj oruzja horizontalan i da se oruzje moze zakretati za 360, izracunati koliko je meta pogodeno jednim punjenjem.


#endif

