#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>

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

// Recursive function to traverse the binary tree and count paths that sum to 'k'.
void solve(Node* root, int k, int &ans, vector<int> path) {
    if(!root) {
        return;
    }
    // Add the current node's value to the path.
    path.push_back(root->value);
    // Recursively traverse the left and right subtrees.
    solve(root->left, k, ans, path);
    solve(root->right, k, ans, path);
    int size = path.size();
    long long sum = 0;
    // Calculate sums along the path and update the answer count.
    for(int i = size - 1; i >= 0; i--) {
        sum += path[i];
        if(sum == k) {
            ans++;
        }
    }
}

//Approach 1: Function to count the number of paths in the binary tree that sum to 'k'.
int pathSum(Node* root, int k) {
    if(!root) {
        return 0;
    }
    // Initialize variables to store the answer and the current path.
    vector<int> path;
    int ans = 0;
    // Start the traversal from the root node.
    solve(root, k, ans, path);
    return ans;
}

// Helper function for optimized path sum calculation using prefix sum.
void pathSumHelper(Node* root, int k, long long currSum, unordered_map<long long, int> &path, int &ans) {
    if(!root) {
        return;
    }
    // Update the current sum with the value of the current node.
    currSum += root->value;
    // Check if there exists a path ending at the current node with sum 'k'.
    ans += path[currSum - k];
    // Increment the count of the current sum in the prefix sum map.
    path[currSum]++;
    // Recursively process the left and right subtrees.
    pathSumHelper(root->left, k, currSum, path, ans);
    pathSumHelper(root->right, k, currSum, path, ans);
    // Decrement the count of the current sum in the prefix sum map to backtrack.
    path[currSum]--;
}

//Approach 2: Optimized function to count the number of paths in the binary tree that sum to 'k'.
int pathSumOptimized(Node* root, int k) {
    if(!root) {
        return 0;
    }
    // Initialize a prefix sum map and other variables.
    unordered_map<long long, int> path;
    // Initialize with a prefix sum of 0.
    path[0] = 1;
    int ans = 0;
    long long currSum = 0;
    // Start the optimized path sum calculation.
    pathSumHelper(root, k, currSum, path, ans);
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
    root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right = new Node(2);
    root->left->right->right = new Node(1);
    root->right = new Node(-3);
    root->right->right = new Node(11);

    int targetSum = 8;

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Number of Paths with Sum "<<targetSum<<" using Recursive Approach: "<<pathSum(root, targetSum)<<endl;

    cout<<"The Number of Paths with Sum "<<targetSum<<" using Optimized Recursive Approach: "<<pathSumOptimized(root, targetSum)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
