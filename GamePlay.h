#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Helper.h"
#include <thread>         // std::this_thread::sleep_for

using namespace std;

class GamePlay {

private:
	int* ShuffleNumbers(int* array);
	int* RandomShuffleNumbers();
	void PrintMatrix(int* array, int numberOfMatrix);
	void DisplayTimer(int counter);
	int* Swap(int* array);
	int GetResult(int* orgArr, int* swappedArr);
	void DisplayResult(bool isWon, int totalGuesses);
	void PlayAndDisplayResult(int* shuffledArray, int* orgArray);
	void DisplayTryCounter(int counter);
public:
	int numberOfMatrix;
	int numberOfTry;
	void PlayGame();
	void DisplayTopMenu();
};


void GamePlay::PlayGame() {

	DisplayTopMenu();

	//shuffle numbers to guess
	int* array = RandomShuffleNumbers();

	//copy origional array 
	int* orgArray = Helper::CopyArray(array, numberOfMatrix);

	cout << "10 Seconds to memorise" << endl;
	PrintMatrix(array, numberOfMatrix);
	DisplayTimer(9);

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
	while (counter <= numberOfTry) {
		int* swappedArray = Swap(shuffledArray);
		successRate = GetResult(orgArray, swappedArray);
		if (successRate == numberOfMatrix) {
			DisplayResult(true, successRate);
			break;
		}
		DisplayTryCounter(counter);

		PrintMatrix(swappedArray, numberOfMatrix);
		counter++;
	}
	bool isWon = successRate == numberOfMatrix;
	DisplayResult(isWon, successRate);
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
	cout << "Total Correct Guesses: " << totalGuesses;

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

int* GamePlay::Swap(int* array) {
	int first, second;
	cout << "Enter number:";
	cin >> first;
	cout << "Swap with number:";
	cin >> second;
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
	cout << "------- F1 : How to play, F2 : Start Game, F3 : Quit Game -------\n\n\n";
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
	cout << "___________________________" << endl;
	int idx = 0;
	for (int j = 1; j <= numberOfMatrix; j++) {
		if (j % 3 == 0) {
			cout << "|       |         |       |" << endl;
			cout << "|  " << array[idx] << "   |   " << array[idx + 1] << "    |   " << array[idx + 2] << "  |" << endl;
			cout << "|_______|_________|_______|" << endl;
			idx += 3;
		}
	}
}

void GamePlay::DisplayTimer(int counter) {
	while (counter >= 1)
	{
		cout << "\rTime remaining: 00:0" << counter << flush;
		Sleep(1000);
		counter--;
	}
}