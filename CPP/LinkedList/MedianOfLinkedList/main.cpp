#include <iostream>
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
        //when the linked list is empty
        if(this->isEmpty()) {   
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
        // when the linked list is empty
        if(head == NULL || head->next == NULL) {   
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

    //Approach 1: This is the brute force approach to find the middle of the linked list.
    // It uses the length of the linked list to determine the middle index.
    // Time Complexity: O(N), where N is the length of the linked list.
    // Space Complexity: O(1), as it uses a constant amount of extra space.
    Node* findMiddleBruteForce(Node* head) {
        // Calculate the middle index.
        int mid = (this->length / 2);
        int count = 0;
        Node* currNode = head;
        while(count != mid) {
            count++; // Increment the count.
            currNode = currNode->next; // Move the current node
        }
        // Set the head to the middle node.
        head = currNode;
        return head;

    }

    //Approach 2: Optimized way to find the middle using the two-pointer approach.
    // The fast pointer moves twice as fast as the slow pointer, effectively reaching the middle when fast reaches the end.
    // Time Complexity: O(N), where N is the length of the linked list.
    // Space Complexity: O(1), as it uses a constant amount of extra space.
    Node* findMiddle (Node* &head) {
        Node *fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL) {
            // Move the fast pointer two steps.
            fast = fast->next->next;
            // Move the slow pointer one step.
            slow = slow->next;
        }
        // The slow pointer is now at the middle node.
        return slow;
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
    // head = li.pushBack(40);
    // head = li.pushBack(45);
    li.display(head);
    Node *mid = NULL;
    mid = li.findMiddleBruteForce(head);
    li.display(mid);
    mid = li.findMiddle(head);
    li.display(mid);
    return 0;
}
