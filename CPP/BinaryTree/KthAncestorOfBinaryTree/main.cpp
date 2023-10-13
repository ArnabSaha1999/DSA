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

// Function to find the kth ancestor of a node in a binary tree
Node* solve(Node* root, int &k, int node) {
    // Base case: If the root is null, return null as no ancestor can be found
    if(!root) {
        return NULL;
    }
    // If the current node's data matches the target node's data, it's an ancestor
    if(root->value == node) {
        return root;
    }
    // Recursively search for the target node in the left and right subtrees
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    // Check if the target node was found in either the left or right subtree
    if(leftAns && !rightAns) {
        if(k > 0) {
            k--;
            if(k == 0) {
                // If k reaches 0, return the current node as an ancestor
                return root;
            }
        }
        // Continue searching for the target node in the left subtree
        return leftAns;
    }
    
    if(!leftAns && rightAns) {
        if(k > 0) {
            k--;
            if(k == 0) {
                // If k reaches 0, return the current node as an ancestor
                return root;
            }
        }
        // Continue searching for the target node in the right subtree
        return rightAns;
    }
}

//Approach 1: Function to find the kth ancestor of a node in a binary tree
int kthAncestor(Node *root, int k, int node) {
    // Call the solve function to find the kth ancestor of the target node
    Node* ans = solve(root, k, node);
    // Check if the result is null or if it's the same as the target node
    if(!ans || ans->value == node)
        return -1;
    else {
        // Return the data of the kth ancestor found
        return ans->value;
    }
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

    int k = 2;
    int targetNode = 15;

    cout<<"The "<<k<<" Ancestor of "<<targetNode<<" is: "<<kthAncestor(root, k, targetNode)<<endl;
    
    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
