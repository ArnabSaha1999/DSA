#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//Approach 1: Using Hashmap and Set to track the count of each array elements.
bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> count;
    unordered_set<int> unique;
    for(int i : arr) {
        count[i]++;
    }
    for(auto i : count) {
        /*
        unique.insert(i.second), the insert function is called to insert the occurrence count into the unique set, 
        and (i.second).second checks the boolean value of the pair returned by insert to determine if the insertion was successful and if the occurrence count is unique.
        */
        if(!unique.insert(i.second).second)
            return false;
    }
    return true;
}

int main() {
    vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
    cout<<uniqueOccurrences(arr);
    return 0;
}
