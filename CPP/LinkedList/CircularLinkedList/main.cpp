#include <iostream>
using namespace std;

// A Node class with pointer next
class Node {
public:
    int value;
    Node *next;
    Node (int value) {      //creates new node when called
        this->value = value;
        this->next = nullptr;
    }
};

// A CircularLinkedList class with pointer head and tail.
// A Circular Linked List's Tail node's next pointer always points to the head node.

class CircularLinkedList {
    Node* head;
    Node* tail;
    int length;

private:
    // checks if the linked list is empty or not
    bool isEmpty () {
        if(this->length == 0) {
            return true;
        }
        return false;
    }

    // inserts an element if the linked list is empty
    void insertWhileEmpty (Node* newNode) {
        this->head = this->tail = newNode;
        this->tail->next = this->head;
        this->length++;
    }

    // deletes the element if the element is the only element of the linked list
    // means the head and tail node pointing to the same node
    void deleteOnlyElement () {
        this->head = this->tail = nullptr;
        this->length--;
    }

    // find the index of a given node value
    Node* findIndex (int index) {
        int count = 0;
        Node* currentNode = head;
        while(count != index) {
            count++;
            currentNode = currentNode->next;
        }
        return currentNode;
    }

    // find the value of a given index position node
    int findValue(int value) {
        int index = 0;
        Node* currentNode = this->head;
        do {
            if(currentNode->value == value) {
                return index;
            }
            currentNode = currentNode->next;
            index++;
        } while(currentNode != this->head);
        return -1;
    }

    // swaps two node element called by the sort function
    void swap (Node* first , Node* second) {
        int temp = first->value;
        first->value = second->value;
        second->value = temp;
    }

public:
    CircularLinkedList() {      //creates an empty linked list
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }
    // pushes the element onto the end of the linked list
    void pushBack (int value) {
        Node* newNode = new Node(value);
        if(this->isEmpty()) {   //when the linked list is empty
            this->insertWhileEmpty(newNode);
            return;
        }
        this->tail->next = newNode;
        this->tail = newNode;
        this->tail->next = this->head;
        this->length++;
    }

