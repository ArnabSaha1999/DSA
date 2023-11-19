#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Backtracking approach to solve N-Queens problem
bool isPossible(int row, int col, int n, vector<string> &board) {
    // Check if there is a Queen in the same row
    int c = col - 1;
    while(c >= 0) {
        if(board[row][c--] == 'Q') {
            return false;
        }
    }
    // Check if there is a Queen in the upper-left diagonal
    int r = row - 1;
    c = col - 1;
    while(r >= 0 && c >= 0) {
        if(board[r--][c--] == 'Q') {
            return false;
        }
    }
    // Check if there is a Queen in the lower-left diagonal
    r = row + 1;
    c = col - 1;
    while(r < n && c >= 0) {
        if(board[r++][c--] == 'Q') {
            return false;
        }
    }
    return true;
}

// Backtracking helper function
void solve(vector<string> &board, int col, int n, vector<vector<string>> &ans) {
    // Base case: All columns are filled, add the current board to the solutions
    if(col == n) {
        ans.push_back(board);
        return;
    }
    // Try placing a Queen in each row of the current column
    for(int row = 0; row < n; row++) {
        // Check if it's possible to place a Queen at the current position
        if(isPossible(row, col, n, board)) {
            // Place a Queen
            board[row][col] = 'Q';
            // Recur for the next column
            solve(board, col + 1, n, ans);
            // Backtrack: Reset the current position
            board[row][col] = '.';
        }
    }
}

//Approach 1: function to solve N-Queens problem using the Backtracking approach
vector<vector<string>> solveNQueens(int n) {
    // Initialize an empty chessboard
    vector<string> board(n, string (n, '.'));
    // Store all distinct solutions
    vector<vector<string>> ans;
    // Start solving from the first column
    solve(board, 0, n, ans);
    return ans;
}

// Hashmap to track occupied rows, downward diagonals, and upward diagonals during N-Queens placement
unordered_map<int, bool> mapRow, mapDownDiagonal, mapUpDiagonal;

// Check if placing a Queen at the specified position is feasible
bool isPossible(int row, int col, int n) {
    if(mapRow[row] || mapDownDiagonal[row + col] || mapUpDiagonal[(n - 1) + col - row]) {
        return false;
    }
    return true;
}

// Set values in hash maps when placing a Queen
void setMapValues(int row, int col, int n) {
    // Mark the current row
    mapRow[row] = true;
    // Mark the downward diagonal
    mapDownDiagonal[row + col] = true;
    // Mark the upward diagonal
    mapUpDiagonal[(n - 1) + col - row] = true;
}

// Reset values in hash maps during backtracking
void resetMapValues(int row, int col, int n) {
    // Unmark the current row
    mapRow[row] = false;
    // Unmark the downward diagonal
    mapDownDiagonal[row + col] = false;
    // Unmark the upward diagonal
    mapUpDiagonal[(n - 1) + col - row] = false;
}

// Optimized backtracking helper function
void nQueensHelper(vector<string> &board, int col, int n, vector<vector<string>> &ans) {
    // Base case: All columns are filled, add the current board to the solutions
    if(col == n) {
        ans.push_back(board);
        return;
    }
    // Try placing a Queen in each row of the current column
    for(int row = 0; row < n; row++) {
        // Check if it's possible to place a Queen at the current position
        if(isPossible(row, col, n)) {
            // Place a Queen
            board[row][col] = 'Q';
            // Update hash maps
            setMapValues(row, col, n);
            // Recur for the next column
            nQueensHelper(board, col + 1, n, ans);
            // Backtrack: Reset the current position
            board[row][col] = '.';
            // Reset hash maps
            resetMapValues(row, col, n);
        }
    }
}

//Approach 2: function to solve N-Queens problem using the Optimized Backtracking approach
vector<vector<string>> solveNQueensOptimized(int n) {
    // Initialize an empty chessboard
    vector<string> board(n, string (n, '.'));
    // Store all distinct solutions
    vector<vector<string>> ans;
    // Start solving from the first column
    solve(board, 0, n, ans);
    return ans;
}


int main() {
    int n = 4;
    cout<<"The distinct Representations using the Backtracking Approach: "<<endl;
    vector<vector<string>> ans = solveNQueens(n);
    for(vector<string> arr : ans) {
        for(string str : arr) {
            cout<<str<<endl;
        } 
        cout<<endl;
    }

    cout<<endl<<"The distinct Representations using the Optimized Backtracking Approach: "<<endl;
    ans = solveNQueensOptimized(n);
    for(vector<string> arr : ans) {
        for(string str : arr) {
            cout<<str<<endl;
        } 
        cout<<endl;
    }
    return 0;
}
