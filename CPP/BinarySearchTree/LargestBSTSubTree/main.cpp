#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

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

// Function to check if a binary tree rooted at 'root' is a valid BST with values in the range [mini, maxi]
bool isBST(Node* root, int mini, int maxi) {
    if(!root) {
        // An empty tree is a valid BST
        return true;
    }
    if(root->value <= mini || root->value >= maxi) {
        // If the current node's value is outside the valid range, it's not a BST
        return false;
    }
    // Recursively check the left and right subtrees with updated min and max values
    return isBST(root->left, mini, root->value) && isBST(root->right, root->value, maxi);
}

// Function to calculate the size (number of nodes) of a binary tree rooted at 'root'
int getSize(Node* root) {
    if(!root) {
        // An empty tree has a size of 0
        return 0;
    }
    if(!root->left && !root->right) {
        // A leaf node has a size of 1
        return 1;
    }
    // Recursively calculate the size by adding the sizes of left and right subtrees
    return 1 + getSize(root->left) + getSize(root->right);
}

//Approach 1: Function to find the largest BST subtree within a binary tree using a brute-force approach
int largestBSTBruteForce(Node * root) {
    if(!root) {
        // An empty tree has no BST
        return 0;
    }
    // Check if the entire tree is a valid BST; if yes, return its size
    if(isBST(root, INT_MIN, INT_MAX)) {
        return getSize(root);
    }
    // If the entire tree is not a valid BST, find the largest BST in its left and right subtrees
    return max(largestBSTBruteForce(root->left), largestBSTBruteForce(root->right));
}

// Class to store information about a tree's subtree
class Info {
    public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

// Helper function to find the largest BST subtree within a binary tree
Info largestBSTHelper(Node* root, int &maxSize) {
    if(!root) {
        // An empty tree is a valid BST with no size
        return {INT_MAX, INT_MIN, true, 0};
    }
    
    Info leftTree = largestBSTHelper(root->left, maxSize);
    Info rightTree = largestBSTHelper(root->right, maxSize);
    Info currNode;
    // Calculate the size of the current subtree by summing the sizes of left and right subtrees and adding 1 for the current node
    currNode.size = leftTree.size + rightTree.size + 1;
    // Determine the minimum and maximum values within the current subtree
    currNode.mini = min(root->value, leftTree.mini);
    currNode.maxi = max(root->value, rightTree.maxi);
    // Check if the subtree rooted at the current node is a valid BST
    if(leftTree.isBST && rightTree.isBST && (root->value > leftTree.maxi && root->value < rightTree.mini)) {
        currNode.isBST = true;
        maxSize = max(maxSize, currNode.size);
    } else {
        currNode.isBST = false;
    }
    return currNode;
}

//Approach 2: Function to find the largest BST subtree within a binary tree using an optimized approach
int largestBST(Node * root){
    if(!root) {
        // An empty tree has no BST
        return 0;
    }
    int maxSize = 0;
    largestBSTHelper(root, maxSize);
    return maxSize;
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

    cout<<"The Largest BST Nodes using the Brute Force Approach: "<<largestBSTBruteForce(root)<<endl;

    cout<<"The Largest BST Nodes using the Optimized Approach: "<<largestBST(root)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
