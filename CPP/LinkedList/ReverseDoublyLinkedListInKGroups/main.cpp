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
        //when the linked list is empty
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

    //Approach 1: Reverse k nodes in a group using Iterative and recursive approach.
    Node* reverseKGroup(Node* &head, int k) {
        if(head == NULL || k <= 1) {
            return head;
        }
        
        // Initialize pointers for reversing
        Node* currNode = head;
        Node *prevNode = NULL, *nextNode = NULL;
        int count = 0;
        // Reverse the current k nodes in the group
        while (currNode != NULL && k != count) {
            count++;
            nextNode = currNode->next;
            currNode->next = prevNode;
            currNode->prev = nextNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        // Connect the head of the reversed group to the next reversed group
        head->next = reverseKGroup(nextNode, k);
        // Update the head to the new head of the reversed group
        head = prevNode;
        return head;
    }

    //Approach 2: Reverse k nodes in a group using a stack and recursive approach.
    Node* reverseKGroupUsingStack(Node* &head, int k) {
        if(head == NULL || k <= 1) {
            return head;
        }
        // Initialize pointers
        Node* currNode = head;
        stack<Node*> st;
        // Push k nodes onto the stack
        for(int i = 1; i <= k && currNode != NULL; i++) {
            st.push(currNode);
            currNode = currNode->next;
        }
        // Set the new head of the reversed group
        Node* newHead = st.top();
        st.pop();
        Node* tempNode = newHead;
        // Reverse the nodes using the stack
        while(!st.empty()) {
            tempNode->next = st.top();
            tempNode->next->prev = tempNode;
            st.pop();
            tempNode = tempNode->next;
        }
        // Connect the end of the reversed group to the next reversed group
        tempNode->next = reverseKGroupUsingStack(currNode, k);
        head = newHead;
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
    head = dl.pushBack(1);
    head = dl.pushBack(2);
    head = dl.pushBack(3);
    head = dl.pushBack(4);
    head = dl.pushBack(5);
    head = dl.pushBack(6);
    head = dl.pushBack(7);
    head = dl.pushBack(-1);
    head = dl.pushBack(-2);

    cout<<"Displaying the Doubly LinkedList."<<endl;
    dl.display(head);

    int k = 4;

    cout<<"Displaying the Doubly LinkedList after reversing in "<<k<<" groups using iterative approach."<<endl;
    head = dl.reverseKGroup(head, k);
    dl.display(head);

    cout<<"Displaying the Doubly LinkedList after reversing in "<<k<<" group using stack based approach."<<endl;
    head = dl.reverseKGroupUsingStack(head, k);
    dl.display(head);
    

    return 0;
}
