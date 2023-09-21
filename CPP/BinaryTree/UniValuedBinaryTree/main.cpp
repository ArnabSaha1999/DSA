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

// Helper function for recursively checking if a binary tree is univalued
bool solve(Node* root, int val) {
    // Base case: An empty tree is considered univalued.
    if(!root) {
        return true;
    }
    // If the value doesn't match, the tree is not univalued.
    if(root->value != val) {
        return false;
    }
    // Recursively check both left and right subtrees.
    return (solve(root->left, val) && solve(root->right, val));
}

//Approach 1: Recursive approach to check if a binary tree is univalued.
bool isUnivalTreeRecursively(Node* root) {
    // An empty tree is considered univalued.
    if(!root) {
        return false;
    }
    int val = root->value;
    // Call the helper function.
    return solve(root, val);
}

//Approach 2: Iterative approach to check if a binary tree is univalued
bool isUnivalTree(Node* root) {
    // An empty tree is considered univalued.
    if(!root) {
        return false;
    }
    int val = root->value;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* currNode = st.top();
        st.pop();
        // If the value doesn't match, the tree is not univalued.
        if(currNode->value != val) {
            return false;
        }
        // Push left and right children onto the stack for further processing.
        if(currNode->left) {
            st.push(currNode->left);
        }
        if(currNode->right) {
            st.push(currNode->right);
        }
    }
    return true;
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
    root->left = new Node(1);
    root->left->left = new Node(1);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(1);
    root->left->right = new Node(1);
    root->right = new Node(1);
    root->right->right = new Node(1);
    root->right->right->left = new Node(1);
    root->right->right->right = new Node(1);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"Using Recursive approach to check UniValued Binary Tree: "<<endl;
    if(isUnivalTreeRecursively(root)) {
        cout<<"The Binary Tree is Uni-Valued"<<endl;
    } else {
        cout<<"The Binary Tree is not Uni-Valued"<<endl;
    }

    cout<<"Using Iterative approach to check UniValued Binary Tree: "<<endl;
    if(isUnivalTree(root)) {
        cout<<"The Binary Tree is Uni-Valued"<<endl;
    } else {
        cout<<"The Binary Tree is not Uni-Valued"<<endl;
    }    

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
