#include<iostream>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

//Approach 1: Find Largest Rectangle Area in Histogram using Brute Force approach
int largestRectangleArea(vector<int>& heights) {
    int size = heights.size();
    int area = 0;
    // Iterate through each bar as the potential starting point of the rectangle
    for (int i = 0; i < size; i++) {
        int minHeight = heights[i];
        // Find the minimum height among the bars within the current potential rectangle
        for (int j = i; j < size; j++) {
            minHeight = min(minHeight, heights[j]);
            // Calculate the area of the current potential rectangle
            int breadth = j - i + 1;
            int newArea = minHeight * breadth;
            // Update the maximum area if the current rectangle's area is greater
            area = max(area, newArea);
        }
    }

    return area;

}

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

//Approach 2: Find Largest Rectangle Area in Histogram using Stack
int largestRectangleAreaUsingStack(vector<int>&heights) {
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

int main() {
    vector<int> arr = {2,1,5,6,2,3};
    cout<<"The input Histogram: "<<endl;
    for(int a : arr) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The Largest Area in Histogram using Brute Force approach: "<<largestRectangleArea(arr)<<endl;

    cout<<"The Largest Area in Histogram Using Stack approach: "<<largestRectangleAreaUsingStack(arr)<<endl;
    return 0;
}
