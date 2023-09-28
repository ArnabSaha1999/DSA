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

// Helper function to recursively reverse odd levels of a binary tree
void reverseTree(Node* leftNode, Node* rightNode, int level) {
    // Base case: If either leftNode or rightNode is null, return
    if(!leftNode || !rightNode) {
        return;
    }
    // Check if the current level is odd
    if(level & 1) {
        // Swap the values of nodes at odd levels
        swap(leftNode->value, rightNode->value);
    }
    // Recursively reverse the subtrees at the next level
    reverseTree(leftNode->left, rightNode->right, level + 1);
    reverseTree(leftNode->right, rightNode->left, level + 1);
}

//Approach 1: Function to reverse odd levels of a binary tree using recursion
Node* reverseOddLevelsRecursive(Node* root) {
    // Base case: If the root is null, return null
    if(!root) {
        return root;
    }
    int level = 1;
    // Call the helper function to reverse odd levels
    reverseTree(root->left, root->right, level);
    return root;
}

//Approach 2: Function to reverse odd levels of a binary tree using an iterative approach
Node* reverseOddLevelsIterative(Node* root) {
    if(!root) {
        return root;
    }
    queue<Node*> q;
    // Temporary storage for values at odd levels
    vector<int> currQueue;
    q.push(root);
    int level = 0;
    while(!q.empty()) {
        int size = q.size();
        vector<int> temp;
        for(int i = 0; i < size; i++) {
            Node* currNode = q.front();
            q.pop();
            // Check if the current level is odd
            if(level & 1) {
                // Set the value of the current node to the value from currQueue
                currNode->value = currQueue[size - i - 1];
            }
            // Push the left and right children onto the stack for further processing
            if(currNode->left) {
                q.push(currNode->left);
                temp.push_back(currNode->left->value);
            }
            if(currNode->right) {
                q.push(currNode->right);
                temp.push_back(currNode->right->value);
            }
        }
        level++;
        // Update currQueue with values at the next odd level
        currQueue = temp;   
    }
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
    Node* root;
    root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(0);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(1);
    root->right->left->left = new Node(2);
    root->right->left->right = new Node(2);
    root->right->right->left = new Node(2);
    root->right->right->right = new Node(2);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"Reverse Odd Levels of Binary Tree Using the Recursive approach:"<<endl;
    Node* ans = reverseOddLevelsRecursive(root);
    levelOrderTraversal(ans);

    // Clean up memory by deleting the nodes
    deleteTree(root);

    root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(0);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(1);
    root->right->left->left = new Node(2);
    root->right->left->right = new Node(2);
    root->right->right->left = new Node(2);
    root->right->right->right = new Node(2);

    cout<<"Reverse Odd Levels of Binary Tree Using the Iterative approach:"<<endl;
    ans = reverseOddLevelsIterative(root);
    levelOrderTraversal(ans);

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
