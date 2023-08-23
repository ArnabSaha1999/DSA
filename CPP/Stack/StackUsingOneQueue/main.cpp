#include<iostream>
#include<queue>

using namespace std;

// A Stack class with one queues
class Stack{
    queue<int> q;
public:
    // Pushes an element onto the stack
    void push(int value) {
        q.push(value);
        // Rotate the queue to maintain the stack order
        for(int i = 0; i < q.size() - 1; i++) {
            q.push(q.front()); // Move the front element to the back
            q.pop();           // Remove the front element
        }
    }
    
    // Removes and returns the top element from the stack
    int pop() {
        // Stack is empty
        if(q.empty()) {
            return -1;
        }
        int deletedTop = q.front();
        q.pop();
        return deletedTop;
    }

    // Returns the top element of stack
    int getTop() {
        // Stack is empty
        if(q.empty()) {
            return -1;
        }
        return q.front();
        
    }

    // Checks if the stack is empty
    bool isEmpty() {
        if(q.empty()) {
            return true;
        }
        return false;
    }

    // Returns the size of the stack
    int getSize() {
        if(q.empty()) {
            return 0;
        }
        return q.size();
    }

    // Destructor to release memory used by queues
    ~Stack() {
        while (!q.empty()) {
            q.pop();
        }
    }
};

int main() {
    Stack st;

    if(!st.isEmpty()) {
        cout<<"The Stack is empty"<<endl;
    } else {
        cout<<"The Stack is not empty"<<endl;
    }

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<"The Top of Stack: "<<st.getTop()<<endl;
    cout<<"The Size of Stack: "<<st.getSize()<<endl;
    cout<<"The Popped element from Stack: "<<st.pop()<<endl;

    cout<<"The Top of Stack: "<<st.getTop()<<endl;
    cout<<"The Size of Stack: "<<st.getSize()<<endl;

    st.push(7);

    cout<<"The Top of Stack: "<<st.getTop()<<endl;
    cout<<"The Size of Stack: "<<st.getSize()<<endl;

    return 0;
}
