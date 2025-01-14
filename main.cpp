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

int moves;

void checkForGameOver() {

    // Tie Check
    if (moves >= 9) {
        gameOver = true;
    }

    // Horizontal Checks
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
            board[i][0] != ' ' && board[i][1] != ' ' && board[i][2] != ' ') {
            cout << "Winning player is " << board[i][0] << "! Congrats!" <<endl;
            gameOver = true;
        }
    }

    // Vertical Checks
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
            board[0][i] != ' ' && board[1][i] != ' ' && board[2][i] != ' ') {
            cout << "Winning player is " << board[0][i] << "! Congrats!" << endl;
            gameOver = true;
        }
    }

    // Diagonal checks
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] != ' ') {
        cout << "Winning player is " << board[1][1] << "! Congrats!" << endl;
        gameOver = true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
        board[0][2] != ' ' && board[1][1] != ' ' && board[2][0] != ' ') {
        cout << "Winning player is " << board[1][1] << "! Congrats!" << endl;
        gameOver = true;
    }
}

void getMove() {

    if (isPlayerX) {
        cout << "It is player X's turn." << endl;
    } else {
        cout << "It is player O's turn." << endl;
    }

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

    if (board[intRow][intBox] == ' ') {
        board[intRow][intBox] = isPlayerX ? 'X' : 'O';
    } else {
        getMove();
        makeMove();
    }
    isPlayerX = !isPlayerX;
    moves++;
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
        checkForGameOver();

        if (gameOver) {
            break;
        }

        getMove();
        makeMove();
        cout << endl;
    }

    return 0;
}