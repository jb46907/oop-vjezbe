#include "introScreen.h"

#define INTRO_WIDTH 52
#define INTRO_HEIGHT 26

void IntroScreen::introScreen() //intro crtanje i padanje sa zgrade
{
	//Game game;
	system("cls");	//ocisti screen
	game1.drawBorder();	//iscratj granice
	groundPos = 0, changeManAnim = 0, manAnimation = 0, manPosX = 22, manPosY = 24, counter = 0;
	counter = INTRO_HEIGHT;
	manAnimation = 0 + rand() % 3; //random animacija za lika

	for (int i = INTRO_HEIGHT; i < SCREEN_HEIGHT; i += 2) {

		for (int j = INTRO_WIDTH/* - groundPos*/; j > 0; j--) {
			gotoxy(j, i);
			cout << "_";
			if (j % 4 == 0) {
				gotoxy(j, i + 1);
				cout << "|";
			}
			else {
				gotoxy(j, i + 1);
				cout << "_";
			}
		}

	}

	while (1) {
		//	drawingBuilding(); //iscrtavanje zgrade
		//	drawMan();	//iscrtavanje lika
		//
		//	if (counter && changeManAnim == 12) {	//pomicanje zgrade do vrha i podizanje lika
		//
		//		//while (1) {
		//
		//		//	eraseMan();
		//		//	if (manPosY > SCREEN_HEIGHT / 7) {
		//		//		manPosY -= 1;
		//		//		manPosX += 1;
		//		//	}
		//		//	//drawingBuildingUP();
		//		//	drawMan();
		//		//	if (!counter) {	//zapocni igru kada counter dodje do 0
		//		//		break;
		//		//	}
		//		//	Sleep(150);
		//		//	
		//		//	counter -= 2;
		//		//}
		//	}
		//	if (!counter) {	//zapocni igru kada counter dodje do 0
		//		break;
		//	}
		//	Sleep(150);
		//	eraseBuilding();	//brisanje zgrade
		//	eraseMan();
		//	if (groundPos < 36) {		//pomicanje zgrade u livo
		//		groundPos += 4;
		//	}
		//	
		//
		//	if (changeManAnim < 12) {		//promjena animacija od lika
		//		changeManAnim += 1;
		//	}
		//	
		//	counter-=2;
		//}

		//drawingBuilding(); //iscrtavanje zgrade
		drawMan();	//iscrtavanje lika

		if (counter && changeManAnim == 12) {	//pomicanje zgrade do vrha i podizanje lika

			while (1) {

				eraseMan();
				drawingBuilding();
				if (manPosY > SCREEN_HEIGHT / 7) {
					manPosY -= 1;
					manPosX += 1;
				}
				drawingBuildingUP();
				drawMan();
				if (!counter) {	//zapocni igru kada counter dodje do 0
					break;
				}
				Sleep(70);

				counter -= 2;
			}
		}

		if (!counter) {	//zapocni igru kada counter dodje do 0
			break;
		}
		
		Sleep(150);
		eraseBuilding();	//brisanje zgrade
		eraseMan();

		if (groundPos < 36) {		//pomicanje zgrade u livo
			groundPos += 4;
			//Beep(523, 100);
		}
		if (changeManAnim < 12) {		//promjena animacija od lika
			changeManAnim += 1;
		}
		
	}

}

//-----PROMINIT TJ SKRATIT FOR PETLJU
void IntroScreen::drawingBuilding()
{
	 //iscrtaje zgradu dok se skroz ne pomakne ulivo
	if (groundPos < 36) { //iscrtaje zgradu dok se skroz ne pomakne ulivo
		
	}
	else {	//iscrtavanje podizanje zgrade
		for (int i = 26; i < SCREEN_HEIGHT; i++) {

			for (int j = INTRO_WIDTH - groundPos; j > 0; j--) {
				gotoxy(j, i);
				cout << "_";
				gotoxy(SCREEN_WIDTH - j, i);
				cout << "_";
			}
			i++;
			for (int j = INTRO_WIDTH - groundPos; j > 0; j--) {
				if (j % 4 == 0) {
					gotoxy(j, i);
					cout << "|";
					gotoxy(SCREEN_WIDTH - j, i);
					cout << "|";
				}
				else {
					gotoxy(j, i);
					cout << "_";
					gotoxy(SCREEN_WIDTH - j, i);
					cout << "_";
				}
			}
		}
	}
}

