#include "controller.h"
#include "view.h"

bool HangmanController::checkLetter(string word, string guessed, HangmanView& a)
{
	bool won = true;
	string str;
	for (int i = 0; i < word.length(); i++) {
		if (guessed.find(word[i]) == string::npos) {
			won = false;
			str += "_ ";
			
		}
		else {
			str += word[i];
			str += " ";
		}
	}
	a.displayHangman(str, false);
	return won;
}

int HangmanController::checkLives(string word, string guessed)
{
	int lives = 0;
	for (int i = 0; i < guessed.length(); i++) {
		if (word.find(guessed[i]) == string::npos) {
			lives++;
		}
	}
	return lives;
}

char HangmanController::userEntry()
{
	char x;
	cout << ">";
	cin >> x;
	return x;
}

void HangmanController::checkGame(bool win, HangmanView& a)
{
	if (win) {
		a.displayHangman("YOU WON");
	}
	else {
		a.displayHangman("GAME OVER");
	}
}
