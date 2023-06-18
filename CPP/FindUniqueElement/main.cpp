#include<iostream>
#include<unordered_map>
using namespace std;

//Approach 1: Using a tested loop to compare all the array elements with each other.
int findUniqueBruteForce(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(i != j && arr[i] == arr[j]) {
                count++;
                break;
            }
        }
        if(count == 0) {
            return arr[i];
        }
    }
    return -1;
}

//Approach 2: Using a XOR operation to find the Unique element.
int findUniqueXOR(int arr[], int size) {
    int ans = 0;
    for(int i = 0; i < size; i++) {
        ans ^= arr[i];
    }
    return ans;
} 

//Approach 3: Using an unordered map to store the frequency of each element in the array.
int findUniqueHashMap(int arr[], int size) {
    unordered_map<int, int> unique;
    for(int i = 0; i < size; i++) {
        unique[arr[i]]++;
    }

    for(auto u:unique) {
        if(u.second == 1)
            return u.first;
    }
    return -1;
}

int main(){
    int arr[7] = {3,1,1,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = findUniqueXOR(arr, size);
    cout<<"The unique element is : "<<ans<<endl;
}
