#include <stdio.h>
#include "tic_tac_toe.h"

int main()
{
    char board[SIZE][SIZE];
    bool gameOver = false;
    int currentPlayer = 1;
    char playerSymbol;

    initializeBoard(board);

    while (!gameOver)
    {
        displayBoard(board);
        playerSymbol = (currentPlayer == 1) ? 'x' : 'o';

        // Get the player's move
        playerMove_t move = getPlayerMove(currentPlayer);

        // Validate and make the move
        if (makeMove(board, move, playerSymbol))
        {
            // Check for win condition
            if (checkWin(board, playerSymbol))
            {
                displayBoard(board);
                printf("Player #%d (%c) wins!\n", currentPlayer, playerSymbol);
                gameOver = true;
            }
            // Check for tie condition
            else if (checkTie(board))
            {
                displayBoard(board);
                printf("The game is a tie!\n");
                gameOver = true;
            }
            else
            {
                // Switch players
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        }
        else
        {
            printf("Invalid move, please try again.\n");
        }
    }
    return 0;
}
