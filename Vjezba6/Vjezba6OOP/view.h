#pragma once

#include "controller.h"
#include <iostream>
#include <string>

using namespace std;

class HangmanView {
	friend class HangmanModel;
	friend class HangmanController;
public:
	void displayHangman(string title, bool top = true, bool bottom = true);
	void displayCurrentProgress(int guessCount = 0);
	void displayUsedLetters(string letter, char from, char to);
	void lettersInput(string input);

};

