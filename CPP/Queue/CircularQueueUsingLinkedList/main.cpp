#include<iostream>

using namespace std;

// Node class to represent elements in the circular queue
class Node {
public:
    Node* next;
    int value;
    Node(int value) {
        this->value = value;
    }
};

// CircularQueue class for implementing a circular queue using linked list
class CircularQueue {
    Node *front, *rear;
public:

    // Constructor to initialize an empty circular queue
    CircularQueue() {
        front = rear = nullptr;
    }

    // Method to enqueue an element to the circular queue
    void enQueue(int val) {
        Node* newNode = new Node(val);
        if(isEmpty()) {
            // If the queue is empty, the front and rear both point to the new node
            front = rear = newNode;
        } else {
            // Otherwise, link the current rear to the new node and update the rear
            rear->next = newNode;
            rear = newNode;
        }

        rear->next = front; // Make the queue circular
    }

    // Method to dequeue an element from the front of the circular queue
    int deQueue() {
        if(isEmpty()) {
            return -1;
        }
        int deleteFront = front->value;
        if(front == rear) {
            // If there's only one element in the queue, set front and rear to nullptr
            front = rear = nullptr;
        } else {
            // Otherwise, update the front to the next node and link rear to front
            front = front->next;
            rear->next = front;
        }
        return deleteFront;
    }

    // Method to get the front element of the circular queue
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return front->value;
    }

    // Method to get the rear element of the circular queue
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return rear->value;
    }

    // Method to check if the circular queue is empty
    bool isEmpty() {
        return rear == nullptr;
    }

    // Method to get the size (number of elements) of the circular queue
    int getSize() {
        if(isEmpty()) {
            return 0;
        }
        int size = 0;
        Node* currNode = front;
        do {
            size++;
            currNode = currNode->next;
        } while(currNode != front); // Traverse the circular queue
        return size;
    }

    // Method to display the elements in the circular queue
    void display() {
        if(isEmpty()) {
            cout<<"The Circular Queue is Empty"<<endl;
            return;
        }
        cout<<"The Circular Queue: "<<endl;
        Node* currNode = front;
        do {
            cout<<currNode->value<<" -> ";
            currNode = currNode->next;
        } while(currNode != front); // Traverse the circular queue
        cout<<"front("<<front->value<<")"<<endl;
    }
};

int main() {
    CircularQueue cq;

    cq.isEmpty();

    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);
    cq.enQueue(4);
    cq.enQueue(5);

    cq.display();

    cout<<"The Front element: "<<cq.getFront()<<endl;
    cout<<"The Rear element: "<<cq.getRear()<<endl;
    cout<<"The Size of Circular Queue: "<<cq.getSize()<<endl;

    cout<<"The Popped element: "<<cq.deQueue()<<endl;
    cout<<"The Popped element: "<<cq.deQueue()<<endl;
    cout<<"The Popped element: "<<cq.deQueue()<<endl;
    cout<<"The Popped element: "<<cq.deQueue()<<endl;
    cout<<"The Popped element: "<<cq.deQueue()<<endl;

    cout<<"The Size of Circular Queue: "<<cq.getSize()<<endl;

    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);

    cout<<"The Front element: "<<cq.getFront()<<endl;
    cout<<"The Rear element: "<<cq.getRear()<<endl;
    cout<<"The Size of Circular Queue: "<<cq.getSize()<<endl;
    
    cq.display();
    return 0;
}
