#include<iostream>

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

// A LinkedList class with pointer head and tail
class LinkedList {
    Node* head;
    Node* tail;
    int length;

private:
    // checks if the linked list is empty or not
    bool isEmpty () {
        if(this->head == nullptr) {
            return true;
        }
        return false;
    }
    // inserts an element if the linked list is empty 
    void insertWhileEmpty (Node* newNode) {
        this->head = this->tail = newNode;
        this->length++;
    }

public:
    LinkedList() {      //creates an empty linked list
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }
    // pushes the element onto the end of the linked list
    Node* pushBack (int value) {
        Node* newNode = new Node(value);
        if(this->isEmpty()) {   //when the linked list is empty
            this->insertWhileEmpty(newNode);
            return head;
        }
        this->tail->next = newNode;
        this->tail = newNode;
        this->length++;
        return head;
    }


    // displaying the elements of the linked list
    void display (Node* head) {
        if(this->isEmpty()) {   // when the linked list is empty
            cout << "The Linked list is empty";
        }
        Node* currentNode = head;
        while(currentNode != nullptr) {
            cout<<currentNode->value<<" -> ";
            currentNode = currentNode->next;
        }
        cout<<"NULL"<<endl;
    }

    // Function to find the length of the linked list
    int findLength(Node* head) {
        Node* currNode = head;
        int length = 0;
        while(currNode != nullptr) {
            length++;
            currNode = currNode->next;
        }
        return length;
    }

    //Approach 1: Function to rotate the linked list by 'k' positions
    Node* rotateLinkedList(Node* head, int k) {
        // Handle base cases: empty list or single node list
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        // Calculate the length of the linked list
        int length = findLength(head);
        // Normalize 'k' to a value less than 'length'
        if(length <= k) {
            k %= length;
        }
        // If 'k' is zero or negative, no rotation needed
        if(k < 1) {
            return head;
        }
        // Calculate the new position for the head after rotation
        length -= k;
        int count = 0;
        Node* currNode = head;
        Node* prevNode = nullptr;
        // Traverse to the new head position
        while(count != length) {
            prevNode = currNode;
            currNode = currNode->next;
            count++;
        }
        // Set the new head and traverse to the old tail
        Node* newHead = currNode;
        currNode = newHead;
        while(currNode->next != nullptr) {
            currNode = currNode->next;
        }
        // Update pointers to perform the rotation
        prevNode->next = nullptr;
        currNode->next = head;
        head = newHead;

        return head;
    }

    // Destructor: Clean up memory for all nodes
    ~LinkedList() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            Node* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }

};

int main() {
    Node* head = nullptr;
    LinkedList ls;
    head = ls.pushBack(1);
    head = ls.pushBack(2);
    head = ls.pushBack(3);
    head = ls.pushBack(4);
    head = ls.pushBack(5);
    head = ls.pushBack(6);
    head = ls.pushBack(7);
    head = ls.pushBack(8);

    cout<<"The Linked List"<<endl;
    ls.display(head);
    
    int k = 6;
    cout<<"The Linked List after Rotating in "<<k<<" places"<<endl;
    head = ls.rotateLinkedList(head, k);
    ls.display(head);

    return 0;
}
