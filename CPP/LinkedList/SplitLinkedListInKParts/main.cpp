#include<iostream>
#include<vector>

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

    // Calculate the length of the linked list
    int findLength(Node* head) {
        Node* currNode = head;
        int length = 0;
        while(currNode != nullptr) {
            length++;
            currNode = currNode->next;
        }
        return length;
    }

    // Add a new node at the tail of the linked list
    void pushAtTail(Node* &head, Node* &tail, Node* currNode) {
        if(head == nullptr) {
            head = tail = currNode;
            return;
        }
        tail->next = currNode;
        tail = currNode;
        return;
    }

    //Approach 1: Split the linked list into k parts
    vector<Node*> splitListToParts(Node* head, int k) {
        int length = findLength(head);
        int groupSize = length / k;
        int remGroup = length % k;
        int index = 0;
        Node* currNode = head;
        vector<Node*> res(k, nullptr);
        // Distribute nodes into groups dynamically
        while(currNode != nullptr) {
            Node* tempHead = nullptr;
            Node* tempTail = nullptr;
            // Create a group with 'groupSize' nodes
            for(int i = 0; i < groupSize; i++) {
                pushAtTail(tempHead, tempTail, currNode);
                currNode = currNode->next;
            }
            // Distribute remaining nodes if any
            if(remGroup != 0) {
                pushAtTail(tempHead, tempTail, currNode);
                currNode = currNode->next;
                remGroup--;
            }
            // Set the tail of the current group to null
            tempTail->next = nullptr;
            // Store the current group in the result vector
            res[index++] = tempHead;
        }
        return res;
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
    Node* head = nullptr;
    LinkedList ls;
    head = ls.pushBack(1);
    head = ls.pushBack(2);
    head = ls.pushBack(3);
    head = ls.pushBack(4);
    head = ls.pushBack(5);
    head = ls.pushBack(6);
    cout<<"The Linked List"<<endl;
    ls.display(head);
    int k = 4;

    vector<Node*> ans = ls.splitListToParts(head, k);
    cout<<"The Linked List "<<k<<" group "<<endl;
    for(auto node : ans) {
        ls.display(node);
    }

    return 0;


}
