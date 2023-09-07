#include<iostream>

using namespace std;

// Node class to represent elements in the doubly linked list
class Node {
public: 
    Node *next, *prev;
    int value;
    Node(int value) {
        this->value = value;
        this->next = this->prev = nullptr;
    }
};

// Deque class for implementing a Double-Ended Queue
class Deque {
    Node *front, *rear;
public:
    
    // Constructor to initialize an empty deque
    Deque() {
        front = rear = nullptr;
    }

    // Pushes an element to the front of the deque.
    void pushFront(int value) {
        Node* newNode = new Node(value);
        if(isEmpty()) {
            // If the deque is empty, set both front and rear to the new node
            front = rear = newNode;
        } else {
            // If not empty, update the links and move front pointer
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Pushes an element to the rear of the deque.
    void pushRear(int value) {
        Node* newNode = new Node(value);
        if(isEmpty()) {
            // If the deque is empty, set both front and rear to the new node
            front = rear = newNode;
        } else {
            // If not empty, update the links and move rear pointer
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty.
    int popFront() {
        if(isEmpty()) {
            return -1;
        }
        Node* nodeToDelete = front;
        int deleteFront = nodeToDelete->value;
        front = front->next;
        delete nodeToDelete;
        return deleteFront;
    }

    // Pops an element from the rear of the deque. Returns -1 if the deque is empty.
    int popRear() {
        if(isEmpty()) {
            return -1;
        }
        Node* nodeToDelete = rear;
        int deleteRear = nodeToDelete->value;
        rear = rear->prev;
        rear->next = nullptr;
        return deleteRear;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return front->value;
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return rear->value;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty() {
        return rear == nullptr;
    }
    
    // Returns the current number of elements in the deque.
    int getSize() {
        if(isEmpty()) {
            return 0;
        }
        int size = 0;
        Node* currNode = front;
        while(currNode != nullptr) {
            size++;
            currNode = currNode->next;
        } 
        return size;
    }

    // Method to display the elements in the deque
    void display() {
        if(isEmpty()) {
            cout<<"The Doubly Ended Queue is Empty"<<endl;
            return;
        }
        Node* currNode = front;
        cout<<"The Doubly Ended Queue: "<<endl;
        while(currNode != nullptr) {
            cout<<currNode->value<<" ";
            currNode = currNode->next;
        } cout<<endl;
    }

    // Destructor to release memory allocated for the deque
    ~Deque() {
        while (front != nullptr) {
            Node* nodeToDelete = front;
            front = front->next;
            delete nodeToDelete;
        }
        rear = nullptr;
    }
};

int main() {
    Deque dq;
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
    cout<<"The Size of Doubly Ended Queue: "<<dq.getSize()<<endl;

    dq.popFront();
    dq.popRear();

    cout<<"The Front Element of Double Ended Queue: "<<dq.getFront()<<endl;
    cout<<"The Rear Element of Double Ended Queue: "<<dq.getRear()<<endl;
    cout<<"The Size of Doubly Ended Queue: "<<dq.getSize()<<endl;
    
    dq.display();
    
    dq.popFront();
    dq.popRear();
    
    dq.display();
    return 0;
}
