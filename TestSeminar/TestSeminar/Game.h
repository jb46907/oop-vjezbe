#pragma once
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <dos.h> 
#include <windows.h>
#include <time.h>
#include <fstream>
#define SCREEN_WIDTH 70
#define SCREEN_HEIGHT 36
#define GAP_SIZE 10

using namespace std;

void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size);
void color(int color);

class Game {

public:
	//Game();
	void drawBorder();
	void setting();
};




