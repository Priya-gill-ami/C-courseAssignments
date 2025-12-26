#ifndef PLAYER_H
#define PLAYER_H

// Parses the player's input into row and column indices.
// Returns 1 for valid input and 0 for invalid input.
int parse_move(const char *input, int *row, int *col);

// Checks if a move is valid (within bounds and on an empty cell).
int is_valid_move(const char board[3][3], int row, int col);

#endif // PLAYER_H