void IntroScreen::drawingBuildingUP()
{
	//iscrtavanje podizanje zgrade
	for (int i = counter; i <= counter; i+=2) {

		for (int j = INTRO_WIDTH - groundPos; j > 0; j--) {
			gotoxy(j, i);
			cout << "_";
			gotoxy(SCREEN_WIDTH - j, i);
			cout << "_";
			if (j % 4 == 0) {
				gotoxy(j, i+1);
				cout << "|";
				gotoxy(SCREEN_WIDTH - j, i+1);
				cout << "|";
			}
			else {
				gotoxy(j, i+1);
				cout << "_";
				gotoxy(SCREEN_WIDTH - j, i+1);
				cout << "_";
			}
		}
		
	}
	
}

void IntroScreen::eraseBuilding()
{
	if (groundPos < 36) {
		for (int i = INTRO_HEIGHT; i < SCREEN_HEIGHT; i++) {

			for (int j = INTRO_WIDTH - groundPos; j > INTRO_WIDTH - groundPos - 4; j--) {
				gotoxy(j, i);
				cout << " ";
			}
		}
	}
}


void IntroScreen::drawMan()
{
	switch (manAnimation) {
	case 0:
		switch (changeManAnim) { //animacija lika
		case 0:
			gotoxy(1, 24); cout << "  o";
			gotoxy(1, 25); cout << "///";
			gotoxy(1, 26); cout << "/_)";
			break;
		case 1:
			gotoxy(2, 24); cout << "   o";
			gotoxy(2, 25); cout << " ///";
			gotoxy(2, 26); cout << "/)";
			break;
		case 2:
			gotoxy(4, 24); cout << "  o";
			gotoxy(4, 25); cout << "///";
			gotoxy(4, 26); cout << "/_)";
			break;
		case 3:
			gotoxy(6, 24); cout << "   o";
			gotoxy(6, 25); cout << " ///";
			gotoxy(6, 26); cout << "/)";
			break;
		case 4:
			gotoxy(8, 24); cout << "_ o";
			gotoxy(8, 25); cout << " /\\";
			gotoxy(8, 26); cout << "/_)";
			break;
		case 5:
			gotoxy(10, 24); cout << " /";
			gotoxy(10, 25); cout << "/ \\o";
			gotoxy(10, 26); cout << "___\\";
			break;
		case 6:
			gotoxy(10, 24); cout << "__ __";
			gotoxy(10, 25); cout << "  |o";
			gotoxy(10, 26); cout << "__|";
			break;
		case 7:
			gotoxy(10, 24); cout << " \\";
			gotoxy(10, 25); cout << " /\\";
			gotoxy(10, 26); cout << "|o";
			break;
		case 8:
			gotoxy(10, 25); cout << " __|";
			gotoxy(10, 26); cout << "/o_|";
			break;
		case 9:
			gotoxy(12, 24); cout << "\\o ";
			gotoxy(12, 25); cout << " \\ /";
			gotoxy(12, 26); cout << "__|";
			break;
		case 10:
			gotoxy(14, 24); cout << " o";
			gotoxy(14, 25); cout << "/\\";
			gotoxy(14, 26); cout << "/\\";
			break;

		case 11:
			gotoxy(18, 22); cout << "  o /";
			gotoxy(18, 23); cout << " /";
			gotoxy(18, 24); cout << "/ )";
			break;
		case 12:
			gotoxy(manPosX, manPosY); cout << "\\___/o";
			break;
		case 13:
			gotoxy(manPosX, manPosY); cout << "o\\___/";
			break;
		}
		break;
	case 1:
		switch (changeManAnim) { //animacija lika
		case 0:
			gotoxy(1, 24); cout << "  o";
			gotoxy(1, 25); cout << "///";
			gotoxy(1, 26); cout << "/_)";
			break;
		case 1:
			gotoxy(2, 24); cout << "   o";
			gotoxy(2, 25); cout << " ///";
			gotoxy(2, 26); cout << "/)";
			break;
		case 2:
			gotoxy(4, 24); cout << "  o";
			gotoxy(4, 25); cout << "///";
			gotoxy(4, 26); cout << "/_)";
			break;
		case 3:
			gotoxy(6, 24); cout << "   o";
			gotoxy(6, 25); cout << " ///";
			gotoxy(6, 26); cout << "/)";
			break;
		case 4:
			gotoxy(8, 24); cout << "_ o";
			gotoxy(8, 25); cout << " /\\";
			gotoxy(8, 26); cout << "/_)";
			break;
		case 5:
			gotoxy(10, 24); cout << "__|";
			gotoxy(10, 25); cout << "  \\o ";
			gotoxy(10, 26); cout << "__(_\\";
			break;
		case 6:
			gotoxy(10, 24); cout << "\\ /";
			gotoxy(10, 25); cout << " |";
			gotoxy(10, 26); cout << "/o\\";
			break;
		case 7:
			gotoxy(10, 24); cout << "   |__";
			gotoxy(10, 25); cout << " o/";
			gotoxy(10, 26); cout << "/_)";
			break;
		case 8:
			gotoxy(10, 25); cout << "o/__";
			gotoxy(10, 26); cout << "|__(\\";
			break;
		case 9:
			gotoxy(12, 24); cout << "o _";
			gotoxy(12, 25); cout << "/\\";
			gotoxy(12, 26); cout << "/_|";
			break;
		case 10:
			gotoxy(14, 24); cout << " o";
			gotoxy(14, 25); cout << "/\\";
			gotoxy(14, 26); cout << "/\\";
			break;

		case 11:
			gotoxy(18, 22); cout << "  o /";
			gotoxy(18, 23); cout << " /";
			gotoxy(18, 24); cout << "/ )";
			break;
		case 12:
			gotoxy(manPosX, manPosY); cout << "\\___/o";
			break;
		case 13:
			gotoxy(manPosX, manPosY); cout << "o\\___/";
			break;
		}
		break;
	case 2:
		switch (changeManAnim) { //animacija lika
		case 0:
			gotoxy(2, 24); cout << "  o";
			gotoxy(2, 25); cout << "///";
			gotoxy(2, 26); cout << "/_)";
			break;
		case 1:
			gotoxy(4, 24); cout << "   o";
			gotoxy(4, 25); cout << " ///";
			gotoxy(4, 26); cout << "/)";
			break;
		case 2:
			gotoxy(8, 24); cout << "  o";
			gotoxy(8, 25); cout << "///";
			gotoxy(8, 26); cout << "/_)";
			break;
		case 3:
			gotoxy(10, 24); cout << "_ o";
			gotoxy(10, 25); cout << " /\\";
			gotoxy(10, 26); cout << "/_)";
			break;
		case 4:
			gotoxy(12, 24); cout << "__|";
			gotoxy(12, 25); cout << "  \\o ";
			gotoxy(12, 26); cout << "__(_\\";
			break;
		case 5:
			gotoxy(12, 24); cout << "\\ /";
			gotoxy(12, 25); cout << " |";
			gotoxy(12, 26); cout << "/o\\";
			break;
		case 6:
			gotoxy(12, 24); cout << "  __";
			gotoxy(12, 25); cout << " /";
			gotoxy(12, 26); cout << "o|";
			break;
		case 7:
			gotoxy(14, 24); cout << "__o";
			gotoxy(14, 25); cout << "  |";
			gotoxy(14, 26); cout << "_<<";
			break;
		case 8:
			gotoxy(14, 24); cout << " |o";
			gotoxy(14, 25); cout << " /";
			gotoxy(14, 26); cout << "|";
			break;
		case 9:
			gotoxy(16, 22); cout << "  |o";
			gotoxy(16, 23); cout << "/|/";
			
			break;
		case 10:
			gotoxy(20, 22); cout << " /\\/";
			gotoxy(20, 23); cout << "o\\";
			
			break;

		case 11:
			gotoxy(24, 22); cout << "o__";
			gotoxy(24, 23); cout << "|  \\";
			
			break;
		case 12:
			gotoxy(manPosX, manPosY); cout << "o\\___/";
			break;
		case 13:
			gotoxy(manPosX, manPosY); cout << "\\___/o";
			break;
		}
		break;
	}
}

