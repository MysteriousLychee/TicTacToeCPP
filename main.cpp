#include <iostream>

using namespace std;

char board[3][3] = {
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' }
};

bool isPlayerX = true;
bool gameOver = false;

string strRow;
string strBox;
int intRow;
int intBox;

void getMove() {

    cout << "Enter the row you'd like to move in (1...3): " << endl;
    cin >> strRow;
    cout << "Enter the box you'd like to move in (1...3): " << endl;
    cin >> strBox;
    intRow = stoi(strRow);
    intBox = stoi(strBox);
    intRow--;
    intBox--;
}

void makeMove() {

    board[intRow][intBox] = isPlayerX ? 'X' : 'O';
    isPlayerX = !isPlayerX;
}

void printBoard() {

    for (int i = 0; i < 3; i++) {
        cout << board[i][0] << "|";
        cout << board[i][1] << "|";
        cout << board[i][2] << endl;
    }
}

[[noreturn]] int main() {

    while (true) {
        printBoard();
        if (!gameOver) {
            getMove();
            makeMove();
        }
    }

    return 0;
}