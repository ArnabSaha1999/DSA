#include<iostream>
#include<stack>

using namespace std;

// A Node class with pointer next
class Node{
public:
    Node* next;
    int value;
    //Constructor: creates new node when called
    Node(int value) {
        this->value = value;
    }
};

// A Circular LinkedList class with pointer head and tail
class CircularLinkedList {
private:
    Node *head, *tail;
    int length;

    // checks if the linked list is empty or not
    bool isEmpty() {
        if(head == nullptr) {
            return true;
        }
        return false;
    }

    // inserts an element if the linked list is empty
    void insertWhileEmpty(Node* newNode) {
        this->head = this->tail = newNode;
        this->tail->next = this->head->next = this->head;
        this->length++;
    }

public:
    //Constructor: creates an empty linked list
    CircularLinkedList() {
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    // pushes the element onto the end of the linked list
    Node* pushBack(int value) {
        Node* newNode = new Node(value);
        if(isEmpty()) {
            insertWhileEmpty(newNode);
            return head;
        }
        this->tail->next = newNode;
        this->tail = newNode;
        this->tail->next = this->head;
        this->length++;
        return head;
    }

    // displaying the elements of the linked list
    void display(Node* &head) {
        // when the linked list is empty
        if(isEmpty()) {
            cout<<"The Circular Linked List is Empty."<<endl;
            return;
        }
        Node* currNode = head;
        cout<<"The Circular Linked List: "<<endl;
        do{
            cout<<currNode->value<<" -> ";
            currNode = currNode->next;
        } while(currNode != head);
        cout<<"head ("<<head->value<<")"<<endl;
    }

    //Approach 1: Reverse the linked list iteratively
    Node* reverseIteratively(Node* &head) {
        // Check if the list is empty or has only one element
        if(head == nullptr || head->next == head) {
            return head;
        }
        Node* currNode = head;
        Node* prevNode = nullptr;
        Node* nextNode = nullptr;
        // Update tail to the current head
        this->tail = this->head; 
        // Continue until we reach the initial head
        do {
            // Store the next node before modifying pointers
            nextNode = currNode->next; 
            // Reverse the next pointer
            currNode->next = prevNode; 
            // Move prevNode to current node
            prevNode = currNode; 
            // Move currNode to next node
            currNode = nextNode; 
        } while(currNode != head); 
        // Update the head to the new start of the list
        head = prevNode; 
        // Update tail's next pointer to the new head
        this->tail->next = head;
        return head;
    }

    //Approach 2: Reverse the linked list using a stack
    Node* reverseUsingStack(Node* &head) {
        if(head == nullptr) {
            return head;
        }

        stack<Node*> st;
        Node* currNode = head;
        // Continue until we reach the initial head
        do {
            // Push each node onto the stack
            st.push(currNode); 
            // Move to the next node
            currNode = currNode->next; 
        } while(currNode != head);  
        // Update head to the last node (top of the stack)
        head = st.top(); 
        st.pop();
        currNode = head;
        // Pop elements from the stack and adjust pointers to reverse the list
        while(!st.empty()) {
            // Set the next pointer to the top of the stack
            currNode->next = st.top(); 
            st.pop();
            // Move to the next node
            currNode = currNode->next; 
        }
        // Complete the circular link by setting the last node's next to head
        currNode->next = head; 
        return head;
    }

    // Destructor: Clean up memory for all nodes
    ~CircularLinkedList() {
        Node* currNode = head;
        do {
            Node* nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        } while(currNode != this->head);
    }
};

int main() {
    CircularLinkedList cl;
    Node* head = NULL;
    head = cl.pushBack(15);
    head = cl.pushBack(25);
    head = cl.pushBack(87);
    head = cl.pushBack(5);
    head = cl.pushBack(95);
    cl.display(head);

    head = cl.reverseIteratively(head);
    cl.display(head);

    head = cl.reverseUsingStack(head);
    cl.display(head);
    return 0;
}
