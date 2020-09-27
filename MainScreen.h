#include<iostream>
using namespace std;


class MainScreens {
public:
	void InitializeMainscreen();
	void DisplayWelcome();
	void DisplayGameName();
	void DisplayMainMenu();
	void DisplayInstruction();
	int QuitGame();
	void ReinitialiseScreen();
};
void MainScreens::InitializeMainscreen() {
	//Welcome
	system("cls");
	DisplayWelcome();

	// displaying game name *number shuffle*
	DisplayGameName();

	//displaying main menu 
	DisplayMainMenu();
}

void MainScreens::DisplayMainMenu()
{
	cout << "			. ___________________ MAIN MENU________________ . " << endl;
	cout << "			.                                               . " << endl;
	cout << "			.              Press F1 : How to play           . " << endl;
	cout << "			.              Press F2 : Start Game            . " << endl;
	cout << "			.              Press F3 : Quit Game             . " << endl;
	cout << "			. _____________________________________________ . " << endl << endl;
}
//void DisplayWelcome();
void MainScreens::DisplayWelcome()
{
	cout << "	**           **     *********   **            **********   **********    **      **     ****** " << endl;
	cout << "	**           **    **           **           **           **        **  ** **  ** **   **  " << endl;
	cout << "	**           **    **           **           **           **        **  **   **   **   **  " << endl;
	cout << "	**           **    *********    **           **           **        **  **        **   ******  " << endl;
	cout << "	**    **     **    **           **           **           **        **  **        **   **     " << endl;
	cout << "	**  **  **   **    **           **           **           **        **  **        **   **    " << endl;
	cout << "	** **     ** **     *********   **********    *********    **********   **        **    ******  " << endl << endl;
}

void MainScreens::DisplayGameName()
{

	cout << "     ###  ###         ##  #  #  # ## ## ####  #### #####         ##### #   # #  #  #### #### #     #####" << endl;
	cout << "      #   # #         # # #  #  # # # # #  #  #    #   #         #     #   # #  #  #    #    #     #    " << endl;
	cout << "      #   # #         #  ##  #  # #   # ####  #### #####         ##### ##### #  #  ###  ###  #     #### " << endl;
	cout << "      #   # #         #  ##  #  # #   # #  #  #    #   #             # #   # #  #  #    #    #     #    " << endl;
	cout << "      #   ###         #   #  #### #   # ####  #### #   #         ##### #   # ####  #    #    ####  #####" << endl << endl;

}


int MainScreens::QuitGame() {
	char val;
	cout << "Are you sure, you want to quit this game? Enter y or n:";
	cin >> val;
	if (val == 'Y' || val == 'y') {
		return 0;
	}
	return 1;
}

void MainScreens::ReinitialiseScreen() {
	system("cls");
	InitializeMainscreen();
}

void MainScreens::DisplayInstruction()
{
	cout << "		__________________________INSTRUCTIONS_____________________________" << endl;
	cout << "		*                                                                 *" << endl;
	cout << "		*           1. Press F2 start the game                            *" << endl;
	cout << "		*           2. When player is ready press S to shuffle            *" << endl;
	cout << "		*              the numbers in the boxes                           *" << endl;
	cout << "		*           3. Start putting numbers back to the original place.  *" << endl;
	cout << "		*           4. if player manages to finish the game in 3min.      *" << endl;
	cout << "		*              the player wins or else they will lose             *" << endl;
	cout << "		*_________________________________________________________________*" << endl;
}