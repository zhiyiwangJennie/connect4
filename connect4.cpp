#include "connect4.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Press 1 for terminal and 2 for graphics: ";
    int choice;
    while (!(cin >> choice)) {
        cin.clear();
        string garbage;
        getline(cin, garbage);
        cout << "Press 1 for terminal and 2 for graphics: ";
    }
    if (choice == 1) {
        terminalPlay();
    } else {
        cout << "Under construction..." << endl;
        //graphicsPlay(argc, argv);
    }
    return 0;
}

void terminalPlay(){
    cout << "\nEnter: the column to move, q to quit, s to save" << endl;
    cout <<  " enter your move: ";
    cout << "Thanks for playing!"<< endl;
    cout << "ILLEGAL MOVE: Try again" << endl;
    cout << "Congratulations ";
    cout << "! You won!" << endl;
    cout << "Draw!" << endl;
}

Board getBoard(string &p1, string &p2) {
    cout << "Enter L to load a game, or P to play: " << flush;
    cout << "Player 1, enter your name: " << flush;
    cout << endl << "Player 2, enter your name: " << flush;
    cout << "Enter the filename: " << flush;
    return Board();
}

void saveBoard(string p1, string p2, const Board &board) {
    cout << "Enter the filename: " << flush;
}
