#include "connect4.h"
#include "graphics.h"
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
    //name of player 1
    string p1;
    //name of player 2
    string p2;
    int userColumn;
    char userInput;
    Board boardChoice;
    Result moveResult = NoResult;
    
    boardChoice = getBoard(p1, p2);
    while ((userInput != 'q') &&
           ((moveResult == IllegalMove) ||
             moveResult == NoResult)) {
        boardChoice.prettyPrintBoard(cout);
        cout << "\nEnter: the column to move, q to quit, s to save" << endl;
        //player 1's turn
        if (boardChoice.toMove() == 1) {
            cout <<  p1 << " enter your move: ";
        }
        //player 2's turn
        else if (boardChoice.toMove() == 2) {
            cout <<  p2 << " enter your move: ";
        }
        cin >> userColumn;
        //if user entered a character instead of a column number
        if (cin.fail()) {
            cin.clear();
            cin >> userInput;
            userInput = tolower(userInput);
            if (userInput == 's') {
                saveBoard(p1, p2, boardChoice);
            }
            else if (userInput == 'q') {
                break;
            }
            else {
                cout << "ILLEGAL MOVE: Try again" << endl;
            }
        }
        //if user entered a column number
        else {
            moveResult = boardChoice.makeMove(userColumn - 1);
            if (moveResult == IllegalMove) {
                cout << "ILLEGAL MOVE: Try again" << endl;
            }
        }
    }
    //end of the game
    if (userInput == 'q') {
        cout << "Thanks for playing!"<< endl;
    }
    else if (moveResult == Win) {
        //player 2 wins if board is won before player 1's turn
        if (boardChoice.toMove() == 1) {
            cout << "Congratulations " << p2;
            cout << "! You won!" << endl;
        }
        //player 1 wins if board is won before player 2's turn
        else if (boardChoice.toMove() == 2) {
            cout << "Congratulations " << p1;
            cout << "! You won!" << endl;
        }
        boardChoice.prettyPrintBoard(cout);
    }
    else if (moveResult == Draw) {
        cout << "Draw!" << endl;
        boardChoice.prettyPrintBoard(cout);
    }
}

Board getBoard(string &p1, string &p2) {
    char userChoice;
    string fileName;
    ifstream inFS;
    
    cout << "Enter L to load a game, or P to play: " << flush;
    cin >> userChoice;
    userChoice = tolower(userChoice);
    if (userChoice == 'p') {
        cout << "Player 1, enter your name: " << flush;
        cin >> p1;
        cout << endl << "Player 2, enter your name: " << flush;
        cin >> p2;
        Board newBoard;
    }
    //all other user input except "play" loads saved file
    else {
        cout << "Enter the filename: " << flush;
        cin >> fileName;
        inFS.open(fileName);
        inFS >> p1;
        inFS >> p2;
        //open saved file with FEN string info(TODO)
        inFS.close();
    }
    return Board();
}

void saveBoard(string p1, string p2, const Board &board) {
    ofstream outFile;
    string userFile;
    
    cout << "Enter the filename: " << flush;
    cin >> userFile;
    outFile.open(userFile);
    outFile << p1 << endl;
    outFile << p2 << endl;
    //TODO: print out FEN string of saved board to file
    outFile.close();
}
