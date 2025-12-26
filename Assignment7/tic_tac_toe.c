#include <stdio.h>
#include "tic_tac_toe.h"

// Initialize the game board with empty spaces
void initializeBoard(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Display the current game board
void displayBoard(char board[SIZE][SIZE])
{
    printf("\n  1 2 3\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%c ", 'A' + i);
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("  -----\n");
    }
    printf("\n");
}

// Get the player's move as row and column
playerMove_t getPlayerMove(int playerNumber)
{
    playerMove_t move;
    printf("Player #%d, enter your move (e.g., A-1): ", playerNumber);
    scanf(" %c-%d", &move.row, &move.col);
    move.row = move.row - 'A'; // Convert 'A'-'C' to 0-2
    move.col = move.col - 1;   // Convert 1-3 to 0-2
    return move;
}

// Make a move if the spot is empty
bool makeMove(char board[SIZE][SIZE], playerMove_t move, char player)
{
    if (move.row >= 0 && move.row < SIZE && move.col >= 0 && move.col < SIZE && board[move.row][move.col] == ' ')
    {
        board[move.row][move.col] = player;
        return true;
    }
    return false;
}

// Check if a player has won
bool checkWin(char board[SIZE][SIZE], char player)
{
    // rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

// Check if the board is full and no more moves are possible
bool checkTie(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
