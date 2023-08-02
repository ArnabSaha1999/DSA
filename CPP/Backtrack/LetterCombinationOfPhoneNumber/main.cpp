#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Recursive function to generate all possible letter combinations for the given digits
void solve(string digits, string &output, int index, string mapping[], vector<string> &ans) {
    // Base case: If the index is greater than or equal to the length of the digits string,
    // we have considered all digits, so add the current output to the answer and return.
    if(index >= digits.length()) {
        ans.push_back(output);
        return;
    }
    // Get the integer value of the current digit
    int element = digits[index] - '0';
    // Get the corresponding string of letters for the current digit
    string value = mapping[element];
    // Recursively explore all possible combinations of letters for the current digit
    for(int i = 0; i < value.length(); i++) {
        output.push_back(value[i]); // Include the current letter in the output
        solve(digits, output, index + 1, mapping, ans); // Explore combinations for the next digit
        output.pop_back(); // Backtrack by removing the last letter from the output
    }
}

//Approach 1: Function to find all possible letter combinations for the given digits using Backtracking approach
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    // If the digits string is empty, return an empty vector
    if(digits.length() == 0) {
        return ans;
    }
    string output = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = 0;
    solve(digits, output, index, mapping, ans);
    return ans;
}

int main() {
    string digits = "235";
    cout<<"The letter combination of digits "<<digits<<endl;
    vector<string> ans = letterCombinations(digits);
    for(string a : ans) {
        cout<<a<<" ";
    } cout<< endl;
    return 0;
}
