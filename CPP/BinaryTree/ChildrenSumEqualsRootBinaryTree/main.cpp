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

bool sumTreeRecursive(Node* root) {
    if(!root) {
        return true;
    }
    if(!root->left && !root->right) {
        return true;
    }
    bool leftSumTree = sumTreeRecursive(root->left);
    bool rightSumTree = sumTreeRecursive(root->right);
    int leftSum = (root->left) ? root->left->value : 0;
    int rightSum = (root->right) ? root->right->value : 0;
    return (root->value == leftSum + rightSum) && leftSumTree && rightSumTree;
}

bool sumTreeIterative(Node* root) {
    if(!root) {
        return true;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        if(!currNode->left && !currNode->right) {
            continue;
        } 
        if((!currNode->left && (currNode->value != currNode->right->value)) || (!currNode->right && (currNode->value != currNode->left->value)) || (currNode->value != currNode->left->value + currNode->right->value)) {
            return false;
        }
        q.push(currNode->left);
        q.push(currNode->right);
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
    root = new Node(31);
    root->left = new Node(9);
    root->right = new Node(22);
    root->right->left = new Node(6);
    root->right->right = new Node(16);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"Using The Recursive approach: "<<endl;
    if(sumTreeRecursive(root)) {
        cout<<"The Binary tree is a Sum tree"<<endl;
    } else {
        cout<<"The Binary tree is not a Sum tree"<<endl;
    }

    cout<<"Using The Iterative approach: "<<endl;
    if(sumTreeIterative(root)) {
        cout<<"The Binary tree is a Sum tree"<<endl;
    } else {
        cout<<"The Binary tree is not a Sum tree"<<endl;
    }

    // cout<<"Using the Optimized Recursive approach: "<<endl;
    // if(isBalancedOptimized(root)) {
    //     cout<<"The Binary tree is a Sum tree"<<endl;
    // } else {
    //     cout<<"The Binary tree is not a Sum tree"<<endl;
    // }
    
    // Clean up memory by deleting the nodes
    deleteTree(root);

    root = new Node(41);
    root->left = new Node(32);
    root->right = new Node(9);
    root->left->left = new Node(31);
    root->left->right = new Node(1);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(5);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"Using the Recursive approach: "<<endl;
    if(sumTreeRecursive(root)) {
        cout<<"The Binary tree is a Sum tree"<<endl;
    } else {
        cout<<"The Binary tree is not a Sum tree"<<endl;
    }

    cout<<"Using The Iterative approach: "<<endl;
    if(sumTreeIterative(root)) {
        cout<<"The Binary tree is a Sum tree"<<endl;
    } else {
        cout<<"The Binary tree is not a Sum tree"<<endl;
    }

    // cout<<"Using the Optimized Recursive approach: "<<endl;
    // if(isBalancedOptimized(root)) {
    //     cout<<"The Binary tree is a Sum tree"<<endl;
    // } else {
    //     cout<<"The Binary tree is not a Sum tree"<<endl;
    // }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
