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

// Helper function to perform vertical order traversal of a binary tree recursively.
void verticalOrderHelper(Node* root, map<int, map<int, vector<int>>> &mp, int horizontalDistance, int level) {
    // Base case: If the node is null, return.
    if(!root) {
        return;
    }
    // Insert the current node's value into the map based on horizontal distance and level.
    mp[horizontalDistance][level].push_back(root->value);
    // Recursively traverse the left and right subtrees with updated horizontal distance and level.
    verticalOrderHelper(root->left, mp, horizontalDistance - 1, level + 1);
    verticalOrderHelper(root->right, mp, horizontalDistance + 1, level + 1);
}

//Approach 1: Function to perform vertical order traversal of a binary tree using a recursive approach.
vector<int> verticalOrderRecursively(Node *root) {
    vector<int> ans;
    // Base case: If the tree is empty, return an empty result.
    if(!root) {
        return ans;
    }
    // Map to store nodes by horizontal distance and level.
    map<int, map<int, vector<int>>> mp;
    // Start the recursive traversal to populate the map.
    verticalOrderHelper(root, mp, 0, 0);
    // Extract nodes from the map and add them to the result vector.
    for(auto i : mp) {
        vector<int> temp;
        for(auto j : i.second) {
            for(auto k : j.second) {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

//Approach 2: Function to perform vertical order traversal of a binary tree using an iterative approach.
vector<int> verticalOrderIteratively(Node *root) {
    vector<int> ans;
    // Base case: If the tree is empty, return an empty result.
    if(!root) {
        return ans;
    }
    // Queue to perform level-order traversal.
    queue<pair<Node*, pair<int, int>>> q;
    // Map to store nodes by horizontal distance and level.
    map<int, map<int, vector<int>>> mp;
    // Push the root node with initial horizontal distance and level.
    q.push(make_pair(root, make_pair(0,0)));
    while(!q.empty()) {
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();
        Node* currNode = temp.first;
        int horizontalDistance = temp.second.first;
        int level = temp.second.second;
        // Insert the current node's value into the map based on horizontal distance and level.
        mp[horizontalDistance][level].push_back(currNode->value);
        // Enqueue left and right children with updated horizontal distance and level.
        if(currNode->left) {
            q.push(make_pair(currNode->left, make_pair(horizontalDistance - 1, level + 1)));
        }
        if(currNode->right) {
            q.push(make_pair(currNode->right, make_pair(horizontalDistance + 1, level + 1)));
        }
    }
    // Extract nodes from the map and add them to the result vector.
    for(auto i : mp) {
        vector<int> temp;
        for(auto j : i.second) {
            for(auto k : j.second) {
                ans.push_back(k);
            }
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

    cout<<"The Vertical Order Traversal using Recursive Approach: "<<endl;
    vector<int> ans = verticalOrderRecursively(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The Vertical Order Traversal using Iterative Approach: "<<endl;
    ans = verticalOrderIteratively(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
