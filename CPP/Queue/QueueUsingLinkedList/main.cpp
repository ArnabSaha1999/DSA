#include<iostream>

using namespace std;

// Node class to represent elements in the queue
class Node {
public:
    Node* next;
    int val;
    Node(int val) {
        this->val = val;
    }
};

// Queue class for implementing a queue using linked list
class Queue {
    Node *front, *rear;
public:

    // Constructor to initialize an empty queue
    Queue() {
        front = rear = nullptr;
    }

    // Method to enqueue an element to the rear of the queue
    void enQueue(int val) {
        Node* newNode = new Node(val);
        if(isEmpty()) {
            // If the queue is empty, the front and rear point to the new node
            front = rear = newNode;
            return;
        }
        // Otherwise, add the new node to the rear and update the rear pointer
        rear->next = newNode;
        rear = newNode;
    }

    // Method to dequeue an element from the front of the queue
    int deQueue() {
        if(isEmpty()) {
            return -1;
        }
        Node* deleteFront = front;
        // Get the value of the front element
        int deleteFrontElement = front->val;
        // Move the front pointer to the next node
        front = front->next;
        // If the queue becomes empty, update the rear pointer
        if(front == nullptr) {
            rear = nullptr;
        }
        delete deleteFront;
        return deleteFrontElement;
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        if(rear == nullptr) {
            return true;
        }
        return false;
    }

    // Method to get the front element of the queue
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return front->val;
    }

    // Method to get the size of the queue
    int getSize() {
        if(isEmpty()) {
            return 0;
        }
        Node* currNode = front;
        int size = 0;
        while(currNode != rear->next) {
            size++;
            currNode = currNode->next;
        }
        return size;
    }

    // Method to display the elements in the queue
    void display() {
        if(isEmpty()) {
            cout<<"The Queue is Empty"<<endl;
            return;
        }
        Node* currNode = front;
        cout<<"The Queue elements: "<<endl;
        while(currNode != rear->next) {
            cout<<currNode->val<<" ";
            currNode = currNode->next;
        } cout<<endl;
    }

    // Destructor to free the dynamically allocated memory
    ~Queue() {
        while (front != rear->next) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);

    q.display();

    cout<<"The Front element: "<<q.getFront()<<endl;
    cout<<"The size of Queue: "<<q.getSize()<<endl;
    cout<<"The popped element: "<<q.deQueue()<<endl;
    cout<<"The popped element: "<<q.deQueue()<<endl;
    cout<<"The popped element: "<<q.deQueue()<<endl;
    cout<<"The size of Queue: "<<q.getSize()<<endl;

    q.display();

    q.enQueue(7);
    cout<<"The size of Queue: "<<q.getSize()<<endl;

    q.display();

    return 0;
}
