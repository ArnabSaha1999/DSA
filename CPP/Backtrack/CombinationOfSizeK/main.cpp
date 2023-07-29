#include<iostream>
#include<vector>

using namespace std;

// Recursive function to find combinations of 'combination' elements from 'num' numbers
void findCombinations(int num, int index, int combination, vector<int> &output, vector<vector<int>> &ans) {
    // If the output vector has reached the desired 'combination' size, add it to the answer
    if(output.size() == combination) {
        ans.push_back(output);
        return;
    }
    // Start from the given 'index' and consider all numbers up to 'num'
    for(int i = index; i <= num; i++) {
        // Choose the current number 'i' as part of the combination
        output.push_back(i);
        // Recursively find the remaining combinations with the next index and updated output
        findCombinations(num, i + 1, combination, output, ans);
        // Backtrack by removing the last element to explore other combinations
        output.pop_back();
    }
}

//Approach 1: Function to find all combinations of 'combination' elements from 'num' numbers
vector<vector<int>> combinations(int num, int combination) {
    vector<vector<int>> ans;
    // If the required 'combination' is larger than the 'num', return an empty result
    if(combination > num) {
        return ans;
    }
    vector<int> output;
    // Call the recursive function to find all combinations
    findCombinations(num, 1, combination, output, ans);
    return ans;
    
}

//Function to print array elements.
void printArray(vector<int> &arr) {
    cout<<"{";
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i];
        if(i != arr.size() - 1) {
            cout<<",";
        }
    }
    cout<<"}";
}

int main() {
    int num, combination;
    cout<<"Enter the number of elements: "<<endl;
    cin>>num;
    cout<<"Enter the number of combination: "<<endl;
    cin>>combination;
    vector<vector<int>> ans = combinations(num, combination);
    cout<<"The Combinations of "<<num<<" numbers and combination of "<<combination<<": "<<endl;
    for(auto &i : ans) {
        printArray(i);
    } cout<<endl;
    
    return 0;
}
