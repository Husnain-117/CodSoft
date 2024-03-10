#include <iostream>
#include <fstream>
using namespace std;

// Function declarations
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], char player, int &row, int &col);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
void switchPlayer(char &currentPlayer);
void saveGame(char board[3][3], char currentPlayer);
bool loadGame(char board[3][3], char &currentPlayer);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameInProgress = true;

    initializeBoard(board);

    int option;
    cout << "Tic-Tac-Toe Game\n";
    do {
        cout << "Menu:\n";
        cout << "1. Play\n";
        cout << "2. Load Game\n";
        cout << "3. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                do {
                    displayBoard(board);

                    // Player input
                    int row, col;
                    cout << "Player " << currentPlayer << ", enter your move (row and column): ";
                    while (!makeMove(board, currentPlayer, row, col)) {
                        cout << "Invalid move. Try again: ";
                    }

                    // Check for win
                    if (checkWin(board, currentPlayer)) {
                        displayBoard(board);
                        cout << "Player " << currentPlayer << " wins!\n";
                        gameInProgress = false;
                    } else if (checkDraw(board)) {
                        displayBoard(board);
                        cout << "It's a draw!\n";
                        gameInProgress = false;
                    } else {
                        switchPlayer(currentPlayer);
                    }

                } while (gameInProgress);

                break;

            case 2:
                if (loadGame(board, currentPlayer)) {
                    cout << "Game loaded successfully!\n";
                    gameInProgress = true;
                } else {
                    cout << "Error loading game. Starting a new game.\n";
                    initializeBoard(board);
                    gameInProgress = true;
                }
                break;

            case 3:
                cout << "Thanks for playing!\n";
                break;

            default:
                cout << "Invalid option. Please choose again.\n";
        }
    } while (option != 3);

    return 0;
}

// Function definitions

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '-';
        }
    }
}

void displayBoard(char board[3][3]) {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

bool makeMove(char board[3][3], char player, int &row, int &col) {
    cout << "Enter row (0, 1, or 2): ";
    cin >> row;
    cout << "Enter column (0, 1, or 2): ";
    cin >> col;

    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
        return false; // Invalid move
    }

    board[row][col] = player;
    return true;
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void saveGame(char board[3][3], char currentPlayer) {
    ofstream file("tictactoe_save.txt");
    if (file.is_open()) {
        file << currentPlayer << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                file << board[i][j] << ' ';
            }
            file << endl;
        }
        file.close();
        cout << "Game saved successfully!\n";
    } else {
        cout << "Error saving game.\n";
    }
}

bool loadGame(char board[3][3], char &currentPlayer) {
    ifstream file("tictactoe_save.txt");
    if (file.is_open()) {
        file >> currentPlayer;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                file >> board[i][j];
            }
        }
        file.close();
        return true;
    } else {
        return false;
    }
}
