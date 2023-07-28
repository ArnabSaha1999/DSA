#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Function to check if moving to the given coordinates is possible
bool isPossible(vector<vector<int>> &maze, int n, int x, int y, vector<vector<int>> &visited) {
    // Check if the coordinates are within the maze boundaries and the cell is unvisited and not blocked
    if((x >= 0 && x < n) && (y >= 0 && y < n) && (maze[x][y] == 1 && visited[x][y] == 0)) {
        return true;
    }
    return false;
}

// Backtracking function to find all possible paths in the maze
void solvePath(vector<vector<int>> &maze, int n, string &path, int srcX, int srcY, vector<string> &ans, vector<vector<int>> &visited) {
    // If the current position is the destination cell, add the current path to the answer and return
    if(srcX == n - 1 && srcY == n - 1) {
        ans.push_back(path);
        return;
    }
    // Mark the current cell as visited
    visited[srcX][srcY] = 1;

    //Moving Downwards
    int newX = srcX + 1;
    int newY = srcY;

    if(isPossible(maze, n, newX, newY, visited)) {
        path.push_back('D');
        solvePath(maze, n, path, newX, newY, ans, visited);
        path.pop_back(); // Backtrack by removing the last character
    }

    //Moving Leftwards
    newX = srcX;
    newY = srcY - 1;

    if(isPossible(maze, n, newX, newY, visited)) {
        path.push_back('L');
        solvePath(maze, n, path, newX, newY, ans, visited);
        path.pop_back(); // Backtrack by removing the last character
    }

    //Moving Rightwards
    newX = srcX;
    newY = srcY + 1;

    if(isPossible(maze, n, newX, newY, visited)) {
        path.push_back('R');
        solvePath(maze, n, path, newX, newY, ans, visited);
        path.pop_back(); // Backtrack by removing the last character
    }


    //Moving Upwards
    newX = srcX - 1;
    newY = srcY;
    
    if(isPossible(maze, n, newX, newY, visited)) {
        path.push_back('U');
        solvePath(maze, n, path, newX, newY, ans, visited);
        path.pop_back(); // Backtrack by removing the last character
    }

    visited[srcX][srcY] = 0; // Backtrack by marking the current cell as unvisited

}

//Approach 1: Function to find all possible paths in the maze from source to destination
vector<string> findPath(vector<vector<int>> &maze, int n) {
    vector<string> ans;
    if(maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        // If the source or destination is blocked, there are no possible paths
        return ans;
    }
    int srcX = 0, srcY = 0;
    string path = "";
    vector<vector<int>> visited = maze;
    // Initialize the visited matrix to 0
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            visited[r][c] = 0;
        }
    }
    // Call the backtracking function to find all paths
    solvePath(maze, n, path, srcX, srcY, ans, visited);
    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    cout<<"The Paths to reach the destination: "<<endl;
    vector<string> ans = findPath(maze, maze.size());
    
    for(string a : ans) {
        cout<<"'"<<a<<"' ";
    } cout<<endl;
    
    return 0;
}
