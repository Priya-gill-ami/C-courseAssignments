#ifndef GAME_H
#define GAME_H

// Checks if there is a winner on the board.
// Returns 1 if Player 1 wins, 2 if Player 2 wins, and 0 otherwise.
int check_winner(const char board[3][3]);

// Checks if the game is a tie (all cells filled, no winner).
int is_tie(const char board[3][3]);

// Manages the entire game flow, including player turns and win/tie detection.
void play_game(int *p1_wins, int *p2_wins, int *ties, int *total_turns, int *max_turns, int *min_turns);

#endif // GAME_H
