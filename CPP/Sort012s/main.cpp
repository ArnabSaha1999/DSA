#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Using Bubble Sort to sort the array of 0s, 1s and 2s
vector<int> sort012s(vector<int> &arr) {
    bool isSwapped;
    for(int i = 0; i < arr.size() - 1; i++) {
        isSwapped = false;
        for(int j = 0; j < arr.size() - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if(!isSwapped)
            break;
        
    }
    return arr;
}

//Approach 2: Using Dutch National Flag algorithm to sort 0s, 1s and 2s
vector<int> sort012sOptimized(vector<int> &arr) {
    int low=0, mid=0, high = arr.size() - 1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]); // Place 0 at the beginning
            low++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++; // Ignore 1 and move to the next element
        } else {
            swap(arr[mid], arr[high]); // Place 2 at the end
            high--;
        }
    }
    return arr;
}

int main(){ 
    vector<int> arr {0,2,1,0,1,0,2,0};
    cout<<"After sorting the Array: "<<endl;
    vector<int> ans = sort012sOptimized(arr);
    for(int i : ans) {
        cout<<i<<" ";
    }
    return 0;
}
