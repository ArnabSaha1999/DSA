#include<iostream>
#include<utility>
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

// A Circular LinkedList class with pointer head and tail
class CircularLinkedList {
    Node *head;
    Node *tail;
    int length;

private:
    // checks if the linked list is empty or not
    bool isEmpty() {
        if (this->length == 0) {
            return true;
        }
        return false;
    }

    // inserts an element if the linked list is empty
    void insertWhileEmpty(Node *newNode) {
        this->head = this->tail = newNode;
        this->tail->next = this->head;
        this->length++;
    }
public:
    //Constructor: creates an empty linked list
    CircularLinkedList() {     
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    // pushes the element onto the end of the linked list
    Node* pushBack (int value) {
        Node* newNode = new Node(value);
        //when the linked list is empty
        if(this->isEmpty()) {   
            this->insertWhileEmpty(newNode);
            return this->head;
        }
        this->tail->next = newNode;
        this->tail = newNode;
        this->tail->next = this->head;
        this->length++;
        return this->head;
    }

    // displaying the elements of the linked list
    void display (Node* &head) {
        // when the linked list is empty
        if(this->isEmpty()) {   
            cout << "The Linked list is empty";
            return;
        }
        Node* currentNode = head;
        do {
            cout<<currentNode->value<<" -> ";
            currentNode = currentNode->next;
        } while(currentNode != head);
        cout<<"head ("<<head->value<<")"<<endl;
    }

    //Approach 1: Splits the circular linked list into two halves using length calculation
    pair<Node*, Node*> splitCircularLinkedList(Node* head) {
        // Check if the list is empty or has only one node
        if(head == nullptr || head->next == nullptr) {
            return make_pair(head, nullptr);
        }
        int length = 0;
        Node* currNode = head;
        Node* prevNode;
        // Calculate the length of the circular linked list
        do{
            length++;
            prevNode = currNode;
            currNode = currNode->next;
        } while(currNode != head);
        // Find the node that will be the tail of the right half
        Node* rightTail = prevNode;
        int mid = length/2;
        currNode = head;
        int count = 0;
        prevNode = nullptr;
        // Traverse to the midpoint to find the node that will be the head of the right half
        while(count != mid) {
            count++;
            prevNode = currNode;
            currNode = currNode->next;
        }
        // The node that will be the head of the right half
        Node* rightHead = currNode;
        // Update the next of the last node of left half to point to head
        prevNode->next = head;
        // Update the next of the last node of right half to point to right head
        rightTail->next = rightHead;
        // Return a pair with the head of the left half as the first element and the head of the right half as the second
        return make_pair(head, rightHead);   
    }

    //Approach 2: Splits the circular linked list into two halves using optimized approach
    pair<Node*, Node*> splitCircularLinkedListOptimized(Node* head) {
        // Check if the list is empty or has only one node
        if(head == nullptr || head->next == nullptr) {
            return make_pair(head, nullptr);
        }
        // Slow pointer initially at the head
        Node* slowNode = head;
        // Fast pointer initially at the head
        Node* fastNode = head;
        // Move the fast pointer by two steps and the slow pointer by one step until fast pointer reaches the end
        while(fastNode->next != head && fastNode->next->next != head) {
            // Move slow pointer by one step
            slowNode = slowNode->next;
            // Move fast pointer by two steps
            fastNode = fastNode->next->next;
        }
        // The node before the starting of the right half
        Node* rightTail = fastNode->next;
        // The head of the right half
        Node* rightHead = slowNode->next;
        // Update the last node of the left half to point to head
        slowNode->next = head;
        // Update the last node of the right half to point to right head
        rightTail->next = rightHead;
        // Return a pair with the head of the left half as the first element and the head of the right half as the second
        return make_pair(head, rightHead);
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
    Node *head = nullptr, *newHead = nullptr;
    CircularLinkedList cl, cl1;
    // Populate and display the first circular linked list
    head = cl.pushBack(1);
    head = cl.pushBack(2);
    head = cl.pushBack(9);
    head = cl.pushBack(7);
    head = cl.pushBack(5);
    head = cl.pushBack(2);
    head = cl.pushBack(4);
    head = cl.pushBack(3);
    cout<<"Displaying the LinkedList"<<endl;
    cl.display(head);

    // Split and display the first circular linked list using length-based splitting
    pair<Node*, Node*> pairList1, pairList2;

    cout<<"Using Length calculation approach"<<endl;
    pairList1 = cl.splitCircularLinkedList(head);
    cout<<"The First Half of Linked List"<<endl;
    cl.display(pairList1.first);
    cout<<"The Second Half of Linked List"<<endl;
    cl.display(pairList1.second);

    // Populate and display the second circular linked list
    head = cl1.pushBack(1);
    head = cl1.pushBack(2);
    head = cl1.pushBack(9);
    head = cl1.pushBack(7);
    head = cl1.pushBack(5);
    head = cl1.pushBack(2);
    head = cl1.pushBack(4);
    head = cl1.pushBack(3);

    cout<<"Using optimized two pointer approach"<<endl;
    // Split and display the second circular linked list using optimized splitting
    pairList2 = cl1.splitCircularLinkedListOptimized(head);
    cout<<"THe First Half of Linked List"<<endl;
    cl1.display(pairList2.first);
    cout<<"The Second Half of Linked List"<<endl;
    cl1.display(pairList2.second);

    return 0;
}
