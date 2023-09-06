#include<iostream>
#include<stack>

using namespace std;

// Queue class implemented using a single stack
class Queue {
    stack<int> st;
public:
    // Constructor to initialize the queue
    Queue() {
        
    }
    
    // Method to push an element into the queue
    void push(int x) {
        // Check if the stack is empty
        if(st.empty()) {
            st.push(x);
            return;
        }
        // Recursive call to push the element to the bottom of the stack
        int stackTop = st.top();
        st.pop();
        push(x);
        // Restore the original stack order by pushing the elements back
        st.push(stackTop);
    }
    
    // Method to pop the front element from the queue
    int pop() {
        if(st.empty()) {
            return -1;
        }
        int deleteFront = st.top();
        st.pop();
        return deleteFront;
    }
    
    // Method to get the front element of the queue
    int getFront() {
        if(st.empty()) {
            return -1;
        }
        return st.top();
    }

    // Method to get the size of the queue
    int getSize() {
        return st.size();
    }
    
    // Method to check if the queue is empty
    bool empty() {
        if(st.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<"The Front element of Queue: "<<q.getFront()<<endl;
    cout<<"The Size of Queue: "<<q.getSize()<<endl;
    cout<<"The popped element of Queue: "<<q.pop()<<endl;

    cout<<"The Front element of Queue: "<<q.getFront()<<endl;
    q.push(4);
    cout<<"The Size of Queue: "<<q.getSize()<<endl;

    return 0;
}
