#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

// Function to perform DFS traversal for flood-fill
void dfsTraversal(int initialRow, int initialCol, int initialColor, int newColor, int rowMap[4], int colMap[4], vector<vector<int>> &image, vector<vector<int>> &ansImage) {
    // Mark the current pixel with the new color
    ansImage[initialRow][initialCol] = newColor;
    // Get the dimensions of the image
    int rowSize = image.size();
    int colSize = image[0].size();
    // Explore neighboring pixels
    for(int i = 0; i < 4; i++) {
        int newRow = initialRow + rowMap[i];
        int newCol = initialCol + colMap[i];
        // Check if the neighboring pixel is within bounds, has the initial color, and has not been colored with the new color
        if(newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize && image[newRow][newCol] == initialColor && ansImage[newRow][newCol] != newColor) {
            // Recursively call DFS for the neighboring pixel
            dfsTraversal(newRow, newCol, initialColor, newColor, rowMap, colMap, image, ansImage);
        }
    }
}

//Approach 1: Function to perform flood-fill using DFS
vector<vector<int>> floodFillDFS(vector<vector<int>> &image, int initialRow, int initialCol, int newColor) {
    // If the initial pixel already has the new color, no need to fill
    if(image[initialRow][initialCol] == newColor) {
        return image;
    }
    int initialColor = image[initialRow][initialCol];
    // Create a copy of the image to store the result
    vector<vector<int>> ansImage = image;
    // Define directional movement for neighbors U/R/D/L
    int rowMap[4] = {-1, 0, 1, 0};
    int colMap[4] = {0, 1, 0, -1};
    // Start DFS traversal from the initial pixel
    dfsTraversal(initialRow, initialCol, initialColor, newColor, rowMap, colMap, image, ansImage);
    // Return the modified image
    return ansImage;
}

//Approach 2: Function for flood fill using BFS
vector<vector<int>> floodFillBFS(vector<vector<int>> &image, int initialRow, int initialCol, int newColor) {
    // If the initial pixel already has the new color, no need to fill
    if(image[initialRow][initialCol] == newColor) {
        return image;
    }
    int rowSize = image.size();
    int colSize = image[0].size();
    // Create a copy of the image to store the result
    int initialColor = image[initialRow][initialCol];
    // Create a copy of the image to store the result
    vector<vector<int>> ansImage = image;
    // Define directional movement for neighbors U/R/D/L
    int rowMap[4] = {-1, 0, 1, 0};
    int colMap[4] = {0, 1, 0, -1};
    // Create a queue for BFS traversal
    queue<pair<int, int>> bfsQueue;
    // Push the initial pixel to the queue
    bfsQueue.push({initialRow, initialCol});
    // Perform BFS
    while(!bfsQueue.empty()) {
        // Get the front pixel from the queue
        int frontRow = bfsQueue.front().first;
        int frontCol = bfsQueue.front().second;
        bfsQueue.pop();
        // Mark the current pixel with the new color
        ansImage[frontRow][frontCol] = newColor;
        // Explore neighbors in all 4 directions
        for(int i = 0; i < 4; i++) {
            // Get the front pixel from the queue
            int newRow = frontRow + rowMap[i];
            int newCol = frontCol + colMap[i];
            // Check bounds and if the neighbor has the initial color and has not been filled with the new color
            if(newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize && image[newRow][newCol] == initialColor && ansImage[newRow][newCol] != newColor) {
                // Push the neighbor to the queue for further exploration
                bfsQueue.push({newRow, newCol});
            }
        }
    }
    // Return the modified image
    return ansImage;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int initialRow = 1, initialCol = 1, newColor = 2;

    cout<<"The Initial Image: "<<endl;
    for(auto arr: image) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    cout<<endl<<"The Image after modifying with DFS:"<<endl;
    vector<vector<int>> ansImage = floodFillDFS(image, initialRow, initialCol, newColor);
    for(auto arr: ansImage) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    cout<<endl<<"The Image after modifying with BFS:"<<endl;
    ansImage = floodFillBFS(image, initialRow, initialCol, newColor);
    for(auto arr: ansImage) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    image = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    initialRow = 0, initialCol = 0, newColor = 0;

    cout<<endl<<"The Initial Image: "<<endl;
    for(auto arr: image) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    cout<<endl<<"The Image after modifying with DFS:"<<endl;
    ansImage = floodFillDFS(image, initialRow, initialCol, newColor);
    for(auto arr: ansImage) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    cout<<endl<<"The Image after modifying with BFS:"<<endl;
    ansImage = floodFillBFS(image, initialRow, initialCol, newColor);
    for(auto arr: ansImage) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    return 0;    
}
