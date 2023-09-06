#include<iostream>

using namespace std;

// Class Queue with array, front, rear and size member variables
class Queue{
    int *arr;
    int front, rear, size;
public:
    // Constructor to initialize the queue with a given size
    Queue(int size) {
        arr = new int[size];
        this->size = size;
        front = rear = 0;
    }

    // Method to enqueue an element to the rear of the queue
    void enQueue(int val) {
        if(isFull()) {
            return; // Queue is full, cannot enqueue more elements
        }
        arr[rear++] = val;
    }

    // Method to dequeue an element from the front of the queue
    int deQueue() {
        if(isEmpty()) {
            return -1; // Queue is empty, cannot dequeue
        }
        int deleteFrontElement = arr[front];
        // Mark the front element as deleted
        arr[front] = -1;
        front++;
        if(isEmpty()) {
            // Reset front and rear if the queue becomes empty
            front = rear = 0;
        }
        return deleteFrontElement;
    }

    // Method to get the front element of the queue
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    // Method to get the rear element of the queue
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return arr[rear - 1];
    }

    // Method to get the size of the queue
    int getSize() {
        if(isEmpty()) {
            return 0;
        }
        int size = 0;
        for(int i = front; i < rear; i++) {
            size++;
        }
        return size;
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        if(front == rear) {
            return true;
        }
        return false;
    }

    // Method to check if the queue is full
    bool isFull() {
        if(rear == size) {
            return true;
        }
        return false;
    }

    // Method to display the elements in the queue
    void display() {
        if(isEmpty()) {
            cout<<"The Queue is Empty"<<endl;
            return;
        }
        cout<<"The Queue elements: "<<endl;
        for(int i = front; i < rear; i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
    }

    // Destructor to free the dynamically allocated memory
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(7);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);

    q.display();

    cout<<"The Front element: "<<q.getFront()<<endl;
    cout<<"The Rear element: "<<q.getRear()<<endl;
    cout<<"The Size of Queue: "<<q.getSize()<<endl;
    cout<<"The popped element: "<<q.deQueue()<<endl;
    cout<<"The popped element: "<<q.deQueue()<<endl;
    cout<<"The popped element: "<<q.deQueue()<<endl;
    cout<<"The Size of Queue: "<<q.getSize()<<endl;

    q.display();

    q.enQueue(7);

    q.display();
    cout<<"The Size of Queue: "<<q.getSize()<<endl;

    return 0;
}
