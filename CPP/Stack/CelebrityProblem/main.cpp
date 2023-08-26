#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//Approach 1: Function to find the celebrity using brute force approach
int findCelebrityBruteForce(vector<vector<int>> &candidate, int n) {
    // Loop through each person to check if they are a potential celebrity
    for(int i = 0; i < n; i++) {
        bool isCandidate = true;
        for(int j = 0; j < n; j++) {
            // if another person doesn't know the current person (candidate[j][i] == 0)
            if(i != j && (candidate[i][j] == 1 || candidate[j][i] == 0)) {
                // Mark the person as not a candidate
                isCandidate = false;
            }
        }
        if(isCandidate) {
            // Return the index of the potential celebrity
            return i;
        }
    }
    return -1;
}

//Approach 2: Function to find the celebrity using stack approach
int findCelebrityUsingStack(vector<vector<int>> &candidate, int n) {
    stack<int> st;
    // Push all persons onto the stack
    for(int i = 0; i < n; i++) {
        st.push(i);
    }
    // Continuously compare pairs of people until only one person is left in the stack
    while(st.size() > 1) {
        // Get the first person from the top of the stack
        int person1 = st.top();
        st.pop();
        // Get the second person from the top of the stack
        int person2 = st.top();
        st.pop();
        // If person1 knows person2, person2 could be the celebrity
        if(candidate[person1][person2] == 1) {
            st.push(person2);
        } else{
            // Otherwise, person1 could be the celebrity
            st.push(person1);
        }
    }
    // The remaining person in the stack is the potential celebrity
    int potentialCelebrity = st.top();
    st.pop();
    // Check if the potential celebrity knows others or is known by others
    for(int i = 0; i < n; i++) {
        if(i != potentialCelebrity && (candidate[potentialCelebrity][i] == 1 || candidate[i][potentialCelebrity] == 0)) {
            // No celebrity found
            return -1;
        }
    }
    // Return the index of the potential celebrity
    return potentialCelebrity;
}

//Approach 3: Function to find the celebrity using two-pointer approach
int findCelebrity(vector<vector<int>> &candidate, int n) {
    int left = 0, right = n - 1;
    int isCandidate = 0;
    while(left < right) {
        if(candidate[left][right] == 1) {
            // Move left pointer if the left person knows the right person
            left++;
        } else {
            // Move right pointer if the right person knows the left person
            right--;
        }
    }
    // The remaining person at the pointer is the potential celebrity
    isCandidate = left;
    // Check if the potential celebrity knows others or is known by others
    for(int i = 0; i < n; i++) {
        if(i != isCandidate && (candidate[isCandidate][i] == 1 || candidate[i][isCandidate] == 0)) {
            return -1; // No celebrity found
        }
    }
    return isCandidate; // Return the index of the potential celebrity
}

int main() {
    vector<vector<int>> matrix = {
        {0,1,0,1},
        {0,0,0,0},
        {1,1,0,1},
        {1,1,0,0}
    };

    cout<<"The input Matrix: "<<endl;
    for(vector<int> arr : matrix) {
        for(int a : arr) {
            cout<<a<<" ";
        } cout<<endl;
    } cout<<endl;

    cout<<"Finding the Celebrity using Brute Force approach: "<<findCelebrityBruteForce(matrix, matrix.size())<<endl;

    cout<<"Finding the Celebrity using Stack approach: "<<findCelebrityUsingStack(matrix, matrix.size())<<endl;

    cout<<"Finding the Celebrity using Two-Pointer approach: "<<findCelebrity(matrix, matrix.size())<<endl;
    
    return 0;
    
}
