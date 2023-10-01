#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = this->right = nullptr;
    }
};

// Class for a Complete Binary Tree
class CompleteBinaryTree {
    Node *root;
public:
    // Constructor to initialize an empty binary tree
    CompleteBinaryTree() {
        this->root = nullptr;
    } 

    //Appraoch 1: Function to insert a value into the binary tree iteratively
    void insert(int val) {
        // Create a new node with the given value
        Node* newNode = new Node(val);
        // If the tree is empty, set the new node as the root
        if(!root) {
            root = newNode;
            // Return to exit the function
            return;
        }
        // Create a queue for level-order traversal
        queue<Node*> q;
        q.push(root);
        // Perform level-order traversal to find the appropriate position for insertion
        while(!q.empty()) {
            Node* currNode = q.front();
            q.pop();
            // If the current node has no left child, insert the new node as its left child
            if(!currNode->left) {
                currNode->left = newNode;
                return;
            }
            // If the current node has no right child, insert the new node as its right child
            if(!currNode->right) {
                currNode->right = newNode;
                return;
            }
            // Enqueue the left and right children for further traversal
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }

    // Public function to perform level-order traversal
    void levelOrderTraversal() {
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

    // Function to perform in-order traversal recursively
    void inOrderTraversal(Node* root) {
        if(!root) {
            // If the node is nullptr, return without processing
            return;
        }
        // Visit left subtree
        inOrderTraversal(root->left);
        // Print the current node's value
        cout<<root->value<<" ";
        // Visit right subtree
        inOrderTraversal(root->right);
    }

    // Public function for in-order traversal
    void inOrderTraversal() {
        if(!root) {
            cout<<"The Binary Tree is empty"<<endl;
            return;
        }
        // Start in-order traversal from the root
        inOrderTraversal(root);
        cout<<endl;
    }

    // Function to get the root node of the binary tree
    Node* getRoot() {
        // Check if the tree is empty (no root)
        if(!root) {
            return nullptr;
        }
        // Return the root node of the binary tree
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
};

int main() {
    CompleteBinaryTree cbt;
    cbt.insert(1);
    cbt.insert(2);
    cbt.insert(3);
    cbt.insert(4);
    cbt.insert(5);
    cbt.insert(6);
    cbt.insert(7);
    cbt.insert(8);

    cout<<"Level Order Traversal: "<<endl;
    cbt.levelOrderTraversal();
    cout<<"In-Order Traversal: "<<endl;
    cbt.inOrderTraversal();

    // Clean up memory by deleting the nodes
    cbt.deleteTree(cbt.getRoot());

    return 0;
}
