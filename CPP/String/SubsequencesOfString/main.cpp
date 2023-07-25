#include<iostream>
#include<string>
#include<vector>

using namespace std;

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
    vector<string> ans = subsequencesBitwise(str);

    cout<<"The Subsets of the array: "<<endl<<"{";
    for(string a : ans) {
        cout<<a<<" ";
    }
    cout<<"}"<<endl;

    return 0;
}
  
