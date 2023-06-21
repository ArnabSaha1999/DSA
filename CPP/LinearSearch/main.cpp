#include<iostream>
using namespace std;

//Approach 1: Using Iteration method
int linearSearch(int *arr, int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

//Approach 2: Using Recursive method
int linearSearchRecursive(int *arr, int size, int target, int index=0) {
    if(index == size) {
        return -1;
    }
    if(arr[index] == target) {
        return index;
    }
    return linearSearchRecursive(arr, size, target, index+1);
}

int main(){
    int arr[] = {1,3,6,3,4,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 0;
    int ans = linearSearch(arr, size, target);
    if(ans == -1) {
        cout<<"The "<<target<<" Element is not present in the Array."<<endl;
    } else
        cout<<"The "<<target<<" Element is present at the "<<ans<<" Index of the Array."<<endl;
}
