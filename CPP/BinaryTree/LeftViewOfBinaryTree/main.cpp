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

// Helper function for recursive left view traversal.
void leftViewHelper(Node* root, vector<int> &ans, int level) {
    if(!root) {
        return;
    }
    // Check if the current level is equal to the size of ans vector.
    // If they are equal, it means this is the leftmost node at this level.
    if(ans.size() == level) {
        // Add the value of the leftmost node to the ans vector.
        ans.push_back(root->value);
    }
    // Recursively traverse the left subtree first, followed by the right subtree.
    leftViewHelper(root->left, ans, level + 1);
    leftViewHelper(root->right, ans, level + 1);
}

//Approach 1: Function to print Left View of a binary tree using a recursive approach.
vector<int> leftViewRecursively(Node *root) {
    vector<int> ans;
    // If the tree is empty, return an empty result.
    if(!root) {
        return ans;
    }
    // Initialize ans vector with the root value.
    ans.push_back(root->value);
    // Start the recursive traversal from the left child.
    leftViewHelper(root->left, ans, 1);
    // Then traverse the right child.
    leftViewHelper(root->right, ans, 1);
    // Return the vector containing the left view nodes.
    return ans;
}

//Approach 2: Function to print the Left View of a binary tree using an iterative approach
vector<int> leftViewIteratively(Node *root) {
    vector<int> ans;
    // If the tree is empty, return an empty result.
    if(!root) {
        return ans;
    }
    // Create a queue for level-order traversal with a pair of Node and Level
    queue<pair<Node*, int>> q;
    // Push the root node with level 0 into the queue.
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* currNode = temp.first;
        int level = temp.second;
        // Check if the ans vector size is equal to the current level.
        // If they are equal, it means this is the leftmost node at this level.
        if(ans.size() == level) {
            // Add the value of the leftmost node to the ans vector.
            ans.push_back(currNode->value);
        }
        // Enqueue the left child with an updated level (level + 1) if it exists.
        if(currNode->left) {
            q.push(make_pair(currNode->left, level + 1));
        }
        // Enqueue the right child with an updated level (level + 1) if it exists.
        if(currNode->right) {
            q.push(make_pair(currNode->right, level + 1));
        }
    }
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

    cout<<"The Left View Of Binary Tree using Recursive Approach: "<<endl;
    vector<int> ans = leftViewRecursively(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The Left View Of Binary Tree using Iterative Approach: "<<endl;
    ans = leftViewIteratively(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
