#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

// Simple enum: each field is either black, white, or blank.
enum FieldState
{
	BLACK,
	WHITE,
	BLANK
};

// ReversiBoard stores the board state and applies the Reversi rules.
class ReversiBoard
{
private:
	// No private data is needed; the board is stored directly below.

public:
	// Public 2D array keeps the example easy to read and print.
	FieldState board[8][8];

	// Constructor sets the initial four stones on the board.
	ReversiBoard();

	// Destructor is empty because we do not allocate dynamic memory here.
	~ReversiBoard();

	// Reads one field without changing the board.
	FieldState getFieldState(int column, int row);

	// Tries to place a stone and flips opponent stones if the move is valid.
	bool setFieldState(int column, int row, FieldState piece);

};

#endif /* REVERSIBOARD_H_ */
