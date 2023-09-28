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

//Approach 1: Recursively invert a binary tree
Node* invertTreeRecursively(Node* root) {
    // Base case: Return if the tree is empty
    if(!root) {
        return root;
    }
    // Swap the left and right subtrees
    swap(root->left, root->right);
    // Recursively invert the left and right subtrees
    invertTreeRecursively(root->left);
    invertTreeRecursively(root->right);
    return root;
}

//Approach 2: Iteratively invert a binary tree using a stack
Node* invertTreeIteratively(Node* root) {
    // Base case: Return if the tree is empty
    if(!root) {
        return root;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* currNode = st.top();
        st.pop();
        // Swap the left and right subtrees of the current node
        swap(currNode->left, currNode->right);
        // Push the left and right children onto the stack for further processing
        if(currNode->left) {
            st.push(currNode->left);
        }
        if(currNode->right) {
            st.push(currNode->right);
        }
    }
    return root;
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

    cout<<"Invert Binary Tree Using the Recursive approach:"<<endl;
    Node* ans = invertTreeRecursively(root);
    levelOrderTraversal(ans);

    // Clean up memory by deleting the nodes
    deleteTree(root);

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

    cout<<"Invert Binary Tree Using the Iterative approach:"<<endl;
    ans = invertTreeIteratively(root);
    levelOrderTraversal(ans);

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
