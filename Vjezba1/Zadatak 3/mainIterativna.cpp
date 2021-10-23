#include <iostream>

using namespace std;


//3. Napisati iterativnu funkciju za trazenje najveceg i najmanjeg broja u nizu.

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