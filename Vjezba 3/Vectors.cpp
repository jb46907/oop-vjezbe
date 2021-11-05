#include "Vectors.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int>::iterator it;
typedef vector<string>::iterator itStr;

//	ZADATAK 1
void input(vector<int>& vec, int& n) {
	int x;
	
	cout << "Unesi duzinu vektora:" << endl;
	cin >> n;
	cout << "Unesi elemente:" << endl;

	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}
}
void border(vector<int>& vec, int& lower, int& upper) {
	int x;

	cout << "Unesi donju granicu intervala:" << endl;
	cin >> lower;
	cout << "Unesi gornju granicu intervala:" << endl;
	cin >> upper;

	cout << "Unesi elemente:" << endl;
	cin >> x;

	while (lower <= x && x <= upper) {
		vec.push_back(x);

		cin >> x;
	}
}
void print(vector<int>& vec) {
	
	for (it i = vec.begin(); i != vec.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

}

//	ZADATAK 2
void lookup(vector<int>& vec1, vector<int>& vec2, vector<int>& vecNovi) {
	
	int x = 0;
	for (it i = vec1.begin(); i != vec1.end(); ++i) {
		for (it j = vec2.begin(); j != vec2.end(); ++j) {
			if (*i == *j) {
				x++;
			}
		}
		if (!x) {
			vecNovi.push_back(*i);
		}
		x = 0;
	}
}

//	ZADATAK 3
void sum(vector<int>& vec) {
	int sum = 0;
	for (it i = vec.begin(); i != vec.end(); ++i) {
		sum += *i;
	}
	vec.insert(vec.end(), sum);
}

//	ZADATAK 4 
void eraseVec(vector<int>& vec) {
	it i;
	int x;
	
	cout << "Koju poziciju zelis izbrisat?" << endl;
	cin >> x;

	i = vec.end() - 1;
	vec.at(x) = *i;
	vec.pop_back();
}

//	ZADATAK 5
int checkSubstring(string& str, string& subStr) {
	cout << "Unesite string:" << endl;
	getline(cin, str);
	cout << "Unesite subString:" << endl;
	getline(cin, subStr);
	
	int a = 0, x = 0;
	int i;
	
	while ((i = str.find(subStr, x)) != string::npos) {
		a++;
		x = i + 1;
	}
	return a;
}

//	ZADATAK 6
void inputString(vector<string>& vec) {
	string x;
	int n;
	cout << "Unesi koliko stringova zelis zapisat:" << endl;
	cin >> n;
	cout << "Unesi string:" << endl;

	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}
}
void reverseString(vector<string>& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		reverse(vec[i].begin(), vec[i].end());
		//sort(vec[i].begin(), vec[i].end());
	}
	sort(vec.begin(), vec.end());
}
void printString(vector<string>& vec) {

	for (itStr i = vec.begin(); i != vec.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

}
