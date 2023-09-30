#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>

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

// Helper function to recursively find the bottom-left value
void solve(Node* root, int &ans, int &maxHeight, int height) {
    if(!root) {
        return;
    }
    // Check if the current height is greater than the maximum height found so far
    if(height > maxHeight) {
        // Update the answer with the current node's value
        ans = root->value;
        // Update the maximum height
        maxHeight = height;
    }
    // Recursively explore the left and right subtrees
    solve(root->left, ans, maxHeight, height + 1);
    solve(root->right, ans, maxHeight, height + 1);
}

//Approach 1: Function to find the bottom-left value of a binary tree using a recursive approach
int findBottomLeftValueRecursively(Node* root) {
    if(!root) {
        return -1;
    }
    // Initialize the answer with the root's value
    int ans = root->value;
    int maxHeight = 0;
    // Start the recursive exploration
    solve(root, ans, maxHeight, 0);
    return ans;
}

//Approach 2: Function to find the bottom-left value of a binary tree using an iterative approach
int findBottomLeftValueIteratively(Node* root) {
    if(!root) {
        return -1;
    }
    int ans = root->value;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        // Process nodes at the current level
        for(int i = 0; i < size; i++) {
            Node* currNode = q.front();
            q.pop();
            // Update the answer with the current node's value
            ans = currNode->value;
            // Enqueue the right child first (to explore leftmost nodes at the next level)
            if(currNode->right) {
                q.push(currNode->right);
            }
            // Enqueue the left child (if it exists)
            if(currNode->left) {
                q.push(currNode->left);
            }
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

    cout<<"Using the Recursive Approach:" <<endl;
    cout<<"The Bottom Left Value: "<<findBottomLeftValueRecursively(root)<<endl;
    
    cout<<"Using the Iterative Approach:"<<endl;
    cout<<"The Bottom Left Value: "<<findBottomLeftValueIteratively(root)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"Using the Recursive Approach:" <<endl;
    cout<<"The Bottom Left Value: "<<findBottomLeftValueRecursively(root)<<endl;

    cout<<"Using the Iterative Approach:"<<endl;
    cout<<"The Bottom Left Value: "<<findBottomLeftValueIteratively(root)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;

}
