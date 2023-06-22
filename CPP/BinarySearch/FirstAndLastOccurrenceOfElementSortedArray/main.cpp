#include<iostream>
#include<vector>
#include<utility>

using namespace std;

//Approach 1: Find the first and last occurrence of the target element using Linear Search.
pair<int, int> findFirstAndLastOccurrenceBruteForce(vector<int> &arr, int n, int target) {
    int first = -1, last = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            if(first == -1)
                first = i;
        last = i;
        }
    }
    return make_pair(first, last);
}

//Approach 2: Find the first and last occurrence of the target element using Binary Search.
pair<int, int> findFirstAndLastOccurrence(vector<int> &arr, int n, int target) {
    int first = -1, last = -1;
    
    // Binary search to find the first occurrence
    int low = 0, high = n-1, mid;
    while(low <= high) {
        //mid = (low + high) / 2 can cause problem when low + high can exceed the limit of int
        mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if(arr[mid] > target){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Binary search to find the last occurrence
    low = 0, high = n-1;
    while(low <= high) {
        mid = low + (high - low) /2;
        if(arr[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if(arr[mid] > target) {
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }

    return make_pair(first, last);
}

int main() {
    vector<int> arr = {0, 2, 7, 12, 12};
    int target = 12;
    pair<int, int> ansPair = findFirstAndLastOccurrence(arr, arr.size(), target);
    if(ansPair.first == -1){
        cout<<"The element "<<target<<" is not present in the Array"<<endl;
    } else{
        cout<<"The first occurrence of "<<target<<" is at "<<ansPair.first<<" index"<<endl;
        cout<<"The last occurrence of "<<target<<" is at "<<ansPair.second<<" index"<<endl;
    }
    return 0;
}
