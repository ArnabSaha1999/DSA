#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

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

// Function to perform an in-order traversal of the binary search tree
void inorderTraversal(Node* root) {
    if(!root) {
        return;
    }
    // Traverse the Left child
    inorderTraversal(root->left);
    // Print the Root value
    cout<<root->value<<" ";
    // Traverse the Right child
    inorderTraversal(root->right);
}

// Function to perform a pre-order traversal of the binary search tree
void preorderTraversal(Node* root) {
    if(!root) {
        return;
    }
    // Print the Root value
    cout<<root->value<<" ";
    // Traverse the Left child
    preorderTraversal(root->left);
    // Traverse the Right child
    preorderTraversal(root->right);
}

// Function to perform a post-order traversal of the binary search tree
void postorderTraversal(Node* root) {
    if(!root) {
        return;
    }
    // Traverse the Left child
    postorderTraversal(root->left);
    // Traverse the Right child
    postorderTraversal(root->right);
    // Print the Root value
    cout<<root->value<<" ";
}

//Approach 1: Build a Binary Search Tree (BST) from a given postorder traversal using a brute-force approach
Node* bstFromPostorderBruteForce(vector<int>& postorder) {
    // Create a new Node for the root with the last element of the postorder traversal
    Node* root = new Node(postorder[postorder.size() - 1]);
    // Iterate through the remaining elements in the postorder traversal to insert them into the BST
    for(int i = postorder.size() - 2; i >= 0; i--) {
        // Create a new Node with the current element
        Node* newNode = new Node(postorder[i]);
        Node* currNode = root;
        // Traverse the BST to find the appropriate position for the new Node
        while(true) {
            if (newNode->value < currNode->value) {
                if (currNode->left == nullptr) {
                    // Insert the new Node as the left child if the current node has no left child
                    currNode->left = newNode;
                    break;
                } else {
                    currNode = currNode->left;
                }
            } else {
                if (currNode->right == nullptr) {
                    // Insert the new Node as the right child if the current node has no right child
                    currNode->right = newNode;
                    break;
                } else {
                    currNode = currNode->right;
                }
            }
        }
    }
    // Return the root of the constructed BST
    return root;
}

// Helper function to create a BST from a given postorder traversal using an optimized approach
Node* createBST(vector<int> &postorder, int mini, int maxi, int &index) {
    if(index < 0) {
        // Return null when the index exceeds the size of the postorder traversal
        return nullptr;
    }
    if(postorder[index] < mini || postorder[index] > maxi) {
        // Return null when the current element is outside the valid range
        return nullptr;
    }
    // Create a new Node with the current element and decrement the index
    Node* root = new Node(postorder[index--]);
    // Recursively build the right and left subtrees by updating the minimum and maximum values
    root->right = createBST(postorder, root->value, maxi, index);
    root->left = createBST(postorder, mini, root->value, index);
    // Return the root of the constructed BST
    return root;
}

//Approach 2: Build a Binary Search Tree (BST) from a given postorder traversal using an optimized approach
Node* bstFromPostorderOptimized(vector<int>& postorder) {
    // Initialize the minimum and maximum values for elements in the BST
    int mini = INT_MIN;
    int maxi = INT_MAX;
    // Initialize the index for the postorder traversal
    int index = postorder.size() - 1;
    // Call the helper function to create the BST and return its root
    return createBST(postorder, mini, maxi, index);
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
    vector<int> postorder = {2,4,3,7,6,5};

    cout<<"The Input Postorder Traversal: "<<endl;
    for(int post : postorder) {
        cout<<post<<" ";
    } cout<<endl;

    cout<<"Using the Brute Force Approach to create BST from Postorder: "<<endl;
    Node* root = bstFromPostorderBruteForce(postorder);

    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    cout<<"Using the Range-Based Optimized Approach to create the BST from Postorder: "<<endl;
    root = bstFromPostorderOptimized(postorder);

    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
