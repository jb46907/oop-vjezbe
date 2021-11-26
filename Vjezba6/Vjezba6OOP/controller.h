#pragma once
#ifndef HANGMANCONTROLLER_h
#define HANGMANCONTROLER
#include "view.h"
#include "model.h"
#include <iostream>
#include <string>

using namespace std;

class HangmanController {
	friend class HangmanView;
	friend class HangmanModel;
public:
	bool checkLetter(string word, string guesses, HangmanView& a);
	int checkLives(string word, string guessed);
	char userEntry();
	void checkGame(bool win, HangmanView& a);
};

#endif
