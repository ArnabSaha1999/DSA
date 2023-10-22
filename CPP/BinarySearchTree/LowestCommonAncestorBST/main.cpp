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

//Approach 1: Recursive function to find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree
Node* lowestCommonAncestorRecursively(Node* root, Node* p, Node* q) {
    if(!root) {
        // If the tree is empty or the LCA is not found, return nullptr
        return nullptr;
    }
    if(root->value > p->value && root->value > q->value) {
        // If both p and q are in the left subtree, continue the search in the left subtree
        return lowestCommonAncestorRecursively(root->left, p, q);
    }  
    if(root->value < p->value && root->value < q->value) {
        // If both p and q are in the right subtree, continue the search in the right subtree
        return lowestCommonAncestorRecursively(root->right, p, q);
    }
    // If p and q are in different subtrees, or one of them is the current root, return the current root as the LCA
    return root;
}

//Approach 2: Iterative function to find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree
Node* lowestCommonAncestorIteratively(Node* root, Node* p, Node* q) {
    if(!root) {
        // If the tree is empty or the LCA is not found, return nullptr
        return nullptr;
    }
    Node* currNode = root;
    while(currNode) {
        if(currNode->value > p->value && currNode->value > q->value) {
            // Both p and q are in the left subtree, so move to the left
            currNode = currNode->left;
        } else if(currNode->value < p->value && currNode->value < q->value) {
            // Both p and q are in the right subtree, so move to the right
            currNode = currNode->right;
        } else {
            // If p and q are in different subtrees, or one of them is the current node, return the current node as the LCA
            return currNode;
        }
    }
    // If no LCA is found, return nullptr
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

    Node* p = new Node(13);
    Node* q = new Node(5);

    cout<<"Using the Recursive Approach: "<<endl;
    Node* ans = lowestCommonAncestorRecursively(root, p, q);
    if(ans) {
        cout<<"The Lowest Common Ancestor of "<<p->value<<" and "<<q->value<<" is: "<<ans->value<<endl;
    } else {
        cout<<"No Lowest Common Ancestor found for "<<p->value<<" and "<<q->value<<endl;
    }

    cout<<"Using the Iterative Approach: "<<endl;
    ans = lowestCommonAncestorIteratively(root, p, q);
    if(ans) {
        cout<<"The Lowest Common Ancestor of "<<p->value<<" and "<<q->value<<" is: "<<ans->value<<endl;
    } else {
        cout<<"No Lowest Common Ancestor found for "<<p->value<<" and "<<q->value<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
