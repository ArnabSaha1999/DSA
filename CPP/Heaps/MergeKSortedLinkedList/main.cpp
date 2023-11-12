#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// Define a class for a singly linked list node
class Node {
    public:
    Node* next;
    int value;
    // Constructor to initialize a node with a value
    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

// Function to print a linked list
void printLinkedList(Node* head) {
    Node* currNode = head;
    while(currNode) {
        cout<<currNode->value;
        if(currNode->next) {
            cout<<"->";
        }
        currNode = currNode->next;
    } cout<<endl;
}

//Approach 1: Merge K sorted linked lists using a brute force approach
Node* mergeKListsBruteForce(vector<Node*> &lists) {
    Node* currNode = nullptr;
    vector<int> ans;
    // Flatten all the linked lists into a single vector
    for(int i = 0; i < lists.size(); i++) {
        currNode = lists[i];
        while(currNode) {
            ans.push_back(currNode->value);
            currNode = currNode->next;
        }
    }
    // Sort the values in the vector
    sort(ans.begin(), ans.end());
    // Create a new linked list from the sorted values
    if(ans.empty()) {
        return nullptr;
    }
    // Create a new linked list from a sorted vector of values
    Node* newHead = new Node(ans[0]);
    currNode = newHead;
    // Iterate through the sorted values starting from the second value
    for(int i = 1; i < ans.size(); i++) {
        // Create a new node with the current value
        Node* newNode = new Node(ans[i]);
        // Set the current node's next pointer to the new node
        currNode->next = newNode;
        // Move the current node to the new node
        currNode = newNode;
    }
    currNode->next = nullptr;
    // Return the head of the newly created linked list
    return newHead;
}

// Comparator class to use with the priority_queue for heap-based merging
class CompareNodes {
    public:
    bool operator() (Node *first, Node *second) {
        return first->value > second->value;
    }
};

//Approach 2: Merge K sorted linked lists using a min-heap approach
Node* mergeKListsUsingHeap(vector<Node*> &lists) {
    int size = lists.size();
    if(size == 0) {
        return nullptr;
    }
    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;
    // Add the head nodes of each list to the min-heap
    for(int i = 0; i < size; i++) {
        if(lists[i]) {
            minHeap.push(lists[i]);
        }
    }
    Node* mergedHead = nullptr;
    Node* tailNode = mergedHead;
    // Merge the lists by repeatedly taking the smallest node from the heap
    while(!minHeap.empty()) {
        Node *currNode = minHeap.top();
        minHeap.pop();
        if(!mergedHead) {
            // If this is the first node in the merged list, initialize mergedHead and tailNode
            mergedHead = tailNode = currNode;
            // If the current node has a next node, push it back into the heap
            if(tailNode->next) {
                minHeap.push(tailNode->next);
            }
        } else {
            // If the merged list already has nodes, append the current node to the end
            tailNode->next = currNode;
            tailNode = currNode;
            // If the current node has a next node, push it back into the heap
            if(tailNode->next) {
                minHeap.push(tailNode->next);
            }
        }
    }
    if(tailNode) {
        tailNode->next = nullptr;
    }
    return mergedHead;
}

// Merge two sorted linked lists
Node* mergeTwoSortedList(Node* l1, Node* l2) {
    if(!l1) {
        return l2;
    }
    if(!l2) {
        return l1;
    }
    Node* mergedHead = nullptr;
    Node* tailNode = mergedHead;
    // Merge the two lists while maintaining the sorted order
    while(l1 && l2) {
        if(l1->value <= l2->value) {
            if(!mergedHead) {
                mergedHead = tailNode = l1;
            } else {
                tailNode->next = l1;
                tailNode = l1;
            }
            l1 = l1->next;
        } else {
            if(!mergedHead) {
                mergedHead = tailNode = l2;
            } else {
                tailNode->next = l2;
                tailNode = l2;
            }
            l2 = l2->next;
        }
    }
    // Append any remaining nodes from both lists
    while(l1) {
        if(!mergedHead) {
            mergedHead = tailNode = l1;
        } else {
            tailNode->next = l1;
            tailNode = l1;
        }
        l1 = l1->next;
    }
    while(l2) {
        if(!mergedHead) {
            mergedHead = tailNode = l2;
        } else {
            tailNode->next = l2;
            tailNode = l2;
        }
        l2 = l2->next;
    }
    if(tailNode) {
        tailNode->next = nullptr;
    }
    return mergedHead;
}

// Helper function for the divide and conquer approach
Node* mergeKListHelper(vector<Node*> &lists, int start, int end) {
    // Base case: If there's only one list or none, return it
    if(start >= end) {
        return lists[start];
    }
    // Base case: If there are two lists, merge them using mergeTwoSortedList
    if(start + 1 == end) {
        return mergeTwoSortedList(lists[start], lists[end]);
    }
    int mid = start + (end - start) / 2;
    // Recursively merge the left and right halves of the range
    Node* leftList = mergeKListHelper(lists, start, mid);
    Node* rightList = mergeKListHelper(lists, mid + 1, end);
    // Merge the two resulting halves
    return mergeTwoSortedList(leftList, rightList);
}

//Approach 3: Merge K sorted linked lists using a divide and conquer approach
Node* mergeKListsDivideAndConquer(vector<Node*> &lists) {
    if(lists.size() == 0) {
        return nullptr;
    }
    return mergeKListHelper(lists, 0, lists.size() - 1);
}

int main() {
    Node* head1 = nullptr;
    head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(5);

    Node* head2 = nullptr;
    head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);

    Node* head3 = nullptr;
    head3 = new Node(2);
    head3->next = new Node(6);

    vector<Node*> arr = {head1, head2, head3};
    cout<<"The Input Linked Lists: "<<endl;
    for(Node* currNode : arr) {
        printLinkedList(currNode);
    }

    cout<<endl<<"Using the Brute Force Approach: "<<endl;
    Node* ans = mergeKListsBruteForce(arr);
    printLinkedList(ans);
    
    head1 = nullptr;
    head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(5);

    head2 = nullptr;
    head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);

    head3 = nullptr;
    head3 = new Node(2);
    head3->next = new Node(6);

    arr = {head1, head2, head3};

    cout<<endl<<"Using the Heap Approach: "<<endl;
    ans = mergeKListsUsingHeap(arr);
    printLinkedList(ans);
    
    head1 = nullptr;
    head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(5);

    head2 = nullptr;
    head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);

    head3 = nullptr;
    head3 = new Node(2);
    head3->next = new Node(6);

    arr = {head1, head2, head3};

    cout<<endl<<"Using the Divide And Conquer Approach: "<<endl;
    ans = mergeKListsDivideAndConquer(arr);
    printLinkedList(ans);

    return 0;
}
