#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdbool.h>

#define SIZE 3

// Structure to store a player's move
typedef struct
{
    char row;
    int col;
} playerMove_t;

// Function prototype
void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
playerMove_t getPlayerMove(int playerNumber);
bool makeMove(char board[SIZE][SIZE], playerMove_t move, char player);
bool checkWin(char board[SIZE][SIZE], char player);
bool checkTie(char board[SIZE][SIZE]);

#endif // TIC_TAC_TOE_H
