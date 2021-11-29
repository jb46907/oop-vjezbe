#pragma once
#include "HangmanModel.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>

using namespace std;

class HangmanView {
	HangmanModel hm;
public:

	void displayCurrentProgress(HangmanModel life);
	void displayUsedLetters(string input, char a, char z);
	void displayHangman(string HangMan);
	void lettersInput(string input);
};