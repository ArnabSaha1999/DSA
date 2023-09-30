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

// Helper function to recursively find paths with a given target sum
void pathSumHelper(Node* root, vector<int> temp, int targetSum, vector<vector<int>> &ans) {
    if(!root) {
        return;
    }
    // Subtract the current node's value from the target sum
    targetSum -= root->value;
    // Add the current node's value to the temporary path
    temp.push_back(root->value);
    // If we've reached a leaf node and the target sum is 0, add the path to the answer
    if(!root->left && !root->right && targetSum == 0) {
        ans.push_back(temp);
        return;
    }
    // Recursively explore the left and right subtrees
    pathSumHelper(root->left, temp, targetSum, ans);
    pathSumHelper(root->right, temp, targetSum, ans);
}

//Approach 1: Function to find all paths in a binary tree that sum up to the target sum using a recursive approach
vector<vector<int>> pathSumRecursively(Node* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> temp;
    // If the tree is empty, return an empty result
    if(!root) {
        return ans;
    }
    // Start the recursive path-finding process
    pathSumHelper(root, temp, targetSum, ans);
    return ans;
}

//Approach 2: Function to find all paths in a binary tree that sum up to the target sum using an iterative approach
vector<vector<int>> pathSumIteratively(Node* root, int targetSum) {
    vector<vector<int>> ans;
    // If the tree is empty, return an empty result
    if(!root) {
        return ans;
    }
    queue<pair<pair<Node*, int>, vector<int>>> q;
    // Initialize the queue with the root node and its value
    q.push(make_pair(make_pair(root, root->value), vector<int>{root->value}));
    while(!q.empty()) {
        Node* currNode = q.front().first.first;
        int currSum = q.front().first.second;
        vector<int> temp = q.front().second;
        q.pop();
        // If we've reached a leaf node and the current sum is equal to the target sum, add the path to the answer
        if(!currNode->left && !currNode->right && currSum == targetSum) {
            ans.push_back(temp);
            continue;
        }
        // Explore the left child (if it exists)
        if(currNode->left) {
            // Create a new path by adding the left child's value to the current sum
            temp.push_back(currNode->left->value);
            q.push(make_pair(make_pair(currNode->left, currSum + currNode->left->value), temp));
            // Remove the left child's value from the temp path to backtrack
            temp.pop_back();
        }
        // Explore the right child (if it exists)
        if(currNode->right) {
            // Create a new path by adding the right child's value to the current sum
            temp.push_back(currNode->right->value);
            q.push(make_pair(make_pair(currNode->right, currSum + currNode->right->value), temp));
            // Remove the right child's value from the temp path to backtrack
            temp.pop_back();
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
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->right->left = new Node(5);
    root->right->right->right = new Node(1);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    int targetSum = 22;

    cout<<"The Path of Target: "<<targetSum<<" Using the Recursive Approach: "<<endl;
    vector<vector<int>> ans = pathSumRecursively(root, targetSum);
    for(vector<int> arr : ans) {
        for(int a : arr) {
            cout<<a<<" ";
        } cout<<endl;
    }
    
    cout<<"The Path of Target: "<<targetSum<<" Using the Iterative Approach: "<<endl;
    ans = pathSumIteratively(root, targetSum);
    for(vector<int> arr : ans) {
        for(int a : arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

}
