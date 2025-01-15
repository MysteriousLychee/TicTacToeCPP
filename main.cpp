#include <iostream>

using std::cout;
using std::endl;
using std::cin;

char board[3][3] = {
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' }
};

bool isPlayerX = true;

int row;
int box;

int moves;

bool checkForGameOver() {

    // Tie Check
    if (moves >= 9) {
        return true;
    }

    // Horizontal Checks
    for (const auto & i : board) {
        if (i[0] == i[1] && i[1] == i[2] && i[1] != ' ') {
            cout << "Winning player is " << i[0] << "! Congrats!" << endl;
            return true;
        }
    }

    // Vertical Checks
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') {
            cout << "Winning player is " << board[0][i] << "! Congrats!" << endl;
            return true;
        }
    }

    // Diagonal checks
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
        cout << "Winning player is " << board[1][1] << "! Congrats!" << endl;
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
        cout << "Winning player is " << board[1][1] << "! Congrats!" << endl;
        return true;
    }

    return false;
}

void getMove() {

    if (isPlayerX) {
        cout << "It is player X's turn." << endl;
    } else {
        cout << "It is player O's turn." << endl;
    }

    std::string sRow;
    std::string sBox;

    cout << "Enter the row you'd like to move in (1...3): " << endl;
    cin >> sRow;
    cout << "Enter the box you'd like to move in (1...3): " << endl;
    cin >> sBox;
    row = stoi(sRow);
    box = stoi(sBox);
    row--;
    box--;
}

void makeMove() {

    if (board[row][box] == ' ') {
        board[row][box] = isPlayerX ? 'X' : 'O';
    } else {
        getMove();
        makeMove();
    }
    isPlayerX = !isPlayerX;
    moves++;
}

void printBoard() {

    for (const auto & i : board) {
        cout << i[0] << "|";
        cout << i[1] << "|";
        cout << i[2] << endl;
    }
}

int main() {

    while (true) {
        printBoard();
        if (checkForGameOver()) {
            break;
        }
        getMove();
        makeMove();
        cout << endl;
    }

    return 0;
}