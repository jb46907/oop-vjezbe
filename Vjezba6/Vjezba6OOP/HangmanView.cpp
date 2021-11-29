#include "HangmanView.h"


void HangmanView::displayCurrentProgress(HangmanModel life)
{
	displayHangman("-------< HANG MAN >-------");
	displayHangman(" ==++=++=====+=");

	if (life.getLives() <= 7) {
		displayHangman("  || //     |");
	}
	else {
		displayHangman("  || //      ");
	}

	if (life.getLives() <= 6) {
		displayHangman("  ||//      O");
	}
	else {
		displayHangman("  ||//       ");
	}

	if (life.getLives() == 5) {
		displayHangman("  ||/      /");
	}
	if (life.getLives() == 4) {
		displayHangman("  ||/      /|");
	}
	if (life.getLives() <= 3) {
		displayHangman("   ||/      /|\\");
	}
	else if (!(life.getLives() == 5) && !(life.getLives() == 4)) {
		displayHangman("  ||/        ");
	}

	if (life.getLives() <= 2) {
		displayHangman("   ||        |");
	}
	else {
		displayHangman("   ||         ");
	}

	if (life.getLives() == 1) {
		displayHangman("  ||       /");
	}
	if (life.getLives() <= 0) {
		displayHangman("   ||       / \\");
	}
	else if (!(life.getLives() == 1)) {
		displayHangman("  ||        ");
	}
	displayHangman("||       ");
	displayHangman("_____||______     ");
	
	displayHangman("\n");
	displayHangman("~  Used Letters  ~");
	
}

void HangmanView::displayUsedLetters(string input, char a, char z)
{
	string letter;
	for (char i = a; i <= z; i++) {
		if (input.find(i) == input.npos) {
			letter += " ";
		}
		else {
			letter += i;
			letter += " ";
		}
	}
	displayHangman(letter);
}

void HangmanView::displayHangman(string HangMan)
{
	bool space = true;
	for (int i = HangMan.length(); i < 38; i++) {
		if (space) {
			HangMan = " " + HangMan;
		}
		else {
			HangMan = HangMan + " ";
		}
		space = !space;
	}

	cout << HangMan.c_str();
	cout << " " << endl;
}

void HangmanView::lettersInput(string input)
{
	displayUsedLetters(input, 'A', 'I');
	displayUsedLetters(input, 'J', 'R');
	displayUsedLetters(input, 'S', 'Z');
	displayHangman("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}
