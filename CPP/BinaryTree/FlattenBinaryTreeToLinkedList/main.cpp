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

// Function to print a binary tree as a linked list
void printBinaryTreeToLinkedList(Node* root) {
    Node* currNode = root;
    while(currNode) {
        if(currNode->right) {
            // Print the current node's value followed by "->" if there's a right child
            cout<<currNode->value<<" -> ";
        } else {
            // Print the current node's value without "->" if there's no right child
            cout<<currNode->value;
        }
        currNode = currNode->right;
    } cout<<endl;
}

// Helper function to flatten a binary tree using a recursive approach
void flattenHelper(Node* root, Node* &prevNode) {
    if(!root) {
        return;
    }
    // Recursively flatten the right subtree first, then the left subtree
    flattenHelper(root->right, prevNode);
    flattenHelper(root->left, prevNode);
    // Connect the current node to the previously flattened portion (prevNode)
    root->right = prevNode;
    root->left = nullptr;
    prevNode = root;
}

//Approach 1: Flatten a binary tree using a recursive approach
void flattenRecursive(Node* root) {
    if(!root) {
        return;
    }
    Node* prevNode = nullptr;
    // Start the recursive flattening process
    flattenHelper(root, prevNode);
}

//Approach 2: Flatten a binary tree using an iterative approach (stack-based)
void flattenIterative(Node* root) {
    if(!root) {
        return;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* currNode = st.top();
        st.pop();
        // Push the right child to the stack before the left child
        if(currNode->right) {
            st.push(currNode->right);
        }
        // Push the left child to the stack
        if(currNode->left) {
            st.push(currNode->left);
        }
        // Connect the current node's right child to the next node in the stack
        if(!st.empty()) {
            currNode->right = st.top();
        }
        currNode->left = nullptr;
    }
}

//Approach 3: Flatten Binary Tree to Linked List using the Iterative Morris Traversal
void flattenMorrisTraversal(Node* root) {
    Node* currNode = root;
    while (currNode) {
        if (currNode->left) {
            // If the current node has a left child, find its in-order predecessor
            Node* predecessor = currNode->left;
            while (predecessor->right) {
                // Traverse to the rightmost node of the left subtree if not visited already
                predecessor = predecessor->right;
            }
            // Connect the predecessor's right child to the current node's right child
            predecessor->right = currNode->right;
            // Update the current node's right child to be its left child
            currNode->right = currNode->left;
            // Set the left child to nullptr
            currNode->left = nullptr; 
        }
        // Move to the right child
        currNode = currNode->right; 
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
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->left->left->left = new Node(5);
    root->right->left->left = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);  

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    
    cout<<"Using the Recursive Approach to Flatten the Binary Tree to Linked List: "<<endl;
    flattenRecursive(root);
    printBinaryTreeToLinkedList(root);

    // Clean up memory by deleting the nodes
    deleteTree(root);

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->left->left->left = new Node(5);
    root->right->left->left = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);  

    cout<<"Using the Iterative Approach to Flatten the Binary Tree to Linked List: "<<endl;
    flattenIterative(root);
    printBinaryTreeToLinkedList(root);

    // Clean up memory by deleting the nodes
    deleteTree(root);

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->left->left->left = new Node(5);
    root->right->left->left = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);  

    cout<<"Using the Iterative Morris Traversal Approach to Flatten the Binary Tree to Linked List: "<<endl;
    flattenMorrisTraversal(root);
    printBinaryTreeToLinkedList(root);

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
