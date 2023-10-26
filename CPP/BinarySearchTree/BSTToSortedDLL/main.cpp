#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

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

// Function to insert a value into the binary search tree
Node* insertBST(Node* &root, int value) {
    if(!root) {
        // Create a new node if the tree is empty
        root = new Node(value);
        return root;
    }
    if(root->value == value) {
        // Value already exists, no changes needed
        return root;
    } else if(root->value > value) {
        // Recursively insert into the left subtree
        insertBST(root->left, value);
    } else {
        // Recursively insert into the right subtree
        insertBST(root->right, value);
    }
    return root;
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

// Function to print a sorted doubly linked list from its head
void printSortedDLL(Node* head) {
    Node* currNode = head;
    while(currNode->right) {
        // Print the current node's value
        cout<<currNode->value<<" -> ";
        // Move to the next node on the right
        currNode = currNode->right;
    }
    // Print the last node's value
    cout<<currNode->value<<endl;
}

// In-order traversal of a binary search tree using Morris Traversal and store nodes
void inorderTraversal(Node* root, vector<Node*> &ans) {
    Node* currNode = root;
    while(currNode) {
        // If the current node has no left child, visit it and move to its right child
        if(!currNode->left) {
            ans.push_back(currNode);
            currNode = currNode->right;
        } else {
            // If the current node has a left child, find its in-order predecessor
            Node* predecessor = currNode->left;
            // Traverse to the rightmost node of the left subtree if not visited already
            while(predecessor->right && predecessor->right != currNode) {
                predecessor = predecessor->right;
            }
            // If the predecessor's right child is not assigned, assign it to the current node
            if(!predecessor->right) {
                predecessor->right = currNode;
                currNode = currNode->left;
            } else {
                // If the predecessor's right child is already assigned, visit the current node and then move to its right child
                predecessor->right = nullptr;
                ans.push_back(currNode);
                currNode = currNode->right;
            }
        }
    }
}

//Approach 1: Convert a Binary Search Tree (BST) to a sorted doubly linked list using in-order traversal
Node* bstToSortedDLL(Node* root) {
	if(!root) {
        // Return null if the tree is empty
        return root;
    }
    vector<Node*> inorderAns;
    // Perform in-order traversal
    inorderTraversal(root, inorderAns);
    // The head of the doubly linked list
    Node* newHead = inorderAns[0];
    Node* tempNode = newHead;
    for(int i = 1; i < inorderAns.size(); i++) {
        // Get the next node in sorted order
        Node* newNode = inorderAns[i];
        // Set the 'right' pointer of the current node
        tempNode->right = newNode;
        // Set the 'left' pointer of the next node
        newNode->left = tempNode;
        // Move to the next node
        tempNode = newNode;
    }
    // Set the 'right' pointer of the last node to null
    tempNode->right = nullptr;
    // Return the head of the sorted doubly linked list
    return newHead;
}

// Convert a Binary Search Tree (BST) to a sorted doubly linked list using in-order traversal
void covertBSTToSortedDoublyLinkedList(Node* root, Node* &head) {
    if(!root) {
        // Base case: If the current node is null, return
        return;
    }
    // Recursive call to traverse the right subtree first
    covertBSTToSortedDoublyLinkedList(root->right, head);
    // Make the current node the new head of the doubly linked list
    root->right = head;
    if(head) {
        head->left = root;
    } 
    head = root;
    // Recursive call to traverse the left subtree
    covertBSTToSortedDoublyLinkedList(root->left, head);
}

//Approach 2: Convert a Binary Search Tree (BST) to a sorted doubly linked list using an optimized approach
Node* bstToSortedDLLOptimized(Node* root) {
	if(!root) {
        // Return null if the tree is empty
        return root;
    }
    Node* head = nullptr;
    // Convert the BST to a sorted doubly linked list
    covertBSTToSortedDoublyLinkedList(root, head);
    // Return the head of the sorted doubly linked list
    return head;
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
    Node* root = nullptr;
    root = insertBST(root, 10);
    root = insertBST(root, 7);
    root = insertBST(root, 17);
    root = insertBST(root, 5);
    root = insertBST(root, 19);
    root = insertBST(root, 15);
    root = insertBST(root, 3);
    root = insertBST(root, 1);
    root = insertBST(root, 13);

    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    Node* head = bstToSortedDLL(root);

    cout<<"The Sorted Doubly Linked List: "<<endl;
    printSortedDLL(head);

    root = nullptr;
    root = insertBST(root, 10);
    root = insertBST(root, 7);
    root = insertBST(root, 17);
    root = insertBST(root, 5);
    root = insertBST(root, 19);
    root = insertBST(root, 15);
    root = insertBST(root, 3);
    root = insertBST(root, 1);
    root = insertBST(root, 13);
    
    head = bstToSortedDLLOptimized(root);

    cout<<"The Sorted Doubly Linked List Using Optimized Approach: "<<endl;
    printSortedDLL(head);
    
    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}

