#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>

using namespace std;

class HangmanModel {
	string movie;
	string guessMovie;
	int lives = 8;
	bool inGame;


public:
	HangmanModel();
	bool setinGame(bool game);
	string setGuessMovie(char letter);
	string setMovie(string m);
	string getMovie();
	string getGuessMovie();
	int getLives() const;
	bool getinGame();
	int setLives(int life);
};