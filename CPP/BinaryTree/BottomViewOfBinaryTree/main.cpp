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

//Approach 1: Function to print Bottom View of a binary tree using a iterative approach.
vector<int> bottomView(Node *root) {
    vector<int> ans;
    // If the tree is empty, return an empty result.
    if(!root) {
        return ans;
    }
    // Create a map to store bottom view nodes by horizontal distance.
    map<int, int> mp;
    // Create a queue for level-order traversal with a pair of Node and Horizontal Distance
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* currNode = temp.first;
        int horizontalDistance = temp.second;
        // Update the map with the current node's value for the horizontal distance.
        mp[horizontalDistance] = currNode->value;
        // Enqueue left child with an updated horizontal distance (horizontalDistance - 1) if it exists.
        if(currNode->left) {
            q.push(make_pair(currNode->left, horizontalDistance - 1));
        }
        // Enqueue right child with an updated horizontal distance (horizontalDistance + 1) if it exists.
        if(currNode->right) {
            q.push(make_pair(currNode->right, horizontalDistance + 1));
        }
    }
    // Iterate over the map to retrieve top view nodes and store them in the ans vector.
    for(auto m : mp) {
        ans.push_back(m.second);
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

    cout<<"The Bottom View Of Binary Tree: "<<endl;
    vector<int> ans = bottomView(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
