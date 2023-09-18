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

//Function to find the maximum height of the binary tree recursively
int height(Node* root) {
    if(!root) {
        // If the tree is empty, its height is 0.
        return 0;
    }
    // Calculate the height of the left and right subtrees recursively
    int leftSubtreeHeight = height(root->left);
    int rightSubtreeHeight = height(root->right);
    // The height of the tree is the maximum of left and right subtree heights, plus 1 for the current level
    return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

//Approach 1: Function to calculate the diameter of a binary tree
int diameterOfBinaryTree(Node* root) {
    if(!root) {
        // If the root is null, the diameter is 0
        return 0;
    }
    // Calculate the diameter of the left subtree
    int leftDiameter = diameterOfBinaryTree(root->left);
    // Calculate the diameter of the right subtree
    int rightDiameter = diameterOfBinaryTree(root->right);
    // Calculate the height of the current node
    int currentHeight = height(root->left) + height(root->right);
    // Return the maximum of these values
    return max(leftDiameter, max(rightDiameter, currentHeight));
}

// Helper function to calculate the diameter and height of a binary tree
pair<int, int> diameterHelper(Node* root) {
    if(!root) {
        // If the root is null, return a pair with both diameter and height as 0
        return make_pair(0,0);
    }
    // Recursively calculate the diameter and height of the left subtree
    pair<int, int> leftSubtree = diameterHelper(root->left);
    // Recursively calculate the diameter and height of the right subtree
    pair<int, int> rightSubtree = diameterHelper(root->right);
    // Diameter of the left subtree
    int leftDiameter = leftSubtree.first;
    // Diameter of the right subtree
    int rightDiameter = rightSubtree.first;
    // Height of the current subtree
    int currentHeight = leftSubtree.second + rightSubtree.second;
    // Calculate and return the maximum diameter and updated height for the current subtree
    return make_pair(max(leftDiameter, max(rightDiameter, currentHeight)), (max(leftSubtree.second, rightSubtree.second) + 1));
}

//Approach 2: Optimized function to calculate the diameter of a binary tree
int diameterOfBinaryTreeOptimized(Node* root) {
    return diameterHelper(root).second;
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

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Diameter of Binary Tree: "<<diameterOfBinaryTree(root)<<endl;
    cout<<"The Diameter of Binary Tree Optimized approach: "<<diameterOfBinaryTreeOptimized(root)<<endl;
    
    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
