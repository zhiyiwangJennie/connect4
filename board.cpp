#include "board.h"

Board::Board() {
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

PieceType Board::atLocation(int row, int col) {
    return data[row][col];
}

int Board::toMove() const {
    return 1;
}

Result Board::makeMove(int col) {
    return NoResult;
}

int Board::getFirstFreeRow(int col) const {
    return NUM_ROWS;
}

PieceType Board::updateToMove() {
    return Player1;
}

bool Board::isBoardFull() const {
    return false;
}

bool Board::inBounds(int row, int col) const {
    return false;
}

int Board::piecesInDirection(int row, int col, int dRow, int dCol) const {
    return 0;
}

bool Board::isWin(int row, int col) const {
    return false;
}


