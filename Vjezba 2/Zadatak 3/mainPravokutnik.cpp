#include "pravokutnik.hpp"

using namespace std;

//3. Definirati strukturu kruznica i strukturu pravokutnik koja predstavlja pravokutnik cije su stranice 
//paralelne sa osima apscisa i ordinata.
//Napisati funkciju koja prima niz pravokutnika i jednu kruznicu i vraca broj pravokutnika koji sijeku kruznicu.
//Niz pravokutnika i kruznica šalju se u funkciju pomocu const referenci.


int main() {

	Pravokutnik pKutnik1, pKutnik2, pKutnik3, pKutnik4;

	pKutnik1.a.x = 0;
	pKutnik1.a.y = 0;
	pKutnik1.c.x = 4;
	pKutnik1.c.y = 2;

	pKutnik2.a.x = 0;
	pKutnik2.a.y = 0;
	pKutnik2.c.x = 7;
	pKutnik2.c.y = 3;

	pKutnik3.a.x = 0;
	pKutnik3.a.y = 0;
	pKutnik3.c.x = 11;
	pKutnik3.c.y = 5;

	pKutnik4.a.x = 0;
	pKutnik4.a.y = 0;
	pKutnik4.c.x = 25;
	pKutnik4.c.y = 8;

	Kruznica krug;
	krug.s.x = 0;
	krug.s.y = 0;
	krug.radijus = 6;

	Pravokutnik brPravo[4] = { pKutnik1, pKutnik2, pKutnik3, pKutnik4 };

	int a = sFunkcija(brPravo, 4, krug);
	cout << "Sijece: " << a << endl;
}
