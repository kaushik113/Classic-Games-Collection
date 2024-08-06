#include <iostream>
#include <vector>

using namespace std;

const string ANSI_COLOR_RED = "\x1b[31;1m";
const string ANSI_COLOR_GREEN = "\x1b[32;1m";
const string ANSI_COLOR_RESET = "\x1b[0m";

void print_board(const vector<vector<char>>& board, const vector<vector<bool>>& initial) {
    for (int i = 0; i < 9; i++) {
        // Print horizontal lines between boxes
        if (i > 0 && i % 3 == 0) {
            cout << "------+-------+------\n";
        }

        for (int j = 0; j < 9; j++) {
            // Print vertical lines between cells
            if (j > 0 && j % 3 == 0) {
                cout << "| ";
            }

            if (initial[i][j]) {
                cout << ANSI_COLOR_GREEN << board[i][j] << ' ' << ANSI_COLOR_RESET;
            } else if (board[i][j] != '.') {
                cout << ANSI_COLOR_RED << board[i][j] << ' ' << ANSI_COLOR_RESET;
            } else {
                cout << board[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}

bool canFill(int row, int col, char num, const vector<vector<char>>& board) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false;
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) return false;
    }

    // Check box
    int row_adder = (row / 3) * 3;
    int col_adder = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[row_adder + i][col_adder + j] == num) return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<char>>& board, int row, int col) {
    for (int i = row; i < 9; i++) {
        for (int j = col; j < 9; j++) {
            if (board[i][j] == '.') {
                for (int digit = 1; digit <= 9; digit++) {
                    char num = '0' + digit;
                    if (canFill(i, j, num, board)) {
                        board[i][j] = num;
                        if (solveSudoku(board, i, j)) return true;
                        board[i][j] = '.';
                    }
                }
                return false; // Backtrack
            }
        }
        col = 0; // Reset column for next row
    }
    return true; // Sudoku solved
}

void inputSudoku(vector<vector<char>>& board) {
    cout << "Enter the Sudoku puzzle (use '.' for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
}

int main() {
    vector<vector<char>> board(9, vector<char>(9, '.'));

    inputSudoku(board);

    // Mark initial positions
    vector<vector<bool>> initial(9, vector<bool>(9, false));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                initial[i][j] = true;
            }
        }
    }

    if (solveSudoku(board, 0, 0)) {
        print_board(board, initial);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}
