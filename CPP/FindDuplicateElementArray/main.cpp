#include<iostream>
#include<unordered_map>
using namespace std;

//Approach 1: Uses a nested loop to compare each element with every other element in the array.
int findDuplicateBruteForce(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }
    return -1;
}

//Approach 2: Utilizes an unordered map to count the occurrences of each element in the array.
int findDuplicateHashMap(int arr[], int size) {
    unordered_map<int, int> unique;
    for(int i = 0; i < size; i++) {
        unique[arr[i]]++;
    }
    for(auto u:unique) {
        if(u.second > 1)
            return u.first;
    }
    return -1;
}

//Approach 3: Using the Floyd's Tortoise and Hare algorithm, also known as the "fast and slow pointers" technique.
int findDuplicateFloyd(int arr[], int size) {
    // Initialize the slow and fast pointers to the starting point of the array
    int slow = arr[0];
    int fast = arr[0];
    
    // Move the pointers until they meet within the cycle
    do{
        slow = arr[slow];          // Move the slow pointer by one step
        fast = arr[arr[fast]];     // Move the fast pointer by two steps
    } while (slow != fast);

    // Reset the slow pointer to the starting point and move both pointers one step at a time
    // until they meet again at the duplicate element within the cycle
    slow = arr[0];
    while(slow != fast) {
        slow = arr[slow];  // Move the slow pointer by one step
        fast = arr[fast];  // Move the fast pointer by one step
    }

    // Return the duplicate element
    return slow;
}

int main() {
    int arr[5] = {3,1,1,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = findDuplicateFloyd(arr, size);
    cout<<"The Dublicate element is : "<<ans<<endl;
}
