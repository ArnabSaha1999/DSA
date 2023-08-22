#include<iostream>

using namespace std;

// A Node class with pointer next
class Node{
public:
    Node* next;
    int value; 
    //creates new node when called
    Node(int value) {
        this->value = value;
    }
};

// A Stack class with pointer top
class Stack{
    Node* top;
public:
    //creates an empty stack
    Stack() {
        top = nullptr;
    }

    // Checks if stack is empty
    bool isEmpty() {
        // Stack is empty if the top pointer is null
        if(top == nullptr) {
            return true;
        }
        return false;
    }

    // pushes the element on top of stack
    void push(int value) {
        Node* newNode = new Node(value);
        // Setting the new node's next pointer to the previous top
        newNode->next = top;
        // Updating the top pointer to the new node
        top = newNode;
    }
    
    // pops the top element out of the stack
    void pop() {
        // If stack is empty, nothing to pop
        if(top == nullptr) {
            return;
        }
        // Temporary pointer to the node to be deleted
        Node* deleteTop = top;
        // Moving the top pointer to the next node
        top = top->next;
        // Deleting the previous top node
        delete deleteTop;
    }
    
    // Returns the top element of the stack
    int getTop() {
        // Return -1 if stack is empty
        if(top == nullptr) {
            return -1;
        }
        // Return the value of the top node
        return top->value;
    }

    // Calculate the size of the stack
    int getSize() {
        // Stack size is 0 if it's empty
        if(top == nullptr) {
            return 0;
        }
        Node* currNode = top;
        int length = 0;
        // Counting the nodes in the stack
        while(currNode != nullptr) {
            length++;
            currNode = currNode->next;
        }
        return length;
    }

    // Destructor: Clean up memory for all nodes
    ~Stack() {
        while(top != nullptr) {
            Node* deleteTop = top;
            top = top->next;
            delete deleteTop;
        }
    }
};

int main() {
    Node* top = nullptr;
    Stack st;

    if(st.isEmpty()) {
        cout<<"Stack is empty"<<endl;
    } else {
        cout<<"Stack is not empty"<<endl;
    }

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<"The Top element: "<<st.getTop()<<endl;
    cout<<"The size of Stack: "<<st.getSize()<<endl;

    st.pop();

    st.push(7);

    cout<<"The Top element: "<<st.getTop()<<endl;
    cout<<"The size of Stack: "<<st.getSize()<<endl;

    return 0;
}
