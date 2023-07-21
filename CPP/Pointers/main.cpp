#include <iostream>

using namespace std;

// Function to double the value pointed to by a pointer
void doubleValue(int* ptr) {
    if (ptr != nullptr) {
        *ptr *= 2;
    }
}

int main() {
    // Dynamic Memory Allocation for an array of integers
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* dynamicArr = new int[size]; // Allocate memory for an array of integers

    // Initialize the array using pointer arithmetic
    for (int i = 0; i < size; ++i) {
        dynamicArr[i] = i + 1;
    }

    cout << "Dynamic Array Elements: ";
    for (int i = 0; i < size; ++i) {
        cout << dynamicArr[i] << " "; // Output: Dynamic Array Elements: 1 2 3 4 5 ...
    }
    cout << endl;

    // Pointer to Pointer
    int num = 42;
    int* ptr = &num; // Pointer to 'num'
    int** ptrToPtr = &ptr; // Pointer to the pointer 'ptr'

    cout << "Value through Pointer to Pointer: " << **ptrToPtr << endl; // Output: Value through Pointer to Pointer: 42

    // Modifying the value through Pointer to Pointer
    **ptrToPtr = 100;

    cout << "Modified Value of num: " << num << endl; // Output: Modified Value of num: 100

    // Delete dynamically allocated memory
    delete[] dynamicArr;

    return 0;
}
