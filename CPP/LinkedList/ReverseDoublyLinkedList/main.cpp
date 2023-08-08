#include<iostream>
#include<stack>

using namespace std;

// A Node class with pointer next and prev
class Node{
public:
    Node* next;
    Node* prev;
    int value;
    //Constructor: creates new node when called
    Node(int value) {
        this->next = this->prev = nullptr;
        this->value = value;
    }
};

// A Doubly LinkedList class with pointer head and tail
class DoublyLinkedList {
private:
    int length;
    Node *head, *tail;

    // checks if the linked list is empty or not
    bool isEmpty() {
        if(this->head == nullptr) {
            return true;
        }
        return false;
    }

    // inserts an element if the linked list is empty
    void insertWhileEmpty(Node* newNode) {
        this->head = this->tail = newNode;
        this->length++;
    }

public:
    //Constructor: creates an empty linked list
    DoublyLinkedList() {
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    // pushes the element onto the end of the linked list
    Node* pushBack(int value) {
        Node *newNode = new Node(value);
        if(isEmpty()) {
            this->insertWhileEmpty(newNode);
            return this->head;;
        }
        this->tail->next = newNode;
        newNode->prev = this->tail;
        newNode->next = nullptr;
        this->tail = newNode;
        this->length++;
        return head;
    }

    // displaying the elements of the linked list
    void display(Node* &head) {
        // when the linked list is empty
        if(isEmpty()) {
            cout<<"The Doubly Linked List is Empty."<<endl;
            return;
        }
        Node* currNode = head;
        cout<<"The Doubly Linked List"<<endl;
        while(currNode != nullptr) {
            cout<<currNode->value<<" -> ";
            currNode = currNode->next;
        }
        cout<<"NULL"<<endl;
    }


    //Approach 1: Reverse the linked list iteratively
    Node* reverseIteratively(Node* &head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        Node* currNode = head;
        Node* nextNode = nullptr;
        Node* prevNode = nullptr;
        // Iteratively reverse the linked list
        while(currNode != nullptr) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            currNode->prev = nextNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        // Update the head to the new starting point
        head = prevNode;
        return head;
    }

    //Approach 2: Reverse the linked list recursively
    Node* reverseRecursively(Node* &head) {
        // Base case: if the list is empty or has only one element, return the head
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        // Recursive call to reverse the remaining list
        Node* newHead = reverseRecursively(head->next);
        // Adjust the pointers to reverse the current node
        head->next->next = head;
        head->prev = head->next;
        head->next = nullptr;
        return newHead;
    }

    //Approach 3: Reverse the linked list using a stack
    Node* reverseUsingStack(Node* &head) {
        // Return NULL if the linked list is empty
        if(head == nullptr) {
            return head;
        }
        stack<Node*> st;
        Node* currNode = head;
        // Push all nodes onto the stack
        while(currNode != nullptr) {
            st.push(currNode);
            currNode = currNode->next;
        }
        // Update head to the last node which will be the new starting point
        head = st.top();
        st.pop();
        currNode = head;
        // Pop elements from the stack and adjust pointers to reverse the list
        while(!st.empty()) {
            currNode->next = st.top();
            currNode->next->prev = currNode;
            st.pop();
            currNode = currNode->next;
        }
        // Set the next of the last node to NULL
        currNode->next = nullptr;
        return head;
    } 

    //Approach 4: Reverse the linked list in-place using two pointers
    Node* reverseInPlace(Node* &head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        Node* currNode = head;
        // Iteratively reverse the linked list
        while (currNode != nullptr) {
            swap(currNode->next, currNode->prev); // Swap next and prev pointers
            head = currNode; // Update head to current node
            currNode = currNode->prev; // Move to the previous node
        }
        return head;
    }

    // Destructor: Clean up memory for all nodes
    ~DoublyLinkedList() {
        Node* currNode = head;
        while(currNode != nullptr) {
            Node* nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dl;
    Node* head = nullptr;
    head = dl.pushBack(14);
    head = dl.pushBack(98);
    head = dl.pushBack(25);
    head = dl.pushBack(11);
    head = dl.pushBack(23);
    head = dl.pushBack(34);

    dl.display(head);

    cout<<"Using Two pointer approach: "<<endl;
    head = dl.reverseInPlace(head);
    dl.display(head);
    
    cout<<"Using Recursive approach: "<<endl;
    head = dl.reverseRecursively(head);
    dl.display(head);

    cout<<"Using Iterative approach: "<<endl;
    head = dl.reverseIteratively(head);
    dl.display(head);

    cout<<"Using Stack approach: "<<endl;
    head = dl.reverseUsingStack(head);
    dl.display(head);


    
    return 0;
}
