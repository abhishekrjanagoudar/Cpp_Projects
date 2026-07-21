/* ReversiBoard.h
 * Simple notes: header for ReversiBoard class and board state.
 * Learning notes: shows enums, basic class layout, public array member.
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

// FieldState: enum to represent a cell's contents (BLACK, WHITE, BLANK)
// Exam note: enums are integer-like named constants; easier to read than raw ints.
enum FieldState
{
	BLACK, ///< Represents a black piece.
	WHITE, ///< Represents a white piece.
	BLANK  ///< Represents an empty field.
};

// ReversiBoard: holds an 8x8 board and methods to read/write fields.
// OOP note: this class groups data (`board`) and functions (`getFieldState`,
// `setFieldState`) that operate on that data.
class ReversiBoard
{
private:
	// No private members

public:
	// 2D array representing the board with 8x8 fields.
	FieldState board[8][8];

	// Constructor: sets up initial board pieces.
	ReversiBoard();

	// Destructor (no special cleanup required for this simple class).
	~ReversiBoard();

	// Returns the state of the cell at (column, row).
	// Important: parameters are (column, row) — check order when calling.
	FieldState getFieldState(int column, int row);

	// Attempts to place `piece` at (column, row). Returns true if legal move
	// and flips opponent pieces accordingly. Uses loops and conditionals.
	// Exam note: this function demonstrates bounds checks, loops, and
	// modifying a 2D array (board).
	bool setFieldState(int column, int row, FieldState piece);

};

#endif /* REVERSIBOARD_H_ */
