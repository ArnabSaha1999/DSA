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
        Node* currentNode = this->head;
        cout<<endl;
        do {
            cout<<currentNode->value<<" ";
            currentNode = currentNode->next;
        } while(currentNode != this->head);
        cout<<endl;
    }

    //Approach 1: Check if a given linked list is circular by traversing through the list.
    // Time Complexity: O(N), where N is the number of nodes in the linked list.
    // Space Complexity: O(1), as no additional data structures are used
    bool isCircular(Node* &head){
        if(head == NULL) {
            // An empty list is considered circular.
            return true;
        }
        Node* currNode = head->next;
        // Traverse through the list until reaching the end or the initial head.
        while(currNode != NULL && currNode != head) {
            currNode = currNode->next;
        }
        // If the traversal ends at the initial head, the list is circular.
        if(currNode == head) {
            return true;
        }
        // If the traversal ends at a non-null node other than the initial head, the list is not circular.
        return false;
    }

    //Approach 2: Check if a given linked list is circular using a hash map to track visited nodes.
    // Time Complexity: O(N), where N is the number of nodes in the linked list.
    // Space Complexity: O(N), as a hash map is used to store visited nodes.
    bool isCircularUsingMap(Node* &head) {
        if(head == NULL) {
            // An empty list is considered circular.
            return true;
        }
        unordered_map<Node*, bool> map;
        Node* currNode = head;
        while(currNode != NULL) {
            if(!map[currNode]) {
                map[currNode] = true;
                // Traverse through the list and mark visited nodes.
                currNode = currNode->next;
            } else if(currNode == head){
                // If a visited node is encountered again, and it's the initial head, the list is circular.
                return true;
            } else {
                // If a visited node is encountered again (other than head), the list is not circular.
                return false;
            }
        }
        // If the traversal ends without finding a cycle, the list is not circular.
        return false;
    }

    //Approach 3: Check if a given linked list is circular using the Floyd's Tortoise and Hare algorithm (two-pointer approach).
    // Time Complexity: O(N), where N is the number of nodes in the linked list.
    // Space Complexity: O(1), as no additional data structures are used.
    bool isCircularUsingTwoPointer(Node* &head) {
        if(head == NULL) {
            // An empty list is considered circular.
            return true;
        }
        Node* fast = head;
        Node* slow = head;

        while(fast != NULL && fast->next != NULL) {
            // Move slow pointer one step at a time.
            slow = slow->next;
            // Move fast pointer two steps at a time.
            fast = fast->next->next;
            if(slow == fast) {
                if(slow == head) {
                    // If fast and slow pointers meet at the initial head, the list is circular.
                    return true;
                }
                // If fast and slow pointers meet at a non-initial head node, the list is not circular.
                return false;
            }
        }
        // If the traversal ends without finding a cycle, the list is not circular.
        return false;
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

    //Approach 1: Check if a given linked list is circular by traversing through the list.
    // Time Complexity: O(N), where N is the number of nodes in the linked list.
    // Space Complexity: O(1), as no additional data structures are used
    bool isCircular(Node* &head){
        if(head == NULL) {
            // An empty list is considered circular.
            return true;
        }
        Node* currNode = head->next;
        // Traverse through the list until reaching the end or the initial head.
        while(currNode != NULL && currNode != head) {
            currNode = currNode->next;
        }
        // If the traversal ends at the initial head, the list is circular.
        if(currNode == head) {
            return true;
        }
        // If the traversal ends at a non-null node other than the initial head, the list is not circular.
        return false;
    }

    //Approach 2: Check if a given linked list is circular using a hash map to track visited nodes.
    // Time Complexity: O(N), where N is the number of nodes in the linked list.
    // Space Complexity: O(N), as a hash map is used to store visited nodes.
    bool isCircularUsingMap(Node* &head) {
        if(head == NULL) {
            // An empty list is considered circular.
            return true;
        }
        unordered_map<Node*, bool> map;
        Node* currNode = head;
        while(currNode != NULL) {
            if(!map[currNode]) {
                map[currNode] = true;
                // Traverse through the list and mark visited nodes.
                currNode = currNode->next;
            } else if(currNode == head){
                // If a visited node is encountered again, and it's the initial head, the list is circular.
                return true;
            } else {
                // If a visited node is encountered again (other than head), the list is not circular.
                return false;
            }
        }
        // If the traversal ends without finding a cycle, the list is not circular.
        return false;
    }

    //Approach 3: Check if a given linked list is circular using the Floyd's Tortoise and Hare algorithm (two-pointer approach).
    // Time Complexity: O(N), where N is the number of nodes in the linked list.
    // Space Complexity: O(1), as no additional data structures are used.
    bool isCircularUsingTwoPointer(Node* &head) {
        if(head == NULL) {
            // An empty list is considered circular.
            return true;
        }
        Node* fast = head;
        Node* slow = head;

        while(fast != NULL && fast->next != NULL) {
            // Move slow pointer one step at a time.
            slow = slow->next;
            // Move fast pointer two steps at a time.
            fast = fast->next->next;
            if(slow == fast) {
                if(slow == head) {
                    // If fast and slow pointers meet at the initial head, the list is circular.
                    return true;
                }
                // If fast and slow pointers meet at a non-initial head node, the list is not circular.
                return false;
            }
        }
        // If the traversal ends without finding a cycle, the list is not circular.
        return false;
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
    Node* head = NULL;
    CircularLinkedList cl;
    head = cl.pushBack(1);
    head = cl.pushBack(2);
    head = cl.pushBack(3);
    head = cl.pushBack(4);
    head = cl.pushBack(5);

    cout<<endl<<"Displaying Circular Linked List"<<endl;
    cl.display(head);

    cout<<"Using the isCircular function"<<endl;
    if(cl.isCircular(head)) {
        cout<<"The Linked List is Circular"<<endl;
    } else {
        cout<<"The Linked List is not Circular"<<endl;
    }

    cout<<"Using the isCircularUsingMap function"<<endl;
    if(cl.isCircularUsingMap(head)) {
        cout<<"The Linked List is Circular"<<endl;
    } else {
        cout<<"The Linked List is Not Circular"<<endl;
    }

    cout<<"Using the isCircularUsingTwoPointer function"<<endl;
    if(cl.isCircularUsingTwoPointer(head)) {
        cout<<"The Linked List is Circular"<<endl;
    } else {
        cout<<"The Linked List is Not Circular"<<endl;
    }

    LinkedList ll;
    head = ll.pushBack(1);
    head = ll.pushBack(2);
    head = ll.pushBack(3);
    head = ll.pushBack(4);
    head = ll.pushBack(5);
    
    cout<<endl<<"Displaying Singly Linked List"<<endl;
    ll.display(head);

    cout<<"Using the isCircular function"<<endl;
    if(ll.isCircular(head)) {
        cout<<"The Linked List is Circular"<<endl;
    } else {
        cout<<"The Linked List is not Circular"<<endl;
    }

    cout<<"Using the isCircularUsingMap function"<<endl;
    if(ll.isCircularUsingMap(head)) {
        cout<<"The Linked List is Circular"<<endl;
    } else {
        cout<<"The Linked List is Not Circular"<<endl;
    }

    cout<<"Using the isCircularUsingTwoPointer function"<<endl;
    if(ll.isCircularUsingTwoPointer(head)) {
        cout<<"The Linked List is Circular"<<endl;
    } else {
        cout<<"The Linked List is Not Circular"<<endl;
    }
    return 0;
}
