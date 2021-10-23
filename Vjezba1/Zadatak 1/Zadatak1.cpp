#include <iostream>
#include <iomanip>


//1. Unesite sljedeci program i modificirajte ga testirajuci gornje manipulatore.
int main()
{
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << std::boolalpha << flag << std::endl;
	int a = 255;
	std::cout << "hex " << std::hex << a << std::endl;
	std::cout << "dec " << std::dec << a << std::endl;
	std::cout << "oct " << std::oct << a << std::endl;
	double pi = 3.141592;
	std::cout << "pi = " << std::scientific << std::nouppercase;
	std::cout << std::setprecision(5) << std::setw(15) << std::setfill('1');
	std::cout << pi << std::endl;
}