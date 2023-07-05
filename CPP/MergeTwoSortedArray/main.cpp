#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Function to merge two sorted arrays using a temp array
void merge(vector<int> &arr1, int m, vector<int> &arr2, int n) {
    // Create a temporary array to store the merged result
    vector<int> temp(m+n, 0);
    // Pointers for iterating over the input arrays
    int i = 0, j = 0, k = 0;
    // Merge the arrays while there are elements in both of them
    while(i < m && j < n) {
        // Compare elements from both arrays and store the smaller one in the temporary array
        if(arr1[i] < arr2[j]) {
            temp[k++] = arr1[i++];
        } else {
            temp[k++] = arr2[j++];
        }
    }
    // If there are any remaining elements in arr1, copy them to the temporary array
    while(i < m) {
        temp[k++] = arr1[i++];
    }
    // If there are any remaining elements in arr2, copy them to the temporary array
    while(j < n) {
        temp[k++] = arr2[j++];
    }
    // Copy the merged result from the temporary array back to arr1
    arr1 = temp;
}

//Approach 2: Function to merge two sorted arrays in-place.
void mergeOptimized(vector<int> &arr1, int m, vector<int> &arr2, int n) {
    // Pointers for iterating over the input arrays
    int i = m - 1, j = n - 1, k = m + n - 1;
    // Merge the arrays while there are elements in both of them
    while (i >= 0 && j >= 0) {
        // Compare the elements from both arrays and store the larger element at the end of arr1
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }
    // If there are any remaining elements in arr2, copy them to the beginning of arr1
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
}

// Prints the elements of the array
void printArray(vector<int> &arr) {
    for(int i : arr) {
        cout<<i<<" ";
    } cout<<endl;
}

int main() {
    vector<int> num1 = {1,3,8,8,10}, num2 = {2,4,9,12};
    cout<<"The first vector: ";
    printArray(num1);

    cout<<"The second vector: ";
    printArray(num2);

    mergeOptimized(num1, num1.size(), num2, num2.size());
    cout<<"The merged vector: ";
    printArray(num1);
    return 0;
}
