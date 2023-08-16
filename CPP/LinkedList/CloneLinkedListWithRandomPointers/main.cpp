#include <iostream>
#include <unordered_map>
using namespace std;

// A Node class with pointer next and random
class Node {
public:
    int value;
    Node *next;
    Node *random;
    Node (int value) {      //creates new node when called
        this->value = value;
        this->next = NULL;
        this->random = NULL;
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
    //creates an empty linked list
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    }

    // pushes the element onto the end of the linked list
    Node *pushBack(int value) {
        Node *newNode = new Node(value);
        if (this->isEmpty()) {   //when the linked list is empty
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
        if (head == NULL) {   // when the linked list is empty
            cout << "The Linked list is empty";
        }
        Node *currentNode = head;
        cout << endl;
        while(currentNode != nullptr) {
            cout<<currentNode->value<<" -> ";
            currentNode = currentNode->next;
        }
        cout<<"NULL"<<endl;
        currentNode = head;
        while (currentNode != nullptr) {
            if(currentNode->random) {
                cout << currentNode->value << " random -> "<<currentNode->random->value<<endl;
            } else {
                cout << currentNode->value << " random -> NULL"<<endl;
            }
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    //Function to connect Random pointers the nodes
    void connectRandomPointer(Node* &head) {
        Node* currNode = head;

        currNode->random = currNode->next->next;
        currNode->next->random = currNode->next->next->next;
        currNode->next->next->random = currNode;
        currNode->next->next->next->random = currNode->next->next->next->next->next;
        currNode->next->next->next->next->random = currNode->next->next->next->next->next->next;
        currNode->next->next->next->next->next->random = currNode->next;
    }
    
    // Adds a new node at the end of the linked list
    void pushAtTail(Node* &head, Node* &tail, int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        return;

    }

    //Approach 1: Copy the linked list with random pointers using a hash map
    Node* copyRandomListUsingMap(Node* &head) {
        Node* originalNode = head;
        Node *cloneHead = NULL, *cloneTail = NULL;

        // Create a clone list with the same values as the original list
        while(originalNode != NULL) {
            pushAtTail(cloneHead, cloneTail, originalNode->value);
            originalNode = originalNode->next;
        }

        unordered_map<Node*, Node*> randomPointerMap;
        Node* cloneNode = cloneHead;
        originalNode = head;
        // Create a mapping of original nodes to their corresponding clone nodes
        while(originalNode != NULL && cloneNode != NULL) {
            randomPointerMap[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        originalNode = head;
        cloneNode = cloneHead;
        // Set random pointers in the clone list using the map
        while(cloneNode != NULL) {
            cloneNode->random = randomPointerMap[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }

    //Approach 2: Copy the linked list with random pointers (optimized approach)
    Node* copyRandomList(Node* &head) {
        Node* originalNode = head;
        Node *cloneHead = NULL, *cloneTail = NULL;
        // Step 1: Create a new list with the same values
        while(originalNode != NULL) {
            pushAtTail(cloneHead, cloneTail, originalNode->value);
            originalNode = originalNode->next;
        }
        Node* cloneNode = cloneHead;
        originalNode = head;
        // Step 2: Add clone nodes right after the original nodes
        while(originalNode != NULL && cloneNode!= NULL) {
            Node* nextNode = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = nextNode;
            nextNode = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = nextNode;
        }

        originalNode = head;
        //Step 3: Set random pointers for the cloned nodes based on the original nodes
        while(originalNode != NULL) {
            if(originalNode->next != NULL) {
                originalNode->next->random = originalNode->random != NULL ? originalNode->random->next : originalNode->random;
            }
            originalNode = originalNode->next->next;
        }

        originalNode = head;
        cloneNode = cloneHead;
        // Step 4: Restore the original list and extract the cloned list
        while(originalNode!= NULL && cloneNode != NULL) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if(originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        return cloneHead;
        
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
    Node *head = nullptr, *ansHead = nullptr;
    LinkedList ls;
    head = ls.pushBack(6);
    head = ls.pushBack(4);
    head = ls.pushBack(2);
    head = ls.pushBack(3);
    head = ls.pushBack(3);
    head = ls.pushBack(2);
    head = ls.pushBack(1);

    cout<<"Displaying the Linked List with the Random Pointers"<<endl;
    ls.connectRandomPointer(head);
    ls.display(head);

    cout<<"Using HashMap approach"<<endl;
    ansHead = ls.copyRandomListUsingMap(head);
    ls.display(ansHead);

    cout<<"Using Optimized approach"<<endl;
    ansHead = ls.copyRandomList(head);
    ls.display(ansHead);

    return 0;
}
