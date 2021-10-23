#include "matrica.hpp"

void Matrica::alMatrice(int r, int s) {

	red = r;
	stupac = s;

	matrica = new float* [r];

	for (int i = 0; i < r; i++) {
		matrica[i] = new float[s];
	}
}

void Matrica::gMatrice(float a, float b) {

	float temp;

	if (a > b) {
		temp = b;
		b = a;
		a = temp;
	}
	for (int i = 0; i < red; i++) {

		for (int j = 0; j < stupac; j++) {
			matrica[i][j] = a + (float)rand() / (float)RAND_MAX * (b - a);

		}
	}
}

void Matrica::zbrojMatrica(Matrica matrica1, Matrica matrica2) {

	if (matrica1.red == matrica2.red && matrica1.stupac == matrica2.stupac) {
		alMatrice(matrica1.red, matrica1.stupac);

		for (int i = 0; i < red; i++) {
			for (int j = 0; j < stupac; j++) {
				matrica[i][j] = matrica1.matrica[i][j] + matrica2.matrica[i][j];

			}
		}
		ispisMatrice();
	}
	else {
		std::cout << "Uvjet za zbrajanje nije ispunjen. Matrice nisu istih dimenzija" << std::endl << std::endl;
	}
}

void Matrica::oduzimanjeMatrica(Matrica matrica1, Matrica matrica2) {

	if (matrica1.red == matrica2.red && matrica1.stupac == matrica2.stupac) {
		alMatrice(matrica1.red, matrica1.stupac);

		for (int i = 0; i < red; i++) {
			for (int j = 0; j < stupac; j++) {
				matrica[i][j] = matrica1.matrica[i][j] - matrica2.matrica[i][j];
			}
		}
		ispisMatrice();
	}
	else {
		std::cout << "Uvjet za oduzimanje nije ispunjen. Matrice nisu istih dimenzija" << std::endl << std::endl;
	}
}

void Matrica::mnozenjeMatrica(Matrica matrica1, Matrica matrica2) {

	if (matrica1.stupac == matrica2.red) {
		alMatrice(matrica1.red, matrica2.stupac);

		for (int i = 0; i < red; i++) {
			for (int j = 0; j < stupac; j++) {
				float zbroj = 0;
				for (int k = 0; k < red; k++) {
					zbroj += matrica1.matrica[i][k] * matrica2.matrica[k][j];
				}
				matrica[i][j] = zbroj;
			}
		}
		ispisMatrice();
	}
	else {
		std::cout << "Matrice nisu ulancanje, te se ne mogu mnoziti" << std::endl << std::endl;

	}
}

void Matrica::trasMatrice(Matrica matrica1, Matrica matrica2) {
	//trasponiranje 1. matrice
	alMatrice(matrica1.stupac, matrica1.red);
	for (int i = 0; i < stupac; i++) {
		for (int j = 0; j < red; j++) {
			matrica[j][i] = matrica1.matrica[i][j];
		}
	}
	std::cout << "Trasponirana 1. matrica" << std::endl;
	ispisMatrice();

	//trasponiranje 2. matrice
	alMatrice(matrica2.stupac, matrica2.red);
	for (int i = 0; i < stupac; i++) {
		for (int j = 0; j < red; j++) {
			matrica[j][i] = matrica2.matrica[i][j];
		}
	}
	std::cout << "Trasponirana 2. matrica" << std::endl;
	ispisMatrice();
}

void Matrica::ispisMatrice() {

	for (int i = 0; i < red; i++) {
		for (int j = 0; j < stupac; j++) {
			std::cout << std::setprecision(5) << std::right << matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Matrica::brisanjeAlMatrice() {
	for (int i = 0; i < red; i++) {
		delete[] matrica[i];
	}
	delete[] matrica;
}
