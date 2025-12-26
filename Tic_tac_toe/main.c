#include <stdio.h>
#include "board.h"
#include "player.h"
#include "game.h"
#include "statistics.h"

int main()
{
    int p1_wins, p2_wins, ties, total_turns, max_turns, min_turns;

    // Load statistics from the file
    load_statistics(&p1_wins, &p2_wins, &ties, &total_turns, &max_turns, &min_turns);

    char play_again;
    do
    {
        play_game(&p1_wins, &p2_wins, &ties, &total_turns, &max_turns, &min_turns);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    // Save statistics to the file
    save_statistics(p1_wins, p2_wins, ties, total_turns, max_turns, min_turns);

    return 0;
}