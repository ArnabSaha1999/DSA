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

// Helper Recursive function to perform diagonal traversal of a binary tree
void solve(Node* root, map<int, vector<int>> &mp, int horizontalDistance) {
    if(!root) {
        return;
    }
    // Add the current node's value to the corresponding diagonal level in the map
    mp[horizontalDistance].push_back(root->value);
    // Recursively traverse the left subtree with an increased horizontal distance.
    solve(root->left, mp, horizontalDistance + 1);
    // Recursively traverse the right subtree with the same horizontal distance.
    solve(root->right, mp, horizontalDistance);
}

//Approach 1: Function to perform diagonal traversal of a binary tree using recursion.
vector<int> diagonalTraversalRecursively(Node *root) {
   vector<int> ans;
   // If the tree is empty, return an empty result.
   if(!root) {
       return ans;
   }
   // Create a map to store nodes at each diagonal level with Horizontal Distance and vector to store node values for each HD
   map<int, vector<int>> mp;
   // Add the root node's value to the result.
   ans.push_back(root->value);
   // Start recursive traversal for the left and right subtrees.
   solve(root->left, mp, 1);
   solve(root->right, mp, 0);
   // Flatten the map and add values to the result in the correct order
   for(auto m : mp) {
       for(int i : m.second) {
           ans.push_back(i);
       }
   }
   return ans;
}

//Approach 2: Function to perform diagonal traversal of a binary tree iteratively.
vector<int> diagonalTraversalIteratively(Node *root) {
    vector<int> ans;
    // If the tree is empty, return an empty result.
    if(!root) {
        return ans;
    }
    // Create a queue for level-order traversal.
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        while(currNode) {
            // Enqueue the left child if it exists.
            if(currNode->left) {
                q.push(currNode->left);
            }
            // Add the current node's value to the result.
            ans.push_back(currNode->value);
            // Move to the right child.
            currNode = currNode->right;
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
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->right->left = new Node(12);
    root->right->right->right = new Node(13);
    root->left->left->left->left = new Node(14);
    root->left->left->right->right = new Node(15);
    root->right->right->left->left = new Node(16);
    root->right->right->left->right = new Node(17);
    root->right->right->right->right = new Node(18);
    root->left->left->right->right->left = new Node(19);
    root->left->left->right->right->right = new Node(20);
    root->right->right->left->left->left = new Node(21);
    root->right->right->left->left->right = new Node(22);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Diagonal Traversal Of Binary Tree using Recursive Approach: "<<endl;
    vector<int> ans = diagonalTraversalRecursively(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The Diagonal Traversal Of Binary Tree using Iterative Approach: "<<endl;
    ans = diagonalTraversalIteratively(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
