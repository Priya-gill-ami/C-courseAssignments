#include <stdio.h>
#include "board.h"
#include "player.h"
#include "game.h"

void play_game(int *p1_wins, int *p2_wins, int *ties, int *total_turns, int *max_turns, int *min_turns)
{
    char board[3][3];
    initialize_board(board);

    int turn_count = 0;
    int winner = 0;
    while (1)
    {
        display_board(board);

        if (turn_count % 2 == 0)
        {
            get_move(board, 'x');
        }
        else
        {
            get_move(board, 'o');
        }

        turn_count++;
        winner = check_winner(board);
        if (winner || is_full(board))
        {
            break;
        }
    }

    display_board(board);

    if (winner == 1)
    {
        printf("Player 1 wins!\n");
        (*p1_wins)++;
    }
    else if (winner == 2)
    {
        printf("Player 2 wins!\n");
        (*p2_wins)++;
    }
    else
    {
        printf("It's a tie!\n");
        (*ties)++;
    }

    (*total_turns) += turn_count;
    if (turn_count > *max_turns)
    {
        *max_turns = turn_count;
    }
    if (turn_count < *min_turns || *min_turns == 0)
    {
        *min_turns = turn_count;
    }
}
