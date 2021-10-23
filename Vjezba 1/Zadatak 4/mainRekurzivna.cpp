#include <iostream>

using namespace std;


//4. Napisati rekurzivnu funkciju za trazenje najveceg i najmanjeg broja u nizu.

void funminmax(int* niz, int* min, int* max, int n, int i) {

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

	int niz[] = { 2,2,3,1,1,5,4,1,3 };
	int min = niz[0];
	int max = niz[0];
	int i = 0;
	int n = sizeof(niz) / sizeof niz[0];

	funminmax(niz, &min, &max, n, i);

	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;

	return 0;
}