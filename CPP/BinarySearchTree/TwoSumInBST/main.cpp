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

// Search for a pair of nodes in a binary search tree with values summing to 'k'
bool findPair(Node* node1, Node* node2, int k) {
    // Check if either of the nodes is null
    if (!node1 || !node2) {
        return false;
    }
    // Check if the nodes are distinct and their values sum up to k
    if (node1 != node2 && node1->value + node2->value == k) {
        return true;
    }
    if (node1->value + node2->value < k) {
        // If the sum is less than k, we need to increase the sum, so move to the right.
        return findPair(node1, node2->right, k) || findPair(node1->right, node2, k);
    } else {
        // If the sum is greater than k, we need to decrease the sum, so move to the left.
        return findPair(node1, node2->left, k) || findPair(node1->left, node2, k);
    }
}

//Approach 1: Search for a node pair with values summing to 'k' in a binary search tree (Brute Force).
bool findTargetBruteForce(Node* root, int k) {
    // Base case: If the root is null, no pair can be found
    if (!root) {
        return false;
    }
    // Start the search for pairs within the tree
    return findPair(root, root, k);
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

//Approach 2: Find a node pair with values summing to 'k' in a binary search tree using in-order traversal
bool findTarget(Node* root, int k) {
    if(!root) {
        // Base case: If the root is null, no pair can be found
        return false;
    }
    vector<int> inorderAns;
    // Perform in-order traversal and store the values in inorderAns
    inorderTraversal(root, inorderAns);
    int start = 0, end = inorderAns.size() - 1;
    while(start < end) {
        // Check for pairs summing to k
        if(inorderAns[start] + inorderAns[end] == k) {
            return true;
        } else if(inorderAns[start] + inorderAns[end] > k) {
            end--;
        } else {
            start++;
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

    int target = 20;

    cout<<"Using the Brute Force Approach: "<<endl;
    if(findTargetBruteForce(root, target)) {
        cout<<"The Pair exists in BST with target of: "<<target<<endl;
    } else {
        cout<<"The Pair does not exists in BST with target of: "<<target<<endl;
    }

    cout<<"Using the Optimized Inorder Traversal Approach: "<<endl;
    if(findTarget(root, target)) {
        cout<<"The Pair exists in BST with target of: "<<target<<endl;
    } else {
        cout<<"The Pair does not exists in BST with target of: "<<target<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
