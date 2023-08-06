#include <iostream>
using namespace std;

// A Node class with pointers next & prev
class Node {

public:
    int value;
    Node* next;
    Node* prev;
    Node (int value) { //creates new node when called
        this->value = value;
        this->next = this->prev = nullptr;
    }

};

// A DoublyLinkedList class with pointer head and tail.
// A Doubly Linked List have to pointers the next & prev.
// The next pointer points to the next node's address & the prev pointer points to the next node's address.

class CircularDoublyLinkedList {
private:

    // checks if the linked list is empty or not
    bool isEmpty() {
        if(this->length == 0) {
            return true;
        }
        return false;
    }

    // inserts an element if the linked list is empty
    void insertWhileEmpty(Node* newNode) {
        this->head = this->tail = newNode;
        this->tail->next = this->head;
        this->head->prev = this->tail;
        this->length++;
    }

    // find the index of a given node value
    Node* findIndex(int index) {
        int indexCount = 0;
        Node* currentNode = this->head;
        while(indexCount != index) {
            indexCount++;
            currentNode = currentNode->next;
        }
        return currentNode;
    }

    // deletes the element if the element is the only element of the linked list
    // means the head and tail node pointing to the same node
    void deleteOnlyElement() {
        this->head = this->tail = nullptr;
        this->length--;
    }

    // find the value of a given index position node
    int findValue (int value) {
        Node* currentNode = this->head;
        int indexCount = 0;
        do {
            if(currentNode->value == value) {
                return indexCount;
            }
            currentNode = currentNode->next;
            indexCount++;
        } while(currentNode != this->head);
        return -1;
    }

public:
    Node* head;
    Node* tail;
    int length;

