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

// Check if a binary tree is a Binary Search Tree (BST) within the given range [mini, maxi]
bool isBST(Node* root, int mini, int maxi) {
    if(!root) {
        // Base case: An empty tree is a BST
        return true;
    }
    if(root->value <= mini || root->value >= maxi) {
        // If the current node's value is not within the range, it's not a BST
        return false;
    }
    // Recursively check the left and right subtrees with updated ranges
    return (isBST(root->left, mini, root->value) && isBST(root->right, root->value, maxi));
}

// Calculate the sum of values in a binary tree
int getSum(Node* root) {
    if(!root) {
        // Base case: Return 0 for an empty tree
        return 0;
    }
    if(!root->left && !root->right) {
        // If the current node is a leaf, return its value
        return root->value;
    }
    // Recursively calculate the sum of values in the left and right subtrees
    return root->value + getSum(root->left) + getSum(root->right);
}

//Approach 1: Find the maximum sum of values in a Binary Search Tree (BST)
int maxSumBST(Node* root) {
    if(!root) {
        // Base case: Return 0 for an empty tree
        return 0;
    }
    int sum = 0;
    // Check if the entire tree is a BST within the full range of INT_MIN to INT_MAX
    if(isBST(root, INT_MIN, INT_MAX)) {
        // Calculate the sum of values in the BST
        sum = getSum(root); 
        if(sum < 0) {
            // If the sum is negative, set it to 0
            sum = 0;
        }
    }
    // Recursively find the maximum sum in the left and right subtrees
    int leftAns = maxSumBST(root->left);
    int rightAns = maxSumBST(root->right);
    // Return the maximum of the three values
    return max(max(sum, leftAns), rightAns);
}

// Class to store information about a node in a BST
class Info {
    public:
    bool isBST;
    int mini, maxi, sum;
};

// Helper function to find the maximum sum in a BST using an optimized approach
Info maxSumBSTHelper(Node* root, int &maxSum) {
    if(!root) {
        // Base case: An empty tree is a BST
        return {true, INT_MAX, INT_MIN, 0};
    }
    // Recursively calculate information for the left and right subtrees
    Info leftTree = maxSumBSTHelper(root->left, maxSum);
    Info rightTree = maxSumBSTHelper(root->right, maxSum);
    Info currNode;
    currNode.sum = root->value + leftTree.sum + rightTree.sum;
    currNode.mini = min(root->value, leftTree.mini);
    currNode.maxi = max(root->value, rightTree.maxi);
    // Check if the current node and its subtrees form a BST
    if(leftTree.isBST && rightTree.isBST && (root->value > leftTree.maxi && root->value < rightTree.mini)) {
        currNode.isBST = true;
        // Update the maximum sum if necessary
        maxSum = max(maxSum, currNode.sum);
    } else {
        currNode.isBST = false;
    }
    // Return information about the current node
    return currNode;
}

//Approach 2: Find the maximum sum in a BST using an optimized approach
int maxSumBSTOptimized(Node* root) {
    if(!root) {
        // Base case: Return 0 for an empty tree
        return 0;
    }
    int maxSum = 0;
    // Find the maximum sum using the helper function
    maxSumBSTHelper(root, maxSum);
    // Return the maximum sum
    return maxSum;
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
    root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(6);
    
    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    cout<<"The Maximum of Valid BST Subtree using the Brute Force Approach: "<<maxSumBST(root)<<endl;
    cout<<"The Maximum of Valid BST Subtree using the Optimized Approach: "<<maxSumBSTOptimized(root)<<endl;
    
    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
