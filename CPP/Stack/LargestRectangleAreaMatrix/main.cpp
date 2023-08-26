#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<climits>
#define MAX 1000

using namespace std;

// Find the index of the next smaller element for each bar
vector<int> findNextSmallerElement(int* heights, int size) {
    stack<int> st;
    vector<int> ans(size, -1);
    for(int i = size - 1; i >= 0; i--) {
        // Traverse the heights array from right to left
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if(!st.empty()) {
            // Update with the smaller element index
            ans[i] = st.top();
        }
        // Push the current bar's index onto the stack
        st.push(i);
    }
    return ans;
}

// Find the index of the previous smaller element for each bar
vector<int> findPrevSmallerElement(int* heights, int size) {
    stack<int> st;
    vector<int> ans(size, -1);
    // Traverse the heights array from left to right
    for(int i = 0; i < size; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if(!st.empty()) {
            // Update with the smaller element index from the stack 
            ans[i] = st.top();
        }
        // Push the current bar's index onto the stack
        st.push(i);
    }
    return ans;
}

//Find Largest Rectangle Area in Histogram using Stack
int largestRectangleArea(int* heights, int size) {
    // Find the index of the next smaller and previous smaller elements for each bar
    vector<int> nextSmallerElement = findNextSmallerElement(heights, size);
    vector<int> prevSmallerElement = findPrevSmallerElement(heights, size);
    int area = INT_MIN;
    // Calculate the area of each potential rectangle using heights, nextSmallerElement, and prevSmallerElement
    for(int i = 0; i < size; i++) {
        int length = heights[i];
        // If there is no next smaller element, set it to the size of the heights array
        if(nextSmallerElement[i] == -1) {
            nextSmallerElement[i] = size;
        }
        // Calculate the breadth of the potential rectangle
        int breath = nextSmallerElement[i] - prevSmallerElement[i] - 1;
        // Calculate the area of the potential rectangle using length and breadth
        int newArea = length * breath;
        // Update the maximum area if the current rectangle's area is greater
        area = max(area, newArea);
    }
    return area;
}

//Approach 1: Function to calculate the maximum rectangle area in a binary matrix
int maximumRectangleArea(int matrix[][MAX], int n, int m) {
    int area = largestRectangleArea(matrix[0], m);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // If the cell value is not 0, update it with the sum of heights
            if(matrix[i][j] != 0) {
                matrix[i][j] += matrix[i-1][j];
            } else {
                // If the cell value is '0', reset the histogram value for the corresponding column
                matrix[i][j] = 0;
            }
        }
        // Update the maximum area using the largestRectangleArea function
        area = max(area, largestRectangleArea(matrix[i], m));
    }
    return area;
}

int main() {
    int matrix[][MAX] = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };

    cout<<"The input Matrix: "<<endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            cout<<matrix[i][j]<<" ";
        } cout<<endl;
    } cout<<endl;

    cout<<"The Maximum Rectangle Area: "<<maximumRectangleArea(matrix, 4, 5)<<endl;
    return 0;
}
