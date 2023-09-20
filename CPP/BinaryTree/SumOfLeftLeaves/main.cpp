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

// Helper function for recursively calculating the sum of left leaves in a binary tree
void sumOfLeftLeavesHelper(Node* root, int &sum) {
    // Base case: If the node is null, return.
    if(!root) {
        return;
    }
    // Check if the left child of the current node is a leaf node.
    if(root->left && !root->left->left && !root->left->right) {
        // Add the value of the left leaf node to the sum.
        sum += root->left->value;
    }
    // Recursively process the left and right subtrees.
    sumOfLeftLeavesHelper(root->left, sum);
    sumOfLeftLeavesHelper(root->right, sum);
}

//Approach 1: Recursive function to calculate the sum of left leaves in a binary tree
int sumOfLeftLeavesRecursively(Node* root) {
    int sum = 0;
    // Call the helper function to calculate the sum of left leaves.
    sumOfLeftLeavesHelper(root, sum);
    return sum;
}

//Approach 2: Iterative function to calculate the sum of left leaves in a binary tree
int sumOfLeftLeavesIteratively(Node* root) {
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
        // Check if the left child of the current node is a leaf node.
        if(currNode->left) {
            if(!currNode->left->left && !currNode->left->right) {
                // Add the value of the left leaf node to the sum.
                sum += currNode->left->value;
            } else {
                // Push the left child onto the stack for further processing.
                st.push(currNode->left);
            }
        }
        // Push the right child onto the stack for processing.
        if(currNode->right) {
            st.push(currNode->right);
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

    cout<<"The Sum of Left Leaves using the Recursive approach: "<<sumOfLeftLeavesRecursively(root)<<endl;
    cout<<"The Sum of Left Leaves Using the Iterative approach: "<<sumOfLeftLeavesIteratively(root)<<endl;

    return 0;
    
}
