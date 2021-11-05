#include <iostream>
#include "Vectors.hpp"
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> v;

	input(v, n); //unos vektora
	eraseVec(v);
	print(v); //ispisivanje

}