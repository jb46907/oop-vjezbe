#include "template.h"
#include "template.cpp"

int main()
{
	Stack<string> strStack;
	Stack<int> intStack;

	intStack.push(56);
	intStack.push(32);
	intStack.push(10);
	intStack.push(98);
	intStack.push(7);

	strStack.push("OOP");
	strStack.push("spa");
	strStack.push("java");
	strStack.push("Dog");

	cout << "Pop-ano s int Stack-a: " << intStack.pop() << endl;
	cout << "Pop-ano sa string Stack-a: " << strStack.pop() << endl;
	cout << endl;


	char arr[] = { 'G','z','B','N','e','a' };
	int size = sizeof arr / sizeof arr[0];

	for (int i = 0; i < size;++i)
		cout << arr[i] << " ";
	
	sortiraj(arr, size);
	
	cout << endl;
	for (int i = 0; i < size;++i)
		cout << arr[i] << " ";
	
	

}