#ifndef BOARD_H
#define BOARD_H

void initialize_board(char board[3][3]);
void display_board(char board[3][3]);
int is_full(char board[3][3]);
int check_winner(char board[3][3]);

#endif