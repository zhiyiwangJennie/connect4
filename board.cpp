#include "board.h"
#include <iostream>
#include <fstream>

Board::Board() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            data[i][j] = Empty;
        }
    }
    nextPlayer_to_move = Player1;
}

Board::Board(const string &fen) {
}

void Board::printBoard_as_FENstring(ostream &os) const {
}

PieceType Board::atLocation(int row, int col) {
    return data[row][col];
}

void Board::prettyPrintBoard(ostream &os) const {
	os << endl;
    for (int row = NUM_ROWS - 1; row >= 0; row--)  {
        os << "     +---+---+---+---+---+---+---+"
           << endl
           << "    ";
        
        for (int col = 0; col < NUM_COLS; col++)   {
            os << " | " ;
            if ( data[row][col] == Player1)
                os <<  PLAYER1_TOKEN;
            else if (data[row][col] == Player2)
                os << PLAYER2_TOKEN;
            else
                os << EMPTY_TOKEN;
        }
        os << " |" << endl;
    }
    os << "     +---+---+---+---+---+---+---+" << endl
       <<"  col  1   2   3   4   5   6   7" << endl;
    return;
}

int Board::toMove() const {
    if (nextPlayer_to_move == Player1) {
        return 1;
    }
    else {
        return 2;
    }
}

Result Board::makeMove(int col) {
    int row = getFirstFreeRow(col);
    //make valid move
    if (inBounds(row, col)) {
        if (toMove() == 1) {
            data[row][col] = Player1;
        }
        else {
            data[row][col] = Player2;
        }
        updateToMove();
    }
    //invalid move
    else {
        return IllegalMove;
    }
    
    //check result of move
    if (isWin(row, col)) {
        return Win;
    }
    else if (isBoardFull()) {
        return Draw;
    }
    else {
        return NoResult;
    }
}

int Board::getFirstFreeRow(int col) const {
    for (int i = 0; i < NUM_ROWS; ++i) {
        if (data[i][col] == Empty) {
            return i;
        }
    }
    return NUM_ROWS;
}

PieceType Board::updateToMove() {
    if (nextPlayer_to_move == Player1) {
        nextPlayer_to_move = Player2;
        return Player1;
    }
    else {
        nextPlayer_to_move = Player1;
        return Player2;
    }
}

bool Board::isBoardFull() const {
    return false;
}

bool Board::inBounds(int row, int col) const {
    if ((row < NUM_ROWS) && (row >= 0) &&
        (col < NUM_COLS) && (col >= 0)) {
        return true;
    }
    else {
        return false;
    }
}

int Board::piecesInDirection(int row, int col, int dRow, int dCol) const {
    return 0;
}

bool Board::isWin(int row, int col) const {
    return false;
}
