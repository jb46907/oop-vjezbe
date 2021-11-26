#include "view.h"
#include "controller.h"

void HangmanView::displayHangman(string strScreen, bool top, bool bottom)
{
	if (top) {
		cout << "########################################" << endl;
		cout << "#";
	}
	else {
		cout << "#";
	}
	bool space = true;

	for (int i = strScreen.length(); i < 38; i++) {
		if (space) {
			strScreen = " " + strScreen;
		}
		else {
			strScreen = strScreen + " ";
		}
		space = !space;
	}
	cout << strScreen.c_str();

	if (bottom) {
		cout << "#" << endl;
		cout << "#--------------------------------------#" << endl;
	}
	else {
		cout << "#" << endl;
	}
}

void HangmanView::displayCurrentProgress(int guessCount)
{
	displayHangman(" ==++=++=====+=", false, false);
	displayHangman("  || //     |", false, false);
	
	if (guessCount >= 1) {
		displayHangman("  ||//      O", false, false);
	}
	else {
		displayHangman("  ||//       ", false, false);
	}
	
	if (guessCount == 2) {
		displayHangman("  ||/      /", false, false);
	}
	
	if (guessCount == 3) {
		displayHangman("  ||/      /|", false, false);
	}
	
	if (guessCount >= 4) {
		displayHangman("   ||/      /|\\", false, false);
	}
	else if (!(guessCount == 2) && !(guessCount == 3)) {
		displayHangman("  ||/        ", false, false);
	}

	if (guessCount >= 5) {
		displayHangman("   ||        |", false, false);
	}
	else {
		displayHangman("   ||         ", false, false);
	}

	if (guessCount == 6) {
		displayHangman("  ||       /", false, false);
	}

	if (guessCount >= 7) {
		displayHangman("   ||       / \\", false, false);
	}
	else if(!(guessCount == 6)){
		displayHangman("  ||        ", false, false);
	}
	displayHangman("||       ", false, false);
	displayHangman("_____||______     ", false, false);
}

void HangmanView::displayUsedLetters(string letter, char from, char to)
{
	string s;

	for (char i = from; i <= to; i++) {
		if (letter.find(i) == letter.npos) {
			s += "  ";
		}
		else {
			s += i;
			s += " ";

		}
	}
	displayHangman(s, false, false);
}

void HangmanView::lettersInput(string input)
{
	displayHangman("~  Used Letters  ~");
	displayUsedLetters(input, 'A', 'I');
	displayUsedLetters(input, 'J', 'R');
	displayUsedLetters(input, 'S', 'Z');
}
