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

    // Clean up memory by deleting the nodes
    deleteTree(root);
    
    return 0;
}
