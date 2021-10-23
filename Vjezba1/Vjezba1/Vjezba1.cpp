/*
//1. Unesite sljedeći program i modificirajte ga testirajući gornje manipulatore.
#include <iostream>
#include <iomanip>

int main()
{
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << std::boolalpha << flag << std::endl;
	int a = 255;
	std::cout << "hex " << std::hex << a << std::endl;
	std::cout << "dec " << std::dec << a << std::endl;
	std::cout << "oct " << std::oct << a << std::endl;
	double pi = 3.141592;
	std::cout << "pi = " << std::scientific << std::nouppercase;
	std::cout << std::setprecision(5) << std::setw(15) << std::setfill('1');
	std::cout << pi << std::endl;
}
*/
/*2. definirati strukturu koja opisuje matricu.napisati program za osnovne
operacije s matricama čiji su elementi decimalni brojevi(float).program
treba imati sljedeće funkcije :
• funkciju za unos matrice mxn,
• funkciju za generiranje matrice mxn s elementima u rasponu[a, b],
• funkcije za zbarajanje, oduzimanje, množenje matrica,
• funkciju za trasponiranje matrice,
• funkciju za ispisivanje matrice. elementi matrice se ispisuju na četiri
decimale, poravnati udesno.*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Matrica {

	float** matrica;
	int red;
	int stupac;


	//Metoda za alokaciju dinamicke memorije za matrice
	void alMatrice(int r, int s) {

		red = r;
		stupac = s;

		matrica = new float* [r];

		for (int i = 0; i < r; i++) {
			matrica[i] = new float[s];
		}
	}

	//Metoda za generiranje matrica
	void gMatrice(float a, float b) {

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

	//Metoda za zbrajanje matrica
	void zbrojMatrica(Matrica matrica1, Matrica matrica2) {

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
			cout << "Uvjet za zbrajanje nije ispunjen. Matrice nisu istih dimenzija" << endl << endl;
		}
	}
	
	//Metoda za oduzimanje matrica
	void oduzimanjeMatrica(Matrica matrica1, Matrica matrica2) {

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
			cout << "Uvjet za oduzimanje nije ispunjen. Matrice nisu istih dimenzija" << endl << endl;
		}
	}

	//Metoda za mnozenje matrica
	void mnozenjeMatrica(Matrica matrica1, Matrica matrica2) {
		
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
			cout << "Matrice nisu ulancanje, te se ne mogu mnoziti" << endl << endl;
			
		}
	}

	//Metoda za trasponiranje matrice
	void trasMatrice(Matrica matrica1, Matrica matrica2) {
		//trasponiranje 1. matrice
		alMatrice(matrica1.stupac, matrica1.red);
		for (int i = 0; i < stupac; i++) {
			for (int j = 0; j < red; j++) {
				matrica[j][i] = matrica1.matrica[i][j];
			}
		}
		cout << "Trasponirana 1. matrica" << endl;
		ispisMatrice();

		//trasponiranje 2. matrice
		alMatrice(matrica2.stupac, matrica2.red);
		for (int i = 0; i < stupac; i++) {
			for (int j = 0; j < red; j++) {
				matrica[j][i] = matrica2.matrica[i][j];
			}
		}
		cout << "Trasponirana 2. matrica" << endl;
		ispisMatrice();
	}
	
	//Metoda za ispis matrica
	void ispisMatrice() {

		for (int i = 0; i < red; i++) {
			for (int j = 0; j < stupac; j++) {
				cout << setprecision(5) << right << matrica[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	//Metoda za brisanje alocirane memorije
	void brisanjeAlMatrice() {
		for (int i = 0; i < red; i++) {
			delete[] matrica[i];
		}
		delete[] matrica;
	}

};

int main() {

	srand((unsigned)time(NULL));

	int mat1_R = 0, mat1_S = 0, mat2_R = 0, mat2_S = 0;
	float ras_a1 = 0, ras_b1 = 0, ras_a2 = 0, ras_b2 = 0;

	//Velicina prve matrice i raspon elemenata za istu.
	cout << "Broj redaka za prvu matricu:" << endl;
	cin >> mat1_R;
	cout << "Broj stupaca za prvu matricu:" << endl;
	cin >> mat1_S;
	cout << "Raspon elemenata za prvu matricu: " << endl;
	cin >> ras_a1 >> ras_b1;

	//Velicina druge matrice i raspon elemenata za istu.
	cout << "Broj redaka za drugu matricu:" << endl;
	cin >> mat2_R;
	cout << "Broj stupaca za drugu matricu:" << endl;
	cin >> mat2_S;
	cout << "Raspon elemenata za drugu matricu: " << endl;
	cin >> ras_a2 >> ras_b2;

	Matrica matrica1, matrica2, matrica3;

	//Alokacija, generiranje i ispisavanje prve matrice
	matrica1.alMatrice(mat1_R, mat1_S);
	matrica1.gMatrice(ras_a1, ras_b1);
	cout << "Matrica 1" << endl;
	matrica1.ispisMatrice();

	//Alokacija, generiranje i ispisavanje prve matrice
	matrica2.alMatrice(mat2_R, mat2_S);
	matrica2.gMatrice(ras_a2, ras_b2);
	cout << "Matrica 2" << endl;
	matrica2.ispisMatrice();

	//Zbrajanje matrica
	cout << "Zbroj matrica 1. i 2." << endl;
	matrica3.zbrojMatrica(matrica1, matrica2);
	
	//Oduzimanje matrica
	cout << "Rezultat matrica 1. i 2." << endl;
	matrica3.oduzimanjeMatrica(matrica1, matrica2);
	
	//Mnozenje matrica
	cout << "Produkt matrica 1. i 2." << endl;
	matrica3.mnozenjeMatrica(matrica1, matrica2);

	//Trasponirana matrica
	matrica3.trasMatrice(matrica1, matrica2);
	
	//Brisanje alMemorije
	matrica1.brisanjeAlMatrice();
	matrica2.brisanjeAlMatrice();
	matrica3.brisanjeAlMatrice();


}

/*
//3. Napisati iterativnu funkciju za traženje najvećeg i najmanjeg broja u nizu.
#include <iostream>

using namespace std;

void funmaxmin(int niz[], int n) {
	int max = niz[0];
	int min = niz[0];

	for (int i = 0; i < n; i++) {
		if (niz[i] < min) {
			min = niz[i];
		}
		else if (niz[i] > max) {
			max = niz[i];
		}
	}
	cout << "Najveci: " << max << endl;
	cout << "Najmanji: " << min << endl;
}

int main()
{
	int niz[] = { 2, 3, 6, 1, 9, 12, 0 };
	int n = sizeof(niz) / sizeof niz[0];

	funmaxmin(niz, n);

	return 0;
}

/*
//4. Napisati rekurzivnu funkciju za traženje najvećeg i najmanjeg broja u nizu.

#include <iostream>

using namespace std;


void funminmax(int *niz, int *min, int *max, int n, int i) {

	if (i < n) {

		if (niz[i] > *max) {
			*max = niz[i];
		}
		if (niz[i] < *min) {
			*min = niz[i];
		}

		return funminmax(niz, min, max, n, i + 1);
	}
}

int main() {

	int niz[] = {2,2,3,1,1,5,4,1,3};
	int min = niz[0];
	int max = niz[0];
	int i = 0;
	int n = sizeof(niz) / sizeof niz[0];

	funminmax(niz, &min, &max, n, i);

	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;


	return 0;
}
*/