#include <cstdlib>
#include <ctime>
#include <iostream>
#include<string>
#include "Helper.h"

using namespace std;

class GamePlay {

private:
	int* ShuffleNumbers(int* array);
	int* RandomShuffleNumbers();
	void PrintMatrix(int* array, int numberOfMatrix);
	void DisplayTimer(int counter);
	int* Swap(int* array, int first, int second);
	int GetResult(int* orgArr, int* swappedArr);
	void DisplayResult(bool isWon, int totalGuesses);
	void PlayAndDisplayResult(int* shuffledArray, int* orgArray);
	char Select();
	void DisplayTryCounter(int counter);
public:
	int numberOfMatrix;
	int numberOfTry;
	int timeToMemorise;
	void PlayGame();
	void DisplayTopMenu();
};


void GamePlay::PlayGame() {

	//shuffle numbers to guess
	int* array = RandomShuffleNumbers();

	//copy origional array 
	int* orgArray = Helper::CopyArray(array, numberOfMatrix);

	cout << "You have only 10 Seconds to memorise the matrix." << endl;
	PrintMatrix(array, numberOfMatrix);
	DisplayTimer(timeToMemorise);

	system("cls");
	DisplayTopMenu();

	cout << "Start Swapping" << endl;
	cout << "GOOD LUCK!!" << endl;

	int* shuffledArray = ShuffleNumbers(array);
	PrintMatrix(shuffledArray, numberOfMatrix);

	PlayAndDisplayResult(shuffledArray, orgArray);
}

void GamePlay::PlayAndDisplayResult(int* shuffledArray, int* orgArray) {
	int counter = 1;
	DisplayTryCounter(0);
	int successRate = 0;
	string fNum, sNum;
	int firstNum, secondNum;
	while (counter <= numberOfTry) {
		if (sNum == "") {
			if (fNum == "") {
				cout << "Enter number: ";
			}
			//convert char to int value 
			if (fNum == "" || stoi(fNum) < 10) {
				firstNum = Select() - '0';
			}
			if (firstNum < 0) {
				continue;
			}
			fNum += to_string(firstNum);
			cout << firstNum;
			int fNumber = stoi(fNum);
			//using getch only returns first character we wanted to get value more than 10 
			if (fNumber == 0 || fNumber < 10) {
				continue;
			}
		}
		if (sNum == "") {
			cout << "\nSwap with number: ";
		}
		//convert char to int value
		if (sNum == "" || stoi(sNum) < 10) {
			secondNum = Select() - '0';
		}
		if (secondNum < 0) {
			continue;
		}
		//using getch only returns first character we wanted to get value more than 10 
		sNum += to_string(secondNum);
		cout << secondNum;
		int sNumber = stoi(sNum);
		if (sNumber == 0 || sNumber < 10) {
			continue;
		}
		int* swappedArray = Swap(shuffledArray, stoi(fNum), stoi(sNum));
		successRate = GetResult(orgArray, swappedArray);
		if (successRate == numberOfMatrix) {
			break;
		}
		DisplayTryCounter(counter);

		PrintMatrix(swappedArray, numberOfMatrix);
		fNum = "";
		sNum = "";
		firstNum = 0;
		secondNum = 0;
		counter++;
	}
	bool isWon = successRate == numberOfMatrix;
	DisplayResult(isWon, successRate);
	MainScreens mainScreen;
	mainScreen.DisplayMainMenu();
}
void GamePlay::DisplayTryCounter(int counter) {
	cout << "\n\nNumber of Tries Left: " << numberOfTry - counter << "\n\n";

}

void GamePlay::DisplayResult(bool isWon, int totalGuesses) {
	if (isWon) {
		cout << "Congratulations you WON!!" << endl;
	}
	else {
		cout << "Sorry you Lost, try again." << endl;
	}
	cout << "Total Correct Guesses: " << totalGuesses << endl;
}

int GamePlay::GetResult(int* orgArr, int* swappedArr) {
	int successRate = 0;
	for (int i = 0; i < numberOfMatrix; i++)
	{
		if (orgArr[i] == swappedArr[i]) {
			successRate++;
		}
	}
	return successRate;
}
char GamePlay::Select()
{
	MainScreens mainScreen;
	unsigned char x = _getch();
	if (0 == x)
	{
		x = _getch();
	}
	if (x == 59) {
		mainScreen.DisplayInstruction();
		return -1;
	}
	if (x == 61) {
		if (mainScreen.QuitGame() == 0)
		{
			exit(0);
		}
	}
	if (x == '=') {
		return -1;
	}
	return x;
}
int* GamePlay::Swap(int* array, int first, int second) {

	int fIndex = Helper::FindArrayIndex(array, first, numberOfMatrix);
	int sIndex = Helper::FindArrayIndex(array, second, numberOfMatrix);

	int fVal = array[fIndex];
	int sVal = array[sIndex];
	if (fVal > 0 && sVal > 0) {
		array[fIndex] = sVal;
		array[sIndex] = fVal;
	}

	return array;
}

void GamePlay::DisplayTopMenu()
{
	cout << "------- F1 : How to play, F3 : Quit Game -------\n\n\n";
}
int* GamePlay::ShuffleNumbers(int* array) {
	srand(unsigned(std::time(0)));
	//random shuffle origional array
	random_shuffle(array, array + (numberOfMatrix - 1));
	//random shuffle again origional array
	random_shuffle(array, array + (numberOfMatrix - 1));
	return array;
}

int* GamePlay::RandomShuffleNumbers() {
	int* array;
	array = new int[numberOfMatrix];
	srand((unsigned)time(0));
	for (int i = 0; i < numberOfMatrix; i++) {
		//generate random number using rand function
		int rnd = (rand() % 99) + 1;
		int idx = Helper::FindArrayIndex(array, rnd, numberOfMatrix);
		// find index so to check if number is repeatable or
		//check if random number is less than 10 as we only want double digit numbers  
		if (idx > 0 || rnd < 10) {
			--i;
			continue;
		}
		//assign random number to array
		array[i] = rnd;
	}
	return array;
}

void GamePlay::PrintMatrix(int* array, int numberOfMatrix) {
	cout << " ___________________________" << endl;
	int idx = 0;
	for (int j = 1; j <= numberOfMatrix; j++) {
		if (j % 3 == 0) {
			cout << " |       |         |       |" << endl;
			cout << " |  " << array[idx] << "   |   " << array[idx + 1] << "    |   " << array[idx + 2] << "  |" << endl;
			cout << " |_______|_________|_______|" << endl;
			idx += 3;
		}
	}
}

void GamePlay::DisplayTimer(int counter) {
	cout << "\n\n";
	while (counter >= 1)
	{
		cout << "\r Time remaining: 00:0" << counter << flush;
		Sleep(1000);
		counter--;
	}
}