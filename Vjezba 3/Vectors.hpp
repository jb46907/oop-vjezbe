#ifndef VECTORS_HPP
#define VECTORS_HPP
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//	ZADATAK 1
void input(vector<int>& vec, int& n);										
void border(vector<int>& vec, int& lower, int& upper);							
void print(vector<int>& vec);		

//	ZADATAK 2
void lookup(vector<int>& vec1, vector<int>& vec2, vector<int>& vecNovi);

//	ZADATAK 3
void sum(vector<int>& vec);

//	ZADATAK 4
void eraseVec(vector<int>& vec);

//	ZADATAK 5	
int checkSubstring(string& str, string& subStr);

//	ZADATAK 6
void inputString(vector<string>& vec);
void reverseString(vector<string>& vec);
void printString(vector<string>& vec);

#endif