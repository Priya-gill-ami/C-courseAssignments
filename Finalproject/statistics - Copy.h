#ifndef STATISTICS_H
#define STATISTICS_H

#define FILENAME "game.txt"

// Loads game statistics from a file.
void load_statistics(int *p1_wins, int *p2_wins, int *ties, int *total_turns, int *max_turns, int *min_turns);

// Saves game statistics to a file.
void save_statistics(int p1_wins, int p2_wins, int ties, int total_turns, int max_turns, int min_turns);

#endif // STATISTICS_H
