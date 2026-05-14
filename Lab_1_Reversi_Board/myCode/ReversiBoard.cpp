#include "ReversiBoard.h"

namespace
{
bool isInsideBoard(int column, int row)
{
    // Helper: keep index checks in one place.
    return column >= 0 && column < 8 && row >= 0 && row < 8;
}

bool flipDirection(FieldState board[8][8], int startColumn, int startRow,
        int deltaColumn, int deltaRow, FieldState piece)
{
    // Helper logic: walk in one direction until we hit our own stone or stop.
    FieldState opponent = (piece == BLACK) ? WHITE : BLACK;
    int column = startColumn + deltaColumn;
    int row = startRow + deltaRow;
    int capturedFields = 0;

    // Loop until the chain of opponent stones ends.
    while (isInsideBoard(column, row) && board[column][row] == opponent)
    {
        column += deltaColumn;
        row += deltaRow;
        capturedFields++;
    }

    if (capturedFields == 0)
    {
        return false;
    }

    if (!isInsideBoard(column, row) || board[column][row] != piece)
    {
        return false;
    }

    for (int step = 1; step <= capturedFields; step++)
    {
        // Flip the captured stones to the current player's color.
        board[startColumn + step * deltaColumn][startRow + step * deltaRow] =
            piece;
    }

    return true;
}
}

ReversiBoard::ReversiBoard()
{
    // Nested loops are the normal way to fill a 2D array.
    for (int column = 0; column < 8; column++)
    {
        for (int row = 0; row < 8; row++)
        {
            board[column][row] = FieldState::BLANK;
        }
    }

    // Set initial positions for BLACK and WHITE pieces.
    board[3][3] = BLACK;
    board[4][4] = BLACK;
    board[3][4] = WHITE;
    board[4][3] = WHITE;
}

ReversiBoard::~ReversiBoard()
{
    // No cleanup needed because the board uses fixed-size storage.
}

FieldState ReversiBoard::getFieldState(int column, int row)
{
    // Direct array access is enough because the caller uses board coordinates.
    return board[column][row];
}

bool ReversiBoard::setFieldState(int column, int row, FieldState piece)
{
    // First reject invalid coordinates or occupied fields.
    if (!isInsideBoard(column, row))
    {
        return false;
    }

    if (getFieldState(column, row) != BLANK)
    {
        return false;
    }

    bool moveIsValid = false;
    const int directions[8][2] =
    {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, -1}, {-1, -1}, {1, 1}, {-1, 1}
    };

    // Try all eight directions; a legal move must capture in at least one.
    for (int index = 0; index < 8; index++)
    {
        if (flipDirection(board, column, row, directions[index][0],
                directions[index][1], piece))
        {
            moveIsValid = true;
        }
    }

    if (moveIsValid)
    {
        // Place the new stone only after at least one capture was found.
        board[column][row] = piece;
    }

    return moveIsValid;
}
