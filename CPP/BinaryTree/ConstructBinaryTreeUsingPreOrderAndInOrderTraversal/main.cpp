#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>

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

// Recursive function to perform an post-order traversal of the binary tree
void postOrderHelper(Node* root, vector<int> &ans) {
    if(!root) {
        return;
    }
    // Recursively visit left subtree
    postOrderHelper(root->left, ans);
    // Recursively visit right subtree
    postOrderHelper(root->right, ans);
    // Push the value of the current node
    ans.push_back(root->value);
}

// Perform an post-order traversal of the binary tree using recursion
// Post-order traversal: Left subtree, right subtree, current node
vector<int> postOrderTraversal(Node* root) {
    vector<int> ans;
    postOrderHelper(root, ans);
    return ans;
}

// Function to search for a node value in the inorder traversal
int search(vector<int> &in, int n, int node) {
    for(int i = 0; i < n; i++) {
        if(in[i] == node) {
            // Return the index when the node is found
            return i;
        }
    }
    return -1;
}

// Recursive function to build a binary tree from inorder and preorder traversals
Node* solve(vector<int> &in, vector<int> &pre, int n, int &preIndex, int inStartIndex, int inEndIndex) {
    // Base case: If the inorder index is out of bounds or all nodes have been processed in the preorder traversal
    if(inStartIndex > inEndIndex || preIndex >= n) {
        return nullptr;
    }
    // Extract the current element from the preorder traversal
    int element = pre[preIndex++];
    // Create a new node with the current element
    Node* root = new Node(element);
    // Find the index of the current element in the inorder traversal
    int inIndex = search(in, n, element);
    // Recursively build the left and right subtrees
    root->left = solve(in, pre, n, preIndex, inStartIndex, inIndex - 1);
    root->right = solve(in, pre, n, preIndex, inIndex + 1, inEndIndex);
    return root;
    
}

//Approach 1: Function to build a binary tree from preorder and inorder traversals
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() != inorder.size() || preorder.size() == 0) {
        return nullptr;
    }
    int preIndex = 0;
    //Recursively call the Solve function to create the binary tree
    return solve(inorder, preorder, inorder.size(), preIndex, 0, inorder.size() - 1);
}

// Recursive function to build a binary tree using a hashmap for optimized lookup
Node* buildTreeHelper(vector<int> &in, vector<int> &pre, int n, int &preIndex, int inStartIndex, int inEndIndex, unordered_map<int, int> &mp) {
    // Base case: If the inorder index is out of bounds or all nodes have been processed in the preorder traversal
    if(inStartIndex > inEndIndex || preIndex >= n) {
        return nullptr;
    }
    // Extract the current element from the preorder traversal
    int element = pre[preIndex++];
    // Create a new node with the current element
    Node* root = new Node(element);
    // Find the index of the current element in the hashmap
    int inIndex = mp[element];
    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(in, pre, n, preIndex, inStartIndex, inIndex - 1, mp);
    root->right = buildTreeHelper(in, pre, n, preIndex, inIndex + 1, inEndIndex, mp);
    return root;
    
}

//Approach 2: Function to build a binary tree from preorder and inorder traversals using a hashmap for optimized lookup
Node* buildTreeOptimized(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() != inorder.size() || preorder.size() == 0) {
        return nullptr;
    }
    int preIndex = 0;
    int size = inorder.size();
    unordered_map<int, int> mp;
    // Populate the hashmap with the indices of elements in the inorder traversal for efficient lookup
    for(int i = 0; i < size; i++) {
        mp[inorder[i]] = i;
    }
    //Recursively call the Solve function to create the binary tree
    return buildTreeHelper(inorder, preorder, size, preIndex, 0, size - 1, mp);
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
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};

    cout<<"The input Inorder Traversal: "<<endl;
    for(int in : inorder) {
        cout<<in<<" ";
    } cout<<endl;

    cout<<"The input Preorder Traversal: "<<endl;
    for(int pre : preorder) {
        cout<<pre<<" ";
    } cout<<endl;

    cout<<"Using The Build Tree function: "<<endl;

    Node* root = buildTree(preorder, inorder);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    vector<int> postorder = postOrderTraversal(root);
    cout<<"The Output Postorder Traversal: "<<endl;
    for(int post : postorder) {
        cout<<post<<" ";
    } cout<<endl;

    cout<<"Using The Optimized Build Tree function: "<<endl;

    root = buildTreeOptimized(preorder, inorder);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    postorder = postOrderTraversal(root);
    cout<<"The Output Postorder Traversal: "<<endl;
    for(int post : postorder) {
        cout<<post<<" ";
    } cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
