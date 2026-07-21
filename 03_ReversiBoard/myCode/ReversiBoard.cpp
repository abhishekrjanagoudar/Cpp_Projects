/* ReversiBoard.cpp
 * Simple implementation notes and exam hints added near important lines.
 * Learning: shows loops, conditionals, array access, and basic OOP usage.
 */

#include <iostream>
#include "ReversiBoard.h"

// Constructor: initialize board cells and place starting pieces.
// Syntax note: nested loops used to initialize 2D array.
ReversiBoard::ReversiBoard()
{
    // Initialize all fields to BLANK (looping over columns and rows).
    for (int column = 0; column < 8; column++)
    {
        for (int row = 0; row < 8; row++)
        {
            board[column][row] = FieldState::BLANK; // array access: board[c][r]
        }
    }

    // Starting position: four pieces in the center.
    // Exam note: array indices start at 0; center is 3 and 4 for 8x8.
    board[3][3] = BLACK;
    board[4][4] = BLACK;
    board[3][4] = WHITE;
    board[4][3] = WHITE;
}

// Destructor: no dynamic memory, so left empty.
ReversiBoard::~ReversiBoard()
{
}

// Returns the state at (column, row).
// Exam note: simple accessor, constant-time array read.
FieldState ReversiBoard::getFieldState(int column, int row)
{
    return board[column][row];
}

// Attempts to place a piece and flip opponent pieces in all directions.
// Learning notes: uses loops, conditionals, and early `break` to stop checks.
bool ReversiBoard::setFieldState(int column, int row, FieldState piece)
{
    // If cell is not empty, move is invalid.
    if (getFieldState(column, row) != BLANK)
    {
        return false; // condition check example
    }

    bool isAllowedToPlace = false; // flag set to true when a valid flip is found

    // EAST: move right from placed piece
    for (int col = column + 1; col < 8; col++)
    {
        if (getFieldState(col, row) == BLANK) // empty -> no flanking
            break;

        if (getFieldState(col, row) == piece)
        {
            if (col == column + 1) // adjacent same-color piece -> nothing to flip
                break;

            // Flip pieces between `column` and `col` (inclusive of boundaries)
            for (int j = column; j < col; j++)
            {
                board[j][row] = piece; // array write
            }
            isAllowedToPlace = true;
            break;
        }
    }

    // WEST
    for (int col = column - 1; col >= 0; col--)
    {
        if (getFieldState(col, row) == BLANK)
            break;

        if (getFieldState(col, row) == piece)
        {
            if (col == column - 1)
                break;

            for (int j = column; j > col; j--)
            {
                board[j][row] = piece;
            }
            isAllowedToPlace = true;
            break;
        }
    }

    // SOUTH
    for (int row1 = row + 1; row1 < 8; row1++)
    {
        if (getFieldState(column, row1) == BLANK)
            break;

        if (getFieldState(column, row1) == piece)
        {
            if (row1 == row + 1)
                break;

            for (int j = row; j < row1; j++)
            {
                board[column][j] = piece;
            }
            isAllowedToPlace = true;
            break;
        }
    }

    // NORTH
    for (int row1 = row - 1; row1 >= 0; row1--)
    {
        if (getFieldState(column, row1) == BLANK)
            break;

        if (getFieldState(column, row1) == piece)
        {
            if (row1 == row - 1)
                break;

            for (int j = row; j > row1; j--)
            {
                board[column][j] = piece;
            }
            isAllowedToPlace = true;
            break;
        }
    }

    // NORTH-EAST diagonal
    for (int i = 1; i < 8; i++)
    {
        if (!(column >= 0 && column < 8 && row >= 0 && row < 8))
            break; // safety check for indices

        if (getFieldState(column + i, row - i) == BLANK)
            break;

        if (getFieldState(column + i, row - i) == piece)
        {
            if (i == 1)
                break;

            for (int j = 0; j < i; j++)
            {
                board[column + j][row - j] = piece;
            }
            isAllowedToPlace = true;
            break;
        }
    }

    // NORTH-WEST diagonal
    for (int i = 1; i < 8; i++)
    {
        if (!(column >= 0 && column < 8 && row >= 0 && row < 8))
            break;

        if (getFieldState(column - i, row - i) == BLANK)
            break;

        if (getFieldState(column - i, row - i) == piece)
        {
            if (i == 1)
                break;

            for (int j = 0; j < i; j++)
            {
                board[column - j][row - j] = piece;
            }
            isAllowedToPlace = true;
            break;
        }
    }

    // SOUTH-EAST diagonal
    for (int i = 1; i < 8; i++)
    {
        if (!(column >= 0 && column < 8 && row >= 0 && row < 8))
            break;

        if (getFieldState(column + i, row + i) == BLANK)
            break;

        if (getFieldState(column + i, row + i) == piece)
        {
            if (i == 1)
                break;

            for (int j = 0; j < i; j++)
            {
                board[column + j][row + j] = piece;
            }
            isAllowedToPlace = true;
            break;
        }
    }

    // SOUTH-WEST diagonal
    for (int i = 1; i < 8; i++)
    {
        if (!(column >= 0 && column < 8 && row >= 0 && row < 8))
            break;

        if (getFieldState(column - i, row + i) == BLANK)
            break;

        if (getFieldState(column - i, row + i) == piece)
        {
            if (i == 1)
                break;

            for (int j = 0; j < i; j++)
            {
                board[column - j][row + j] = piece;
            }
            isAllowedToPlace = true;
            break;
        }
    }

    // If any direction produced flips, place the new piece.
    if (isAllowedToPlace)
    {
        board[column][row] = piece;
    }

    return isAllowedToPlace; // function returns boolean result
}
