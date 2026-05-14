#include <iostream>
#include <cstdio>
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

using namespace std;

int main()
{
	// Disable buffering so prompts appear immediately in the console.
	setvbuf(stdout, NULL, _IONBF, 0);

	ReversiBoard myBoard;
	ReversiConsoleView myConsoleView(&myBoard);

	int column;
	int row;
	bool isWhitesTurn = true;

	// Keep reading moves until the user stops input or the stream fails.
	while (cin)
	{
		// Redraw the board before every move.
		myConsoleView.print();

		// The turn switch is a simple boolean flip.
		cout << (isWhitesTurn ? "White's Turn" : "Black's Turn") << endl;

		cout << "Enter column: ";
		if (!(cin >> column))
		{
			break;
		}

		cout << "Enter row: ";
		if (!(cin >> row))
		{
			break;
		}

		// The board decides whether the move is legal.
		if (myBoard.setFieldState(column, row, isWhitesTurn ? WHITE : BLACK))
		{
			// Toggle the turn only after a successful move.
			isWhitesTurn = !isWhitesTurn;
		}
		else
		{
			// Invalid moves are rejected and the same player tries again.
			cout << "Invalid move. Try again." << endl;
		}
	}

	return 0;
}
