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

// Helper function for recursive approach 1 to check whether there's a path with a given sum
bool hasPathSumHelper(Node* root, int sum, int targetSum) {
    // Base case: If the node is null, there's no path to consider.
    if(!root) {
        return false;
    }
    // If the current node is a leaf node and the sum matches the targetSum, return true.
    if(!root->left && !root->right) {
        if(sum + root->value == targetSum) {
            return true;
        } 
        return false;
    }
    // Recursively check the left and right subtrees.
    return (hasPathSumHelper(root->left, (sum + root->value), targetSum) || hasPathSumHelper(root->right, (sum + root->value), targetSum));
}

//Approach 1: Recursive approach to Check whether there's a path with a given sum
bool hasPathSumRecursive(Node* root, int targetSum) {
    int sum = 0;
    return hasPathSumHelper(root, sum, targetSum);
}

//Approach 2: Optimized Recursive approach version to check whether there's a path with a given sum
bool hasPathSumRecursiveOptimized(Node* root, int targetSum) {
    // Base case: If the node is null, there's no path to consider.
    if(!root) {
        return false;
    }
    // Subtract the current node's value from the targetSum.
    targetSum -= root->value;
    // If the current node is a leaf node and the remaining targetSum is 0, return true.
    if(!root->left && !root->right && targetSum == 0) {
        return true;
    }
    // Recursively check the left and right subtrees.
    return (hasPathSumRecursiveOptimized(root->left, targetSum) || hasPathSumRecursiveOptimized(root->right, targetSum));
}

//Approach 3: Iterative approach: Check whether there's a path with a given sum
bool hasPathSum(Node* root, int targetSum) {
    // Base case: If the root is null, there's no path to consider, so return false.
    if(!root) {
        return false;
    }
    stack<pair<Node*, int>> st;
    st.push({root, root->value});
    while(!st.empty()) {
        Node* currNode = st.top().first;
        int currSum = st.top().second;
        st.pop();
        // If the current node is a leaf node and the sum matches the targetSum, return true.
        if(!currNode->left && !currNode->right && (currSum == targetSum)) {
            return true;
        }
        // Push left and right children onto the stack for further processing.
        if(currNode->left) {
            st.push({currNode->left, currSum + currNode->left->value});
        }
        if(currNode->right) {
            st.push({currNode->right, currSum + currNode->right->value});
        }
    }
    return false;
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

    int target = 9;

    cout<<"Using the Recursive approach: "<<endl;
    if(hasPathSumRecursive(root, target)) {
        cout<<"The Target Sum: "<<target<<" has Root-To-Leaf Path"<<endl;
    } else {
        cout<<"The Target Sum: "<<target<<" does not have Root-To-Leaf Path"<<endl;
    }

    cout<<"Using the Optimized Recursive approach: "<<endl;
    if(hasPathSumRecursiveOptimized(root, target)) {
        cout<<"The Target Sum: "<<target<<" has Root-To-Leaf Path"<<endl;
    } else {
        cout<<"The Target Sum: "<<target<<" does not have Root-To-Leaf Path"<<endl;
    }

    cout<<"Using the Iterative approach: "<<endl;
    if(hasPathSum(root, target)) {
        cout<<"The Target Sum: "<<target<<" has Root-To-Leaf Path"<<endl;
    } else {
        cout<<"The Target Sum: "<<target<<" does not have Root-To-Leaf Path"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
