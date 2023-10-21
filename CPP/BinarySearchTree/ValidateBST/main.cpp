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

// Function for in-order traversal of a binary search tree using Morris Traversal Approach
void inorderTraversal(Node* root, vector<int> &ans) {
    Node* currNode = root;
    while(currNode) {
        // If the current node has no left child, visit it and move to its right child
        if(!currNode->left) {
            ans.push_back(currNode->value);
            currNode = currNode->right;
        } else {
            // If the current node has a left child, find its in-order predecessor
            Node* predecessor = currNode->left;
            // Traverse to the rightmost node of the left subtree if not visited already
            while(predecessor->right && predecessor->right != currNode) {
                predecessor = predecessor->right;
            }
            // If the predecessor's right child is not assigned, assign it to the current node
            if(!predecessor->right) {
                predecessor->right = currNode;
                currNode = currNode->left;
            } else {
                // If the predecessor's right child is already assigned, visit the current node and then move to its right child
                predecessor->right = nullptr;
                ans.push_back(currNode->value);
                currNode = currNode->right;
            }
        }
    }
}

//Approach 1: Function to check if a binary tree is a valid binary search tree
bool checkValidBST(Node* root) {
    if(!root) {
        // An empty tree is not a valid BST
        return false;
    }
    vector<int> inorderAns;
    // Get the in-order traversal
    inorderTraversal(root, inorderAns);
    for(int i = 0; i < inorderAns.size() - 1; i++) {
        if(inorderAns[i] >= inorderAns[i + 1]) {
            // If values are not in ascending order, it's not a valid BST
            return false;
        }
    }
    // If the in-order traversal is in ascending order, it's a valid BST
    return true;
}

// Helper function to recursively check if a binary tree is a valid binary search tree
bool validBSTHelper(Node* root, long long int minVal, long long int maxVal) {
    if(!root) {
        // An empty tree is a valid BST
        return true;
    }
    // Check if the current node's value is within the valid range for a BST
    if(root->value > minVal && root->value < maxVal) {
        // Check left and right subtrees
        bool leftTree = validBSTHelper(root->left, minVal, root->value);
        bool rightTree = validBSTHelper(root->right, root->value, maxVal);
        return leftTree && rightTree;
    } else {
        // The current node's value is not within the valid range
        return false;
    }
}

//Approach 2: Function to check if a binary tree is a valid binary search tree
bool isValidBST(Node* root) {
    if(!root) {
        return true;
    }
    long long int minVal = -1000000000000;
    long long int maxVal = 1000000000000;
    // Call the helper function
    return validBSTHelper(root, minVal, maxVal);
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

    cout<<"Using The Inorder Traversal to Validate the BST: "<<endl;
    if(checkValidBST(root)) {
        cout<<"The BST is Valid"<<endl;
    } else {
        cout<<"The BST is not Valid"<<endl;
    }

    cout<<"Using The Recursive Approach to Validate the BST: "<<endl;
    if(isValidBST(root)) {
       cout<<"The BST is Valid"<<endl;
    } else {
        cout<<"The BST is not Valid"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(15);
    root->right->left = new Node(16);
    root->right->right = new Node(19);

    cout<<"The Level Order Traversal of Binary Search Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    cout<<"Using The Inorder Traversal to Validate the BST: "<<endl;
    if(checkValidBST(root)) {
        cout<<"The BST is Valid"<<endl;
    } else {
        cout<<"The BST is not Valid"<<endl;
    }

    cout<<"Using The Recursive Approach to Validate the BST: "<<endl;
    if(isValidBST(root)) {
       cout<<"The BST is Valid"<<endl;
    } else {
        cout<<"The BST is not Valid"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
