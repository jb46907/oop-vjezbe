#include "HangmanController.h"

void HangmanController::userEntry()
{
	char letter;
	while (hm.getLives() >= 0) {
		system("cls");
		if (!hm.getLives()) {
			hv.displayCurrentProgress(hm);
			hv.lettersInput(hm.getGuessMovie());
			hv.displayHangman(hm.getMovie());
			hv.displayHangman("\n");
			break;
		}
		
		hv.displayCurrentProgress(hm);
		hv.lettersInput(hm.getGuessMovie());
		hv.displayHangman(hm.getMovie());
		hv.displayHangman("\n");

		if (checkLetter()) {
			break;
		}
		
		cout << "->";
		cin >> letter;
		letter = toupper(letter);


		if (hm.getGuessMovie().find(letter) == string::npos) {
			hm.setGuessMovie(letter);
			updateLives();
		}
		
	}
	checkIfGameIsOver();
}

bool HangmanController::checkLetter()
{
	hm.setinGame(true);
	string  temp, movie = hm.getMovie();
	int a = hm.getMovie().length();
	for (int i = 0; i < a; i++) {
		if ((hm.getGuessMovie().find(movie[i]) == string::npos) && (movie[i] != ' ')) {
			hm.setinGame(false);
			temp += "_ ";
		}
		else {
			temp += movie[i];
			temp += " ";
		}
	}
	hv.displayHangman(temp);

	return hm.getinGame();
}

void HangmanController::updateLives()
{
	hm.setLives(8);
	int temp = hm.getLives();
	int a = hm.getGuessMovie().length();
	string gusMovie = hm.getGuessMovie();
	for (int i = 0; i < a; i++) {
		if (hm.getMovie().find(gusMovie[i]) == string::npos) {
			temp--;
		}
	}
	hm.setLives(temp);
}

void HangmanController::checkIfGameIsOver()
{
	if (hm.getinGame()) {
		hv.displayHangman("YOU WON!");
	}
	else
	{
		hv.displayHangman("GAME OVER!");
	}
}
