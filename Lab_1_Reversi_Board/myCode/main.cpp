/* main.cpp
 * Simple main for running the Reversi console game.
 * Learning notes: shows object construction, passing pointer to view,
 * input with `cin`, and a basic game loop with conditionals.
 */

#include <iostream>
#include <cstdlib>
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

using namespace std;

int main()
{
	// Disable output buffering so console updates appear immediately.
	setvbuf(stdout, NULL, _IONBF, 0);

	// Create board (automatic storage) and pass its address to the view.
	// OOP note: constructing `myBoard` calls its constructor automatically.
	ReversiBoard myBoard;
	ReversiConsoleView myConsoleView(&myBoard); // pass pointer to avoid copying

	int column, row;
	bool isWhitesTurn = true; // boolean flag to track whose turn it is

	// Main game loop: demonstrates `do { } while` and conditional branching.
	do
	{
		if (isWhitesTurn)
		{
			myConsoleView.print();
			cout << "White's Turn" << endl;
			cout << "Enter Column: ";
			cin >> column; // input: beware invalid input in exams
			cout << "Enter Row: ";
			cin >> row;

			// If move valid, swap turn (example of function call and boolean result)
			if (myBoard.setFieldState(column, row, WHITE))
			{
				isWhitesTurn = false; // switch player
			}
		}
		else
		{
			myConsoleView.print();
			cout << "Black's Turn" << endl;
			cout << "Enter Column: ";
			cin >> column;
			cout << "Enter Row: ";
			cin >> row;

			if (myBoard.setFieldState(column, row, BLACK))
			{
				isWhitesTurn = true;
			}
		}
	} while (true); // Infinite loop: exam note -> usually you'd check for game end

	return 0;
}
