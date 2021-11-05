#include <iostream>
#include "Vectors.hpp"
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> v;
	
	input(v, n); //unos vektora
	sort(v.begin(), v.end()); // sortiranje vektora
	sum(v); //suma elemenata vektora
	v.insert(v.begin(), 0); //ubacivanje elementa na prvu poziciju u vektoru
	print(v); //ispisivanje

}