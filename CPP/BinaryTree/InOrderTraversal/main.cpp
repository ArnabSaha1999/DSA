#include<iostream>
#include<vector>
#include<stack>

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

// Recursive function to perform an in-order traversal of the binary tree
void solve(Node* root, vector<int> &ans) {
    if(!root) {
        return;
    }
    // Recursively visit left subtree
    solve(root->left, ans);
    // Push the value of the current node
    ans.push_back(root->value);
    // Recursively visit right subtree
    solve(root->right, ans);
}

//Approach 1: Perform an in-order traversal of the binary tree using recursion
// In-order traversal: Left subtree, current node, right subtree
vector<int> inOrderTraversalRecursive(Node* root) {
    vector<int> ans;
    solve(root, ans);
    return ans;
}

//Approach 2: Perform an in-order traversal of the binary tree using an iterative approach
vector<int> inOrderTraversalIterative(Node* root) {
    vector<int> ans;
    Node* currNode = root;
    stack<Node*> st;
    while(currNode || !st.empty()) {
        while(currNode) {
            // Push the current node and move to its left child
            st.push(currNode);
            currNode = currNode->left;
        }
        // Process the top node on the stack
        currNode = st.top();
        st.pop();
        // Push the value of the current node
        ans.push_back(currNode->value);
        // Move to the right subtree
        currNode = currNode->right;
    }
    return ans;
}

//Approach 3: Morris Traversal Algorithm to perform an iterative inorder traversal of a binary tree
vector<int> inOrderMorrisTraversal(Node* root) {
    // Create a vector to store the inorder traversal result
    vector<int> ans;
    // Check if the root is null (empty tree)
    if(!root) {
        return ans;
    }
    // Start from the root node
    Node* currNode = root;
    while(currNode) {
        // If the current node has no left child, visit it and move to its right child
        if(!currNode->left) {
            ans.push_back(currNode->value);
            currNode = currNode->right;
        } else {
            // If the current node has a left child, find its in-order predecessor
            Node* predecessor = currNode->left;
            // Traverse to the rightmost node of the left subtree if not visited already
            while(predecessor->right && predecessor->right != currNode) {
                predecessor = predecessor->right;
            }
            // If the predecessor's right child is not assigned, assign it to the current node
            if(!predecessor->right) {
                predecessor->right = currNode;
                currNode = currNode->left;
            } else {
                // If the predecessor's right child is already assigned, visit the current node and then move to its right child
                predecessor->right = nullptr;
                ans.push_back(currNode->value);
                currNode = currNode->right;
            }
        }
    }
    // Return the inorder traversal result
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

    cout<<"The Inorder Traversal Of Binary Tree Recursively: "<<endl;
    vector<int> ans = inOrderTraversalRecursive(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The Inorder Traversal Of Binary Tree Iteratively: "<<endl;
    ans = inOrderTraversalIterative(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    cout<<"The Inorder Traversal Of Binary Tree Iterative Morris Traversal: "<<endl;
    ans = inOrderMorrisTraversal(root);
    for(int a : ans) {
        cout<<a<<" ";
    } cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);
    
    return 0;
}
