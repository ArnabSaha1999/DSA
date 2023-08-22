#include<iostream>

using namespace std;

// A Stack class with dynamic array, capacity and top member variables
class Stack{
    int* arr;
    int capacity;
    int top;

public:
    //creates an empty stack
    Stack() {
        capacity = 10;
        arr = new int[capacity];
        top = -1;
    }

    // Checks if stack is empty
    bool isEmpty() {
        // Stack is empty if the top is -1
        if(top == -1) {
            return true;
        }
        return false;
    }

    // Checks if stack is full
    bool isFull() {
        // Stack is full if the top value is equals to the capacity of the stack
        if(top == capacity - 1) {
            return true;
        }
        return false;
    }

    // pushes the element on top of stack
    void push(int value) {
        if(isFull()) {
            // Double the capacity
            capacity *= 2;
            // Create a new array with increased capacity
            int* newArr = new int[capacity];
            // Copy elements from old array to new array
            for(int i = 0; i <= top; i++) {
                newArr[i] = arr[i];
            }
            // Free memory of old array
            delete[] arr;
            // Update the pointer to the new array
            arr = newArr;
        }
        // Increment top and add the value to the array
        arr[++top] = value;
    }

    // pops the top element out of the stack
    void pop() {
        // If Stack is empty then nothing to pop
        if(isEmpty()) {
            return;
        }
        top--; // Decrease top index to remove the top element
    }

    // Returns the top element of the stack
    int getTop() {
        // Return -1 for an empty stack
        if(isEmpty()) {
            return -1;
        }
        // Return the value of the top element
        return arr[top];
    }

    // Calculate the size of the stack
    int getSize() {
        // The size of the stack is the index of the top element + 1
        return top + 1;
    }

    // Destructor: Clean up memory for all nodes
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack st;
    if(st.isEmpty()) {
        cout<<"The Stack is empty"<<endl;
    } else {
        cout<<"The Stack is not empty"<<endl;
    }

    if(st.isFull()) {
        cout<<"The Stack is full"<<endl;
    } else {
        cout<<"The Stack is not full"<<endl;
    }

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);

    if(st.isFull()) {
        cout<<"The Stack is full"<<endl;
    } else {
        cout<<"The Stack is not full"<<endl;
    }

    cout<<"The Top element of Stack: "<<st.getTop()<<endl;
    cout<<"The Size of Stack: "<<st.getSize()<<endl;
    
    st.pop();

    cout<<"The Top element of Stack: "<<st.getTop()<<endl;
    cout<<"The Size of Stack: "<<st.getSize()<<endl;

    st.push(0);

    cout<<"The Top element of Stack: "<<st.getTop()<<endl;
    cout<<"The Size of Stack: "<<st.getSize()<<endl;

    return 0;
}
