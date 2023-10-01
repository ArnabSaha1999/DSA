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

// Helper function for recursive zigzag traversal
void zigzagTraversalHelper(Node* root, int level, vector<vector<int>> &ans) {
    if(!root) {
        return;
    }
    // Ensure that there is a sub-vector for the current level
    if(ans.size() <= level) {
        ans.push_back(vector<int> ());
    }
    // Depending on the level, push the node's value to the temporary vector
    if((level & 1) == 0) {
        // For even levels, left to right
        ans[level].push_back(root->value);
    } else {
        // For odd levels, right to left
        ans[level].insert(ans[level].begin(), root->value);
    }
    // Recursively traverse the left and right subtrees with an increased level
    zigzagTraversalHelper(root->left, level + 1, ans);
    zigzagTraversalHelper(root->right, level + 1, ans);
}

//Approach 1: Function for recursive zigzag traversal
vector<vector<int>> zigzagTraversalRecursively(Node* root) {
    vector<vector<int>> ans;
    if(!root) {
        return ans;
    }
    // Recursively call for root for Zig Zag Traversal level order-wise
    zigzagTraversalHelper(root, 0, ans);
    return ans;
}

//Approach 2: Function for iterative zigzag traversal
vector<vector<int>> zigzagTraversalIteratively(Node* root) {
    vector<vector<int>> ans;
    // Return an empty result if the tree is empty
    if(!root) {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> temp(size);
        for(int i = 0; i < size; i++) {
            Node* currNode = q.front();
            q.pop();
            // Determine the index based on zigzag order
            int index = leftToRight ? i : size - i - 1;
            temp[index] = currNode->value;
            // Enqueue left and right children
            if(currNode->left) {
                q.push(currNode->left);
            }
            if(currNode->right) {
                q.push(currNode->right);
            }
        }
        // Toggle the zigzag direction for the next level
        leftToRight = !leftToRight;
        // Add the temporary vector to the result
        ans.push_back(temp);
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

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Zig Zag Traversal using the Recursive Approach: "<<endl;
    vector<vector<int>> ans = zigzagTraversalRecursively(root);
    int level = 0;
    for(vector<int> temp : ans) {
        cout<<"Level "<<level<<": ";
        for(int a : temp) {
            cout<<a<<" ";
        } cout<<endl;
        level++;
    }
    
    cout<<"The Zig Zag Traversal using the Iterative Approach: "<<endl;
    ans = zigzagTraversalIteratively(root);
    level = 0;
    for(vector<int> temp : ans) {
        cout<<"Level "<<level<<": ";
        for(int a : temp) {
            cout<<a<<" ";
        } cout<<endl;
        level++;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}