void IntroScreen::eraseMan()
{
	switch (manAnimation) {
	case 0:
		switch (changeManAnim) { //brisanje lika
		case 0:
			gotoxy(1, 24); cout << "   ";
			gotoxy(1, 25); cout << "   ";
			gotoxy(1, 26); cout << "___";
			break;

		case 1:
			gotoxy(2, 24); cout << "    ";
			gotoxy(2, 25); cout << "    ";
			gotoxy(2, 26); cout << "__";
			break;

		case 2:
			gotoxy(4, 24); cout << "   ";
			gotoxy(4, 25); cout << "   ";
			gotoxy(4, 26); cout << "___";
			break;

		case 3:
			gotoxy(6, 24); cout << "    ";
			gotoxy(6, 25); cout << "    ";
			gotoxy(6, 26); cout << "__";
			break;

		case 4:
			gotoxy(8, 24); cout << "   ";
			gotoxy(8, 25); cout << "   ";
			gotoxy(8, 26); cout << "___";
			break;

		case 5:
			gotoxy(10, 24); cout << "  ";
			gotoxy(10, 25); cout << "    ";
			gotoxy(10, 26); cout << "____";
			break;

		case 6:
			gotoxy(10, 24); cout << "     ";
			gotoxy(10, 25); cout << "    ";
			gotoxy(10, 26); cout << "___";
			break;

		case 7:
			gotoxy(10, 24); cout << "  ";
			gotoxy(10, 25); cout << "   ";
			gotoxy(10, 26); cout << "__";
			break;

		case 8:
			gotoxy(10, 25); cout << "    ";
			gotoxy(10, 26); cout << "____";
			break;

		case 9:
			gotoxy(12, 24); cout << "   ";
			gotoxy(12, 25); cout << "    ";
			gotoxy(12, 26); cout << "___";
			break;

		case 10:
			gotoxy(14, 24); cout << "  ";
			gotoxy(14, 25); cout << "  ";
			gotoxy(14, 26); cout << "__";
			break;

		case 11:
			gotoxy(18, 22); cout << "     ";
			gotoxy(18, 23); cout << "  ";
			gotoxy(18, 24); cout << "   ";
			break;

		case 12:
			gotoxy(manPosX, manPosY); cout << "      ";
			break;

		case 13:
			gotoxy(manPosX, manPosY); cout << "      ";
			break;

		}
		break;
	case 1:
		switch (changeManAnim) { //brisanje lika
		case 0:
			gotoxy(1, 24); cout << "   ";
			gotoxy(1, 25); cout << "   ";
			gotoxy(1, 26); cout << "___";
			break;

		case 1:
			gotoxy(2, 24); cout << "    ";
			gotoxy(2, 25); cout << "    ";
			gotoxy(2, 26); cout << "__";
			break;

		case 2:
			gotoxy(4, 24); cout << "   ";
			gotoxy(4, 25); cout << "   ";
			gotoxy(4, 26); cout << "___";
			break;

		case 3:
			gotoxy(6, 24); cout << "    ";
			gotoxy(6, 25); cout << "    ";
			gotoxy(6, 26); cout << "__";
			break;

		case 4:
			gotoxy(8, 24); cout << "   ";
			gotoxy(8, 25); cout << "   ";
			gotoxy(8, 26); cout << "___";
			break;

		case 5:
			gotoxy(10, 24); cout << "   ";
			gotoxy(10, 25); cout << "    ";
			gotoxy(10, 26); cout << "_____";
			break;

		case 6:
			gotoxy(10, 24); cout << "   ";
			gotoxy(10, 25); cout << "  ";
			gotoxy(10, 26); cout << "___";
			break;

		case 7:
			gotoxy(10, 24); cout << "      ";
			gotoxy(10, 25); cout << "   ";
			gotoxy(10, 26); cout << "___";
			break;

		case 8:
			gotoxy(10, 25); cout << "    ";
			gotoxy(10, 26);	cout << "______";
			break;

		case 9:
			gotoxy(12, 24); cout << "   ";
			gotoxy(12, 25); cout << "  ";
			gotoxy(12, 26); cout << "___";
			break;

		case 10:
			gotoxy(14, 24); cout << "  ";
			gotoxy(14, 25); cout << "  ";
			gotoxy(14, 26); cout << "__";
			break;

		case 11:
			gotoxy(18, 22); cout << "     ";
			gotoxy(18, 23); cout << "  ";
			gotoxy(18, 24); cout << "   ";
			break;

		case 12:
			gotoxy(manPosX, manPosY); cout << "      ";
			break;

		case 13:
			gotoxy(manPosX, manPosY); cout << "      ";
			break;

		}
		break;
	case 2:
		switch (changeManAnim) { //brisanje lika
		case 0:
			gotoxy(2, 24); cout << "   ";
			gotoxy(2, 25); cout << "   ";
			gotoxy(2, 26); cout << "___";
			break;

		case 1:
			gotoxy(4, 24); cout << "    ";
			gotoxy(4, 25); cout << "    ";
			gotoxy(4, 26); cout << "__";
			break;

		case 2:
			gotoxy(8, 24); cout << "   ";
			gotoxy(8, 25); cout << "   ";
			gotoxy(8, 26); cout << "___";
			break;

		case 3:
			gotoxy(10, 24); cout << "   ";
			gotoxy(10, 25); cout << "   ";
			gotoxy(10, 26); cout << "___";
			break;

		case 4:
			gotoxy(12, 24); cout << "   ";
			gotoxy(12, 25); cout << "     ";
			gotoxy(12, 26); cout << "_____";
			break;

		case 5:
			gotoxy(12, 24); cout << "   ";
			gotoxy(12, 25); cout << "  ";
			gotoxy(12, 26); cout << "___";
			break;

		case 6:
			gotoxy(12, 24); cout << "    ";
			gotoxy(12, 25); cout << "  ";
			gotoxy(12, 26); cout << "__";
			break;

		case 7:
			gotoxy(14, 24); cout << "   ";
			gotoxy(14, 25); cout << "   ";
			gotoxy(14, 26); cout << "___";
			break;

		case 8:
			gotoxy(14, 24); cout << "   ";
			gotoxy(14, 25); cout << "  ";
			gotoxy(14, 26);	cout << "_";
			break;

		case 9:
			gotoxy(16, 22); cout << "    ";
			gotoxy(16, 23); cout << "   ";
			break;

		case 10:
			gotoxy(20, 22); cout << "    ";
			gotoxy(20, 23); cout << "  ";
			break;

		case 11:
			gotoxy(24, 22); cout << "   ";
			gotoxy(24, 23); cout << "    ";
			break;

		case 12:
			gotoxy(manPosX, manPosY); cout << "      ";
			break;

		case 13:
			gotoxy(manPosX, manPosY); cout << "      ";
			break;

		}
		break;
	}
}

//void IntroScreen::gotoxy(int x, int y) {
//	COORD cPosition;
//	cPosition.X = x;
//	cPosition.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPosition);
//}
