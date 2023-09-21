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

// Helper function for recursively searching a target node in a cloned binary tree.
void searchNodeHelper(Node* cloned, Node* target, Node* &ans) {
    // Base case: If the current node is null, return.
    if(!cloned) {
        return;
    }
    // If the current node matches the target, update 'ans'.
    if(cloned->value == target->value) {
        ans = cloned;
    }
    // Recursively search in the left and right subtrees.
    searchNodeHelper(cloned->left, target, ans);
    searchNodeHelper(cloned->right, target, ans);
}

//Approach 1: Recursive approach to search for a target node in a cloned binary tree.
Node* searchNodeRecursively(Node* original, Node* cloned, Node* target) {
    Node* ans = nullptr; // Initialize the answer as null.
    searchNodeHelper(cloned, target, ans); // Call the helper function.
    return ans; // Return the answer.
}

//Approach 2: Optimized recursive approach to search for a target node in a cloned binary tree.
Node* searchNodeRecursivelyOptimized(Node* original, Node* cloned, Node* target) {
    // Base case: If the current node is null, return null.
    if(!cloned) {
        return nullptr;
    }
    // If the current node matches the target, return it.
    if(cloned->value == target->value) {
        return cloned;
    }
    // Recursively search in the left subtree.
    Node* leftSubtree = searchNodeRecursivelyOptimized(original, cloned->left, target);
    if(leftSubtree) {
        // If found in the left subtree, return it.
        return leftSubtree;
    }
    // Recursively search in the right subtree.
    Node* rightSubtree = searchNodeRecursivelyOptimized(original, cloned->right, target);
    // If found in the right subtree, return it.
    return rightSubtree;
}

//Approach 3: Iterative approach to search for a target node in a cloned binary tree.
Node* searchNode(Node* original, Node* cloned, Node* target) {
    if(!cloned) {
        // Base case: If the cloned tree is null, return null.
        return nullptr;
    }
    // Initialize the stack with the root node.
    stack<Node*> st;
    st.push(cloned);
    while(!st.empty()) {
        // Get the current node from the stack.
        Node* currNode = st.top();
        st.pop();
        // If the current node matches the target, return it.
        if(currNode->value == target->value) {
            return currNode;
        } 
        // Push left and right children onto the stack for further processing.
        if(currNode->left) {
            st.push(currNode->left);
        }
        if(currNode->right) {
            st.push(currNode->right);
        }
    }
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
    Node* root;
    root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(11);
    root->left->left->left = new Node(9);
    root->left->left->right = new Node(12);
    root->left->right = new Node(1);
    root->right = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(13);
    root->right->right->right = new Node(15);

    cout<<"The Level Order Traversal of Binary Tree: "<<endl;
    levelOrderTraversal(root);

    Node* targetNode = new Node(13);

    cout<<"Using The Recursive approach: "<<endl;
    Node* ans = searchNodeRecursively(root, root, targetNode);
    if(ans) {
        cout<<"The Target Node "<<targetNode->value<<" is present"<<endl;
    } else {
        cout<<"The Target Node "<<targetNode->value<<" is not present"<<endl;
    }

    cout<<"Using The Optimized Recursive approach: "<<endl;
    ans = searchNodeRecursivelyOptimized(root, root, targetNode);
    if(ans) {
        cout<<"The Target Node "<<targetNode->value<<" is present"<<endl;
    } else {
        cout<<"The Target Node "<<targetNode->value<<" is not present"<<endl;
    }

    cout<<"Using The Iterative approach: "<<endl;
    ans = searchNode(root, root, targetNode);
    if(ans) {
        cout<<"The Target Node "<<targetNode->value<<" is present"<<endl;
    } else {
        cout<<"The Target Node "<<targetNode->value<<" is not present"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root);

    return 0;
}
