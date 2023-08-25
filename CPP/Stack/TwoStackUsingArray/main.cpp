#include<iostream>
using namespace std;

// Implementation of a two-stack using a divided array in half
class TwoStackDivided {
    int *arr;
    int top1, top2;
    int size;
    int mid;

public:
    // Constructor to initialize the TwoStack object
    TwoStackDivided(int size) {
        this->size = size;
        arr = new int[size];
        mid = size / 2;
        top1 = -1;
        top2 = size;
    }

    // Push an element to stack 1
    void push1(int num) {
        // Check if there is space for another element
        if(top1 < mid - 1) {
            arr[++top1] = num;
        }
    }

    // Push an element to stack 2
    void push2(int num) {
        // Check if there is space for another element
        if(top2 > mid) {
            arr[--top2] = num;
        }
    }

    // Pop an element from stack 1
    int pop1() {
        // Check if stack 1 is not empty
        if(top1 != -1) {
            int element = arr[top1];
            top1--;
            return element;
        }
        // Return -1 to indicate underflow
        return -1;
    }

    // Pop an element from stack 2
    int pop2() {
        // Check if stack 2 is not empty
        if(top2 != size) {
            int element = arr[top2];
            top2++;
            return element;
        }
        // Return -1 to indicate underflow
        return -1;
    }

    // Returns the top element of stack 1
    int getTop1() {
        if(top1 != -1) {
            return arr[top1];
        }
        return -1;
    }

    // Returns the top element of stack 2
    int getTop2() {
        if(top2 != size) {
            return arr[top2];
        }
        return -1;
    }

    // Returns the size of the stack 1
    int getSize1() {
        return top1 + 1;
    }

    // Returns the size of the stack 2
    int getSize2() {
        return size - top2;
    }

    // Destructor to release memory allocated for the array
    ~TwoStackDivided() {
        delete[] arr;
    }

};

// TwoStack class implementation
class TwoStack{
    int *arr;
    int top1, top2;
    int size;
public:
    // Constructor to initialize the TwoStack object
    TwoStack(int size) {
        arr = new int[size];
        // Initialize top of stack 1
        top1 = -1;
        // Initialize top of stack 2 at the end
        top2 = size;
        this->size = size;
    }

    // Push an element to stack 1
    void push1(int num) {
        // Check if there is space for another element
        if((top2 - top1) > 1) {
            arr[++top1] = num;
        }
    }

    // Push an element to stack 2
    void push2(int num) {
        // Check if there is space for another element
        if((top2 - top1) > 1) {
            arr[--top2] = num;
        }
    }

    // Pop an element from stack 1
    int pop1() {
        // Check if stack 1 is not empty
        if(top1 != -1) {
            int element = arr[top1];
            top1--;
            return element;
        }
        // Return -1 to indicate underflow
        return -1;
    }

    // Pop an element from stack 2
    int pop2() {
        // Check if stack 2 is not empty
        if(top2 != size) {
            int element = arr[top2];
            top2++;
            return element;
        }
        // Return -1 to indicate underflow
        return -1;
    }

    // Returns the top element of stack 1
    int getTop1() {
        if(top1 != -1) {
            return arr[top1];
        }
        return -1;
    }

    // Returns the top element of stack 2
    int getTop2() {
        if(top2 != size) {
            return arr[top2];
        }
        return -1;
    }

    // Returns the size of the stack 1
    int getSize1() {
        return top1 + 1;
    }

    // Returns the size of the stack 2
    int getSize2() {
        return size - top2;
    }

    // Destructor to release memory allocated for the array
    ~TwoStack() {
        delete[] arr;
    }
};

int main() {
    TwoStackDivided tsd(5);
    tsd.push1(1);
    tsd.push1(2);
    tsd.push1(3);
    tsd.push2(5);
    tsd.push2(4);

    cout<<"The top of the first stack: "<<tsd.getTop1()<<endl;
    cout<<"The top of the second stack: "<<tsd.getTop2()<<endl;

    cout<<"The size of the first stack: "<<tsd.getSize1()<<endl;
    cout<<"The size of the second stack: "<<tsd.getSize2()<<endl;

    cout<<"The popped element of first stack: "<<tsd.pop1()<<endl;
    cout<<"The popped element of second stack: "<<tsd.pop2()<<endl;
    cout<<"The popped element of first stack: "<<tsd.pop1()<<endl;

    cout<<"The size of the first stack: "<<tsd.getSize1()<<endl;
    cout<<"The size of the second stack: "<<tsd.getSize2()<<endl;

    cout<<"The top of the first stack: "<<tsd.getTop1()<<endl;
    cout<<"The top of the second stack: "<<tsd.getTop2()<<endl;

    cout<<endl;

    TwoStack ts(5);
    ts.push1(1);
    ts.push1(2);
    ts.push1(3);
    ts.push2(5);
    ts.push2(4);

    cout<<"The top of the first stack: "<<ts.getTop1()<<endl;
    cout<<"The top of the second stack: "<<ts.getTop2()<<endl;

    cout<<"The size of the first stack: "<<ts.getSize1()<<endl;
    cout<<"The size of the second stack: "<<ts.getSize2()<<endl;

    cout<<"The popped element of first stack: "<<ts.pop1()<<endl;
    cout<<"The popped element of second stack: "<<ts.pop2()<<endl;
    cout<<"The popped element of first stack: "<<ts.pop1()<<endl;

    cout<<"The size of the first stack: "<<ts.getSize1()<<endl;
    cout<<"The size of the second stack: "<<ts.getSize2()<<endl;

    cout<<"The top of the first stack: "<<ts.getTop1()<<endl;
    cout<<"The top of the second stack: "<<ts.getTop2()<<endl;

    return 0;
}
