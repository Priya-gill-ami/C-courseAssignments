#include <stdio.h>
#include "board.h"

void initialize_board(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}

void display_board(char board[3][3])
{
    printf("   1   2   3\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}
int is_full(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                return 0;
            }
        }
    }
    return 1;
}

int check_winner(char board[3][3])
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0] == 'x' ? 1 : 2;
        }
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i] == 'x' ? 1 : 2;
        }
    }

    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0] == 'x' ? 1 : 2;
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2] == 'x' ? 1 : 2;
    }

    return 0;
}