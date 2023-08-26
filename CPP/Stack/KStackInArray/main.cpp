#include<iostream>
#include<cstring>
#include<stack>

using namespace std; 

class KStacks {
    int *arr, *top, *next;
    int freespot;

public:
    //Time Complexity of O(1) & Space Complexity of O(N + K)
    KStacks(int k, int n) {
        arr = new int[n];

        top = new int[k];
        //intializing top with -1
        memset(top, -1, sizeof(int) * k);
        // Initializing array elements with -1 (empty slots)
        memset(arr, -1, sizeof(int) * n);
        
        next = new int[n];

        // Initializing next array to point to the next element
        for(int i = 0; i < n-1; i++) {
            next[i] = i+1;
        }

        next[n-1] = -1;

        freespot = 0;
    }

    // Pushes an element onto the specified stack
    bool push(int x, int m) {
        // No space available
        if(freespot == -1) {
            return false;
        }
        
        // Get the next free spot
        int index = freespot;
        
        // Insert the element into the array
        arr[index] = x;
        
        // Update the free spot
        freespot = next[index];
       
        // Update the next pointer to the previous top
        next[index] = top[m-1];
        
        // Update the top index
        top[m-1] = index;
        
        return true;
    }

    // Pops and returns the top element from the specified stack
    int pop(int m) {
        // Stack is empty
        if(top[m-1] == -1) {
            return -1;
        }
        // Get the top index of the specified stack
        int index= top[m-1];
        // Update the top index to the next element
        top[m-1] = next[index];
        // Update the next pointer to the previous free spot
        next[index] = freespot;
        // Update the free spot
        freespot = index;
        // Return the popped element
        return arr[index];
    }

    // Returns the top element of the specified stack
    int getTop(int m) {
        // Stack is empty
        if(top[m - 1] == -1) {
            return -1;
        }
        return arr[top[m - 1]];
    }

    // Returns the number of elements in the specified stack
    int getSize(int m) {
        int size = 0;
        int index = top[m - 1];
        while(index != -1) {
            size++;
            index = next[index];
        } 
        return size;
    }

    bool isEmpty(int m) {
        if(top[m - 1] == -1) {
            return true;
        }
        return false;
    }
};

int main() {
    int stackNumber = 3;
    int arrSize = 6;
    
    // Create a KStacks object with specified stack count and array size
    KStacks ks(stackNumber, arrSize);

    // Push elements onto stacks
    ks.push(15, 2); // Push 15 onto Stack 2
    ks.push(16, 2); // Push 16 onto Stack 2
    ks.push(17, 1); // Push 17 onto Stack 1

    // Display the top element of Stack 2
    cout << "Top of Stack 2: " << ks.getTop(2) << endl;

    // Display the size of Stack 2
    cout << "Size of Stack 2: " << ks.getSize(2) << endl;

    // Check if Stack 1 is empty
    cout << "Is Stack 1 Empty: " << (ks.isEmpty(1) ? "Yes" : "No") << endl;

    // Pop an element from Stack 2 and display it
    cout << "Popped element from Stack 2: " << ks.pop(2) << endl;

    return 0;
}
