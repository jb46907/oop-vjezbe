#pragma once
#include "controller.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class HangmanModel {
	int live = 8;
public:
	string randomMovie();
};