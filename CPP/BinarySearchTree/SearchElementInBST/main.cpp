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

//Approach 1: Recursive function to search for a value in the BST
Node* searchBSTRecursive(Node* root, int value) {
    if(!root) {
        // Return nullptr if the tree is empty or the value is not found
        return root;
    }
    if(root->value == value) {
        // Return the node if the value is found
        return root;
    } else if(root->value > value) {
        // Recursively search in the left subtree
        return searchBSTRecursive(root->left, value);
    } else if(root->value < value) {
        // Recursively search in the right subtree
        return searchBSTRecursive(root->right, value);
    } 
    return nullptr;
}

//Approach 2: Iterative function to search for a value in the BST
Node* searchBSTIterative(Node* root, int value) {
    if(!root) {
        // Return nullptr if the tree is empty
        return root;
    }
    Node* currNode = root;
    while(currNode) {
        if(currNode->value == value) {
            // Return the node if the value is found
            return currNode;
        } else if(currNode->value > value) {
            // Move to the left subtree
            currNode = currNode->left;
        } else {
            // Move to the right subtree
            currNode = currNode->right;
        }
    } 
    // Return nullptr if the value is not found
    return nullptr;
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

    int targetNode = 15;
    cout<<"Using the Recursive Approach: "<<endl;
    Node* ans = searchBSTRecursive(root, targetNode);
    if(ans) {
        cout<<"The Target "<<targetNode<<" is present in BST"<<endl;
    } else {
        cout<<"The Target "<<targetNode<<" is not present in BST"<<endl;
    }

    cout<<"Using the Iterative Approach: "<<endl;
    ans = searchBSTIterative(root, targetNode);
    if(ans) {
        cout<<"The Target "<<targetNode<<" is present in BST"<<endl;
    } else {
        cout<<"The Target "<<targetNode<<" is not present in BST"<<endl;
    }

    targetNode = 14;

    cout<<"Using the Recursive Approach: "<<endl;
    ans = searchBSTRecursive(root, targetNode);
    if(ans) {
        cout<<"The Target "<<targetNode<<" is present in BST"<<endl;
    } else {
        cout<<"The Target "<<targetNode<<" is not present in BST"<<endl;
    }

    cout<<"Using the Iterative Approach: "<<endl;
    ans = searchBSTIterative(root, targetNode);
    if(ans) {
        cout<<"The Target "<<targetNode<<" is present in BST"<<endl;
    } else {
        cout<<"The Target "<<targetNode<<" is not present in BST"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
