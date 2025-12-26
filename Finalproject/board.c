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

void render_board(const char board[3][3])
{
    printf("   1   2   3\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("  ---+---+---\n");
    }
}

void make_move(char board[3][3], int row, int col, char player)
{
    board[row][col] = player;
}
