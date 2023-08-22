#include<iostream>

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
    Node* head;
    Node* tail;
    int length;

private:
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
    LinkedList() {      //creates an empty linked list
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }
    // pushes the element onto the end of the linked list
    Node* pushBack (int value) {
        Node* newNode = new Node(value);
        if(this->isEmpty()) {   //when the linked list is empty
            this->insertWhileEmpty(newNode);
            return head;
        }
        this->tail->next = newNode;
        this->tail = newNode;
        this->length++;
        return head;
    }


    // displaying the elements of the linked list
    void display (Node* head) {
        if(this->isEmpty()) {   // when the linked list is empty
            cout << "The Linked list is empty";
        }
        Node* currentNode = head;
        while(currentNode != nullptr) {
            cout<<currentNode->value<<" -> ";
            currentNode = currentNode->next;
        }
        cout<<"NULL"<<endl;
    }

    // Function to add a node to the tail of a linked list
    void pushAtTail(Node* &head, Node* &tail, Node* currNode) {
        if(head == nullptr) {
            head = tail = currNode;
            return;
        }
        tail->next = currNode;
        tail = currNode;
        return;
    }

    //Approach 1: Rearrange the linked list with odd nodes first followed by even nodes
    Node* oddEvenList(Node* head) {
        // Handle base cases: empty list, single node list, or two nodes
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        Node* currNode = head;
        Node* oddHead = nullptr;
        Node* oddTail = oddHead;
        Node* evenHead = nullptr;
        Node* evenTail = evenHead;
        int index = 1;
        // Traverse through the linked list and distribute nodes
        while(currNode != nullptr) {
            if(index & 1) {
                // Odd index
                pushAtTail(oddHead, oddTail, currNode);
            } else {
                // Even index
                pushAtTail(evenHead, evenTail, currNode);
            }
            currNode = currNode->next;
            index++;
        }
        // Connect the odd and even parts, set evenTail's next to nullptr
        oddTail->next = evenHead;
        evenTail->next = nullptr;

        return oddHead;
    }

    //Approach 2: Rearrange the linked list with odd nodes first followed by even nodes (Optimized approach)
    Node* oddEvenListOptimized(Node* head) {
        // Handle base cases: empty list, single node list, or two nodes
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        Node* oddHead = head;
        Node* oddTail = oddHead;
        Node* evenHead = head->next;
        Node* evenTail = evenHead;
        // Traverse through the linked list and rearrange nodes
        while(oddTail->next != nullptr && evenTail->next != nullptr) {
            // Connect the oddTail to the next of even node
            oddTail->next = evenTail->next;
            // Update oddTail to the connected node
            oddTail = oddTail->next;
            // Connect the evenTail to the next of odd node
            evenTail->next = oddTail->next;
            // Update evenTail to the connected node
            evenTail = evenTail->next;
        }
        // Connect the odd and even parts
        oddTail->next = evenHead;

        return oddHead;
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
    Node* head;
    LinkedList ls1, ls2;
    head = ls1.pushBack(1);
    head = ls1.pushBack(2);
    head = ls1.pushBack(3);
    head = ls1.pushBack(4);
    head = ls1.pushBack(5);
    head = ls1.pushBack(6);
    head = ls1.pushBack(7);
    head = ls1.pushBack(8);
    cout<<"The Linked List"<<endl;
    ls1.display(head);

    cout<<"The Odd Even Linked List"<<endl;
    Node* newHead = ls1.oddEvenList(head);
    ls1.display(newHead);

    head = nullptr;
    head = ls2.pushBack(1);
    head = ls2.pushBack(2);
    head = ls2.pushBack(3);
    head = ls2.pushBack(4);
    head = ls2.pushBack(5);
    head = ls2.pushBack(6);
    head = ls2.pushBack(7);
    head = ls2.pushBack(8);
    cout<<"The Linked List"<<endl;
    ls2.display(head);

    cout<<"The Odd Even Linked List using Optimized approach"<<endl;
    newHead = ls2.oddEvenListOptimized(head);
    ls2.display(newHead);

    return 0;
}
