#include<iostream>
#include<deque>

using namespace std;

// A Stack class using deque
class Stack{
    deque<int> dq;
public:
    // Pushes an element onto the stack
    void push(int value) {
        dq.push_back(value);
    }

    // Pops and returns the top element from the stack
    int pop() {
        // Stack is empty
        if(dq.empty()) {
            return -1;
        }
        int deletedTop = dq.back();
        dq.pop_back();
        return deletedTop;
    }

    // Returns the top element of stack
    int getTop() {
        // Stack is empty
        if(dq.empty()) {
            return -1;
        }
        return dq.back();
        
    }

    // Checks if the stack is empty
    bool isEmpty() {
        if(dq.empty()) {
            return true;
        }
        return false;
    }

    // Returns the size of the stack
    int getSize() {
        if(dq.empty()) {
            return 0;
        }
        return dq.size();
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
