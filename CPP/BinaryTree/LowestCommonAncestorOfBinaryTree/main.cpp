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

//Approach 1: Function to find the lowest common ancestor (LCA) of two nodes in a binary tree.
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    // Base case: If the root is null, return null.
    if(!root) {
        return nullptr;
    }
    // If the current root is either p or q, it is the LCA.
    if(root == p || root == q) {
        return root;
    }
    // Recursively find the LCA in the left and right subtrees.
    Node* leftAns = lowestCommonAncestor(root->left, p, q);
    Node* rightAns = lowestCommonAncestor(root->right, p, q);
    // If both left and right subtrees return non-null values, the current root is the LCA.
    if(leftAns && rightAns) {
        return root;
    }
    // If either leftAns or rightAns is non-null, return the non-null value.
    return (leftAns) ? leftAns : rightAns;
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

    Node* p = root->left->left;
    Node* q = root->right->right;

    Node* ans = lowestCommonAncestor(root, p, q);
    cout<<"The Lowest Common Ancestor of "<<p->value<<" and "<<q->value<<" is : "<<ans->value<<endl;
    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
