#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Using Linear Search
int linearSearch(vector<int> &arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

//Function to find the Pivot/Smallest element in the array.
int findPivotIndex(vector<int> &arr) {
    int low = 0, high = arr.size() - 1, mid;
    while(low < high) {
        mid = low + (high - low) / 2;
        if(arr[mid] > arr[high]) { //If middle element is bigger than high element means pivot lies in the right of the array.
            low = mid+1;
        } else{ //If middle element is smaller than low element means pivot lies in the left or the middle itself is the pivot.
            high = mid;
        }
    
    }
    return low;
}

//Approach 2: Using Binary Search with the help of Pivot/Smallest element index.
int findElementIndex(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1, mid;
    int pivotIndex = findPivotIndex(arr);
    if(arr[pivotIndex] > target) {
        return -1; // If the target is smaller than the pivot element, it cannot exist in the array.
    }
    if(arr[pivotIndex] == target) {
        return pivotIndex; // If the target is equal to the pivot element, return the pivot index.
    }
    if(arr[pivotIndex] < target && target <= arr[arr.size()-1]) {
        low = pivotIndex + 1; // If the target is within the range of the sorted right half, adjust the low pointer accordingly.
    } else {
        high = pivotIndex - 1; // If the target is within the range of the sorted left half, adjust the high pointer accordingly.
    }
    //Applying Binary Search
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;

}

int main() {
    vector<int> arr = {3,4,5,1,2};
    int target = 8;
    int ans = findElementIndex(arr, target);
    if(ans == -1) {
        cout<<"The element "<<target<<" is not present in the Array."<<endl;
    } else{
        cout<<"The element "<<target<<" is present at the index : "<<ans<<endl;
    }
    return 0;
}
