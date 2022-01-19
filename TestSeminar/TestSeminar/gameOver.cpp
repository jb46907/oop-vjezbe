#include "gameOver.h"


int GameOver::gameover() {

	

	for (int i = 10; i <= 60; i++) {	//gornja i donja granica
		for (int j = 11; j <= 24; j++) { //brisanje polja za gameover
			gotoxy(i, j); cout << " ";
		}
		gotoxy(i, 10); cout << "±";
		gotoxy(i, 25); cout << "±";
	}
	for (int i = 10; i < 25; i++) {	//liva granica i desna 
		gotoxy(10, i); cout << "±";
		gotoxy(60, i); cout << "±";
	}
	//for (int i = 10; i < 25; i++) {	//desna granica
	//	gotoxy(60, i); cout << "±";
	//}

	{
		//izgled gameover zaslon
		gotoxy(12, 11); cout << "  ___                      ___";
		gotoxy(12, 12); cout << " / __| __ _  _ __   ___   / _ \\ __ __ ___  _ _ ";
		gotoxy(12, 13); cout << "| (_ |/ _` || '  \\ / -_) | (_) |\\ V // -_)| '_|";
		gotoxy(12, 14); cout << " \\___|\\__,_||_|_|_|\\___|  \\___/  \\_/ \\___||_|";
		gotoxy(28, 16); cout << "You are dead!";
		gotoxy(31, 18); cout << "SCORE: " << score;

		PlaySound(TEXT("arcaderetrogameover.wav"), NULL, SND_ASYNC);

		gotoxy(29, 21); cout << "PLAY AGAIN?";
	}

	int set[] = { 12, 7 };	//postavljanje boje teksta
	int counter = 1;
	char key;	//liva ili desan key strelica 

	highScore();

	while (1) {

		color(set[0]);
		gotoxy(30, 22); cout << "YES";

		color(set[1]);
		gotoxy(35, 22); cout << "NO!";

		key = _getch();	//unos znaka

		//strelice livo i desno
		if (key == 75 && counter == 2) {
			PlaySound(TEXT("arcadegamejumpcoin.wav"), NULL, SND_SYNC); //play sound
			counter--;
		}
		if (key == 77 && counter == 1) {
			PlaySound(TEXT("arcadegamejumpcoin.wav"), NULL, SND_SYNC); //play sound
			counter++;
		}
		if (key == '\r') {
			if (counter == 1) {		//play again YES
				return 1;
			}
			else if (counter == 2) {	//play again NO
				set[1] = 7;
				color(set[1]);
				return 0;
			}
		}
		//postavljanje boje teksta i zavisnosti o counteru
		set[0] = 7; set[1] = 7;
		if (counter == 1) {
			set[0] = 12;
		}
		if (counter == 2) {
			set[1] = 12;
		}
	}
}

void GameOver::highScore() {

	int hScore = 0;


	ifstream inFile("highscore.txt");
	if (!inFile.is_open()) {
		ofstream outFile("highscore.txt");
		if (!outFile.is_open()) {
			return;
		}
		outFile.close();
		//return;
	}
	inFile >> hScore;
	inFile.close();

	ofstream outFile("highscore.txt");
	if (!outFile.is_open()) {
		return;
	}
	if (hScore < score) {
		outFile << score;
	}
	else {
		outFile << hScore;
	}
	score = hScore;


	outFile.close();
}

/*void GameOver::gotoxy(int x, int y) {
	COORD cPosition;
	cPosition.X = x;
	cPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPosition);
}

void GameOver::color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}*/