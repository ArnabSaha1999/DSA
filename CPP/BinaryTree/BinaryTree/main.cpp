#include<iostream>
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

// Define a class for binary trees
class BinaryTree {
    Node* root;

    // Private helper function to insert a node on the left side
    bool insertLeft(Node* currentNode, int parentValue, Node *newNode) {
        if(!currentNode) {
            // If the current node is nullptr, return false
            return false;
        }
        if(currentNode->value == parentValue) {
            if(!currentNode->left) {
                // If left child is nullptr, insert the new node
                currentNode->left = newNode;
                return true;
            }
            // If left child is not nullptr, return false
            return false;
        }
        // Recursively search for the parent node on the left
        bool inserted = insertLeft(currentNode->left, parentValue, newNode);
        if(!inserted) {
            // If not found on the left, search on the right
            inserted = insertLeft(currentNode->right, parentValue, newNode);
        }
        return inserted;
    }

    // Private helper function to insert a node on the right side
    bool insertRight(Node* currentNode, int parentValue, Node* newNode) {
        if(!currentNode) {
            // If the current node is nullptr, return false
            return false;
        }
        if(currentNode->value == parentValue) {
            if(!currentNode->right) {
                // If right child is nullptr, insert the new node
                currentNode->right = newNode;
                return true;
            }
            // If right child is not nullptr, return false
            return false;
        }
        // Recursively search for the parent node on the left
        bool inserted = insertRight(currentNode->left, parentValue, newNode);
        if(!inserted) {
            // If not found on the left, search on the right
            inserted = insertRight(currentNode->right, parentValue, newNode);
        }
        return inserted;
    }

    // Private helper function for in-order traversal
    void inOrderTraversal(Node* root) {
        if(!root) {
            // If the node is nullptr, return without processing
            return;
        }
        // Visit left subtree
        inOrderTraversal(root->left);
        // Print the current node's value
        cout<<root->value<<" ";
        // Visit right subtree
        inOrderTraversal(root->right);
    }

    // Private helper function for pre-order traversal
    void preOrderTraversal(Node* root) {
        if(!root) {
            // If the node is nullptr, return without processing
            return;
        }
        // Print the current node's value
        cout<<root->value<<" ";
        // Visit left subtree
        preOrderTraversal(root->left);
        // Visit right subtree
        preOrderTraversal(root->right);
    }

    // Private helper function for post-order traversal
    void postOrderTraversal(Node* root) {
        if(!root) {
            // If the node is nullptr, return without processing
            return;
        }
        // Visit left subtree
        postOrderTraversal(root->left);
        // Visit right subtree
        postOrderTraversal(root->right);
        // Print the current node's value
        cout<<root->value<<" ";
    }

    // Private recursive function to delete nodes
    void destroyTree(Node* node) {
        if (node) {
            // Recursively delete left subtree
            destroyTree(node->left);
            // Recursively delete right subtree
            destroyTree(node->right);
            // Delete the current node
            delete node;
        }
    }

public:
    // Constructor to initialize an empty binary tree
    BinaryTree() {
        this->root = nullptr; // Initialize the root pointer to nullptr
    }

    // Public function to insert a node with the specified parent and position
    bool insert(int parentValue, int value, char childPosition) {
        // Create a new node with the given value
        Node* newNode = new Node(value);
        if(!root) {
            // If the tree is empty, set the new node as the root
            root = newNode;
            return true;
        }

        if(childPosition == 'L') {
            // Insert on the left side
            return insertLeft(root, parentValue, newNode);
        } else if(childPosition == 'R') {
            // Insert on the right side
            return insertRight(root, parentValue, newNode);
        }
        // Return false if an invalid child position is specified
        return false;
    }

    // Public function to perform level-order traversal
    void levelOrderTraversal() {
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

    // Public function for in-order traversal
    void inOrderTraversal() {
        if(!root) {
            cout<<"The Binary Tree is empty"<<endl;
            return;
        }
        // Start in-order traversal from the root
        inOrderTraversal(root);
        cout<<endl;
    }

    // Public function for pre-order traversal
    void preOrderTraversal() {
        if(!root) {
            cout<<"The Binary Tree is empty"<<endl;
            return;
        }
        // Start pre-order traversal from the root
        preOrderTraversal(root);
        cout<<endl;
    }

    // Public function for post-order traversal
    void postOrderTraversal() {
        if(!root) {
            cout<<"The Binary Tree is empty"<<endl;
            return;
        }
        // Start post-order traversal from the root
        postOrderTraversal(root);
        cout<<endl;
    }

    // Destructor to release the memory allocated for nodes
    ~BinaryTree() {
        // Call a recursive function to delete nodes
        destroyTree(root);
    }
};

int main() {
    // Create a binary tree object
    BinaryTree bt;
    // Insert nodes into the binary tree
    bt.insert(5,5,'L');
    bt.insert(5,3,'L');
    bt.insert(5,9,'L');
    bt.insert(5,7,'R');
    bt.insert(3,10,'L');
    bt.insert(3,1,'R');
    bt.insert(7,12,'R');
    bt.insert(10,77,'L');
    bt.insert(10,36,'R');
    bt.insert(1,9,'R');
    bt.insert(12,13,'L');
    bt.insert(12,15,'R');
    bt.insert(12,33,'R');

    cout<<"Level Order Traversal: "<<endl;
    bt.levelOrderTraversal();

    cout<<"Inorder Traversal: "<<endl;
    bt.inOrderTraversal();

    cout<<"Preorder Traversal: "<<endl;
    bt.preOrderTraversal();
    
    cout<<"Postorder Traversal: "<<endl;
    bt.postOrderTraversal();

    return 0;
}
