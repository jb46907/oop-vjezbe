#include "matrica.hpp"

using namespace std;

/*2. definirati strukturu koja opisuje matricu.napisati program za osnovne
operacije s matricama ciji su elementi decimalni brojevi(float).program
treba imati sljedece funkcije :
• funkciju za unos matrice mxn,
• funkciju za generiranje matrice mxn s elementima u rasponu[a, b],
• funkcije za zbarajanje, oduzimanje, mnozenje matrica,
• funkciju za trasponiranje matrice,
• funkciju za ispisivanje matrice. elementi matrice se ispisuju na cetiri
decimale, poravnati udesno.*/


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