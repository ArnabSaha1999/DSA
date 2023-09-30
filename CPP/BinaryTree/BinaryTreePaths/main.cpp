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

// Helper function to recursively find binary tree paths
void binaryTreePathHelper(Node* root, string temp, vector<string> &ans) {
    if(!root) {
        return;
    }
    // If it's a leaf node, add the path to the answer
    if(!root->left && !root->right) {
        temp += to_string(root->value);
        ans.push_back(temp);
        return;
    }
    // Add the current node's value to the path
    temp += to_string(root->value)+"->";
    // Recursively explore the left and right subtrees
    binaryTreePathHelper(root->left, temp, ans);
    binaryTreePathHelper(root->right, temp, ans);
}

//Approach 1: Function to find binary tree paths using a recursive approach
vector<string> binaryTreePathsRecursively(Node* root) {
    vector<string> ans;
    string temp = "";
    if(!root) {
        return ans;
    }
    // Start the recursive exploration with an empty path
    binaryTreePathHelper(root, temp, ans);
    return ans;
}

//Approach 2: Function to find binary tree paths using an iterative approach
vector<string> binaryTreePathsIteratively(Node* root) {
    vector<string> ans;
    string temp = "";
    if(!root) {
        return ans;
    }
    queue<pair<Node*, string>> q;
    q.push(make_pair(root, to_string(root->value)));
    while(!q.empty()) {
        Node* currNode = q.front().first;
        string path = q.front().second;
        q.pop();
        // If it's a leaf node, add the path to the answer
        if(!currNode->left && !currNode->right) {
            ans.push_back(path);
            continue;
        }
        // Explore the left and right subtrees
        if(currNode->left) {
            q.push(make_pair(currNode->left, path + "->" + to_string(currNode->left->value)));
        }
        if(currNode->right) {
            q.push(make_pair(currNode->right, path + "->" + to_string(currNode->right->value)));
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

    cout<<"Using the Recursive Approach: "<<endl;
    vector<string> ans = binaryTreePathsRecursively(root);
    for(string a : ans) {
        cout<<"("<<a<<") ";
    } cout<<endl;

    cout<<"Using the Iterative Approach: "<<endl;
    ans = binaryTreePathsIteratively(root);
    for(string a : ans) {
        cout<<"("<<a<<") ";
    } cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
