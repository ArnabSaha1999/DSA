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

//Approach 1: Function to find the minimum value in the BST using a recursive approach
int minValueRecursive(Node* root) {
    if(!root) {
        // Return -1 for an empty tree
        return -1;
    }
    if(!root->left) {
        // The leftmost leaf node contains the minimum value
        return root->value;
    }
    // Recursively check the left subtree
    return minValueRecursive(root->left);
}

//Approach 2: Function to find the minimum value in the BST using an iterative approach
int minValueIterative(Node* root) {
    if(!root) {
        // Return -1 for an empty tree
        return -1;
    }
    Node* currNode = root;
    while(currNode->left) {
        // Traverse to the leftmost node in the tree
        currNode = currNode->left;
    }
    return currNode->value;
}

//Approach 1: Recursive function to find the maximum value in the BST
int maxValueRecursive(Node* root) {
    if(!root) {
        // Return -1 for an empty tree
        return -1;
    }
    if(!root->right) {
        // The rightmost leaf node contains the maximum value
        return root->value;
    }
    // Recursively check the right subtree
    return maxValueRecursive(root->right);
}

//Approach 2: Iterative function to find the maximum value in the BST
int maxValueIterative(Node* root) {
    if(!root) {
        // Return -1 for an empty tree
        return -1;
    }
    Node* currNode = root;
    while(currNode->right) {
        // Traverse to the rightmost node in the tree
        currNode = currNode->right;
    }
    return currNode->value;
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

    cout<<"The Minimum Value of BST using Recursive Approach: "<<minValueRecursive(root)<<endl;
    cout<<"The Minimum Value of BST using Iterative Approach: "<<minValueIterative(root)<<endl;
    
    cout<<"The Maximum Value of BST using Recursive Approach: "<<maxValueRecursive(root)<<endl;
    cout<<"The Maximum Value of BST using Iterative Approach: "<<maxValueIterative(root)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
