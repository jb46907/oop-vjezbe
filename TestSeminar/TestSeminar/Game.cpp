#include "Game.h"

void gotoxy(int x, int y) {
	COORD cPosition;
	cPosition.X = x;
	cPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPosition);
}

void setcursor(bool visible, DWORD size)
{
	if (size == 0)
		size = 20;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &lpCursor);
}

void color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void Game::drawBorder() {
	for (int i = 0; i <= SCREEN_WIDTH; i++) {	//gornja i donja granica
		gotoxy(i, 0); cout << "±";
		gotoxy(i, SCREEN_HEIGHT); cout << "±";
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++) {	//liva granica
		gotoxy(0, i); cout << "±";
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++) {	//desna granica
		gotoxy(SCREEN_WIDTH, i); cout << "±";
	}

}


//iscrtavanje granice

