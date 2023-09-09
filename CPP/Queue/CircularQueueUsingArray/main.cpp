#include<iostream>

using namespace std;

// CircularQueue class for implementing a circular queue
class CircularQueue {
    int *arr;
    int front, rear, size, length;
public:

    // Constructor to initialize the circular queue with a given size
    CircularQueue(int k) {
        arr = new int[k];
        front = 0;
        rear = 0;
        length = 0;
        this->size = k;
    }
    
    // Method to enqueue an element to the circular queue
    void enQueue(int value) {
        if(isFull()) {
            return;
        }
        arr[rear] = value;
        // Circular increment of rear
        rear = (rear + 1) % size;
        length++;
    }
    
    // Method to dequeue an element from the circular queue
    int deQueue() {
        if(isEmpty()) {
            return -1;
        }
        int deleteFront = arr[front];
        arr[front] = -1;
        // Circular increment of front
        front = (front + 1) % size;
        length--;
        return deleteFront;
    }
    
    // Method to get the front element of the circular queue
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        //Get the Circular Front
        return arr[front % size];
    }
    
    // Method to get the rear element of the circular queue
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        //Get the Circular Rear
        return arr[(rear - 1 + size) % size];
    }
    
    // Method to check if the circular queue is empty
    bool isEmpty() {
        return length == 0;
    }
    
    // Method to check if the circular queue is full
    bool isFull() {
        return size == length;
    }

    // Method to get the size of the circular queue
    int getSize() {
        return length;
    }

    // Method to display the elements in the circular queue
    void display() {
        if(isEmpty()) {
            cout<<"The Circular Queue is Empty"<<endl;
            return;
        }
        int curr = front;
        cout<<"The Circular Queue: "<<endl;
        for(int i = 0; i < length; i++) {
            cout<<arr[curr]<<" ";
            // Circular increment for display
            curr = (curr + 1) % size;
        } cout<<endl;
    }

    // Destructor to free the dynamically allocated memory
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);
    cq.enQueue(4);
    cq.enQueue(5);

    cout<<"The Front of the Circular Queue: "<<cq.getFront()<<endl;
    cout<<"The Rear of the Circular Queue: "<<cq.getRear()<<endl;
    cout<<"The Size of Circular Queue: "<<cq.getSize()<<endl;
    cq.display();

    cout<<"The popped element: "<<cq.deQueue()<<endl;

    cout<<"The Front Element: "<<cq.getFront()<<endl;
    cout<<"The Rear Element: "<<cq.getRear()<<endl;

    cq.enQueue(6);

    cout<<"The Front of the Circular Queue: "<<cq.getFront()<<endl;
    cout<<"The Rear of the Circular Queue: "<<cq.getRear()<<endl;
    cout<<"The Size of Circular Queue: "<<cq.getSize()<<endl;
    
    cq.display();

    return 0;
}
