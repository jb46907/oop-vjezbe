#include <cstddef>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

struct Matrica {

	float** matrica;
	int red;
	int stupac;

	void alMatrice(int r, int s);	//Metoda za alokaciju dinamicke memorije za matrice
	void gMatrice(float a, float b);	//Metoda za generiranje matrica
	void zbrojMatrica(Matrica matrica1, Matrica matrica2);	//Metoda za zbrajanje matrica
	void oduzimanjeMatrica(Matrica matrica1, Matrica matrica2);		//Metoda za oduzimanje matrica
	void mnozenjeMatrica(Matrica matrica1, Matrica matrica2);	//Metoda za mnozenje matrica
	void trasMatrice(Matrica matrica1, Matrica matrica2);	//Metoda za trasponiranje matrice
	void ispisMatrice();	//Metoda za ispis matrica
	void brisanjeAlMatrice();	//Metoda za brisanje alocirane memorije

};