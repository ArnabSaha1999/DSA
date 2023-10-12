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

// Function to compute the maximum sum of non-adjacent nodes.
pair<int, int> solve(Node* root) {
    if(!root) {
        // Base case: If the node is null, return a pair with both values as 0.
        return make_pair(0, 0);
    }
    // Recursively calculate the maximum sums for the left and right subtrees.
    pair<int, int> leftTree = solve(root->left);
    pair<int, int> rightTree = solve(root->right);
    // Initialize a pair to store the result.
    pair<int, int> ans;
    // Calculate the maximum sum including the current node.
    ans.first = root->value + leftTree.second + rightTree.second;
    // Calculate the maximum sum excluding the current node.
    ans.second = max(leftTree.first, leftTree.second) + max(rightTree.first, rightTree.second);
    // Return the result pair.
    return ans;
}

//Approach 1: Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root) {
    // If the root is null, return 0 as there are no nodes to consider.
    if(!root) {
        return 0;
    }
    // Call the solve function to get the maximum sums.
    pair<int, int> ans = solve(root);
    // Return the maximum of the two values in the result pair.
    return max(ans.first, ans.second);
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
    root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right = new Node(2);
    root->left->right->right = new Node(1);
    root->right = new Node(-3);
    root->right->right = new Node(11);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Maximum Sum of Non-Adjacent Nodes: "<<getMaxSum(root)<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
