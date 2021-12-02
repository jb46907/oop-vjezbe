#include "Board.h"

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Board::Board()
{
	row = 10;
	column = 20;
	ch = 'o';
	matrix = new char* [row];

	for (int i = 0; i < row; i++) {
		matrix[i] = new char[column];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (i == 0 || i == row - 1 || j == 0 || j == column - 1) {
				matrix[i][j] = ch;
			}
			else {
				matrix[i][j] = ' ';
			}
		}
	}
}

Board::Board(const Board& other)
{
	row = other.row;
	column = other.column;
	ch = other.ch;
	matrix = new char* [row];

	for (int i = 0; i < row; i++) {
		matrix[i] = new char[column];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

Board::Board(int row, int column, char ch)
{
	this->row = row;
	this->column = column;
	this->ch = ch;
	matrix = new char* [this->row];

	for (int i = 0; i < this->row; i++) {
		matrix[i] = new char[this->column];
	}

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->column; j++) {
			if (i == 0 || i == this->row - 1 || j == 0 || j == this->column - 1) {
				matrix[i][j] = this->ch;
			}
			else {
				matrix[i][j] = ' ';
			}
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < row; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Board::draw_char(Point p, char ch)
{
	if (p.x > row || p.y > column) {
		return;
	}

	int wNumRow = round(p.x);
	int wNumColumn = round(p.y);

	matrix[wNumRow][wNumColumn] = ch;
}

void Board::draw_up_line(Point p, char ch)
{
	if (p.x > row || p.y > column)
		return;

	int wNumRow = round(p.x);
	int wNumColumn = round(p.y);

	for (wNumRow; wNumRow > 0; wNumRow--) {
		matrix[wNumRow][wNumColumn] = ch;
	}
}

void Board::draw_line(Point p1, Point p2, char ch)
{
	if (p1.x > row || p1.y > column)
		return;
	if (p2.x > row || p2.y > column)
		return;

	if (p1.x == p2.x){
		if (p1.y < p2.y) {
			for(p1.y; p1.y <= p2.y; ++p1.y){
				Point p;
				p.x = p1.x;
				p.y = p1.y;
				draw_char(p, ch);
			}
		}
		else {
			for (p1.y; p1.y >= p2.y; --p1.y) {
				Point p;
				p.x = p1.x;
				p.y = p1.y;
				draw_char(p, ch);
			}
		}
	}

	else if (p1.y == p2.y) {
		if (p1.x < p2.x) {
			for (p1.x; p1.x <= p2.x; ++p1.x) {
				Point p;
				p.x = p1.x;
				p.y = p1.y;
				draw_char(p, ch);
			}
		}
		else {
			for (p1.x; p1.x >= p2.x; --p1.x) {
				Point p;
				p.x = p1.x;
				p.y = p1.y;
				draw_char(p, ch);
			}
		}
	}

	else if (abs(p1.x - p2.x) > abs(p1.y - p2.y)) {
		if (p1.x < p2.x) {
			for (double x = p1.x; x <= p2.x; x += 1.0) {
				double y = p1.y + (p2.y - p1.y) / (p2.x - p1.x) * (x - p1.x);
				Point p;
				p.x = x;
				p.y = y;
				draw_char(p, ch);
			}
		}
		else {
			for (double x = p2.x; x < p1.x; x += 1.0) {
				double y = p1.y + ((p2.y - p1.y) / (p2.x - p1.x) * (x - p1.x));
				Point p;
				p.x = x;
				p.y = y;
				draw_char(p, ch);
			}
		}
	}
	else                        
	{
		if (p1.y < p2.y) {
			for (double y = p1.y; y < p2.y; y += 1.0) {
				double x = ((p2.x - p1.x) * (y - p1.y)) / (p2.y - p1.y) + p1.x;
				Point p;
				p.x = x;
				p.y = y;
				draw_char(p, ch);
			}
		}

		else {
			for (double y = p1.y; y < p2.y; y += 1.0) {
				double x = ((p2.x - p1.x) * (y - p1.y)) / (p2.y - p1.y) + p1.x;
				Point p;
				p.x = x;
				p.y = y;
				draw_char(p, ch);
			}
		}
	}

}

void Board::display() const
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << matrix[i][j];
		}
		cout << "\n";
	}
}

