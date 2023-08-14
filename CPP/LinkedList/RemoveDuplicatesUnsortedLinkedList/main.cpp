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

//Approach 1: Remove duplicates from a linked list using a brute force approach
Node* removeDuplicate(Node* head) {
    // If the list is empty or has only one node, no duplicates to remove
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* currNode = head;
    while(currNode != nullptr) {
        // Temporary pointer to check duplicates with subsequent nodes
        Node* tempNode = currNode;
        while(tempNode->next != nullptr) {
            if(currNode->value == tempNode->next->value) {
                // Duplicate found, remove the duplicate node
                Node* nodeToDelete = tempNode->next;
                tempNode->next = tempNode->next->next;
                // Free memory for the duplicate node
                delete nodeToDelete;
            } else {
                // Move to the next node to check for duplicates
                tempNode = tempNode->next;
            }
        }
        // Move to the next node to check for duplicates
        currNode = currNode->next;
    }
    return head;
}

//Approach 2: Remove duplicates from a linked list using a hash map (unordered_map)
Node* removeDuplicateUsingHashMap(Node* head) {
    // If the list is empty or has only one node, no duplicates to remove
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    unordered_map<int, bool> visited;
    Node* currNode = head;
    // Pointer to keep track of the previous node
    Node* prevNode = nullptr;
    while(currNode != nullptr) {
        if(!visited[currNode->value]) {
            // Mark the value as visited
            visited[currNode->value] = true;
            // Update the previous node to the current node
            prevNode = currNode;
            currNode = currNode->next;
        } else {
            // Duplicate found, remove the duplicate node
            Node* nodeToDelete = currNode;
            // Update the previous node's next pointer
            prevNode->next = currNode->next;
            currNode = prevNode->next;
            // Free memory for the duplicate node
            delete nodeToDelete;
        }
    }
    return head;
}

int main() {
    // Creating a singly linked list
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next->next = nullptr;

    cout<<"Displaying The LinkedList"<<endl;
    display(head);

    cout<<"Removing Duplicates using Brute force approach"<<endl;
    head = removeDuplicate(head);
    display(head);

    cout<<"Removing Duplicates using HashMap(Unordered_Map)"<<endl;
    head = removeDuplicateUsingHashMap(head);
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
