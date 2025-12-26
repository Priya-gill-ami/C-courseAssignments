#include <stdio.h>
#include <stdlib.h>
#include "statistics.h"

#define STATS_FILE "game.txt"

void load_statistics(int *p1_wins, int *p2_wins, int *ties, int *total_turns, int *max_turns, int *min_turns)
{
    FILE *file = fopen(STATS_FILE, "r");
    if (!file)
    {
        // If file does not exist, initialize statistics with default values
        *p1_wins = 0;
        *p2_wins = 0;
        *ties = 0;
        *total_turns = 0;
        *max_turns = 0;
        *min_turns = 1000;
        return;
    }

    // Read statistics from the file
    fscanf(file, "%d %d %d %d %d %d", p1_wins, p2_wins, ties, total_turns, max_turns, min_turns);
    fclose(file);
}

void save_statistics(int p1_wins, int p2_wins, int ties, int total_turns, int max_turns, int min_turns)
{
    FILE *file = fopen(STATS_FILE, "w");
    if (!file)
    {
        fprintf(stderr, "Error saving statistics.\n");
        return;
    }

    // Write statistics to the file
    fprintf(file, "%d %d %d %d %d %d\n", p1_wins, p2_wins, ties, total_turns, max_turns, min_turns);
    fclose(file);
}