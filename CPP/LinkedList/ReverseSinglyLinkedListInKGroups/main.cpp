#include<iostream>
#include<stack>

using namespace std;

// A Node class with pointer next
class Node {
public:
    int value;
    Node *next;
    //Constructor: creates new node when called
    Node (int value) {
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
    bool isEmpty() {
        if (this->head == nullptr) {
            return true;
        }
        return false;
    }

    // inserts an element if the linked list is empty
    void insertWhileEmpty(Node *newNode) {
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
    Node *pushBack(int value) {
        Node *newNode = new Node(value);
        //when the linked list is empty
        if (this->isEmpty()) {
            this->insertWhileEmpty(newNode);
            return this->head;
        }
        this->tail->next = newNode;
        this->tail = newNode;
        this->length++;
        return this->head;
    }

    // displaying the elements of the linked list
    void display(Node *&head) {
        // when the linked list is empty
        if (head == NULL || head->next == NULL) {
            cout << "The Linked list is empty";
        }
        Node *currentNode = head;
        cout << endl;
        while (currentNode != nullptr) {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    //Approach 1: Reverse k nodes in a group using Iterative and recursive approach.
    Node *reverseKGroup(Node *&head, int k) {
        if(head == NULL || k <= 1) {
            return head;
        }

        // Check if there are at least k nodes remaining
        Node* currNode = head;
        for(int i = 0; i < k-1 && currNode != NULL; i++) {
            currNode = currNode->next;
        }
        // If there are not enough nodes for a group of size k, do nothing
        if(currNode == NULL) {
            return head;
        }
        // Initialize pointers
        currNode = head;
        Node *prevNode = NULL, *nextNode = NULL;
        int count = 0;
        // Reverse the current k nodes
        while (currNode != NULL && k != count) {
            count++;
            nextNode = currNode->next;
            currNode->next = prevNode;
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
        // Check if there are at least k nodes remaining
        Node* currNode = head;
        for(int i = 0; i < k-1 && currNode != NULL; i++) {
            currNode = currNode->next;
        }
        // If there are not enough nodes for a group of size k, do nothing
        if(currNode == NULL) {
            return head;
        }
        // Initialize pointers
        currNode = head;
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
            st.pop();
            tempNode = tempNode->next;
        }
        // Connect the end of the reversed group to the next reversed group
        tempNode->next = reverseKGroupUsingStack(currNode, k);
        return newHead;
    }

    // Destructor: Clean up memory for all nodes
    ~LinkedList() {
    Node* currNode = head;
    while (currNode != nullptr) {
        Node* nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
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

    int k = 4;

    cout<<endl<<"After Reverse Iteratively in "<<k<<" groups:"<<endl;
    head = li.reverseKGroup(head, k);
    li.display(head);

    cout<<endl<<"After Reverse using Stack in "<<k<<" groups:"<<endl;
    head = li.reverseKGroupUsingStack(head, k);
    li.display(head);
    
    return 0;
}
