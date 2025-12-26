#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "player.h"

int parse_move(const char *input, int *row, int *col)
{
    if (strlen(input) != 2)
        return 0;
    char row_char = toupper(input[0]);
    char col_char = input[1];
    if (row_char < 'A' || row_char > 'C' || col_char < '1' || col_char > '3')
        return 0;
    *row = row_char - 'A';
    *col = col_char - '1';
    return 1;
}

int is_valid_move(const char board[3][3], int row, int col)
{
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-');
}
