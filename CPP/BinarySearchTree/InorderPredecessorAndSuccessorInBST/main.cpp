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

// Function to insert a value into the binary search tree
Node* insertBST(Node* &root, int value) {
    if(!root) {
        // Create a new node if the tree is empty
        root = new Node(value);
        return root;
    }
    if(root->value == value) {
        // Value already exists, no changes needed
        return root;
    } else if(root->value > value) {
        // Recursively insert into the left subtree
        insertBST(root->left, value);
    } else {
        // Recursively insert into the right subtree
        insertBST(root->right, value);
    }
    return root;
}

// In-order Traversal of a Binary Search Tree using Morris Traversal
void inorderTraversal(Node* root, vector<int> &ans) {
    Node* currNode = root;
    while(currNode) {
        if(!currNode->left) {
            // If there is no left child, add the current node's value to the result
            ans.push_back(currNode->value);
            // Move to the right child
            currNode = currNode->right;
        } else {
            // If there is a left child, find the in-order predecessor
            Node* predecessor = currNode->left;
            // Traverse to the rightmost node of the left subtree if not visited already
            while(predecessor->right && predecessor->right != currNode) {
                predecessor = predecessor->right;
            }
            if(!predecessor->right) {
                // If the predecessor's right is not connected, establish the link
                predecessor->right = currNode;
                // Move to the left child
                currNode = currNode->left;
            } else {
                // If the link is already established, add the current node's value to the result
                predecessor->right = nullptr;
                ans.push_back(currNode->value);
                // Move to the right child
                currNode = currNode->right;
            }
        }
    }
}

//Approach 1: Function to find the in-order predecessor and successor of a key in a BST using Inorder Traversal
pair<int, int> predecessorSuccessor(Node *root, int key) {
    if(!root) {
        // If the tree is empty, return {-1, -1}
        return {-1, -1};
    }
    // Initialize vectors to store in-order traversal result
    vector<int> inorderAns;
    // Perform in-order traversal of the tree and store the result in 'inorderAns'
    inorderTraversal(root, inorderAns);
    int predecessor = -1, successor = -1;
    // Find the predecessor by iterating through the 'inorderAns' from left to right
    for (int i = 0; i < inorderAns.size(); i++) {
        if(inorderAns[i] < key) {
            predecessor = inorderAns[i];
        }
    }
    // Find the successor by iterating through the 'inorderAns' from right to left
    for(int i = inorderAns.size() - 1; i >= 0; i--) {
        if(inorderAns[i] > key) {
            successor = inorderAns[i];
        }
    }
    // Return the predecessor and successor
    return {predecessor, successor};
}

//Approach 2: Optimized function to find the in-order predecessor and successor of a key in a BST
pair<int, int> predecessorSuccessorOptimized(Node *root, int key) {
    if(!root) {
        // If the tree is empty, return {-1, -1}
        return {-1, -1};
    }
    int predecessor = -1;
    int successor = -1;
    // Initializing temporary node with the root
    Node *temp = root;
    // Traverse the tree to find the predecessor and successor
    while (temp != NULL) {
        // Updating predecessor when moving to the right
        if (key > temp->value) {
            predecessor = temp->value;
            temp = temp->right;
        }
        else {
            // Move to the left subtree
            temp = temp->left;
        }
    }
    // Reset the temporary node to the root
    temp = root;
    // Traverse the tree again to find the successor
    while (temp != NULL) {
        // Move to the right subtree
        if (key >= temp->value) {
            temp = temp->right;
        }
        else {
            // Updating successor when moving to the left
            successor = temp->value;
            temp = temp->left;
        }
    }
    // Return the predecessor and successor
    return make_pair(predecessor, successor);
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
    Node* root = nullptr;
    root = insertBST(root, 10);
    root = insertBST(root, 7);
    root = insertBST(root, 17);
    root = insertBST(root, 5);
    root = insertBST(root, 19);
    root = insertBST(root, 15);
    root = insertBST(root, 3);
    root = insertBST(root, 1);
    root = insertBST(root, 13);

    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    int k = 10;
    pair<int, int> preAndSucc = predecessorSuccessor(root, k);
    cout<<"Using the Inorder Traversal Helper Approach: "<<endl;
    cout<<"The Inorder Predecessor of "<<k<<" is: "<<preAndSucc.first<<endl;
    cout<<"The Inorder Successor of "<<k<<" is: "<<preAndSucc.second<<endl;

    preAndSucc = predecessorSuccessorOptimized(root, k);
    cout<<"Using the Optimized Approach: "<<endl;
    cout<<"The Inorder Predecessor of "<<k<<" is: "<<preAndSucc.first<<endl;
    cout<<"The Inorder Successor of "<<k<<" is: "<<preAndSucc.second<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
