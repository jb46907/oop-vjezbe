#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


//1. Napisati funkciju koja racuna najveci i najmanji broj u nizu od n prirodnih brojeva.
//Funkcija vraca trazene brojeve pomocu referenci.

void minmax(int* niz, int n, int &min, int &max) {
	min = niz[0];
	max = niz[0];

	for (int i = 0; i < n; i++) {
		if (niz[i] < min) {
			min = niz[i];
		}
		else if (niz[i] > max) {
			max = niz[i];
		}
	}
}

int main() {

	int niz[] = { 2, 5, 3, 7, 3, 4, 4 };
	int n = sizeof(niz) / sizeof(niz[0]);
	int min;
	int max;

	minmax(niz, n, min, max);
	cout << "najveci je: " << max << "\n";
	cout << "najmanji je: " << min << "\n";
}