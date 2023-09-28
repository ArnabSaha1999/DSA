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

// Helper function to check if two subtrees are symmetric
bool isSymmetricHelper(Node* left, Node* right) {
    // Base case: Both nodes are null, indicating symmetry
    if(!left && !right) {
        return true;
    }
    // Base case: One of the nodes is null while the other is not, indicating asymmetry
    if((!left || !right)) {
        return false;
    } 
    // Check if the values of the current nodes are equal
    if(left->value != right->value) {
        return false;
    }
    // Recursively check the left subtree of the left node with the right subtree of the right node
    // and the right subtree of the left node with the left subtree of the right node
    return (isSymmetricHelper(left->left, right->right) && (isSymmetricHelper(left->right, right->left)));
}

//Approach 1: Function to check if a binary tree is symmetric using recursive approach
bool isSymmetricRecursively(Node* root) {
    // If the tree is empty, it is symmetric by definition
    if(!root) {
        return true;
    }
    // Start the recursive check from the root's left and right subtrees
    return isSymmetricHelper(root->left, root->right);
}

//Approach 2: Function to check if a binary tree is symmetric using iterative approach
bool isSymmetricIteratively(Node* root) {
    // If the tree is empty, it is symmetric by definition
    if(!root) {
        return true;
    }
    // Use a queue to perform level-order traversal
    queue<Node*> q;
    q.push(root->left);
    q.push(root->right);
    while(!q.empty()) {
        Node* left = q.front();
        q.pop();
        Node* right = q.front();
        q.pop();
        // Both nodes are null, continue to the next level
        if(!left && !right) {
            continue;
        }
        // One of the nodes is null while the other is not, indicating asymmetry
        if(!left || !right) {
            return false;
        }
        // Check if the values of the current nodes are equal
        if(left->value != right->value) {
            return false;
        }
        // Enqueue the corresponding nodes for the next level
        q.push(left->left);
        q.push(right->right);
        q.push(left->right);
        q.push(right->left);
    }
    // If the traversal completes without finding asymmetry, the tree is symmetric
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
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"Using the Recursive approach: "<<endl;
    if(isSymmetricRecursively(root)) {
        cout<<"The Tree is Symmetric/Mirror Binary Tree"<<endl;
    } else {
        cout<<"The Tree is not a Symmetric/Mirror Binary Tree"<<endl;
    }

    cout<<"Using the Iterative approach: "<<endl;
    if(isSymmetricIteratively(root)) {
        cout<<"The Tree is Symmetric/Mirror Binary Tree"<<endl;
    } else {
        cout<<"The Tree is not a Symmetric/Mirror Binary Tree"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
