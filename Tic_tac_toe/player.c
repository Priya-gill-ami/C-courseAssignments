#include <stdio.h>
#include "player.h"
#include "board.h"

int get_move(char board[3][3], char player)
{
    char input[3];
    int row, col;

    while (1)
    {
        printf("Player %c Move > ", player);
        scanf("%s", input);

        if (input[0] >= 'A' && input[0] <= 'C')
        {
            row = input[0] - 'A';
        }
        else
        {
            printf("Invalid input.\n");
            continue;
        }

        if (input[1] == '-' && input[2] >= '1' && input[2] <= '3')
        {
            col = input[2] - '1';
        }
        else
        {
            printf("Invalid input.\n");
            continue;
        }
        if (board[row][col] == '-')
        {
            board[row][col] = player;
            break;
        }
        else
        {
            printf("Square already occupied.\n");
        }
    }
    return 1;
}