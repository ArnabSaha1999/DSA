#include<iostream>
#include<vector>

using namespace std;

// Reverses the elements of the array between the start and end indices
void reverse(vector<int> &arr, int start, int size) {
    int end = size - 1;
    while(start <= end) {
        swap(arr[start++], arr[end--]);
    }
    return;
}

//Approach 1: Calculates the sum of two arrays of digits
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m) {
    int i = n - 1, j = m - 1, carry = 0;
    vector<int> ans;
    // Add digits from both arrays until one or both arrays are exhausted
    while(i >= 0 && j >= 0) {
        int sum = a[i--] + b[j--] + carry;
        carry = sum/10;
        sum %= 10;
        ans.push_back(sum);
    }
    // Add remaining digits from array 'a' if any
    while(i >= 0) {
        int sum = a[i--] + carry;
        carry = sum/10;
        sum %= 10;
        ans.push_back(sum);
    }
    // Add remaining digits from array 'b' if any
    while(j >= 0) {
        int sum = b[j--] + carry;
        carry = sum/10;
        sum %= 10;
        ans.push_back(sum);
    }
    // Add any remaining carry
    while(carry != 0) {
        int sum = carry;
        carry = sum/10;
        sum %= 10;
        ans.push_back(sum);
    }
    reverse(ans, 0, ans.size()); // Reverse the result array
    return ans; 
}

//Approach 2: Calculates the sum of two arrays of digits (optimized version)
vector<int> findArraySumOptimized(vector<int> &a, int n, vector<int> &b, int m) {
    int i = n - 1, j = m - 1, carry = 0;
    vector<int> ans;
    // Add digits from both arrays until one or both arrays are exhausted
    while(i >= 0 || j >= 0 || carry != 0) {
        int sum = carry;
        if(i >= 0) {
            sum += a[i--];
        }

        if(j >= 0) {
            sum += b[j--];
        }

        ans.push_back(sum % 10);
        carry = sum / 10;
    }
    reverse(ans, 0, ans.size()); // Reverse the result array
    return ans;
}

// Prints the elements of the array
void printArray(vector<int> &arr) {
    for(int i : arr) {
        cout<<i<<" ";
    } cout<<endl;
}

int main() {
    vector<int> a = {1,2,4,0,1};
    vector<int> b = {9};
    cout<<"The first Array: ";
    printArray(a);
    cout<<"The second Array: ";
    printArray(b);
    
    vector<int> ans = findArraySumOptimized(a, a.size(), b, b.size());
    cout<<"The Sum of two Array: ";
    printArray(ans);
    return 0;
}
