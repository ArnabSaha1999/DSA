#include<iostream>
#include<stack>
#include<utility>
#include<climits>

using namespace std;

//Approach 1: MinStack class using two stacks to track minimum value
class MinStack {
    stack<int> st, minStack;
    int mini = INT_MAX;
public:

    // Push a value onto the stack
    void push(int val) {
        st.push(val);
        if(minStack.empty()) {
            mini = val;
        } else {
            // Update the minimum value
            mini = min(minStack.top(), val);
        }
        // Push the minimum value onto the minStack
        minStack.push(mini);
    }

    // Pop a value from the stack
    int pop() {
        if(!st.empty()) {
            int topOfStack = st.top();
            st.pop();
            minStack.pop();
            // Pop the corresponding minimum value
            return topOfStack;
        }
        // Reset mini if stack is empty
        mini = INT_MAX;
        return -1;
    }

    // Get the top value of the stack
    int getTop() {
        if(!st.empty()) {
            return st.top();
        }
        // Return -1 for empty stack
        return -1;
    }

    // Get the minimum value from the stack
    int getMin() {
        if(!st.empty()) {
            return minStack.top();
        }
        // Return -1 for empty stack
        return -1;
    }
};

//Approach 2: MinStackDifference class using a single stack and difference to track minimum value
class MinStackDifference {
    stack<int> st;
    int mini = INT_MAX;
public:

    // Push a value onto the stack
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if(val < mini) {
                // Store the difference to track minimum
                st.push(2 * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    // Pop a value from the stack
    int pop() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        } 
        int curr = st.top();
        st.pop();
        if(curr > mini) {
            return curr;
        } else {
            int prevMin = mini;
            // Restore the previous minimum
            mini = 2 * mini - curr;
            return prevMin;
        }
    }

    // Get the top value of the stack
    int getTop() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        }
        int curr = st.top();
        if(curr < mini) {
            return mini;
        } 
        return curr;
    }

    // Get the minimum value from the stack
    int getMin() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        }
        return mini;
    }
};

//Approach 3: SpecialStackPair class using pairs to track both the element and the minimum value
class SpecialStackPair {
    stack<pair<int, int>> st;
    int mini = INT_MAX;
public:

    // Push a value onto the stack
    void push(int val) {
        if(st.empty()) {
            // Push the current element along with minimum
            st.push({val, val});
            mini = val;
        } else {
            mini = min(mini, val);
            // Push the current element along with minimum
            st.push({val, mini});
        }
    }

    // Pop a value from the stack
    int pop() {
        if(st.empty()) {
            return -1;
        }
        int stackOfTop = st.top().first;
        st.pop();
        if(st.empty()) {
            // Reset mini if stack is empty
            mini = INT_MAX;
        } else {
            // Update mini to the minimum of remaining elements
            mini = st.top().second;
        }
        return stackOfTop;
    }

    // Get the top value of the stack
    int getTop() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        }
        return st.top().first;
    }

    // Get the minimum value from the stack
    int getMin() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        }
        return st.top().second;
    }
};

int main() {
    // Testing MinStack
    MinStack minStack;
    minStack.push(5);
    minStack.push(2);
    minStack.push(7);

    cout << "MinStack:" << endl;
    cout << "Top: " << minStack.getTop() << endl;
    cout << "Min: " << minStack.getMin() << endl;
    cout << "Pop: " << minStack.pop() << endl;
    cout << "Top: " << minStack.getTop() << endl;
    cout << "Min: " << minStack.getMin() << endl;

    // Testing MinStackDifference
    MinStackDifference diffStack;
    diffStack.push(5);
    diffStack.push(2);
    diffStack.push(7);

    cout << "MinStackDifference:" << endl;
    cout << "Top: " << diffStack.getTop() << endl;
    cout << "Min: " << diffStack.getMin() << endl;
    cout << "Pop: " << diffStack.pop() << endl;
    cout << "Top: " << diffStack.getTop() << endl;
    cout << "Min: " << diffStack.getMin() << endl;

    // Testing SpecialStackPair
    SpecialStackPair pairStack;
    pairStack.push(5);
    pairStack.push(2);
    pairStack.push(7);

    cout << "SpecialStackPair:" << endl;
    cout << "Top: " << pairStack.getTop() << endl;
    cout << "Min: " << pairStack.getMin() << endl;
    cout << "Pop: " << pairStack.pop() << endl;
    cout << "Top: " << pairStack.getTop() << endl;
    cout << "Min: " << pairStack.getMin() << endl;

    return 0;
}
