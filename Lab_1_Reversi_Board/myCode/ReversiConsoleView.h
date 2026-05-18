/* ReversiConsoleView.h
 * Simple notes: console view for printing the board.
 * Learning: demonstrates pointer member to another object (ReversiBoard*).
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

// ReversiConsoleView: prints the board to the console.
// Pointer note: stores `ReversiBoard *reversiBoard` — shows simple pointer use.
class ReversiConsoleView
{
private:
	/// Pointer to the ReversiBoard object to be displayed.
	ReversiBoard *reversiBoard;

public:
	// Constructor: takes pointer to a ReversiBoard to display.
	// Exam note: passing pointer avoids copying the whole board; caller owns board.
	ReversiConsoleView(ReversiBoard *reversiBoard);

	// Destructor: no ownership cleanup here (does not delete the board pointer).
	~ReversiConsoleView();

	// Prints board to console using simple characters (O/X/+).
	// Loops and conditionals demo: iterates rows/columns and branches on state.
	void print();
};

#endif /* REVERSICONSOLEVIEW_H_ */
