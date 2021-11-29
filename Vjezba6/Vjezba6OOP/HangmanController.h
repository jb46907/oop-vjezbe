#pragma once
#include "HangmanModel.h"
#include "HangmanView.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>

using namespace std;

class HangmanController {
	HangmanModel hm;
	HangmanView hv;

public:
	void userEntry();
	bool checkLetter();
	void updateLives();
	void checkIfGameIsOver();
};