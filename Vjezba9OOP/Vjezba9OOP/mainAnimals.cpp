#include "animals.h"
#include "kukac.h"
#include "ptica.h"
#include "pauk.h"


int main()
{
	Counter counter;

	Animals* niz[] = { new tarantula, new zohar, new vrabac };

	for (int i = 0; i < 3;i++)
	{
		counter.add(niz[i]);
	}
	cout << "Ukupno ima: " << counter.getCounter() << " nogu" << endl;


	for (int i = 0; i < 3;i++) {
		delete niz[i];
	}
}