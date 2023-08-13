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

// Approach: Hash Set (unordered_map) for Cycle Detection
// Time Complexity: O(n), where n is the number of nodes in the linked list
// Space Complexity: O(n), a hash map is used to store visited nodes
bool hasCycleHashMap(Node* &head) {
    if(head == nullptr || head->next == nullptr) {
        return false;
    }
    Node* currNode = head;
    unordered_map<Node*, bool> visited;
    while(currNode != nullptr) {
        if(visited[currNode]) {
            return true; // Cycle detected
        }
        visited[currNode] = true;
        currNode = currNode->next;
    }
    return false; // No cycle detected
}

// Approach 2: Floyd's Cycle Detection Algorithm (Tortoise and Hare)
// Time Complexity: O(n), where n is the number of nodes in the linked list
// Space Complexity: O(1), only a constant amount of extra space is used
bool hasCycle(Node* &head) {
    if(head == nullptr || head->next == nullptr) {
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true; // Cycle detected
        }
    }
    return false; // No cycle detected
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

    cout<<"Applying Floyd's Cycle Detection Algorithm."<<endl;
    if(hasCycle(head)) {
        cout<<"Cycle detected."<<endl;
    } else {
        cout<<"Cycle not detected."<<endl;
    }

    cout<<"Applying HashSet approach to find Cycle."<<endl;
    if(hasCycleHashMap(head)) {
        cout<<"Cycle detected."<<endl;
    } else {
        cout<<"Cycle not detected."<<endl;
    }

    // Creating a Circular linked list
    Node* CyclicHead = new Node(1);
    CyclicHead->next = new Node(2);
    CyclicHead->next->next = new Node(3);
    CyclicHead->next->next->next = new Node(4);
    CyclicHead->next->next->next->next = new Node(5);
    CyclicHead->next->next->next->next->next = CyclicHead->next;
    cout<<"Applying Cycle detection approaches on Circular linkedlist."<<endl;

    cout<<"Applying Floyd's Cycle Detection Algorithm."<<endl;
    if(hasCycle(CyclicHead)) {
        cout<<"Cycle detected."<<endl;
    } else {
        cout<<"Cycle not detected."<<endl;
    }

    cout<<"Applying HashSet approach to find Cycle."<<endl;
    if(hasCycleHashMap(CyclicHead)) {
        cout<<"Cycle detected."<<endl;
    } else {
        cout<<"Cycle not detected."<<endl;
    }

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
