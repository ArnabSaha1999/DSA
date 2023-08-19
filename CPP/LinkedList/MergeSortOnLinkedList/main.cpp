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

    //Function to merge two linked lists Recursively
    Node* mergeTwoListsRecursively(Node* list1, Node* list2) {
        // Base cases: if one of the lists is empty, return the other list
        if(list1 == NULL) {
            return list2;
        }
        
        if(list2 == NULL) {
            return list1;
        }
        // Compare values and merge the lists accordingly
        if(list1->value <= list2->value) {
            // Recursively merge the rest of the lists and connect the nodes
            list1->next = mergeTwoListsRecursively(list1->next, list2);
            return list1;
        } else {
            // Recursively merge the rest of the lists and connect the nodes
            list2->next = mergeTwoListsRecursively(list2->next, list1);
            return list2;
        }
        
    }

    // Function to push a node to the tail of the linked list
    void pushAtTail(Node* &head, Node* &tail, Node* currNode) {
        // If the list is empty, update both head and tail to the new node
        if(head == nullptr) {
            head = tail = currNode;
            return;
        }
        // Otherwise, update the tail's next to the new node and move tail to the new node 
        tail->next = currNode;
        tail = currNode;
        return;
    }

    // Function to merge two sorted linked lists iteratively
    Node* mergeTwoLists(Node* list1, Node* list2) {
        // If the first list is empty, return the second list
        if(list1 == nullptr) {
            return list2;
        }
        // If the second list is empty, return the first list
        if(list2 == nullptr) {
            return list1;
        }
        // Initialize pointers for the merged list's head and tail
        Node* mergedHead = nullptr;
        Node* mergedTail = mergedHead;
        // Merge the two lists by comparing elements one by one
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->value <= list2->value) {
                // If the value in the first list is smaller or equal,
                // add the node to the merged list and move to the next node in the first list
                pushAtTail(mergedHead, mergedTail, list1);
                list1 = list1->next;
            } else {
                // If the value in the second list is smaller,
                // add the node to the merged list and move to the next node in the second list
                pushAtTail(mergedHead, mergedTail, list2);
                list2 = list2->next;
            }
        }
        // If any nodes are remaining in the first list, add them to the merged list
        while(list1 != nullptr) {
            pushAtTail(mergedHead, mergedTail, list1);
            list1 = list1->next;
        }
        // If any nodes are remaining in the second list, add them to the merged list
        while(list2 != nullptr) {
            pushAtTail(mergedHead, mergedTail, list2);
            list2 = list2->next;
        }
        // Return the head of the merged list
        return mergedHead;
    }

    //Function to find the middle using the two-pointer approach.
    Node* findMid(Node* head) {
        Node *slowNode = head, *fastNode = head;
        while(fastNode->next != NULL && fastNode->next->next != NULL) {
            // Move the slow pointer one step.
            slowNode = slowNode->next;
            // Move the fast pointer two steps.
            fastNode = fastNode->next->next;
        }
        // The slow pointer is now at the middle node.
        return slowNode;
    }

    //Function to Merge Sort on Linked List.
    Node* mergeSort(Node* head) {
        // Base case: If the list is empty or has only one element, it's already sorted
        if(head == NULL || head->next == NULL) {
            return head;
        }
        // Find the middle node of the linked list
        Node* midNode = findMid(head);
        // Split the linked list into two halves: left and right
        Node* left = head;
        Node* right = midNode->next;
        midNode->next = NULL;

        // Recursively sort the left and right halves
        left = mergeSort(left);
        right = mergeSort(right);
        // Merge the sorted left and right halves
        Node* ans = mergeTwoLists(left, right);
    
        // Node* ans = mergeTwoListsRecursively(left, right);
        return ans;
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
    Node *head = NULL, *ansHead = NULL;
    LinkedList ls;
    head = ls.pushBack(6);
    head = ls.pushBack(4);
    head = ls.pushBack(2);
    head = ls.pushBack(3);
    head = ls.pushBack(3);
    head = ls.pushBack(2);
    head = ls.pushBack(1);
    cout<<"Displaying the Linked List"<<endl;
    ls.display(head);

    cout<<"Applying Merge Sort on Linked List"<<endl;
    ansHead = ls.mergeSort(head);
    ls.display(ansHead);

    return 0;
}
