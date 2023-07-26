#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Backtracking is used to generate all possible combinations of characters from the input string 'str'
void solve(string str, string output, int index, vector<string>& ans) {
    // Base case: If the index is greater than or equal to the size of the input set,
    // we have considered all elements, so we add the current subset to the answer.
    if(index >= str.length()) {
        if(output != "") {
            ans.push_back(output);
        }
        return ;
    }
    
    // Exclude the current element and continue exploring other elements in the set
    solve(str, output, index+1, ans);
    
    // Include the current element in the subset and continue exploring other elements
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);
    
}


//Approach 1: Function to find all subsets of a given string using backtracking approach
vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
    
}

//Approach 2: Function to find the power set of a string using the Bitwise approach
vector<string> subsequencesBitwise(string str) {
    int totalSubsets = (1 << str.length());
    vector<string> ans;
    for(int i = 0; i < totalSubsets; i++) {
        string subsets = "";
        for(int j = 0; j < str.length(); j++) {
            // If the j-th bit of i is set, add the corresponding element to the subset
            if(i & (1 << j)) {
                subsets.push_back(str[j]);
            }
        }
        // Check if the subset is not empty, and add it to the result
        if(subsets != "") 
            ans.push_back(subsets); // Store the current subset in the power set
    }
    return ans;

}


int main() {
    string str = "abc";

    vector<string> ans_backTracking = subsequences(str);
    cout<<"The Subsequences of the string: "<<str<<" using the (Backtracking approach): "<<endl<<"{";
    for (string i : ans_backTracking) {
        cout<<i<<" ";
    }
    cout<<"}"<<endl;

    vector<string> ans = subsequencesBitwise(str);
    cout<<"The SUbsequences of the string: "<<str<<" is :"<<endl<<"{";
    for(string a : ans) {
        cout<<a<<" ";
    }
    cout<<"}"<<endl;
    return 0;
}
