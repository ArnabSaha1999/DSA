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

// Helper function for recursively calculating the sum of right leaves in a binary tree
void sumOfRightLeavesHelper(Node* root, int &sum) {
    // Base case: If the node is null, return.
    if(!root) {
        return;
    }
    // Check if the right child of the current node is a leaf node.
    if(root->right && !root->right->left && !root->right->right) {
        // Add the value of the right leaf node to the sum.
        sum += root->right->value;
    }
    // Recursively process the left and right subtrees.
    sumOfRightLeavesHelper(root->left, sum);
    sumOfRightLeavesHelper(root->right, sum);
}

//Approach 1: Recursive function to calculate the sum of right leaves in a binary tree
int sumOfRightLeavesRecursively(Node* root) {
    int sum = 0;
    // Call the helper function to calculate the sum of right leaves.
    sumOfRightLeavesHelper(root, sum);
    return sum;
}

//Approach 2: Iterative function to calculate the sum of right leaves in a binary tree
int sumOfRightLeavesIteratively(Node* root) {
    // If the node is null, return.
    if(!root) {
        return 0;
    }
    int sum = 0;
    // Create a stack for iterative traversal.
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* currNode = st.top();
        st.pop();
        // Push the left child onto the stack for processing.
        if(currNode->left) {
            st.push(currNode->left);
        }
        // Check if the right child of the current node is a leaf node.
        if(currNode->right) {
            if(!currNode->right->left && !currNode->right->right) {
                // Add the value of the right leaf node to the sum.
                sum += currNode->right->value;
            } else {
                // Push the right child onto the stack for further processing.
                st.push(currNode->right);
            }
        }
    }
    return sum;
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

    cout<<"The Sum of Right Leaves using the Recursive approach: "<<sumOfRightLeavesRecursively(root)<<endl;
    cout<<"The Sum of Right Leaves Using the Iterative approach: "<<sumOfRightLeavesIteratively(root)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
