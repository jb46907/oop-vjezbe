#include "Game.h"

using namespace std;

void HumanPlayer::ruka_HP(Player& p1)
{
	
	int a;
	cout << "Unesite broj izmedu 0 i 3 ili 5 i 8: " << "\n";
	cin >> a;
	while (a < 0 || a > 8 || a == 4)
	{
		cout << "Ponovno unesite broj izmedu 0 i 3 ili 5 i 8: " << "\n";
		cin >> a;
	}
	p1.set_ruka(a);	//ruka=a;
}

void ComputerPlayer::ruka_CP(Player& p2)
{
	int x;
	do {
		x = (rand() % 9); // %9 jer su brojevi 0-9
	} while (x == 4);

	p2.set_ruka(x);

	cout << "ComputerPlayer ruka: " << p2.get_ruka() << "\n" << endl;
}

void HumanPlayer::odabirHP(Player& p1)
{
	int a;
	cout << "Pogodi zbroj odabranih kovanica u rukama svih igraèa:" << "\n";
	cin >> a;
	while (a < 0 || a > 16)
	{
		cout << "Ponovni unos:"<< "\n";
		cin >> a;
	}
	p1.set_zbroj(a);
}

void ComputerPlayer::odabirCP(Player& p2)
{
	int a = rand() % 17;		// 0 ili 16
	p2.set_zbroj(a);
	cout << "Izbor CP-a: " << p2.get_zbroj() << "\n" << endl;
}

void Game::bodovi_idu()
{
	int suma = p1.get_ruka() + p2.get_ruka();
	if (p1.get_zbroj() == suma)
	{
		p1.set_bodovi(p1.get_bodovi() + 1);
		cout << "Bod idu p1 igracu" << "\n";


	} else {
		cout << "p1 je falia" << "\n";
	}
	
	if (p2.get_zbroj() == suma)
	{
		p2.set_bodovi(p2.get_bodovi() + 1);
		cout << "Bod idu p2 igracu" << "\n";


	}
	else {
		cout << "p2 je falia" << "\n";
	}
}


void Game::play()
{
	//runda
	while (p1.get_bodovi() != zadani_br_bodova && p2.get_bodovi() != zadani_br_bodova)
	{
		
		H1->ruka_HP(p1);
		C1->ruka_CP(p2);
		H1->odabirHP(p1);
		C1->odabirCP(p2);
		bodovi_idu();
		cout << "Prvi igrac-bodovi: " << p1.get_bodovi() << "\n";
		cout << "Drugi igrac-bodovi: " << p2.get_bodovi() << "\n" <<endl;
	}

	//pobjednik
	if (p1.get_bodovi() > p2.get_bodovi())
	{
		cout << "Pobjednik je prvi igrac " << "\n";
	}
	else if (p1.get_bodovi() == p2.get_bodovi())
	{
		cout << "Nerijeseno " << "\n";
	}
	else
	{
		cout << "Pobjednik je drugi igrac " << "\n";
	}

}


