#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

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

// In-order traversal of a binary search tree using Morris Traversal and store values
void inorderTraversal(Node* root, vector<int> &ans) {
    Node* currNode = root;
    while(currNode) {
        // If the current node has no left child, visit it and move to its right child
        if(!currNode->left) {
            ans.push_back(currNode->value);
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
                ans.push_back(currNode->value);
                currNode = currNode->right;
            }
        }
    }
}

// Update the binary search tree (BST) nodes with values from 'arr' using in-order traversal
void updateBST(Node* root, vector<int> &arr, int &index) {
    if(!root) {
        // Base case: Return when the node is null
        return;
    }
    // Update the left subtree
    updateBST(root->left, arr, index);
    // Assign the value from 'arr' to the current node
    root->value = arr[index++];
    // Update the right subtree
    updateBST(root->right, arr, index);
}

//Approach 1: Recover a binary search tree (BST) with two swapped nodes
void recoverTree(Node* root) {
    if(!root) {
        // Base case: Return when the tree is empty
        return;
    }
    // Create a vector to store in-order traversal results
    vector<int> inorderAns;
    // Perform in-order traversal and store the values
    inorderTraversal(root, inorderAns);
    // Sort the in-order values
    sort(inorderAns.begin(), inorderAns.end());
    // Initialize an index for 'arr'
    int index = 0;
    // Update the BST with sorted values
    updateBST(root, inorderAns, index);
}

// Helper function to recover a binary search tree (BST) with two swapped nodes
void recoverBSTHelper(Node* root, Node* &first, Node* &last, Node* &prev) {
    if(!root) {
        // Base case: Return when the node is null
        return;
    }
    // Traverse the left subtree
    recoverBSTHelper(root->left, first, last, prev);
    if(prev && root->value < prev->value) {
        if(!first) {
            // Identify the first misplaced node
            first = prev;
            // Identify the last misplaced node
            last = root;
        } else {
            // Update the last misplaced node
            last = root;
        }
    }
    // Update the previous node
    prev = root;
    // Traverse the right subtree
    recoverBSTHelper(root->right, first, last, prev);
}

//Approach 2: Recover a binary search tree (BST) with two swapped nodes using an optimized approach
void recoverTreeOptimized(Node* root) {
    if(!root) {
        // Base case: Return when the tree is empty
        return;
    }
    // Initialize the first misplaced node
    Node* first = nullptr;
    // Initialize the last misplaced node
    Node* last = nullptr;
    // Initialize the previous node
    Node* prev = nullptr;
    // Identify misplaced nodes
    recoverBSTHelper(root, first, last, prev);
    if(first && last)
    // Swap the values of the misplaced nodes
    swap(first->value, last->value);
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
    root = new Node(1);
    root->left = new Node(7);
    root->right = new Node(17);
    root->left->left = new Node(5);
    root->right->left = new Node(15);
    root->right->right = new Node(19);
    root->left->left->left = new Node(3);
    root->right->left->left = new Node(13);
    root->left->left->left->left = new Node(10);
    
    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    cout<<endl<<"Using The Brute Force Approach To Recover BST"<<endl;
    recoverTree(root);

    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    root = nullptr;
    root = new Node(1);
    root->left = new Node(7);
    root->right = new Node(17);
    root->left->left = new Node(5);
    root->right->left = new Node(15);
    root->right->right = new Node(19);
    root->left->left->left = new Node(3);
    root->right->left->left = new Node(13);
    root->left->left->left->left = new Node(10);

    cout<<endl<<"Using The Optimized Approach To Recover BST"<<endl;
    recoverTreeOptimized(root);

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
