#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class timer {
	int h;
	int m;
	double s;

	friend class penalty;
public:
	timer() { h = 0, m = 0, s = 0; }
	timer(int hh, int mm, double ss) : h(hh), m(mm), s(ss) {};

	void operator+=(const timer& t);
	void operator/=(size_t sizeV);
	
	friend ostream& operator<<(ostream& COUT, const timer& toPrint);

	operator double();

	friend timer operator-(const timer& a, const timer& b);
	
};

class penalty {
	int pen;
	
public:
	penalty(int x) : pen(x) {};
	void operator()(timer& x);
};