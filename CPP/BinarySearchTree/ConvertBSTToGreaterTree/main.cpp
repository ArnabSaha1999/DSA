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

// In-order traversal of a binary tree to calculate and store the cumulative sum of values in 'ans' vector, with the current sum 'currSum' passed by reference
void inorderTraversal(Node* root, vector<int> &ans, int &currSum) {
    if(!root) {
        // Base case: Return when the node is null
        return;
    }
    // Traverse the right subtree
    inorderTraversal(root->right, ans, currSum);
    // Add the current node's value to the cumulative sum
    currSum += root->value;
    // Store the cumulative sum in the 'ans' vector
    ans.push_back(currSum);
    // Traverse the left subtree
    inorderTraversal(root->left, ans, currSum);
}

// Update the values of a binary search tree (BST) with values from 'arr'
void updateBST(Node* root, vector<int> &arr) {
    if(!root) {
        // Base case: Return when the node is null
        return;
    }
    // Update the left subtree
    updateBST(root->left, arr);
    // Assign the last value from 'arr' to the current node
    root->value = arr.back();
    // Remove the last value from 'arr'
    arr.pop_back();
    // Update the right subtree
    updateBST(root->right, arr);
}

//Approach 1: Convert a binary search tree (BST) into a Greater Sum Tree (GST)
Node* convertBST(Node* root) {
    if(!root) {
        // Base case: Return null if the tree is empty
        return nullptr;
    }
    // Create a vector to store cumulative sums
    vector<int> inorderAns;
    // Initialize the current sum
    int currSum = 0;
    // Calculate cumulative sums
    inorderTraversal(root, inorderAns, currSum);
    // Update the BST values with cumulative sums
    updateBST(root, inorderAns);
    // Return the root of the GST
    return root;
}

// Helper function to convert a BST into a Greater Sum Tree (GST)
void convertBSTHelper(Node* root, int &currGreaterSum) {
    if(!root) {
        // Base case: Return when the node is null
        return;
    }
    // Traverse the right subtree
    convertBSTHelper(root->right, currGreaterSum);
    // Update the current greater sum
    currGreaterSum += root->value;
    // Update the current node's value with the greater sum
    root->value = currGreaterSum;
    // Traverse the left subtree
    convertBSTHelper(root->left, currGreaterSum);
}

//Approach 2: Convert a binary search tree (BST) into a Greater Sum Tree (GST) using an optimized approach
Node* convertBSTOptimized(Node* root) {
    if(!root) {
        // Base case: Return null if the tree is empty
        return nullptr;
    }
    // Initialize the current greater sum
    int currGreaterSum = 0;
    // Convert the BST to GST
    convertBSTHelper(root, currGreaterSum);
    // Return the root of the GST
    return root;
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
    root = insertBST(root, 4);
    root = insertBST(root, 1);
    root = insertBST(root, 6);
    root = insertBST(root, 0);
    root = insertBST(root, 2);
    root = insertBST(root, 5);
    root = insertBST(root, 7);
    root = insertBST(root, 3);
    root = insertBST(root, 8);
    
    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    cout<<endl<<"Using The Brute Force Approach"<<endl;
    root = convertBST(root);

    cout<<"The Level Order Traversal of Greater Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Greater Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Greater Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Greater Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    root = nullptr;
    root = insertBST(root, 4);
    root = insertBST(root, 1);
    root = insertBST(root, 6);
    root = insertBST(root, 0);
    root = insertBST(root, 2);
    root = insertBST(root, 5);
    root = insertBST(root, 7);
    root = insertBST(root, 3);
    root = insertBST(root, 8);

    cout<<endl<<"Using The Optimized Approach"<<endl;
    root = convertBSTOptimized(root);

    cout<<"The Level Order Traversal of Greater Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Greater Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Greater Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Greater Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;
    
    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
