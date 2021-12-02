#pragma once
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	double x;
	double y;

	Point() = default;
	Point(double x, double y);
};

class Board {
	int row;
	int column;
	char ch;
	char** matrix;

public:
	Board();
	Board(const Board& b);
	Board(int row, int column, char ch);
	~Board();
	void draw_char(Point p, char ch);
	void draw_up_line(Point p, char ch);
	void draw_line(Point p1, Point p2, char ch);
	void display() const;

};

