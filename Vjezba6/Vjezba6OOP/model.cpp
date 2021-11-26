#include "model.h"


using namespace std;

string HangmanModel::randomMovie()
{
	string word;
	vector<string> v;

	ifstream file("movie.txt");

	if (file.is_open()) {
		while (getline(file, word)) {
			v.push_back(word);
		}
		int random = rand() % v.size();

		word = v.at(random);
		file.close();
	}
	transform(word.begin(), word.end(), word.begin(), ::toupper);
	return word;
}
