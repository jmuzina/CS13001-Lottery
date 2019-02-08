// Lottery Game
// Project #6 Lottery
// CS 13011
// Joseph Muzina
// 09/28/2018

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lottery.h"

using std::cout; using std::cin; using std::endl;

// Number of lottery numbers
const int arraySize = 20;

int main()
{
	int wins[arraySize];
	assign(wins);
	draw(wins);
	int userInput = entry();
	check(userInput, wins);
	printOut(userInput, wins);

	system("pause");
}

// Initializes all elements of array wins[] to 0
void assign(int wins[])
{
	for (int i = 0; i < arraySize; ++i)
		wins[i] = 0;
}

// Fills array wins[] with 20 random numbers
void draw(int wins[])
{
	srand(time(nullptr));

	int numSelected = 0;

	while (numSelected < arraySize)
	{
		int randNum = rand() % 100 + 1;
		bool alreadyDrawn = check(randNum, wins);

		if (!alreadyDrawn)
		{
			wins[numSelected] = randNum;
			++numSelected;
		}
	}
}

// Returns user input
int entry()
{
	cout << "Enter a number from 1 to 100: ";
	int input;
	cin >> input;
	return input;
}

// Returns whether or not the user entered one of the random lottery numbers
bool check(int input, int wins[])
{
	// Whether or not the input is in the array already
	bool inArray;

	for (int i = 0; i < arraySize; ++i)
	{
		if (wins[i] == input)
		{
			inArray = true;
			break;
		}
		else
			inArray = false;
	}
	return inArray;
}

// Displays Lottery numbers and whether user won
void printOut(int x, int wins[])
{
	cout << "The lottery numbers were: " << endl;
	for (int i = 0; i < arraySize; ++i)
		cout << wins[i] << endl;
	cout << endl << "You entered " << x << ". " << endl;

	// Whether or not the user won
	bool won = check(x, wins);

	if (won)
		cout << "Congratulations, you won! " << endl << endl;
	else
		cout << "Sorry, you did not win. Try again!" << endl << endl;
}