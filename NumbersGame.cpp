#include<iostream>
#include "MainScreen.h"
#include "Main.h"
using namespace std;

int main()
{
	MainScreens mainScreen;
	mainScreen.InitializeMainscreen();

	Main main;
	main.SelectMenu();

	//cout << menu;

	system("pause");
	return 0;
}


