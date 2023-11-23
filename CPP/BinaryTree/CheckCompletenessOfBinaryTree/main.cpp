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

// Function to count the total number of nodes in a binary tree
int countNodes(Node* root) {
    if(!root) {
        return 0;
    }
    // Count nodes in the left and right subtrees
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    // Return the total count of nodes in the tree rooted at 'root'
    return 1 + leftCount + rightCount;
}

// Helper function for checking if a binary tree is complete
bool isCBTHelper(Node* root, int index, int totalNodes) {
    // If the current node is null, it is a valid part of a complete tree
    if(!root) {
        return true;
    }
    // If the current index is beyond the total number of nodes, it's not a complete tree
    if(index >= totalNodes) {
        return false;
    }
    // Recursively check the left and right subtrees
    bool isLeftCBT = isCBTHelper(root->left, index * 2 + 1, totalNodes);
    bool isRightCBT = isCBTHelper(root->right, index * 2 + 2, totalNodes);
    // Return true if both subtrees are complete
    return (isLeftCBT && isRightCBT);
}

//Approach 1: Recursive function to check if a binary tree is a complete binary tree
bool isCompleteTreeRecursively(Node* root) {
    if(!root) {
        // An empty tree is considered complete
        return true;
    }
    // Count the total number of nodes in the tree
    int totalNodes = countNodes(root);
    // Check if the tree is complete using the helper function
    return isCBTHelper(root, 0, totalNodes);   
}

//Approach 2: Iterative function to check if a binary tree is a complete binary tree
bool isCompleteTreeIteratively(Node* root) {
    if (!root) {
        // An empty tree is considered complete
        return true;
    }
    // Use a queue for level order traversal
    queue<Node*> q;
    q.push(root);
    // Flag to indicate if a non-complete structure has been encountered
    bool notCBT = false;

    while (!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        if (currNode) {
            // If a non-complete structure has been encountered, return false
            if (notCBT) {
                return false;
            }
            // Add left and right children to the queue for further exploration
            q.push(currNode->left);
            q.push(currNode->right);
        } else {
            // If a null node is encountered, set the flag to indicate non-complete structure
            notCBT = true;
        }
    }
    // If the loop completes without returning false, the tree is complete
    return true;
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
    Node *root = nullptr;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    if(isCompleteTreeRecursively(root)) {
        cout<<"The Given Binary Tree is Complete Binary Tree"<<endl;
    } else {
        cout<<"The Given Binary Tree is not Complete Binary Tree"<<endl;
    }

    deleteTree(root);

    root = nullptr;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    if(isCompleteTreeIteratively(root)) {
        cout<<"The Given Binary Tree is Complete Binary Tree"<<endl;
    } else {
        cout<<"The Given Binary Tree is not Complete Binary Tree"<<endl;
    }

    deleteTree(root);

    return 0;
}
