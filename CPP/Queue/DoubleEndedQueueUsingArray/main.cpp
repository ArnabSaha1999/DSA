#include<iostream>

using namespace std;

// Deque class for implementing a Double-Ended Queue
class Deque {
    int *arr;
    int size, length, front, rear;
public:
    
    // Constructor to initialize an empty deque with a given size
    Deque(int n) {
        arr = new int[n];
        this->size = n;
        length = 0;
        rear = front = 0;
    }

    // Pushes an element to the front of the deque.
    void pushFront(int value) {
        if(isFull()) {
            return;
        }
        // Update the front pointer circularly and store the value
        front = ((front - 1) + size) % size;
        arr[front] = value;
        length++;
    }

    // Pushes an element to the rear of the deque.
    void pushRear(int value) {
        if(isFull()) {
            return;
        }
        // Store the value at the rear position and update the rear pointer circularly
        arr[rear] = value;
        rear = (rear + 1) % size;
        length++;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty.
    int popFront() {
        if(isEmpty()) {
            return -1;
        }
        int deleteFront = arr[front];
        arr[front] = -1;
        // update front circularly
        front = (front + 1) % size;
        length--;
        return deleteFront;
    }

    // Pops an element from the rear of the deque. Returns -1 if the deque is empty.
    int popRear() {
        if(isEmpty()) {
            return -1;
        }
        // Update rear circularly
        rear = ((rear - 1) + size) % size;
        int deleteRear = arr[rear];
        arr[rear] = -1;
        length--;
        return deleteRear;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return arr[((rear - 1) + size) % size];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty() {
        return length == 0;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull() {
        return length == size;
    }

    // Returns the current number of elements in the deque.
    int getSize() {
        return length;
    }
    
    // Method to display the elements in the deque
    void display() {
        if(isEmpty()) {
            cout<<"The Double Ended Queue is Empty"<<endl;
            return;
        }
        int curr = front;
        cout<<"The Double Ended Queue: "<<endl;
        for(int i = 0; i < length; i++) {
            cout<<arr[curr]<<" ";
            curr = (curr + 1) % size;
        } cout<<endl;
    }

    // Destructor to release memory allocated for the deque
    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque dq(5);
    if(dq.isEmpty()) {
        cout<<"The Double Ended Queue is Empty"<<endl;
    } else {
        cout<<"The Double Ended Queue is Not Empty"<<endl;
    }

    dq.pushFront(1);
    dq.pushRear(2);
    dq.pushFront(3);
    dq.pushFront(4);
    dq.pushRear(5);

    dq.display();
    
    cout<<"The Front Element of Double Ended Queue: "<<dq.getFront()<<endl;
    cout<<"The Rear Element of Double Ended Queue: "<<dq.getRear()<<endl;
    cout<<"The Size of Double Ended Queue: "<<dq.getSize()<<endl;

    dq.popFront();
    dq.popRear();

    cout<<"The Front Element of Double Ended Queue: "<<dq.getFront()<<endl;
    cout<<"The Rear Element of Double Ended Queue: "<<dq.getRear()<<endl;
    cout<<"The Size of Double Ended Queue: "<<dq.getSize()<<endl;
    
    dq.display();
    
    dq.popFront();
    dq.popRear();
    
    dq.display();
    return 0;
}
