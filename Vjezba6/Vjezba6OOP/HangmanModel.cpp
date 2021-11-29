#include "HangmanModel.h"

HangmanModel::HangmanModel()
{
	vector<string> allMovies;
	ifstream fileMovie("movie.txt");

	if (fileMovie.is_open()) {
		while (getline(fileMovie, movie)) {
			allMovies.push_back(movie);
		}
		int random = rand() % allMovies.size();

		movie = allMovies.at(random);
		fileMovie.close();
	}

	transform(movie.begin(), movie.end(), movie.begin(), ::toupper);

	setMovie(movie);
}

bool HangmanModel::setinGame(bool game)
{
	inGame = game;
	return inGame;
}

string HangmanModel::setGuessMovie(char letter)
{
	guessMovie += letter;
	return guessMovie;
}

string HangmanModel::setMovie(string m)
{
	movie = m;
	return movie;
}

string HangmanModel::getMovie()
{
	return movie;
}

string HangmanModel::getGuessMovie()
{
	return guessMovie;
}

int HangmanModel::getLives() const
{
	return lives;
}

bool HangmanModel::getinGame()
{
	return inGame;
}

int HangmanModel::setLives(int life)
{
	lives = life;
	return lives;
}
