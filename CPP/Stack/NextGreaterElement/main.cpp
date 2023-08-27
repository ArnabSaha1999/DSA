#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//Approach 1: Function to find the next greater elements using a brute force approach
vector<int> nextGreaterElement(vector<int> &arr, int n) {
    // Initialize as -1, assuming no greater element found
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                // Update with the greater element
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

//Approach 2: Function to find the next greater elements using a stack-based approach
vector<int> nextGreaterElementUsingStack(vector<int> &arr, int n) {
    // Initialize with -1, assuming no greater element found
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack until finding a greater element
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            // Update with the greater element from the stack
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

    cout<<"The next greater elements using Brute force approach: "<<endl;
    vector<int> ans = nextGreaterElement(arr, arr.size());
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The next greater elements using Stack approach: "<<endl;
    ans = nextGreaterElementUsingStack(arr, arr.size());
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    return 0;
}
