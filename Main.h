#include <iostream>
#include <windows.h>
#include <conio.h>
#include "GamePlay.h"
using namespace std;


class Main {
private:
	void PlayGame();
public:
	int SelectMenu();

};

int Main::SelectMenu() {
	int count = 0;
	MainScreens mainScreen;
	while (1)
	{
		unsigned char x = _getch();
		if (0 == x)
		{
			x = _getch();
		}
		if (x == 59) {
			mainScreen.DisplayInstruction();
		}
		if (x == 60) {
			PlayGame();
		}
		if (x == 61)
		{
			if (mainScreen.QuitGame() == 0)
			{
				exit(0);
			}
			mainScreen.ReinitialiseScreen();
		}
	}
	return 0;
}

void Main::PlayGame() {
	system("cls");
	GamePlay gamePlay;
	gamePlay.numberOfMatrix = 9;
	gamePlay.numberOfTry = 10;
	gamePlay.timeToMemorise = 9;
	gamePlay.PlayGame();
}
