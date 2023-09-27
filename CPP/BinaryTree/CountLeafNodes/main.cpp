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

// Helper function for counting leaves recursively
void inorderCount(Node* root, int &count) {
    if(!root) {
        return;
    }
    // Traverse the left subtree
    inorderCount(root->left, count);
    // Check if the current node is a leaf node
    if(!root->left && !root->right) {
        // Increment the leaf count
        count++;
        return;
    }
    // Traverse the right subtree
    inorderCount(root->right, count);
}

//Approach 1: Function to count leaves recursively
int countLeavesRecursively(Node* root) {
    int count = 0;
    inorderCount(root, count);
    return count;
}

//Approach 2: Function to count leaves iteratively
int countLeavesIteratively(Node* root) {
    if(!root) {
        return 0;
    }
    stack<Node*> st;
    st.push(root);
    int count = 0;
    while(!st.empty()) {
        Node* currNode = st.top();
        st.pop();
        // Check if the current node is a leaf node
        if(!currNode->left && !currNode->right) {
            count++;
        }
        // Push the left child onto the stack if it exists
        if(currNode->left) {
            st.push(currNode->left);
        }
        // Push the right child onto the stack if it exists
        if(currNode->right) {
            st.push(currNode->right);
        }
    }
    return count;
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
    root = new Node(13);
    root->left = new Node(15);
    root->right = new Node(1);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(9);
    root->left->left->left = new Node(11);
    root->left->right->left = new Node(16);
    root->left->right->right = new Node(17);
    root->right->right->left = new Node(91);
    root->right->right->left->right = new Node(10);

    levelOrderTraversal(root);

    cout<<"The Leaves Count Recursively: "<<countLeavesRecursively(root)<<endl;
    cout<<"The Leaves Count Iteratively: "<<countLeavesIteratively(root)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
