#include <iostream>
using namespace std;

// A function to show the current board status
void showBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// A function to check if a player has won
bool isWin(char board[3][3], char mark) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return true;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return true;
    }
    // No win condition
    return false;
}

// A function to check if the board is full
bool isFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// A function to get the user's move
void getUserMove(char board[3][3]) {
    int row, col;
    cout << "Enter your move (row and column): ";
    cin >> row >> col;
    // Validate the input
    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
        cout << "Invalid move. Try again: ";
        cin >> row >> col;
    }
    // Update the board
    board[row-1][col-1] = 'X';
}

// A function to get the computer's move
void getComputerMove(char board[3][3]) {
    int row, col;
    // Find a random empty spot
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    // Update the board
    board[row][col] = 'O';
}

// The main function
int main() {
    // Initialize the board
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    
    // Welcome message
    cout << "Welcome to Tic-Tac-Toe!\n";
    
    // Game loop
    while (true) {
        // Show the board
        showBoard(board);
        
        // Get the user's move
        getUserMove(board);
        
        // Check if the user has won or the board is full
        if (isWin(board, 'X')) {
            cout << "You win!\n";
            break;
        }
        if (isFull(board)) {
            cout << "It's a tie!\n";
            break;
        }
        
        // Get the computer's move
        getComputerMove(board);
        
        // Check if the computer has won or the board is full
        if (isWin(board, 'O')) {
            cout << "You lose!\n";
            break;
        }
        if (isFull(board)) {
            cout << "It's a tie!\n";
            break;
        }
        
    }
    
    // Show the final board
    showBoard(board);
    
    return 0;
}
