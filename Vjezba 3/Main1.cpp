#include "Vectors.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0, lower = 0, upper = 0;
	vector<int> vec1; 

	input(vec1, n);
	print(vec1);
	vec1.clear();

	border(vec1, lower, upper);
	print(vec1);
	vec1.clear();

}