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

// Function to find the minimum value in the BST using an iterative approach
int minValue(Node* root) {
    if(!root) {
        // Return -1 for an empty tree
        return -1;
    }
    Node* currNode = root;
    while(currNode->left) {
        // Traverse to the leftmost node in the tree
        currNode = currNode->left;
    }
    return currNode->value;
}

// Iterative function to find the maximum value in the BST
int maxValue(Node* root) {
    if(!root) {
        // Return -1 for an empty tree
        return -1;
    }
    Node* currNode = root;
    while(currNode->right) {
        // Traverse to the rightmost node in the tree
        currNode = currNode->right;
    }
    return currNode->value;
}

//Approach 1: Function to delete a node with the minimum value in the BST (Inorder Predecessor)
Node* deleteNodeMinValue(Node* root, int key) {
    if(!root) {
        // If the tree is empty, return nullptr
        return nullptr;
    }
    if(root->value == key) {
        // If it's a leaf node, delete it
        if(!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // If it has a left child only, replace it with the left child
        if(root->left && !root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // If it has a right child only, replace it with the right child
        if(!root->left && root->right) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // If it has both left and right children, replace it with the smallest value from the right subtree
        if(root->left && root->right) {
            int mini = minValue(root->right);
            root->value = mini;
            root->right = deleteNodeMinValue(root->right, mini);
            return root;
        }

    } else if(root->value > key) {
        // Recursively delete in the left subtree
        root->left = deleteNodeMinValue(root->left, key);
    } else {
        root->right = deleteNodeMinValue(root->right, key);
    }
    // Recursively delete in the right subtree
    return root;
}

//Approach 2: Function to delete a node with the maximum value in the BST (Inorder Successor)
Node* deleteNodeMaxValue(Node* root, int key) {
    if(!root) {
        // If the tree is empty, return nullptr
        return nullptr;
    }
    if(root->value == key) {
        // If it's a leaf node, delete it
        if(!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // If it has a left child only, replace it with the left child
        if(root->left && !root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // If it has a right child only, replace it with the right child
        if(!root->left && root->right) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // If it has both left and right children, replace it with the largest value from the left subtree
        if(root->left && root->right) {
            int maxi = maxValue(root->left);
            root->value = maxi;
            root->left = deleteNodeMaxValue(root->left, maxi);
            return root;
        }

    } else if(root->value > key) {
        // Recursively delete in the left subtree
        root->left = deleteNodeMaxValue(root->left, key);
    } else {
        // Recursively delete in the right subtree
        root->right = deleteNodeMaxValue(root->right, key);
    }
    return root;
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

    int deleteNode = 15;
    cout<<"Using the Inorder Predecessor Approach: "<<endl;
    Node* ans = deleteNodeMinValue(root, deleteNode);
    levelOrderTraversal(ans);

    deleteNode = 17;
    cout<<"Using the Inorder Successor Approach: "<<endl;
    ans = deleteNodeMaxValue(root, deleteNode);
    levelOrderTraversal(ans);

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
