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
        if(head == nullptr) {   // when the linked list is empty
            cout << "The Linked list is empty";
        }
        Node* currentNode = head;
        while(currentNode != nullptr) {
            cout<<currentNode->value<<" -> ";
            currentNode = currentNode->next;
        }
        cout<<"NULL"<<endl;
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

    // Adds two numbers represented by linked lists iteratively
    Node* addTwoNumbers(Node* l1, Node* l2) {
        //If first linked list is empty then return second list as answer
        if(l1 == NULL) {
            return l2;
        }
        //If second linked list is empty then return first list as answer
        if(l2 == NULL) {
            return l1;
        }

        int carry = 0;
        Node *ansHead = NULL, *ansTail = NULL;

        // Traverse both linked lists or process carry
        while(l1 != NULL || l2 != NULL || carry != 0) {
            // Initialize sum with current carry
            int sum = carry;
            // Add corresponding digits from l1 and l2
            if(l1 != NULL) {
                sum += l1->value;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                sum += l2->value;
                l2 = l2->next;
            }
            // Calculate carry for the next iteration
            carry = sum/10;
            // Add the digit to the result linked list
            pushAtTail(ansHead, ansTail, sum % 10);

        }
        return ansHead;
    }

    // Add two numbers represented by linked lists recursively
    Node* addTwoNumbersRecursively(Node* l1, Node* l2, int carry = 0) {
        // Base case: both linked lists are empty and no carry
        if(!l1 && !l2 && carry == 0) {
            return nullptr;
        }
        int sum = carry;
        // Add corresponding digits from l1 and l2
        if(l1) {
            sum += l1->value;
            l1 = l1->next;
        }
        if(l2) {
            sum += l2->value;
            l2 = l2->next;
        }
        // Calculate carry for next iteration
        carry = sum / 10;
        // Create a new node with the digit sum % 10
        Node* ansHead = new Node(sum % 10);
        // Recursive call for the next digits
        ansHead->next = addTwoNumbersRecursively(l1, l2, carry);
        return ansHead;
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
    Node *head1 = NULL, *head2 = NULL, *ansHead = NULL;
    LinkedList ls1, ls2, ls;
    head1 = ls1.pushBack(5);
    head1 = ls1.pushBack(6);
    head1 = ls1.pushBack(4);
    head1 = ls1.pushBack(9);
    head2 = ls2.pushBack(2);
    head2 = ls2.pushBack(4);
    head2 = ls2.pushBack(9);

    cout<<"The first Linked List"<<endl;
    ls.display(head1);

    cout<<"The second Linked List"<<endl;
    ls.display(head2);

    cout<<"Using the Iterative approach"<<endl;
    ansHead = ls.addTwoNumbers(head1, head2);
    ls.display(ansHead);

    cout<<"Using the Recursive approach"<<endl;
    ansHead = ls.addTwoNumbersRecursively(head1, head2);
    ls.display(ansHead);

    return 0;
}
