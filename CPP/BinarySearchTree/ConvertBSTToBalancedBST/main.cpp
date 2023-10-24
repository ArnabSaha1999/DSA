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


// In-order traversal of a binary search tree using Morris Traversal and store values
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

// Function to create a balanced BST from a sorted array of values
Node* createBalancedBST(int start, int end, vector<int> &inorderAns) {
    if(start > end) {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    // Create a new Node for the root with the value from the middle of the sorted values
    Node* root = new Node(inorderAns[mid]);
    // Recursively create left subtree
    root->left = createBalancedBST(start, mid - 1, inorderAns);
    // Recursively create right subtree
    root->right = createBalancedBST(mid + 1, end, inorderAns);
    return root; 
}

//Approach 1: Function to balance a binary search tree using Morris in-order traversal
Node* balanceBST(Node* root) {
    if(!root) {
        return root;
    }
    vector<int> inorderAns;
    // Perform in-order traversal to get values
    inorderTraversal(root, inorderAns);
    // Create a balanced BST
    return createBalancedBST(0, inorderAns.size() - 1, inorderAns);
}

// In-order traversal of a binary search tree using Morris Traversal and store Nodes
void inorderTraversal(Node* root, vector<Node*> &ans) {
    Node* currNode = root;
    while(currNode) {
        // If the current node has no left child, visit it and move to its right child
        if(!currNode->left) {
            ans.push_back(currNode);
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
                ans.push_back(currNode);
                currNode = currNode->right;
            }
        }
    }
}

// Function to create a balanced BST from a sorted array of nodes
Node* createBalancedBST(int start, int end, vector<Node*> &inorderAns) {
    if(start > end) {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    // Set the root to the Node from the middle of the sorted array
    Node* root = inorderAns[mid];
    // Recursively create left subtree
    root->left = createBalancedBST(start, mid - 1, inorderAns);
    // Recursively create right subtree
    root->right = createBalancedBST(mid + 1, end, inorderAns);
    return root; 
}

//Approach 2: Function to balance a binary search tree using Morris in-order traversal and store Nodes
Node* balanceBSTOptimized(Node* root) {
    if(!root) {
        return root;
    }
    vector<Node*> inorderAns;
    // Perform in-order traversal to get Nodes
    inorderTraversal(root, inorderAns);
    // Create a balanced BST
    return createBalancedBST(0, inorderAns.size() - 1, inorderAns);
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

    Node* balancedBst = balanceBST(root);

    cout<<"The Balanced Binary Search Tree: "<<endl;
    levelOrderTraversal(balancedBst);

    // Clean up memory by deleting the nodes
    deleteTree(root);

    root = nullptr;
    root = insertBST(root, 10);
    root = insertBST(root, 7);
    root = insertBST(root, 17);
    root = insertBST(root, 5);
    root = insertBST(root, 19);
    root = insertBST(root, 15);
    root = insertBST(root, 3);
    root = insertBST(root, 1);
    root = insertBST(root, 13);

    balancedBst = balanceBSTOptimized(root);

    cout<<"The Optimized Approach to Balanced Binary Search Tree: "<<endl;
    levelOrderTraversal(balancedBst);

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