    CircularDoublyLinkedList () {  //creates an empty linked list
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    // pushes the element onto the end of the linked list
    void pushBack(int value) {
        Node* newNode = new Node(value);
        if(this->isEmpty()) {
            insertWhileEmpty(newNode);
            return;
        }
        this->tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        this->tail = newNode;
        this->tail->next = this->head;
        this->head->prev = this->tail;
        this->length++;
    }

    // pushes the element onto the start of the linked list
    void pushFront(int value) {
        Node* newNode = new Node(value);
        if(isEmpty()) {
            insertWhileEmpty(newNode);
            return;
        }
        newNode->next = this->head;
        newNode->prev = this->head->prev;
        this->head->prev = newNode;
        this->head = newNode;
        this->head->prev = this->tail;
        this->tail->next = this->head;
        this->length++;
    }

    //inserts an element after a given index number
    void insertAfterIndex(int index, int value) {
        if(index < 0) { // if the given index is less than 0 do nothing
            return;
        }
        Node* newNode = new Node(value);
        if(isEmpty()) {
            this->insertWhileEmpty(newNode);
            return;
        }

        if(index >= this->length - 1) { //when the given index is bigger the actual linked list size then insert the element onto the end of the linked list
            this->pushBack(value);
            return;
        }

        Node* currentNode = this->findIndex(index);
        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
        this->head->prev = this->tail;
        this->tail->next = this->head;
        this->length++;
    }

    // inserts an element before a given index number
    void insertBeforeIndex(int index, int value) {
        if(index <= 0) {
            this->pushFront(value);
            return;
        }
        Node* newNode = new Node(value);
        if(isEmpty()) {
            this->insertWhileEmpty(newNode);
            return;
        }

        if(index >= this->length) {
            return;
        }
        Node* currentNode = this->findIndex(index);
        newNode->next = currentNode;
        currentNode->prev->next = newNode;
        newNode->prev = currentNode->prev;
        currentNode->prev = newNode;
        this->tail->next = this->head;
        this->head->prev = this->tail;
        this->length++;
    }

    // pops the last element out of the linked list
    void popBack() {
        if(isEmpty()) {
            return;
        }
        if(this->head == this->tail) {
            this->deleteOnlyElement(); // when there is only one element to delete
            return;
        }
        this->tail = this->tail->prev;
        this->tail->next = this->head;
        this->head->prev = this->tail;
        this->length--;
    }

    // pops the first element out of the linked list
    void popFront() {
        if(isEmpty()) {
            return;
        }
        this->head = this->head->next;
        this->tail->next = this->head;
        this->head->prev = this->tail;
        this->length--;
    }

    // deletes an element at a given index number
    void deleteNode(int index) {
        if(isEmpty()) {
            return;
        }
        if(index > this->length || index < 0) { // when the index is less than 0 or greater than the length of the linked list
            return;
        }
        if(index == 0 ) { // when the index position is the first element of the linked list
            this->popFront();
            return;
        }
        if(index == this->length-1) { //when the given index position is the last element of the linked list
            this->popBack();
            return;
        }

        Node* deleteNode = this->findIndex(index);
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;
        this->head->prev = this->tail;
        this->tail->next = this->head;
        this->length--;
    }

    // displaying the elements of the linked list
    void display() {
        Node* currentNode = this->head;
        if(this->isEmpty()) {
            cout<<"The Circular Doubly Linked List is Empty"<<endl;
            return;
        }
        cout<<"The Circular Doubly Linked List"<<endl;
        cout<<"head -> ";
        do {
            cout<<currentNode->value<<" -> ";
            currentNode = currentNode->next;
        } while(currentNode != this->head);
        cout<<"tail"<<endl;

    }

    // to reverse the existing linked list
    void reverse () {
        if(isEmpty() || this->length == 1) { // when the linked list either empty or have only one element do not need to reverse it
            return;
        }
        Node* currentNode = this->head;
        this->tail = this->head;
        Node* prevNode = this->head;
        Node* nextNode = nullptr;

        do { // looping through till the currentNode becomes the head pointer.
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            currentNode->prev = nextNode;
            prevNode = currentNode;
            currentNode = nextNode;
        } while(currentNode != this->head);
        this->head = prevNode;
        this->head->prev = this->tail;
        this->tail->next = this->head;
    }

    // to search an element and find its index position
    void search (int value) {
        if(isEmpty()) {
            cout<<"The Linked List is Empty"<<endl;
            return;
        }

        int index = this->findValue(value); // returns the index position
        if(index == -1) { // when the index is -1 means the element is not present in the linked list
            cout<<"The Value "<<value<<" is not found."<<endl;
            return;
        }
        cout<<"The value "<<value<<" is found at index "<<index<<endl;
    }

    // update the value of a existing node
    void update(int index, int value) {
        if(isEmpty()) {
            return;
        }
        if(index < 0 || index >= this->length) { // if the index is less than 0 or greater than the size of the linked list
            return;
        }
        Node* updateNode = this->findIndex(index);
        updateNode->value = value;
    }


    // returns the value of the head node
    void headPointer () {
        if(isEmpty()) {
            cout<<"The Head Pointer value is -> NULL"<<endl;
            return;
        }
        cout<<"The Head Pointer value is -> "<<this->head->value<<endl;

    }

    // returns the tail node value
    void tailPointer() {
        if(isEmpty()) {
            cout<<"The Tail Pointer value is -> NULL"<<endl;
            return;
        }
        cout<<"The Tail Pointer value is -> "<<this->tail->value<<endl;
    }

    // returns the length of the linked list
    void findLength() {
        cout<<"The Doubly Linked List length is : "<<this->length<<endl;
    }

    // Destructor: Clean up memory for all nodes
    ~CircularDoublyLinkedList() {
        Node* currNode = head;
        do {
            Node* nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        } while(currNode != NULL);
    }
};

int main() {
    CircularDoublyLinkedList cdl;
    
    cdl.pushBack(33);
    cdl.pushBack(32);
    cdl.pushBack(31);
    cdl.pushBack(30);
    cdl.pushBack(29);
    cdl.pushFront(28);
    
    cdl.insertAfterIndex(5, 44);
    cdl.insertBeforeIndex(6, 77);
    
    cdl.display();
    cdl.headPointer();
    cdl.tailPointer();
    cdl.findLength();
    
    cdl.popBack();
    cdl.popFront();
    cdl.deleteNode(2);
    
    cdl.search(28);
    cdl.update(2, 99);
    
    cdl.display();
    
    cdl.reverse();
    cdl.display();
    
    cdl.headPointer();
    cdl.tailPointer();
    cdl.findLength();
    
    return 0;
}
