#include "Vectors.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0, lower = 0, upper = 0;
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vecNovi;

	input(vec1, n);
	input(vec2, n);

	lookup(vec1, vec2, vecNovi);
	print(vecNovi);

}