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

// Helper function to recursively convert a BST to a Min Heap
Node* convertBSTToMinHeapHelper(Node* root, vector<int> &ans, int &index) {
    if(!root) {
        // Base case: Return null for an empty node
		return nullptr;
	}
    // Traverse the tree in in-order and assign values from the vector
	root->value = ans[index++];
    // Recursively convert the left and right subtrees
	root->left = convertBSTToMinHeapHelper(root->left, ans, index);
	root->right = convertBSTToMinHeapHelper(root->right, ans, index);
    // Return the modified node
	return root;
}

//Approach 1: Main function to convert a BST to a Min Heap
void convertBSTToMinHeap(Node* root) {
    if(!root || !root->left && !root->right) {
        // Base case: Return if the tree is empty or has only one node
		return;
	}
    // To store values of the BST in in-order
	vector<int> inorderAns;
    // Get in-order traversal of BST
	inorderTraversal(root, inorderAns);
    // Initialize the index to the beginning of the vector
	int index = 0;
    // Call the helper function to perform the conversion
	convertBSTToMinHeapHelper(root, inorderAns, index);
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

    cout<<endl<<"The Inorder Traversal of Binary Search Tree: "<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<endl<<"The Preorder Traversal of Binary Search Tree: "<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<endl<<"The Postorder Traversal of Binary Search Tree: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    cout<<endl<<"Converting The BST To Min Heap: "<<endl;
    convertBSTToMinHeap(root);

    cout<<"The Level Order Traversal of Min Heap: "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"The Inorder Traversal of Min Heap: "<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<endl<<"The Preorder Traversal of Min Heap: "<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<endl<<"The Postorder Traversal of Min Heap: "<<endl;
    postorderTraversal(root);
    cout<<endl;

    return 0;
}
