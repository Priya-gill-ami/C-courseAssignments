#ifndef BOARD_H
#define BOARD_H

// Initializes the game board with empty cells ('-').
void initialize_board(char board[3][3]);

// Renders the current state of the board to the console.
void render_board(const char board[3][3]);

// Updates the board with the player's move.
void make_move(char board[3][3], int row, int col, char player);

#endif // BOARD_H
