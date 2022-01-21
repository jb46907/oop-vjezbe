#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

template <typename T>

class Stack {
	
	T* stackP;
	int size;	//maximum size of the stack
	int pos;	//this is the index of topmost element in our array


public:
	Stack() { pos = -1; size = 7; stackP = new T[size]; }
	~Stack() { delete[] stackP; }

	void push(T elem);
	T pop();
	bool isEmpty();
};