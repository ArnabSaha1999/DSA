#include<iostream>
#include<vector>

using namespace std;

// Function to check if placing a value at a specific position is valid in Sudoku
bool isPossible(int row, int col, int n, char value, vector<vector<char>> &board) {
    for(int i = 0; i < n; i++) {
        // Check for the presence of the value in the current row, column, and the 3x3 subgrid
        if(board[row][i] == value || board[i][col] == value || board[3 * (row/3) + i/3][3 * (col / 3) + i % 3] == value) {
            // If the value is found in the current row, column, and the 3x3 subgrid
            return false;
        }
    }
    // If the value is not found in the row, column, or subgrid, placement is valid
    return true;
} 

// Backtracking helper function to solve the Sudoku puzzle
bool solve(vector<vector<char>> &board) {
    int n = board.size();
    // Iterate through each cell in the board
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            // Check if the cell is empty
            if(board[row][col] == '.') {
                // Try placing values from '1' to '9'
                for(int value = '1'; value <= '9'; value++) {
                    // Check if placing the value at the current position is valid
                    if(isPossible(row, col, n, value, board)) {
                        // Place the value and recursively check for the next cell
                        board[row][col] = value;
                        bool isSolutionPossible = solve(board);
                        // If a solution is found, return true
                        if(isSolutionPossible) {
                            return true;
                        } else {
                            // Backtrack: If placing the value doesn't lead to a solution, reset the cell
                            board[row][col] = '.';
                        }
                    }
                }
                // If no valid value is found for the current cell, return false
                return false;
            }
        }
    }
    // If all cells are filled, the board is solved
    return true;
}

//Approach 1: Function to solve the Sudoku puzzle
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

int main() {
    vector<vector<char>> board;
    board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','.','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout<<"The Input Sudoku: "<<endl;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout<<board[i][j]<<" ";
        } cout<<endl;
    }

    cout<<endl<<"The Solved Sudoku Board: "<<endl;
    solveSudoku(board);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout<<board[i][j]<<" ";
        } cout<<endl;
    }

    return 0;
}
