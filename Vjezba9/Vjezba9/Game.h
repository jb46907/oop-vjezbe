#pragma once
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>


using namespace std;

//bazna klasa-predstavlja igraca
class Player {
	int bodovi = 0;
	int ruka = 0;	//broj prstiju na ruci
	int zbroj = 0;

public:
	void set_bodovi(int b) { bodovi = b; }
	int get_bodovi() { return bodovi; }
	int get_ruka() { return ruka; }
	void set_ruka(int broj) { ruka = broj; }
	int get_zbroj() { return zbroj; }
	void set_zbroj(int a) { zbroj = a; }
};


//nasljedena klasa
class HumanPlayer : public Player {

public:
	void ruka_HP(Player& p1);
	void odabirHP(Player& p1);
	friend class Player;
	

	//virtual int f()const { return 0; };
};



//nasljedena klasa
class ComputerPlayer : public Player {

public:
	void ruka_CP(Player& p2);
	void odabirCP(Player& p2);
	friend class Player;

	//virtual int f()const { return 1; };
};


//game bi trebala sadrzavati pravila igre, igrace, rezultat
class Game {
	int zadani_br_bodova = 3;
	//HumanPlayer* H1;
	//ComputerPlayer* C1;
	
	Player& p1;
	Player& p2;

public:
	HumanPlayer* H1;
	ComputerPlayer* C1;
	Game(HumanPlayer& h1, ComputerPlayer& c1) : p1(h1), p2(c1) { }	//konstruktor s parametrima
	//void HP_or_CP(Player* p1);
	void bodovi_idu();
	void play();
};
