#include<iostream>
#include<stack>
#include<utility>
#include<climits>

using namespace std;

//Approach 1: MaxStack class using two stacks to track maximum value
class MaxStack {
    stack<int> st, maxStack;
    int maxi = INT_MIN;
public:

    // Push a value onto the stack
    void push(int val) {
        st.push(val);
        if(maxStack.empty()) {
            maxi = val;
        } else {
            // Update the maximum value
            maxi = max(maxi, val);
        }
        // Push the maximum value onto the maxStack
        maxStack.push(maxi);
    }

    // Pop a value from the stack
    int pop() {
        if(!st.empty()) {
            int topOfStack = st.top();
            st.pop();
            maxStack.pop();
            // Pop the corresponding maximum value
            return topOfStack;
        }
        // Reset maxi if stack is empty
        maxi = INT_MIN;
        return -1;
    }

    // Get the top value of the stack
    int getTop() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        }
        return st.top();
    }

    // Get the maximum value from the stack
    int getMax() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        }
        return maxStack.top();
    }
};

//Approach 2: MaxStackDifference class using a single stack and difference to track maximum value
class MaxStackDifference {
    stack<int> st;
    int maxi = INT_MIN;
public:

    // Push a value onto the stack
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            maxi = val;
            st.push(val);
        } else {
            if(val > maxi) {
                // Store the difference to track maximum
                st.push(2 * val - maxi);
                maxi = val;
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
        if(curr < maxi) {
            return curr;
        }
        int prevMax = maxi;
        // Restore the previous maximum
        maxi = 2 * maxi - curr;
        return prevMax;
    }

    // Get the top value of the stack
    int getTop() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        }
        int curr = st.top();
        if(curr > maxi) {
            return maxi;
        }
        return curr;
    }

    // Get the maximum value from the stack
    int getMax() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        }
        return maxi;
    }
};

//Approach 3: SpecialStackPair class using pairs to track both the element and the maximum value
class SpecialStackPair {
    stack<pair<int, int>> st;
    int maxi = INT_MIN;
public:

    // Push a value onto the stack
    void push(int val) {
        if(st.empty()) {
            // Push the current element along with maximum
            st.push({val, val});
            maxi = val;
        } else {
            // Push the current element along with maximum
            maxi = max(maxi, val);
            st.push({val, maxi});
        }
    }

    // Pop a value from the stack
    int pop() {
        if(st.empty()) {
            return -1;
        }
        int topOfStack = st.top().first;
        st.pop();
        if(st.empty()) {
            // Reset maxi if stack is empty
            maxi = INT_MIN;
        } else {
            // Update maxi to the maximum of remaining elements
            maxi = st.top().second;
        }
        return topOfStack;
    }

    // Get the top value of the stack
    int getTop() {
        if(st.empty()) {
            // Return -1 for empty stack
            return -1;
        }
        return st.top().first;
    }

    int getMax() {
        if(st.empty()) {
            // Get the maximum value from the stack
            return -1;
        }
        return st.top().second;
    }
};

int main() {
    // Testing MaxStack
    MaxStack maxStack;
    maxStack.push(5);
    maxStack.push(2);
    maxStack.push(7);

    cout << "MaxStack:" << endl;
    cout << "Top: " << maxStack.getTop() << endl;
    cout << "Max: " << maxStack.getMax() << endl;
    cout << "Pop: " << maxStack.pop() << endl;
    cout << "Top: " << maxStack.getTop() << endl;
    cout << "Max: " << maxStack.getMax() << endl;

    // Testing MaxStackDifference
    MaxStackDifference diffStack;
    diffStack.push(5);
    diffStack.push(2);
    diffStack.push(7);

    cout << "MaxStackDifference:" << endl;
    cout << "Top: " << diffStack.getTop() << endl;
    cout << "Max: " << diffStack.getMax() << endl;
    cout << "Pop: " << diffStack.pop() << endl;
    cout << "Top: " << diffStack.getTop() << endl;
    cout << "Max: " << diffStack.getMax() << endl;

    // Testing SpecialStackPair
    SpecialStackPair pairStack;
    pairStack.push(5);
    pairStack.push(2);
    pairStack.push(7);

    cout << "SpecialStackPair:" << endl;
    cout << "Top: " << pairStack.getTop() << endl;
    cout << "Max: " << pairStack.getMax() << endl;
    cout << "Pop: " << pairStack.pop() << endl;
    cout << "Top: " << pairStack.getTop() << endl;
    cout << "Max: " << pairStack.getMax() << endl;

    return 0;
}
