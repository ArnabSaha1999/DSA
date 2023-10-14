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

// Recursive function to perform an pre-order traversal of the binary tree
void preOrderHelper(Node* root, vector<int> &ans) {
    if(!root) {
        return;
    }
    // Push the value of the current node
    ans.push_back(root->value);
    // Recursively visit left subtree
    preOrderHelper(root->left, ans);
    // Recursively visit right subtree
    preOrderHelper(root->right, ans);
}

// Perform an pre-order traversal of the binary tree using recursion
// Pre-order traversal: current node, Left subtree, right subtree
vector<int> preOrderTraversal(Node* root) {
    vector<int> ans;
    preOrderHelper(root, ans);
    return ans;
}

// Function to search for the index of a node value in the inorder traversal
int search(vector<int> &in, int n, int node) {
    for(int i = 0; i < n; i++) {
        // Return the index when the node is found
        if(in[i] == node) {
            return i;
        }
    }
    return -1;
}

// Recursive function to build a binary tree from inorder and postorder traversals
Node* solve(vector<int> &in, vector<int> &post, int n, int &postIndex, int inStartIndex, int inEndIndex) {
    // Base case: If the inorder index is out of bounds or all nodes have been processed in the postorder traversal
    if(inStartIndex > inEndIndex || postIndex < 0) {
        return nullptr;
    }
    // Extract the current element from the postorder traversal
    int element = post[postIndex--];
    // Create a new node with the current element
    Node* root = new Node(element);
    // Find the index of the current element in the inorder traversal
    int inIndex = search(in, n, element);
    // Recursively build the right and left subtrees (note the order)
    root->right = solve(in, post, n, postIndex, inIndex + 1, inEndIndex);
    root->left = solve(in, post, n, postIndex, inStartIndex, inIndex - 1);
    
    return root;
}

//Approach 1: Function to build a binary tree from inorder and postorder traversals
Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(postorder.size() != inorder.size() || postorder.size() == 0) {
        return nullptr;
    }
    int size = inorder.size();
    int postIndex = size - 1;
    //Recursively call the Solve function to create the binary tree
    return solve(inorder, postorder, inorder.size(), postIndex, 0, size - 1);
}

// Recursive helper function to build a binary tree from inorder and postorder traversals with an unordered map for efficient search
Node* buildtreeHelper(vector<int> &in, vector<int> &post, int n, int &postIndex, int inStartIndex, int inEndIndex, unordered_map<int, int> &mp) {
    // Base case: If the inorder index is out of bounds or all nodes have been processed in the postorder traversal
    if(inStartIndex > inEndIndex || postIndex < 0) {
        return nullptr;
    }
    // Extract the current element from the postorder traversal
    int element = post[postIndex--];
    // Create a new node with the current element
    Node* root = new Node(element);
    // Find the index of the current element in the inorder traversal using the unordered map
    int inIndex = mp[element];
    // Recursively build the right and left subtrees (note the order)
    root->right = buildtreeHelper(in, post, n, postIndex, inIndex + 1, inEndIndex, mp);
    root->left = buildtreeHelper(in, post, n, postIndex, inStartIndex, inIndex - 1, mp);
    return root;
}

//Approach 2: Function to build a binary tree from inorder and postorder traversals with an unordered map for efficient search
Node* buildTreeOptimized(vector<int>& inorder, vector<int>& postorder) {
    if(postorder.size() != inorder.size() || postorder.size() == 0) {
        return nullptr;
    }
    int size = inorder.size();
    unordered_map<int, int> mp;
    // Create a mapping of elements to their indices in the inorder traversal
    for(int i = 0; i < size; i++) {
        mp[inorder[i]] = i;
    }
    int postIndex = size - 1;
    //Recursively call the Solve function to create the binary tree
    return buildtreeHelper(inorder, postorder, inorder.size(), postIndex, 0, size - 1, mp);
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
    vector<int> postorder = {9,15,7,20,3};

    cout<<"The input Inorder Traversal: "<<endl;
    for(int in : inorder) {
        cout<<in<<" ";
    } cout<<endl;

    cout<<"The input Postorder Traversal: "<<endl;
    for(int post : postorder) {
        cout<<post<<" ";
    } cout<<endl;

    cout<<"Using The Build Tree function: "<<endl;

    Node* root = buildTree(inorder, postorder);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    vector<int> preorder = preOrderTraversal(root);
    cout<<"The Output Preorder Traversal: "<<endl;
    for(int pre : preorder) {
        cout<<pre<<" ";
    } cout<<endl;

    cout<<"Using The Optimized Build Tree function: "<<endl;

    root = buildTreeOptimized(inorder, postorder);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    preorder = preOrderTraversal(root);
    cout<<"The Output Preorder Traversal: "<<endl;
    for(int pre : preorder) {
        cout<<pre<<" ";
    } cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
