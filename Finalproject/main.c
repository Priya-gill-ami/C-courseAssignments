#include <stdio.h>
#include "board.h"
#include "player.h"
#include "game.h"
#include "statistics.h"

int main()
{
    int p1_wins = 0, p2_wins = 0, ties = 0;
    int total_turns = 0, max_turns = 0, min_turns = 1000; // Initial high value for min_turns

    // Load statistics from the file
    load_statistics(&p1_wins, &p2_wins, &ties, &total_turns, &max_turns, &min_turns);

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Statistics Loaded:\n");
    printf("Player 1 Wins: %d\n", p1_wins);
    printf("Player 2 Wins: %d\n", p2_wins);
    printf("Ties: %d\n", ties);
    printf("Average Turns: %.2f\n", total_turns > 0 ? (double)total_turns / (p1_wins + p2_wins + ties) : 0.0);
    printf("Max Turns: %d\n", max_turns);
    printf("Min Turns: %d\n\n", min_turns == 1000 ? 0 : min_turns);

    char play_again;
    do
    {
        play_game(&p1_wins, &p2_wins, &ties, &total_turns, &max_turns, &min_turns);

        printf("\nWould you like to play another game? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    // Save updated statistics to the file
    save_statistics(p1_wins, p2_wins, ties, total_turns, max_turns, min_turns);

    printf("\nThank you for playing Tic-Tac-Toe!\n");
    printf("Final Statistics:\n");
    printf("Player 1 Wins: %d\n", p1_wins);
    printf("Player 2 Wins: %d\n", p2_wins);
    printf("Ties: %d\n", ties);
    printf("Average Turns: %.2f\n", (double)total_turns / (p1_wins + p2_wins + ties));
    printf("Max Turns: %d\n", max_turns);
    printf("Min Turns: %d\n", min_turns == 1000 ? 0 : min_turns);

    return 0;
}
