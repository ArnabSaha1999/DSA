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

//Approach 1: Recursive approach to check if a binary tree is a sum tree
bool sumTreeRecursive(Node* root) {
    // Base case: If the node is null, it's considered a sum tree.
    if(!root) {
        return true;
    }
    // Base case: If the node is a leaf node, it's considered a sum tree.
    if(!root->left && !root->right) {
        return true;
    }
    // Recursively check the left and right subtrees.
    bool leftSumTree = sumTreeRecursive(root->left);
    bool rightSumTree = sumTreeRecursive(root->right);
    // Calculate the sum of left and right child nodes.
    int leftSum = (root->left) ? root->left->value : 0;
    int rightSum = (root->right) ? root->right->value : 0;
    // Check if the current node is a sum tree based on the sum of its children and recursively checked subtrees.
    return (root->value == leftSum + rightSum) && leftSumTree && rightSumTree;
}

//Approach 2: Iterative approach using a queue to check if a binary tree is a sum tree
bool sumTreeIterative(Node* root) {
    // Base case: If the tree is empty, it's considered a sum tree.
    if(!root) {
        return true;
    }
    // Create a queue for level-order traversal.
    queue<Node*> q;
    q.push(root);
    // Perform level-order traversal of the tree.
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        // If the current node is a leaf node, continue to the next node.
        if(!currNode->left && !currNode->right) {
            continue;
        } 
        // Check if the current node is a sum tree based on its children.
        if((!currNode->left && (currNode->value != currNode->right->value)) || (!currNode->right && (currNode->value != currNode->left->value)) || (currNode->value != currNode->left->value + currNode->right->value)) {
            return false;
        }
        // Add the left and right children to the queue for further processing.
        q.push(currNode->left);
        q.push(currNode->right);
    }
    // If the loop completes without returning false, the entire tree is a sum tree.
    return true;
}

// Helper function for the optimized recursive approach
pair<bool, int> sumTreeHelper(Node* root) {
    // Base case: If the node is null, it's considered a sum tree.
    if(!root) {
        return make_pair(true, 0);
    }
    // Base case: If the node is a leaf node, it's considered a sum tree with its value.
    if(!root->left && !root->right) {
        return make_pair(true, root->value);
    }
    // Recursively check the left and right subtrees.
    pair<bool, int> leftTree = sumTreeHelper(root->left);
    pair<bool, int> rightTree = sumTreeHelper(root->right);
    // Check if the current node is a sum tree based on the sum of its children and recursively checked subtrees.
    bool equals = (root->value == leftTree.second + rightTree.second);

    if(leftTree.first && rightTree.first && equals) {
        return make_pair(true, root->value);
    } 
    // If any condition fails, return false to indicate it's not a sum tree.
    return make_pair(false, 0);
}

//Approach 3: Optimized recursive approach to check if a binary tree is a sum tree
bool sumTreeOptimized(Node* root) {
    // Call the helper function to perform the check and return the result.
    return sumTreeHelper(root).first;
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

    cout<<"Using the Optimized Recursive approach: "<<endl;
    if(sumTreeOptimized(root)) {
        cout<<"The Binary tree is a Sum tree"<<endl;
    } else {
        cout<<"The Binary tree is not a Sum tree"<<endl;
    }
    
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

    cout<<"Using the Optimized Recursive approach: "<<endl;
    if(sumTreeOptimized(root)) {
        cout<<"The Binary tree is a Sum tree"<<endl;
    } else {
        cout<<"The Binary tree is not a Sum tree"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
