#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

// A ListNode class with pointer next
class ListNode {
public:
    ListNode* next;
    int value;
    //Constructor: creates new node when called
    ListNode(int value) {
        this->value = value;
    } 
};

// Define a class for binary tree nodes
class Node {
public:
    Node* left;
    Node* right;
    int value;
    // Constructor to initialize a node with a given value
    Node(int value) {
        this->value = value;
        this->left = this->right = nullptr;
    }
};

// Public function to perform level-order traversal
void levelOrderTraversal(Node* root) {
    if(!root) {
        cout<<"Binary Tree is empty"<<endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    int level = 0;
    // Begin the level-order traversal
    while(!q.empty()) {
        // Get the number of nodes at the current level
        int size = q.size();
        // Print the current level
        cout<<"Level "<<level++<<": ";
        // Process nodes at the current level
        for(int i = 0; i < size; i++) {
            // Get the front node from the queue
            Node* temp = q.front();
            // Remove the front node from the queue
            q.pop();
            // Enqueue the left child if it exists
            if(temp->left) {
                q.push(temp->left);
            }
            // Enqueue the right child if it exists
            if(temp->right) {
                q.push(temp->right);
            }
            cout<<temp->value<<" "; // Print the value of the current node
        }
        // Move to the next level (line break)
        cout<<endl;
    }
}

// Function to perform an in-order traversal of the binary search tree
void inorderTraversal(Node* root) {
    if(!root) {
        return;
    }
    // Traverse the Left child
    inorderTraversal(root->left);
    // Print the Root value
    cout<<root->value<<" ";
    // Traverse the Right child
    inorderTraversal(root->right);
}

// Function to perform a pre-order traversal of the binary search tree
void preorderTraversal(Node* root) {
    if(!root) {
        return;
    }
    // Print the Root value
    cout<<root->value<<" ";
    // Traverse the Left child
    preorderTraversal(root->left);
    // Traverse the Right child
    preorderTraversal(root->right);
}

// Function to perform a post-order traversal of the binary search tree
void postorderTraversal(Node* root) {
    if(!root) {
        return;
    }
    // Traverse the Left child
    postorderTraversal(root->left);
    // Traverse the Right child
    postorderTraversal(root->right);
    // Print the Root value
    cout<<root->value<<" ";
}

// Function to print a sorted linked list from its head
void printSortedLinkedList(ListNode* head) {
    ListNode* currNode = head;
    while(currNode->next) {
        // Print the current node's value
        cout<<currNode->value<<" -> ";
        // Move to the next node on the right
        currNode = currNode->next;
    }
    // Print the last node's value
    cout<<currNode->value<<endl;
}

// Function to find the middle of a linked list and split it, returns the middle node and sets prevNode to the previous node
ListNode* findMiddle(ListNode* head, ListNode* &prevNode) {
    ListNode* slowNode = head;
    ListNode* fastNode = head;
    while(fastNode->next && fastNode->next->next) {
        // Set the previous node before moving
        prevNode = slowNode;
        // Move slowNode one step
        slowNode = slowNode->next;
        // Move fastNode two steps
        fastNode = fastNode->next->next;
    }
    // Return the middle node
    return slowNode;
}

// Recursive function to convert a sorted linked list to a balanced binary search tree
Node* solve(ListNode* head) {
    if(!head) {
        // If the linked list is empty, return a null pointer
        return nullptr;
    }
    ListNode* prevNode = nullptr;
    // Find the middle node of the linked list
    ListNode* middle = findMiddle(head, prevNode);
    // Get the node after the middle
    ListNode* nextNode = middle->next;
    // Disconnect the middle node
    middle->next = nullptr;
    // Create a new node for the middle value
    Node* root = new Node(middle->value);
    if(prevNode) {
        // If there is a previous node, disconnect it
        prevNode->next = nullptr;
        // Recursively build the left subtree
        root->left = solve(head);
    }
    if(nextNode) {
        // Recursively build the right subtree
        root->right = solve(nextNode);
    }
    // Return the root of the binary search tree
    return root;
}

//Approach 1: Function to start the process of converting a sorted linked list to a balanced binary search tree
Node* sortedListToBST(ListNode* head) {
    if(!head) {
        // If the linked list is empty, return a null pointer
        return nullptr;
    }
    // Call the solve function to perform the conversion
    return solve(head);
}

// Function to delete the binary tree to free memory
void deleteTree(Node* root) {
    if (!root) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = nullptr;

    cout<<"The Input Linked Linked List"<<endl;
    printSortedLinkedList(head);

    Node* root = sortedListToBST(head);
    
    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;
    
    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
