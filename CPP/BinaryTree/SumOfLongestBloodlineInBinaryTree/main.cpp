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

// Helper Recursive function to find the sum of the longest bloodline in a binary tree.
void solve(Node* root, int &maxHeight, int height, int &maxSum, int sum) {
    if(!root) {
        return;
    }
    // Add the current node's value to the running sum.
    sum += root->value;
    // Check if the current height is greater than the maximum height.
    if(maxHeight < height) {
        maxHeight = height;
        maxSum = sum;
    }
    // If heights are equal, compare the sums and update maxSum if needed.
    else if(maxHeight == height && maxSum < sum) {
        maxSum = sum;
    }
    // Recursively traverse the left and right subtrees.
    solve(root->left, maxHeight, height + 1, maxSum, sum);
    solve(root->right, maxHeight, height + 1, maxSum, sum);
}

//Approach 1: Function to calculate the sum of the longest bloodline in a binary tree using recursion
int sumOfLongestBloodlineRecursively(Node *root) {
    if(!root) {
        return 0;
    } 
    // Initialize maxSum and maxHeight with root's value and height 0.
    int maxSum = root->value;
    int maxHeight = 0;
    // Start recursive traversal for the left and right subtrees.
    solve(root->left, maxHeight, 1, maxSum, root->value);
    solve(root->right, maxHeight, 1, maxSum, root->value);
    // Return the maximum sum encountered.
    return maxSum;
}

//Approach 2: Function to calculate the sum of the longest bloodline in a binary tree using iteration.
int sumOfLongestBloodlineIteratively(Node *root) {
    if(!root) {
        return 0;
    }
    // Create a queue for level-order traversal with a pair of Node, height, and sum.
    queue<pair<Node*, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, root->value)));
    int ans;
    int maxHeight = 0;
    while(!q.empty()) {
        int size = q.size();
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();
        Node* currNode = temp.first;
        int height = temp.second.first;
        int sum = temp.second.second;
        // Check if the current height is greater than the maximum height.
        if(maxHeight < height) {
            maxHeight = height;
            ans = sum;
        } 
        // If heights are equal, compare the sums and update ans if needed.
        else if(ans < sum) {
            ans = sum;
        }
        // Enqueue the left and right children with updated height and sum.
        if(currNode->left) {
            q.push(make_pair(currNode->left, make_pair(height + 1, sum + currNode->left->value)));
        }
        if(currNode->right) {
            q.push(make_pair(currNode->right, make_pair(height + 1, sum + currNode->right->value)));
        }
    }
    // Return the maximum sum encountered.
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

    cout<<"The Sum of Longest Bloodline using Recursive Approach: "<<sumOfLongestBloodlineRecursively(root)<<endl;

    cout<<"The Sum of Longest Bloodline using Iterative Approach: "<<sumOfLongestBloodlineIteratively(root)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
