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

//Approach 1: Function to find the minimum height of the binary tree recursively
int minHeightRecursively(Node* root) {
    if(!root) {
        // If the tree is empty, its height is 0.
        return 0;
    }
    // If there's no left subtree, return the height of the right subtree plus 1
    if(!root->left) {
        return minHeightRecursively(root->right) + 1;
    }
    // If there's no right subtree, return the height of the left subtree plus 1
    if(!root->right) {
        return minHeightRecursively(root->left) + 1;
    }
    // Return the minimum height between the left and right subtrees, plus 1 for the current level
    return min(minHeightRecursively(root->left), minHeightRecursively(root->right)) + 1;
}

//Approach 2: Function to find the minimum height of the binary tree iteratively
int minHeightIteratively(Node* root) {
    if(!root) {
        // If the tree is empty, its height is 0.
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    // Start with a height of 1 since the root is at level 1.
    int height = 1;
    while(!q.empty()) {
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++) {
            Node* currNode = q.front();
            q.pop();
            // If a leaf node is encountered, return the current height as the minimum height.
            if(!currNode->left && !currNode->right) {
                return height;
            }
            // Enqueue the left child if it exists
            if(currNode->left) {
                q.push(currNode->left);
            }
            // Enqueue the right child if it exists
            if(currNode->right) {
                q.push(currNode->right);
            }
        }
        // Increment the height for each level
        height++;
    }
    return height;
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
    root = new Node(13);
    root->left = new Node(15);
    root->right = new Node(1);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(9);
    root->left->left->left = new Node(11);
    root->left->right->left = new Node(16);
    root->left->right->right = new Node(17);
    root->right->right->left = new Node(91);
    root->right->right->left->right = new Node(10);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Minimum Height of Binary Tree Recursively: "<<minHeightRecursively(root)<<endl;
    cout<<"The Minimum Height of Binary Tree Iteratively: "<<minHeightIteratively(root)<<endl;
    
    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
