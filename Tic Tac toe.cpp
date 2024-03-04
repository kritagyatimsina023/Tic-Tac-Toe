#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void initializeBoard(int n, vector<vector<char>>& board);
void printBoard(const vector<vector<char>>& board);
bool isMoveValid(const vector<vector<char>>& board, int row, int col);
bool checkForWin(const vector<vector<char>>& board, char player);
bool isBoardFull(const vector<vector<char>>& board);

int main() {
    int n;
    cout << "Enter the number of rows and columns (n): ";
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '-'));

    char currentPlayer = 'X';
    bool gameWon = false;
    int moves = 0;

    while (!gameWon && moves < n * n) {
        printBoard(board);

        int row, col;
        do {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
        } while (!isMoveValid(board, row, col));

        board[row][col] = currentPlayer;

        if (checkForWin(board, currentPlayer)) {
            gameWon = true;
            cout << "Player " << currentPlayer << " wins!\n";
        } else if (isBoardFull(board)) {
            gameWon = true;
            cout << "It's a draw!\n";
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        moves++;
    }

    printBoard(board);

    return 0;
}

void initializeBoard(int n, vector<vector<char>>& board) {
    board = vector<vector<char>>(n, vector<char>(n, '-'));
}

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool isMoveValid(const vector<vector<char>>& board, int row, int col) {
    int n = board.size();
    return row >= 0 && row < n && col >= 0 && col < n && board[row][col] == '-';
}

bool checkForWin(const vector<vector<char>>& board, char player) {
    int n = board.size();

    // Check rows and columns
    for (int i = 0; i < n; ++i) {
        bool rowWin = true;
        bool colWin = true;
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != player)
                rowWin = false;
            if (board[j][i] != player)
                colWin = false;
        }
        if (rowWin || colWin)
            return true;
    }

    // Check diagonals
    bool diag1Win = true;
    bool diag2Win = true;
    for (int i = 0; i < n; ++i) {
        if (board[i][i] != player)
            diag1Win = false;
        if (board[i][n - 1 - i] != player)
            diag2Win = false;
    }
    if (diag1Win || diag2Win)
        return true;

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == '-')
                return false;
        }
    }
    return true;
}
