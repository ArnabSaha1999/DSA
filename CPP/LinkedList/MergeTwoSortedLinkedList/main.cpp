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

    //Approach 1: Iterative approach to merge two sorted linked lists
    Node* mergeTwoListsIteratively(Node* firstList, Node* secondList) {
        // Initialize mergedList and prevNode pointers
        Node* mergedList = nullptr;
        Node* prevNode = mergedList;
        // Merge the lists while both lists have remaining elements
        while(firstList != nullptr && secondList != nullptr) {
            if(firstList->value <= secondList->value) {
                // Connect the current node to the merged list
                if(prevNode == nullptr) {
                    mergedList = prevNode = firstList;
                } else {
                    prevNode->next = firstList;
                    prevNode = firstList;
                }
                firstList = firstList->next;
            } else {
                // Connect the current node to the merged list
                if(prevNode == nullptr) {
                    mergedList = prevNode = secondList;
                } else {
                    prevNode->next = secondList;
                    prevNode = secondList;
                }
                secondList = secondList->next;
            }
        }
        // Append any remaining nodes from the firstList
        while(firstList != nullptr) {
            // Connect the current node to the merged list
            if(prevNode == nullptr) {
                mergedList = prevNode = firstList;
            } else {
                prevNode->next = firstList;
                prevNode = firstList;
            }
            firstList = firstList->next;
            
        }

        // Append any remaining nodes from the secondlist
        while(secondList != nullptr) {
            // Connect the current node to the merged list
            if(prevNode == nullptr) {
                mergedList = prevNode = secondList;
            } else {
                prevNode->next = secondList;
                prevNode = secondList;
            }
            secondList = secondList->next;
        }
        return mergedList;
    }
    
    //Approach 2: Recursive approach to merge two sorted linked lists
    Node* mergeTwoListsRecursively(Node* firstList, Node* secondList) {
        // Base cases: if one of the lists is empty, return the other list
        if(firstList == nullptr) {
            return secondList;
        }

        if(secondList == nullptr) {
            return firstList;
        }
        // Compare values and merge the lists accordingly
        if(firstList->value <= secondList->value) {
            // Recursively merge the rest of the lists and connect the nodes
            firstList->next = mergeTwoListsRecursively(firstList->next, secondList);
            return firstList;
        } else {
            // Recursively merge the rest of the lists and connect the nodes
            secondList->next = mergeTwoListsRecursively(firstList, secondList->next);
            return secondList;
        }
        
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
    LinkedList ls1, ls2;
    Node *firstList, *secondList;
    firstList = ls1.pushBack(1);
    firstList = ls1.pushBack(1);
    firstList = ls1.pushBack(3);
    firstList = ls1.pushBack(6);
    cout<<"The First Linked List"<<endl;
    ls1.display(firstList);

    secondList = ls2.pushBack(1);
    secondList = ls2.pushBack(2);
    secondList = ls2.pushBack(2);
    secondList = ls2.pushBack(4);
    secondList = ls2.pushBack(9);
    cout<<"The Second Linked List"<<endl;
    ls2.display(secondList);

    Node* mergeNode = ls1.mergeTwoListsIteratively(firstList, secondList);
    cout<<"The Merged Linked Linked using Iterative approach"<<endl;
    ls1.display(mergeNode);


    LinkedList ls3, ls4;

    firstList = ls3.pushBack(1);
    firstList = ls3.pushBack(3);
    firstList = ls3.pushBack(3);
    firstList = ls3.pushBack(5);
    cout<<"The Third Linked List"<<endl;
    ls3.display(firstList);

    secondList = ls4.pushBack(2);
    secondList = ls4.pushBack(3);
    secondList = ls4.pushBack(4);
    secondList = ls4.pushBack(4);
    secondList = ls4.pushBack(6);
    cout<<"The Fourth Linked List"<<endl;
    ls4.display(secondList);

    mergeNode = ls3.mergeTwoListsRecursively(firstList, secondList);
    cout<<"The Merged Linked List using Recursive approach"<<endl;
    ls3.display(mergeNode);
    return 0;
}
