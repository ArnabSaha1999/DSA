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

// Function to create a parent mapping using BFS and find the target node
Node* parentMapping(Node* root, int target, map<Node*, Node*> &mp) {
    queue<Node*> q;
    // The parent of the root is null.
    mp[root] = nullptr;
    q.push(root);
    Node* targetNode = nullptr;
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        // Found the target node.
        if(currNode->value == target) {
            targetNode = currNode;
        }
        if(currNode->left) {
            q.push(currNode->left);
            // Map the left child to its parent.
            mp[currNode->left] = currNode;
        }
        if(currNode->right) {
            q.push(currNode->right);
            // Map the right child to its parent.
            mp[currNode->right] = currNode;
        }
    }
    return targetNode;
}

// Function to calculate the time required for the tree to burn using BFS
int burnTreeHelper(Node* root, map<Node*, Node*> &mp) {
    // Map to track visited nodes
    map<Node*, bool> visited;
    queue<Node*> q;
    int timeRequired = 0;
    // Mark the target node (root) as visited and add it to the queue
    visited[root] = true;
    q.push(root);
    while(!q.empty()) {
        // Flag to check if nodes are still burning at this level
        bool flag = false;
        int size = q.size();
        // Process nodes at the current level
        for(int i = 0; i < size; i++) {
            Node* currNode = q.front();
            q.pop();
            // Check and process left child if not visited
            if(currNode->left && !visited[currNode->left]) {
                flag = true;
                visited[currNode->left] = true;
                q.push(currNode->left);
            }
            // Check and process right child if not visited
            if(currNode->right && !visited[currNode->right]) {
                flag = true;
                visited[currNode->right] = true;
                q.push(currNode->right);
            } 
            // Check and process the parent node if not visited
            if(mp[currNode] && !visited[mp[currNode]]) {
                flag = true;
                visited[mp[currNode]] = true;
                q.push(mp[currNode]);
            }
        }
        // If any nodes are still burning at this level, increment the time
        if(flag) {
            timeRequired++;
        }
    }
    // Return the total time required for the tree to burn
    return timeRequired;
}

//Approach 1: function to find the minimum time for the tree to burn from the target node
int minBurnTime(Node* root, int target) {
    if(!root) {
        // Handle the case when the tree is empty.
        return 0;
    }
    // Create a map to store parent-child relationships
    map<Node*, Node*> mp;
    Node* targetNode = parentMapping(root, target, mp);
    // Calculate the time required to burn the tree
    return burnTreeHelper(targetNode, mp);
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
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right->right = new Node(9);  
    root->right->right->right->right = new Node(10);  

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    int targetNode = 8;

    cout<<"The Minimum Time to Burn the Tree from TargetNode: "<<targetNode<<": "<<minBurnTime(root, targetNode)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
