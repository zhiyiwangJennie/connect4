#ifndef AI_H__
#define AI_H__

#include "board.h"

/**
 * Requires: nothing.
 * Modifies: nothing.
 * Effects: Chooses a column for the next move
 *          and returns the column index. The
 *          return value must be in range
 *          [0, NUM_COLS-1].
 */
int connect4AI(const Board& board);

#endif /* AI_H__ */
