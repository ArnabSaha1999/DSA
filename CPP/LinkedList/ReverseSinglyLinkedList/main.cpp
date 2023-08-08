#include <iostream>
#include <stack>
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
    Node *head;
    Node *tail;
    int length;

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
    //Constructor: creates an empty linked list
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    }

    // pushes the element onto the end of the linked list
    Node* pushBack (int value) {
        Node* newNode = new Node(value);
        if(this->isEmpty()) {   //when the linked list is empty
            this->insertWhileEmpty(newNode);
            return this->head;
        }
        this->tail->next = newNode;
        this->tail = newNode;
        this->length++;
        return this->head;
    }

    // displaying the elements of the linked list
    void display (Node* &head) {
        if(head == NULL || head->next == NULL) {   // when the linked list is empty
            cout << "The Linked list is empty";
        }
        Node* currentNode = head;
        cout<<endl;
        while(currentNode != nullptr) {
            cout<<currentNode->value<<" ";
            currentNode = currentNode->next;
        }
        cout<<endl;
    }

    //Approach 1: Reverse the linked list iteratively
    Node* reverseIteratively(Node* &head) {
        Node* currNode = head;
        Node* prevNode = NULL, * nextNode = NULL;
        // Iteratively reverse the linked list
        while(currNode != NULL) {
            nextNode = currNode->next;
            currNode->next = prevNode;
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
        if(head == NULL || head->next == NULL) {
            return head;
        }
        // Recursive call to reverse the remaining list
        Node* newHead = reverseRecursively(head->next);
        // Adjust the pointers to reverse the current node
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }


    //Approach 3: Reverse the linked list using a stack
    Node* reverseUsingStack(Node* &head) {
        // Return NULL if the linked list is empty
        if(head == NULL) 
            return head;

        stack<Node *> st;
        Node* currNode = head;
        // Push all nodes onto the stack
        while(currNode != NULL) {
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
            st.pop();
            currNode = currNode->next;
        }
        // Set the next of the last node to NULL
        currNode->next = NULL;
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
    LinkedList li;
    Node *head = NULL;
    head = li.pushBack(10);
    head = li.pushBack(15);
    head = li.pushBack(20);
    head = li.pushBack(25);
    head = li.pushBack(30);
    head = li.pushBack(35);

    cout<<endl<<"Before Reverse : "<<endl;
    li.display(head);

    cout<<endl<<"After Reverse Iteratively :"<<endl;
    head = li.reverseIteratively(head);
    li.display(head);

    cout<<endl<<"After Reverse Recursively :"<<endl;
    head = li.reverseRecursively(head);
    li.display(head);

    cout<<endl<<"After Reverse using Stack :"<<endl;
    head = li.reverseUsingStack(head);
    li.display(head);

    return 0;
}
