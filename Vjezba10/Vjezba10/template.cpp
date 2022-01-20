#include "template.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

template<typename Tpl>
void sortiraj(Tpl niz[], int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-1; ++j) {
			if (niz[j] > niz[j + 1]) {
			Tpl temp = niz[j + 1];
			niz[j + 1] = niz[j];
			niz[j] = temp;
			}
		}
	}
}


template <typename T>
void Stack<T>::push(T elem)	
{
	if (pos == size - 1) {
		cout << "Its full" << endl;
	}
	pos++;
	stackP[pos] = elem;
}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty()) {
		cout << "is empty" << endl;
	}
	T popElem = stackP[pos];
	return popElem;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	if (pos == -1)
		return true;
	else
		return false;
}
