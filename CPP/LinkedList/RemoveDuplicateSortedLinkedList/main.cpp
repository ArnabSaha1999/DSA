#include <iostream>
#include <unordered_map>
using namespace std;

// A Node class with pointer next
class Node {
public:
    int value;
    Node *next;
    //Constructor: creates new node when called
    Node (int value) {
        this->value = value;
        this->next = NULL;
    }
};

//Function to display Linked list.
void display(Node* head) {
    while(head) {
        cout<<head->value<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

//Approach 1: Remove duplicates from a Sorted linked list using iterative approach
Node* removeDuplicate(Node* head) {
    // If the list is empty or has only one node, no duplicates to remove
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* currNode = head;
    
    while(currNode->next != nullptr) {
        if(currNode->value == currNode->next->value) {
            // Duplicate found, remove the duplicate node
            Node* nodeToDelete = currNode->next;
            currNode->next = currNode->next->next;
            // Free memory for the duplicate node
            delete nodeToDelete;
        } else {
            // Move to the next node to check for duplicates
            currNode = currNode->next;
        }
    }
    
    return head;
}

//Approach 2: Recursive approach to remove duplicates from a sorted linked list
Node* removeDuplicateRecursively(Node* head) {
    // Base case: if the list is empty or has only one element
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    // Check if the current node's value is the same as the next node's value
    if(head->value == head->next->value) {
        Node* nodeToDelete = head->next;
        // Skip the duplicate node
        head->next = head->next->next;
        delete nodeToDelete;
        // Recursive call for the modified list
        return removeDuplicateRecursively(head);
    } else {
        // If no duplicate is found, recursive call for the next node
        head->next = removeDuplicateRecursively(head->next);
    }
    return head;
}


int main() {
    // Creating a singly linked list
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next->next = nullptr;

    cout<<"Displaying The LinkedList"<<endl;
    display(head);

    cout<<"Removing Duplicates using Iterative approach"<<endl;
    head = removeDuplicate(head);
    display(head);

    cout<<"Removing Duplicates using Recursive approach"<<endl;
    head = removeDuplicateRecursively(head);
    display(head);


    // Free up memory by deleting the nodes
    Node* currentNode = head;
    while (currentNode != nullptr) {
        Node* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    return 0;
}