    // pushes the element onto the start of the linked list
    void pushFront (int value) {
        Node* newNode = new Node(value);
        if(this->isEmpty()) {   //when the linked list is empty
            this->insertWhileEmpty(newNode);
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
        this->tail->next = this->head;
        this->length++;
    }

    //inserts an element after a given index number
    void insertAfterIndex (int index , int value) {
        if(index < 0) {     // if the given index is less than 0 do nothing
            return;
        }
        Node* newNode = new Node(value);
        if(this->isEmpty()) {   //when the linked list is empty
            this->insertWhileEmpty(newNode);
            return;
        }
        if(index >= this->length-1) {     //when the given index is bigger the actual linked list size then insert the element onto the end of the linked list
            this->pushBack(value);
            return;
        }
        Node* currentNode = findIndex(index);
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        this->tail->next = this->head;
        this->length++;
    }

    // inserts an element before a given index number
    void insertBeforeIndex (int index , int value) {
        if(index < 0) { // when the given index is less than 0 do nothing
            return;
        }
        Node* newNode = new Node(value);
        if(this->isEmpty()) {   // when the linked list is empty
            this->insertWhileEmpty(newNode);
            return;
        }
        if(index == 0) {        // when the given index is the first position in the linked list
            this->pushFront(value);
            return;
        }
        if(index >= this->length) { // when the given index is larger than actual size of the linked list do nothing
            return;
        }
        Node* currentNode = this->findIndex(index-1);
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        this->tail->next = this->head;
        this->length++;
    }

    // pops the first element out of the linked list
    void popFront () {
        if(this->isEmpty()) {   // when the linked list is empty
            cout<<"The linked list is empty nothing to delete."<<endl;
            return;
        }
        if(this->head == this->tail) {
            this->deleteOnlyElement();
            return;
        }
        this->head = this->head->next;
        this->tail->next = this->head;
        this->length--;
    }

    // pops the last element out of the linked list
    void popBack () {
        if(this->isEmpty()) {   // when the linked list empty
            cout<<"The Linked List is empty nothing to delete."<<endl;
            return;
        }
        if(this->head == this->tail) {  // when there is only one element to delete
            this->deleteOnlyElement();
            return;
        }

        Node* currentNode = this->head;
        while(currentNode->next != this->tail) {
            currentNode = currentNode->next;
        }
        currentNode->next = nullptr;
        this->tail = currentNode;
        this->tail->next = this->head;
        this->length--;
    }

    // deletes an element at a given index number
    void deleteNode (int index) {
        if(this->isEmpty()) {   // when the linked list empty
            cout<<"the linked list is empty nothing to delete."<<endl;
            return;
        }
        if(index > this->length-1 || index < 0) {   // when the index is less than 0 or greater than the length of the linked list
            return;
        }
        if(index == 0) {    // when the index position is the first element of the linked list
            this->popFront();
            return;
        }
        if(index == this->length - 1) { //when the given index position is the last element of the linked list
            this->popBack();
            return;
        }
        Node* currentNode = this->findIndex(index - 1);
        currentNode->next = currentNode->next->next;
        this->tail->next = this->head;
        this->length--;
    }

    //delete the whole linked list
    void deleteLinkedList () {
        if(this->isEmpty()) {   //when the linked list is empty
            cout << "Linked list is already empty"<<endl;
            return;
        }
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    // displaying the elements of the linked list
    void display () {
        if(this->isEmpty()) {   // when the linked list is empty
            cout << "The Linked list is empty";
            return;
        }
        Node* currentNode = this->head;
        cout<<"head -> ";
        do {
            cout<<currentNode->value<<" -> ";
            currentNode = currentNode->next;
        } while(currentNode != this->head);
        cout<<"tail"<<endl;
    }

    // to reverse the existing linked list
    void reverse () {
        if(this->isEmpty() || this->length == 1) {  // when the linked list either empty or have only one element do not need to reverse it
            return;
        }
        Node *prevNode = this->head;
        Node *nextNode = nullptr;
        Node* currentNode = this->head;
        this->tail = this->head;
        do {     // looping through till the currentNode becomes the head node.
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        } while(currentNode != this->head);
        this->head = prevNode;
        this->tail->next = this->head;
    }

    // to search an element and find its index position
    void search (int value) {
        if(this->isEmpty()) { // when its empty
            cout<<"The linked list is empty"<<endl;
            return ;
        }
        int index = this->findValue(value); // returns the index position
        if(index == -1) {   // when the index is -1 means the element is not present in the linked list
            cout << "The element "<<value<<" is not present in the linked list" <<endl;
            return;
        }
        cout<<"The element "<<value<< " is present in the linked list at " <<index << " index position" <<endl;
    }

    // update the value of a existing node
    void update (int index , int value) {
        if(index < 0 || index > this->length - 1) { // if the index is less than 0 or greater than the size of the linked list
            return;
        }
        Node* currentNode = this->findIndex(index);
        currentNode->value = value;

    }

    // sort the linked list
    void sort () {
        if(this->isEmpty() || this->length == 1) {
            return;
        }
        int count;
        do{
            count = 0;
            Node* currentNode = this->head;
            do {
                if(currentNode->value > currentNode->next->value) {
                    this->swap(currentNode , currentNode->next);
                    count = 1;
                }
                currentNode = currentNode->next;
            } while(currentNode->next != this->head);

        }while(count != 0);
    }

    // returns the value of the head node
    void headNode () {
        if(this->isEmpty()) {
            return;
        }
        cout<<"The head node value is : "<<this->head->value<<endl;
    }

    // returns the tail node value
    void tailNode() {
        if(this->isEmpty()) {
            return;
        }
        cout<<"The tail node value is : "<< this->tail->value<<endl;
    }

    // returns the length of the linked list
    void linkedListLength () {
        cout<<"The Length of the Circular Linked List is : " <<this->length<<endl;

    }

    // Destructor: Clean up memory for all nodes
    ~CircularLinkedList() {
        Node* currNode = head;
        do {
            Node* nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        } while(currNode != NULL);
    }

};

int main() {
    CircularLinkedList linkedList;
    
    linkedList.pushBack(45);
    linkedList.pushBack(35);
    linkedList.pushBack(25);
    linkedList.pushFront(5);
    linkedList.pushFront(15);
    
    linkedList.insertAfterIndex(0, 55);
    linkedList.insertBeforeIndex(0, 65);
    
    linkedList.update(1, -15);
    
    linkedList.search(35);
    
    linkedList.display();
    
    linkedList.reverse();
    linkedList.display();
    
    linkedList.headNode();
    linkedList.tailNode();
    
    linkedList.sort();
    linkedList.display();
    
    linkedList.linkedListLength();
    
    return 0;
}
