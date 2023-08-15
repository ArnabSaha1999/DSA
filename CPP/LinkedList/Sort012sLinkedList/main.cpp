#include <iostream>
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

    //Approach 1: Sort Linked List of 0s, 1s & 2s using Counting approach.
    Node* sort012sCounting(Node* head) {
        // No need to sort if the list is empty or has only one element
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        // Count the occurrences of 0s, 1s, and 2s
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        Node* currNode = head;
        while(currNode != nullptr) {
            if(currNode->value == 0) {
                zeroCount++;
            } else if(currNode->value == 1) {
                oneCount++;
            } else {
                twoCount++;
            }
            currNode = currNode->next;
        }
        currNode = head;
        // Modify the list to arrange 0s, 1s, and 2s in sorted order
        while(currNode != nullptr) {
            if(zeroCount != 0) {
                currNode->value = 0;
                zeroCount--;
            } else if(oneCount != 0) {
                currNode->value = 1;
                oneCount--;
            } else {
                currNode->value = 2;
                twoCount--;
            }
            currNode = currNode->next;
        }
        return head;
    }

    //Function to insert Node after the tail.
    void pushAtTail(Node* &head, Node* &tail, Node* currNode) {
        //When the list is empty create a new list.
        if(head == nullptr) {
            head = tail = currNode;
            return;
        }
        //Add node after the tail and modify the tail.
        tail->next = currNode;
        tail = currNode;
        return;
    } 

    //Approach 2: Sort Linked List of 0s, 1s & 2s using Partition approach
    Node* sort012sPartitioning(Node* head) {
        // No need to sort if the list is empty or has only one element
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        // Create separate lists for 0s, 1s, and 2s
        Node* zeroHead = nullptr;
        Node* zeroTail = zeroHead;
        Node* oneHead = nullptr;
        Node* oneTail = oneHead;
        Node* twoHead = nullptr;
        Node* twoTail = twoHead;
        Node* currNode = head;
        // Traverse the original list and partition elements into the three lists
        while(currNode != nullptr) {
            if(currNode->value == 0) {
                pushAtTail(zeroHead, zeroTail, currNode);
            } else if(currNode->value == 1) {
                pushAtTail(oneHead, oneTail, currNode);
            } else {
                pushAtTail(twoHead, twoTail, currNode);
            }
            currNode = currNode->next;
        }
        // Reconnect the three lists in sorted order
        if(zeroHead != nullptr) {
            head = zeroHead;
            zeroTail->next = (oneHead != nullptr) ? oneHead : twoHead;
        } else if(oneHead != nullptr) {
            head = oneHead;
            oneTail->next = twoHead;
        } else {
            head = twoHead;
        }
        // Set the last node's next pointer to nullptr to terminate the list
        if(twoTail != nullptr) {
            twoTail->next = nullptr;
        }

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
    LinkedList ls;
    Node* head = nullptr;
    head = ls.pushBack(1);
    head = ls.pushBack(0);
    head = ls.pushBack(2);
    head = ls.pushBack(2);
    head = ls.pushBack(0);
    head = ls.pushBack(0);
    head = ls.pushBack(1);
    head = ls.pushBack(0);
    head = ls.pushBack(2);
    cout<<"Displaying the LinkedList"<<endl;
    ls.display(head);

    cout<<"Applying the counting algorithm to sort 0s, 1s & 2s"<<endl;
    Node* newHead = ls.sort012sCounting(head);
    ls.display(newHead);

    cout<<"Applying the partitioning approach to sort 0s, 1s & 2s"<<endl;
    newHead = ls.sort012sPartitioning(head);
    ls.display(newHead);

    return 0;
}
