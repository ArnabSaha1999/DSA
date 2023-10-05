#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>

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

// Helper function to traverse and collect nodes along the left boundary
void traverseLeft(Node* root, vector<int> &ans) {
    // If the node is null or it's a leaf node, return.
    if(!root || (!root->left && !root->right)) {
        return;
    }
    // Add the current node's value to the boundary.
    ans.push_back(root->value);
    // Recursively traverse the left subtree if it exists, otherwise, traverse the right subtree.
    if(root->left) {
        traverseLeft(root->left, ans);
    } else {
        traverseLeft(root->right, ans);
    }
}

// Helper function to traverse and collect leaf nodes.
void traverseLeaf(Node* root, vector<int> &ans) {
    // If the node is null, return.
    if(!root) {
        return;
    }
    // If the node is a leaf node, add its value to the boundary.
    if(!root->left && !root->right) {
        ans.push_back(root->value);
    }
    // Recursively traverse the left and right subtrees.
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

// Helper function to traverse and collect nodes along the right boundary.
void traverseRight(Node* root, vector<int> &ans) {
    // If the node is null or it's a leaf node, return.
    if(!root || (!root->left && !root->right)) {
        return;
    }
    // Recursively traverse the right subtree if it exists, otherwise, traverse the left subtree.
    if(root->right) {
        traverseRight(root->right, ans);
    } else {
        traverseRight(root->left, ans);
    }
    // Add the current node's value to the boundary.
    ans.push_back(root->value);
}

//Approach 1: Main function to collect the boundary nodes of the binary tree.
vector<int> boundaryTraversal(Node *root){
    vector<int> ans;
    // If the tree is empty, return an empty result.
    if(!root) {
        return ans;
    }
    // Add the root node to the result as it's always part of the boundary.
    ans.push_back(root->value);
    // Traverse and collect nodes along the left boundary.
    traverseLeft(root->left, ans);
    // Traverse and collect leaf nodes in the left and right subtrees.
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    // Traverse and collect nodes along the right boundary.
    traverseRight(root->right, ans);
    
    return ans;
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
    Node* root;
    root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(11);
    root->left->left->left = new Node(9);
    root->left->left->right = new Node(12);
    root->left->right = new Node(1);
    root->right = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(13);
    root->right->right->right = new Node(15);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Boundary Traversal Of Binary Tree: "<<endl;
    vector<int> ans = boundaryTraversal(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
