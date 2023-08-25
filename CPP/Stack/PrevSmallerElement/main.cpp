#include<iostream>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

//Approach 1: Function to find the previous smaller elements using a brute force approach
vector<int> previousSmallerElement(vector<int> &arr, int n) {
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--) {
        // Initialize as -1, assuming no smaller element found
        ans[i] = -1;
        for(int j = i - 1; j >= 0; j--) {
            if(arr[j] < arr[i]) {
                // Update with the smaller element
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

//Approach 2: Function to find the previous smaller elements using a stack-based approach
vector<int> previousSmallerElementUsingStack(vector<int> &arr, int n) {
    stack<int> st;
    // Initialize with -1, assuming no smaller element found
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) {
        // Pop elements from the stack until finding a smaller element
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            // Update with the smaller element from the stack
            ans[i] = st.top();
        }
        // Push the current element onto the stack
        st.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {2,4,9,3,1};
    cout<<"The Array elements: "<<endl;
    for(int a : arr) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The previous smaller elements using Brute force approach: "<<endl;
    vector<int> ans = previousSmallerElement(arr, arr.size());
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The previous smaller elements using Stack approach: "<<endl;
    ans = previousSmallerElementUsingStack(arr, arr.size());
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;
}
