#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

// Function to initialize the board
void initializeBoard(char board[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = '-';
        }
    }
}

// Function to print the board
void printBoard(char board[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[MAX_SIZE][MAX_SIZE], int n, char player) {
    // Check rows and columns
    for (int i = 0; i < n; ++i) {
        bool win_row = true;
        bool win_col = true;
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != player)
                win_row = false;
            if (board[j][i] != player)
                win_col = false;
        }
        if (win_row || win_col)
            return true;
    }
    
    // Check diagonals
    bool win_diag1 = true;
    bool win_diag2 = true;
    for (int i = 0; i < n; ++i) {
        if (board[i][i] != player)
            win_diag1 = false;
        if (board[i][n - i - 1] != player)
            win_diag2 = false;
    }
    if (win_diag1 || win_diag2)
        return true;
    
    return false;
}

// Function to check if the board is full
bool isBoardFull(char board[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '-')
                return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the size of the board (n x n): ";
    cin >> n;
    
    if (n < 3 || n > MAX_SIZE) {
        cout << "Invalid board size. Size should be between 3 and " << MAX_SIZE << endl;
        return 1;
    }
    
    char board[MAX_SIZE][MAX_SIZE];
    initializeBoard(board, n);
    
    char currentPlayer = 'X';
    bool gameover = false;
    
    while (!gameover) {
        cout << "Current board:" << endl;
        printBoard(board, n);
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-indexed): ";
        int row, col;
        cin >> row >> col;
        
        if (row < 1 || row > n || col < 1 || col > n || board[row - 1][col - 1] != '-') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        
        board[row - 1][col - 1] = currentPlayer;
        
        if (checkWin(board, n, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameover = true;
        } else if (isBoardFull(board, n)) {
            cout << "It's a draw!" << endl;
            gameover = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    
    cout << "Final board:" << endl;
    printBoard(board, n);
    
    return 0;
}
