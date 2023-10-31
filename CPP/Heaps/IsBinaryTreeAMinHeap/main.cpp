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

// Function to check if the binary tree is a complete binary tree
bool isCompleteTree(Node* root) {
    if (!root) {
        // An empty tree is a complete binary tree
        return true; 
    }
    queue<Node*> q;
    q.push(root);
    bool notCBT = false;

    while (!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        if (currNode) {
            // If a null node is encountered before a non-null node, it's not a complete tree
            if (notCBT) {
                return false; 
            }
            q.push(currNode->left);
            q.push(currNode->right);
        } else {
            // Indicate that further null nodes are expected
            notCBT = true;
        }
    }

    return true;
}

// Function to check if the binary tree is a min heap recursively
bool isMinHeapRecursively(Node* root) {
    // Leaf nodes and empty trees are min heaps by definition
    if(!root || !root->left && !root->right) {
        return true;
    }
    // If the left child exists, but the right child is missing
    if(root->left && !root->right) {
        // If the parent's value is less than the left child's value, it's still a min heap
        if(root->value < root->left->value) {
            return true;
        } else {
            // Violates the min heap property
            return false;
        }
    }
    // If both left and right children exist and parent value is less than both childs its Min Heap
    if(root->value < root->left->value && root->value < root->right->value) {
        return true;
    } else {
        // Violates the min heap property
        return false;
    }
    // Recursively check the left and right subtrees for min heap property
    bool isLeftHeap = isMinHeapRecursively(root->left);
    bool isRightHeap = isMinHeapRecursively(root->right);
    // Ensure both left and right subtrees satisfy the min heap property
    return isLeftHeap && isRightHeap;
}

//Approach 1: Function to check if the binary tree is a heap using the recursive approach
bool isHeapRecursive(Node* root) {
    if(!root) {
        // An empty tree is considered a heap
        return true;
    }
    // Check if the tree is complete and follows min heap properties recursively
    return (isCompleteTree(root) && isMinHeapRecursively(root));
}

// Function to check if the binary tree is a min heap iteratively
bool isMinHeapIteratively(Node* root) {
    if(!root || !root->left && !root->right) {
        // Leaf nodes and empty trees are min heaps by definition
        return true;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        // If the left child exists
        if(currNode->left) {
            if(currNode->value < currNode->left->value) {
                q.push(currNode->left);
            } else {
                // Violates property of Min-Heap
                return false;
            }
        }
        // If the right child exists
        if(currNode->right) {
            if(currNode->value < currNode->right->value) {
                q.push(currNode->right);
            } else {
                // Violates property of Min-Heap
                return false;
            }
        }
    }
    return true;
}

//Approach 2: Function to check if the binary tree is a heap using the iterative approach
bool isHeapItartive(Node* root) {
    if(!root) {
        // An empty tree is considered a heap
        return true;
    }
    // Check if the tree is complete and follows min heap properties iteratively
    return (isCompleteTree(root) && isMinHeapIteratively(root));
}

// Function to check if the binary tree is a complete min heap
bool isCompleteMinHeap(Node* root) {
    queue<Node*> q;
    q.push(root);
    bool notCBT = false;
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        if(currNode) {
            // If a null node is encountered before a non-null node, it's not a complete min heap
            if(notCBT) {
                return false;
            }
            // If the left child exists
            if(currNode->left) {
                // parent value is greater than left child it not a min-heap
                if(currNode->value > currNode->left->value) {
                    return false;
                }
            }
            // If the right child exists
            if(currNode->right) {
                // parent value is greater than right child it not a min-heap
                if(currNode->value > currNode->right->value) {
                    return false;
                }
            }
            q.push(currNode->left);
            q.push(currNode->right);
        } else {
            // Indicates that further null nodes are expected
            notCBT = true;
        }
    }
    return true;
}

//Approach 3: Function to check if the binary tree is a heap using an optimized approach
bool isHeapOptimized(struct Node* root) {
    if(!root || !root->left && !root->right) {
        // Leaf nodes and empty trees are considered heaps
        return true;
    }
    // Check if the tree is a complete min heap using an optimized approach
    return isCompleteMinHeap(root);
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
    root = new Node(7);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(1);

    cout<<endl<<"The Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"Using the Recursive Approach: "<<endl;
    if(isHeapRecursive(root)) {
        cout<<"The Binary Tree is a Min Heap"<<endl;
    } else {
        cout<<"The Binary Tree is not a Min Heap"<<endl;
    }

    cout<<endl<<"Using the Itarative Approach: "<<endl;
    if(isHeapItartive(root)) {
        cout<<"The Binary Tree is a Min Heap"<<endl;
    } else {
        cout<<"The Binary Tree is not a Min Heap"<<endl;
    }

    cout<<endl<<"Using the Optimized Itarative Approach: "<<endl;
    if(isHeapOptimized(root)) {
        cout<<"The Binary Tree is a Min Heap"<<endl;
    } else {
        cout<<"The Binary Tree is not a Min Heap"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    root = nullptr;
    root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout<<endl<<"The First Binary Tree: "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"Using the Recursive Approach: "<<endl;
    if(isHeapRecursive(root)) {
        cout<<"The Binary Tree is a Min Heap"<<endl;
    } else {
        cout<<"The Binary Tree is not a Min Heap"<<endl;
    }

    cout<<endl<<"Using the Itarative Approach: "<<endl;
    if(isHeapItartive(root)) {
        cout<<"The Binary Tree is a Min Heap"<<endl;
    } else {
        cout<<"The Binary Tree is not a Min Heap"<<endl;
    }

    cout<<endl<<"Using the Optimized Itarative Approach: "<<endl;
    if(isHeapOptimized(root)) {
        cout<<"The Binary Tree is a Min Heap"<<endl;
    } else {
        cout<<"The Binary Tree is not a Min Heap"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
