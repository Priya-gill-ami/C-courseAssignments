#include <stdio.h>
#include "game.h"
#include "board.h"
#include "player.h"

int check_winner(const char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
            return board[i][0] == 'x' ? 1 : 2;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
            return board[0][i] == 'x' ? 1 : 2;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
        return board[0][0] == 'x' ? 1 : 2;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
        return board[0][2] == 'x' ? 1 : 2;
    return 0;
}

int is_tie(const char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
                return 0;
        }
    }
    return 1;
}

void play_game(int *p1_wins, int *p2_wins, int *ties, int *total_turns, int *max_turns, int *min_turns)
{
    char board[3][3];
    initialize_board(board);

    int turns = 0, winner = 0;
    char current_player = 'x';
    while (1)
    {
        render_board(board);
        printf("Player %d Move > ", current_player == 'x' ? 1 : 2);

        char move[10];
        int row, col;
        scanf("%s", move);
        if (!parse_move(move, &row, &col) || !is_valid_move(board, row, col))
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        make_move(board, row, col, current_player);
        turns++;
        if ((winner = check_winner(board)) || is_tie(board))
            break;
        current_player = (current_player == 'x') ? 'o' : 'x';
    }

    render_board(board);
    if (winner)
    {
        printf("Player %d Wins!\n", winner);
        if (winner == 1)
            (*p1_wins)++;
        else
            (*p2_wins)++;
    }
    else
    {
        printf("It's a Tie!\n");
        (*ties)++;
    }

    *total_turns += turns;
    if (turns > *max_turns)
        *max_turns = turns;
    if (turns < *min_turns)
        *min_turns = turns;
}
