#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

//2. Napisati funkciju koja vraca referencu na neki element niza.
//Koristeci povratnu vrijednost funkcije kao lvalue uvecajte i - ti element niza za jedan.

int& vElem(int* niz, int x) {
	return niz[x];
}

int main() {
	
	int niz[5] = { 2, 5, 11, 7, 8};
	int x = 2;

	int& r = vElem(niz, x);

	cout << "Vraceni elem: " << r << endl;
	cout << "Elem + 1: " << ++r << endl;

}