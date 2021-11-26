#include "controller.h"
#include "model.h"
#include "view.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main() {
	srand(time(0));

	string guesses;
	string word;

	HangmanView hv;
	HangmanController hc;
	HangmanModel hm;

	word = hm.randomMovie();
	int tries = 0;
	bool win = false;
	do {
		
		system("cls");
		hv.displayHangman("HANG MAN");
		hv.displayCurrentProgress(tries);
		hv.lettersInput(guesses);
		hv.displayHangman("Guess the movie");
		win = hc.checkLetter(word, guesses, hv);
		if (win) {
			break;
		}
		char x = hc.userEntry();

		if (guesses.find(x) == string::npos) {
			guesses += x;
		}

		tries = hc.checkLives(word, guesses);
		
	} while (tries < 7);
	system("cls");
	hv.displayHangman("HANG MAN");
	hv.displayCurrentProgress(tries);
	
	hc.checkGame(win, hv);
	

	return 0;
}