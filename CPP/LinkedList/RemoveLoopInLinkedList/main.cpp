#include<iostream>
#include<unordered_map>

using namespace std;

// A Node class with pointer next
class Node {
public:
    Node* next;
    int value;
    //Constructor: creates new node when called
    Node(int value) {
        this->value = value;
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

// Approach 1: Hash Set (unordered_map) for Cycle Detection
// Time Complexity: O(n), where n is the number of nodes in the linked list
// Space Complexity: O(n), a hash map is used to store visited nodes
Node* detectCycleHashMap(Node* &head) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node* currNode = head;
    unordered_map<Node*, bool> visited;
    while(currNode != nullptr) {
        if(visited[currNode]) {
            return currNode; // Cycle detected
        }
        visited[currNode] = true;
        currNode = currNode->next;
    }
    return nullptr; // No cycle detected
}

// Approach 2: Floyd's Cycle Detection Algorithm (Tortoise and Hare)
// Time Complexity: O(n), where n is the number of nodes in the linked list
// Space Complexity: O(1), only a constant amount of extra space is used
Node* detectCycle(Node* &head) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr; // No cycle detected
}

//Function to remove a detected loop from the linked list.
//Time complexity: O(n) incase of both the approaches.
//Space complexity: O(1) incase of Floyd's algorithm but O(n) incase of unordered_map approach.
Node* removeLoop(Node* head) {
    // Node* startOfLoop = detectCycleHashMap(head);
    Node* startOfLoop = detectCycle(head);
    if(!startOfLoop) {
        return head;
    }
    Node* temp = startOfLoop;
    while(temp->next != startOfLoop) {
        temp = temp->next;
    }
    temp->next = nullptr;
    return head;
}

int main() {
    // Creating a singly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = nullptr;
    cout<<"Applying Cycle detection approaches on singly linkedlist."<<endl;

    head = removeLoop(head);
    display(head);

    // Creating a Circular linked list
    Node* CyclicHead = new Node(1);
    CyclicHead->next = new Node(2);
    CyclicHead->next->next = new Node(3);
    CyclicHead->next->next->next = new Node(4);
    CyclicHead->next->next->next->next = new Node(5);
    CyclicHead->next->next->next->next->next = CyclicHead->next;
    cout<<"Applying Cycle detection approaches on Circular linkedlist."<<endl;

    CyclicHead = removeLoop(CyclicHead);
    display(CyclicHead);

    // Clean up memory
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    delete CyclicHead->next->next->next->next;
    delete CyclicHead->next->next->next;
    delete CyclicHead->next->next;
    delete CyclicHead->next;
    delete CyclicHead;

    return 0;

}
