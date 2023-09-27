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

// Function to find the height of the binary tree
int findHeight(Node* root ) {
    if(!root) {
        return 0;
    }
    // Recursively find the height of the left and right subtrees
    int leftTree = findHeight(root->left);
    int rightTree = findHeight(root->right);
    // Return the maximum height among left and right subtrees, plus one for the current node
    return max(leftTree, rightTree) + 1;
}

// Function to calculate the sum of nodes at a given height
int sum(Node* root, int height, int count) {
    if(!root) {
        return 0;
    }
    // If we reach the desired height, return the value of the current node
    if(height == count) {
        return root->value;
    }
    // Recursively calculate the sum of nodes at the given height in left and right subtrees
    int leftTreeSum = sum(root->left, height, count + 1);
    int rightTreeSum = sum(root->right, height, count + 1);
    // Return the sum of left and right subtree values
    return leftTreeSum + rightTreeSum;

}

//Approach 1: Function to calculate the sum of deepest leaves using recursive approach
int deepestLeavesSumRecursive(Node* root) {
    if(!root) {
        return 0;
    }
    // Find the height of the tree
    int height = findHeight(root);
    // Calculate the sum of nodes at the deepest level
    return sum(root, height, 1);
}

// Helper function to calculate the sum of deepest leaves using optimized recursive approach
void deepestLeavesSumHelper(Node* root, int &sum, int height, int &maxHeight) {
    if(!root) {
        return;
    }
    // If the current node is at a greater height than the maximum height seen so far, reset the sum and update the maximum height
    if(height > maxHeight) {
        sum = 0;
        maxHeight = height;
    }
    // If the current node is at the deepest level, add its value to the sum
    if(height == maxHeight) {
        sum += root->value;
    }
    // Recursively traverse the left and right subtrees
    deepestLeavesSumHelper(root->left, sum, (height + 1), maxHeight);
    deepestLeavesSumHelper(root->right, sum, (height + 1), maxHeight);
}

//Approach 2: Function to calculate the sum of deepest leaves using optimized recursive approach
int deepestLeavesSumOptimizedRecursive(Node* root) {
    if(!root) {
        return 0;
    }
    int sum = 0;
    int maxHeight = 0;
    // Start the recursive traversal from the root node
    deepestLeavesSumHelper(root, sum, 0, maxHeight);
    return sum;
}

//Approach 3: Function to calculate the sum of deepest leaves using iterative approach
int deepestLeavesSumIterative(Node* root) {
    if(!root) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int sum;
    while(!q.empty()) {
        int size = q.size();
        sum = 0;
        // Process nodes at the current level
        for(int i = 0; i < size; i++) {
            Node* currNode = q.front();
            q.pop();
            sum += currNode->value;
            // Enqueue left and right children if they exist
            if(currNode->left) {
                q.push(currNode->left);
            }
            if(currNode->right) {
                q.push(currNode->right);
            }
        }
    }
    return sum;
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
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->right->right->right = new Node(8);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Sum of Deepest Leaves of Binary Tree using Recursive approach: "<<deepestLeavesSumRecursive(root)<<endl;
    cout<<"The Sum of Deepest Leaves of Binary Tree using Optimized Recursive approach: "<<deepestLeavesSumOptimizedRecursive(root)<<endl;
    cout<<"The Sum of Deepest Leaves of Binary Tree using Iterative approach: "<<deepestLeavesSumIterative(root)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

}
