#include<iostream>
#include<string>
#include<stack>
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

    //Approach 1: Brute Force Approach: Convert the linked list to a string and check if it's a palindrome
    bool checkPalindromeBruteForce(Node* head) {
        // An empty or single-node list is considered a palindrome
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        string str = "";
        Node* currNode = head;
        // Convert linked list elements to string
        while(currNode != nullptr) {
            str.push_back(currNode->value);
            currNode = currNode->next;
        }

        int start = 0, end = str.length() - 1;
        while(start < end) {
            if(str[start++] != str[end--]) {
                // If characters don't match, it's not a palindrome
                return false;
            }
        }
        // If all characters matched, it's a palindrome
        return true;
    }

    //Approach 2: Stack Approach: Push elements onto a stack, then pop and compare with the linked list
    bool checkPalindromeUsingStack(Node* head) {
        // An empty or single-node list is considered a palindrome
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        stack<Node*> st;
        Node* currNode = head;
        while(currNode != nullptr) {
            // Push each element onto the stack
            st.push(currNode);
            currNode = currNode->next;
        }

        currNode = head;
        while(!st.empty()) {
            if(currNode->value != st.top()->value){
                // If values don't match, it's not a palindrome
                return false;
            }
            currNode = currNode->next;
            st.pop();
        }
        // If all values matched, it's a palindrome
        return true;
    }

    //Helper function: Find the middle node of the linked list
    Node* findMid(Node* head) {
        Node* slowNode = head;
        Node* fastNode = head;
        while(fastNode->next != nullptr && fastNode->next->next != nullptr) {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }
        return slowNode;
    }
    
    //Helper function: Reverse a linked list and update head
    Node* reverseList(Node* &head) {
        Node* prevNode = nullptr;
        Node* nextNode = nullptr;
        Node* currNode = head;
        while(currNode != nullptr) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
        return head;
    }

    //Approach 3: Optimized Approach: Reverse the second half and compare with the first half
    bool checkPalindromeOptimized(Node* head) {
        // An empty or single-node list is considered a palindrome
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        // Find the middle node
        Node* midNode = findMid(head);
        // Reverse the second half
        midNode->next = reverseList(midNode->next);
        Node* firstHalf = head;
        Node* secondHalf = midNode->next;
        while(secondHalf != nullptr) {
            if(firstHalf->value != secondHalf->value) {
                // Restore the original list structure
                midNode->next = reverseList(midNode->next);
                // If values don't match, it's not a palindrome
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        // Restore the original list structure
        midNode->next = reverseList(midNode->next);
        // If all values matched, it's a palindrome
        return true;
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
    Node *head;
    head = ls.pushBack(1);
    head = ls.pushBack(3);
    head = ls.pushBack(7);
    head = ls.pushBack(9);
    head = ls.pushBack(7);
    head = ls.pushBack(3);
    head = ls.pushBack(1);

    cout<<"Displaying Linked List"<<endl;
    ls.display(head);

    cout<<"Using the Brute Force approach"<<endl;
    bool ans = ls.checkPalindromeBruteForce(head);
    if(!ans) {
        cout<<"The Linked List is not Palindrome"<<endl;
    } else {
        cout<<"The Linked List is Palindrome"<<endl;
    }

    cout<<"Using the Stack approach"<<endl;
    ans = ls.checkPalindromeUsingStack(head);
    if(!ans) {
        cout<<"The Linked List is not Palindrome"<<endl;
    } else {
        cout<<"The Linked List is Palindrome"<<endl;
    }

    cout<<"Using the Reverse and Compare approach"<<endl;
    ans = ls.checkPalindromeOptimized(head);
    if(!ans) {
        cout<<"The Linked List is not Palindrome"<<endl;
    } else {
        cout<<"The Linked List is Palindrome"<<endl;
    }

    return 0;
}
