#include<iostream>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

// Find the index of the next smaller element for each bar
vector<int> findNextSmallerElement(vector<int> &heights, int size) {
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
vector<int> findPrevSmallerElement(vector<int> &heights, int size) {
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
int largestRectangleArea(vector<int>&heights) {
    int size = heights.size();
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

//Approach 1: Maximal Rectangle area using stack based approach
int maximalRectangle(vector<vector<char>>& matrix) {
    // Get the number of rows and columns in the matrix
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    // Initialize a histogram array to keep track of heights of each column
    vector<int> histogram(colSize, 0);
    int area = INT_MIN;
    // Traverse through each row of the matrix
    for(int i = 0; i < rowSize; i++) {
        // Update the histogram array based on the values in the current row
        for(int j = 0; j < colSize; j++) {
            if(matrix[i][j] != '0') {
                // If the cell value is '1', increment the histogram value for the corresponding column
                histogram[j] += 1;
            } else {
                // If the cell value is '0', reset the histogram value for the corresponding column
                histogram[j] = 0;
            }
        }
        // Calculate the largest rectangle area for the current histogram using the largestRectangleArea function
    // and update the maximum area if a larger rectangle is found
        area = max(area, largestRectangleArea(histogram));
    }
    // Return the maximum area of a rectangle
    return area;
}

int main() {
    vector<vector<char>> matrix = {
        {'1','0','0','0','1'},
        {'1','0','1','1','1'},
        {'0','0','1','1','1'},
        {'1','0','1','1','1'},
        {'0','1','1','1','1'},
        {'1','1','0','1','0'}
    };

    cout<<"The input Matrix:"<<endl;
    for(vector<char> arr : matrix) {
        for(char ch : arr) {
            cout<<ch<<" ";
        } cout<<endl;
    } cout<<endl;

    cout<<"The Maximal Rectangle Area: "<<maximalRectangle(matrix)<<endl;

    return 0;
}
