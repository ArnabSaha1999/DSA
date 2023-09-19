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

// Public function to calculate the height of a binary tree
int height(Node* root) {
    if(!root) {
        return 0;
    }
    //Recursively calculate height of the left subtree
    int leftTree = height(root->left);
    //Recursively calculate height of the right subtree
    int rightTree = height(root->right);
    // If either subtree is unbalanced or the difference in heights is greater than 1, return -1
    if(leftTree == -1 || rightTree == -1 || abs(leftTree - rightTree) > 1) {
        return -1;
    }
    // Return the height of the current node's subtree
    return max(leftTree, rightTree) + 1;
}

//Approach 1: Public function to check if a binary tree is balanced
bool isBalanced(Node* root) {
    // If the height function returns -1, the tree is unbalanced; otherwise, it's balanced
    return (height(root) == -1) ? false : true;
}

// Helper function to check if a binary tree is balanced and compute its height
pair<bool, int> isBalancedHelper(Node* root) {
    if(!root) {
        // An empty tree is balanced with a height of 0
        return make_pair(true, 0);
    }
    // Recursively calculate the left subtree's balance status and height
    pair<bool, int> leftTree = isBalancedHelper(root->left);
    // Recursively calculate the right subtree's balance status and height
    pair<bool, int> rightTree = isBalancedHelper(root->right);
    // Check if the current tree is balanced based on the heights of its subtrees
    bool balanced = abs(leftTree.second - rightTree.second) <= 1;
    // If both subtrees are balanced and the current tree is balanced, return true and update height
    if(leftTree.first && rightTree.first && balanced) {
        return make_pair(true, max(leftTree.second, rightTree.second) + 1);
    } 
    // If any of the conditions fail, return false and update height
    return make_pair(false, max(leftTree.second, rightTree.second) + 1);
}

//Approach 2: Public function to check if a binary tree is balanced using an optimized recursive approach
bool isBalancedOptimized(Node* root) {
    return isBalancedHelper(root).first;
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
    root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"Using The Recursive approach: "<<endl;
    if(isBalanced(root)) {
        cout<<"The Tree is Balanced"<<endl;
    } else {
        cout<<"The Tree is not Balanced"<<endl;
    }

    cout<<"Using the Optimized Recursive approach: "<<endl;
    if(isBalancedOptimized(root)) {
        cout<<"The Tree is Balanced"<<endl;
    } else {
        cout<<"The Tree is not Balanced"<<endl;
    }
    
    // Clean up memory by deleting the nodes
    deleteTree(root);

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(4);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"Using the Recursive approach: "<<endl;
    if(isBalanced(root)) {
        cout<<"The Tree is Balanced"<<endl;
    } else {
        cout<<"The Tree is not Balanced"<<endl;
    }

    cout<<"Using the Optimized Recursive approach: "<<endl;
    if(isBalancedOptimized(root)) {
        cout<<"The Tree is Balanced"<<endl;
    } else {
        cout<<"The Tree is not Balanced"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
