#ifndef connect4_h__
#define connect4_h__

#include "board.h"

// This serves as the main function for the Core portion of the project.
// It is where you will write the menu-driven gameplay for the Core.
void terminalPlay();

// Effects: Lets the user choose whether to start a new game, or load an
//          existing one. Returns the game board. modifies p1 and p2 to be
//          the player names.
// Difficulty: Easy-Medium
// Topics: Basic/IO, pass by reference, class construction
Board getBoard(std::string &p1, std::string &p2);

// Prompts the user for the filename, and saves the board.
// Difficulty: Easy
// Topics: streams
void saveBoard(std::string p1, std::string p2, const Board &board);

#endif