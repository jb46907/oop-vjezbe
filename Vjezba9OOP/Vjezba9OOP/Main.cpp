#include "Game.h"

int main()
{
	srand(time(NULL));

	HumanPlayer hPlayer1;
	ComputerPlayer cPlayer1;
	Game game1(hPlayer1, cPlayer1);

	game1.play();
}