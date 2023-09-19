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

//Approach 1: Recursive function to check if two binary trees are the same
bool isSameTreeRecursively(Node* p, Node* q) {
    // Both trees are empty, and thus, they are the same
    if (!p && !q) {
        return true;
    }
    // One tree is empty while the other is not, so they are not the same
    if (!p || !q) {
        return false;
    }
    // Check if the current nodes have the same value and recursively check their left and right subtrees
    return (p->value == q->value) && isSameTreeRecursively(p->left, q->left) && isSameTreeRecursively(p->right, q->right);

}

//Approach 2: Iterative function to check if two binary trees are the same
bool isSameTreeIterative(Node* p, Node* q) {
    // Both trees are empty, and thus, they are the same
    if(!p && !q) {
        return true;
    }
    // One tree is empty while the other is not, so they are not the same
    if(!p || !q) {
        return false;
    }
    // Create two stacks to perform iterative traversal of both trees
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(p);
    st2.push(q);
    while(!st1.empty() && !st2.empty()) {
        Node* node1 = st1.top();
        Node* node2 = st2.top();
        st1.pop();
        st2.pop();
        // Both nodes are empty, continue to the next nodes
        if(!node1 && !node2) {
            continue;
        }
        // Nodes have different values or one node is empty while the other is not, they are not the same
        if((!node1 && node2) || (node1 && !node2) || (node1->value != node2->value)) {
            return false;
        }
        // Push the left and right children of both nodes onto the stacks for further comparison
        st1.push(node1->left);
        st1.push(node1->right);
        st2.push(node2->left);
        st2.push(node2->right);
    }
    // If both stacks are empty, all nodes have been compared and found to be the same
    return (st1.empty() && st2.empty());
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
    Node *root1, *root2;
    root1 = new Node(13);
    root1->left = new Node(15);
    root1->right = new Node(1);
    root1->left->left = new Node(7);
    root1->left->right = new Node(8);
    root1->right->right = new Node(9);
    root1->left->left->left = new Node(11);
    root1->left->right->left = new Node(16);
    root1->left->right->right = new Node(17);
    root1->right->right->left = new Node(91);
    root1->right->right->left->right = new Node(10);

    cout<<"The Level Order Traversal of First Binary Tree: "<<endl;
    levelOrderTraversal(root1);

    root2 = new Node(13);
    root2->left = new Node(15);
    root2->right = new Node(1);
    root2->left->left = new Node(7);
    root2->left->right = new Node(8);
    root2->right->right = new Node(9);
    root2->left->left->left = new Node(11);
    root2->left->right->left = new Node(16);
    root2->left->right->right = new Node(17);
    root2->right->right->left = new Node(91);
    root2->right->right->left->right = new Node(10);


    cout<<"The Level Order Traversal of Second Binary Tree: "<<endl;
    levelOrderTraversal(root2);

    cout<<"Using the Recursive approach: "<<endl;
    if(isSameTreeRecursively(root1, root2)) {
        cout<<"Both the Binary Trees are same"<<endl;
    } else {
        cout<<"The Binary Trees are not same"<<endl;
    }

    cout<<"Using the Iterative approach: "<<endl;
    if(isSameTreeIterative(root1, root2)) {
        cout<<"Both the Binary Trees are same"<<endl;
    } else {
        cout<<"The Binary Trees are not same"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root1);
    deleteTree(root2);

    root1 = new Node(13);
    root1->left = new Node(15);
    root1->right = new Node(1);
    root1->left->left = new Node(7);
    root1->left->right = new Node(8);
    root1->right->right = new Node(9);
    root1->left->left->left = new Node(11);
    root1->left->right->left = new Node(16);
    root1->left->right->right = new Node(17);
    root1->right->right->left = new Node(91);

    cout<<"The Level Order Traversal of First Binary Tree: "<<endl;
    levelOrderTraversal(root1);

    root2 = new Node(13);
    root2->left = new Node(15);
    root2->right = new Node(1);
    root2->left->left = new Node(7);
    root2->left->right = new Node(8);
    root2->right->right = new Node(9);
    root2->left->left->left = new Node(11);
    root2->left->right->left = new Node(16);
    root2->left->right->right = new Node(17);
    root2->right->right->left = new Node(91);
    root2->right->right->left->right = new Node(10);


    cout<<"The Level Order Traversal of Second Binary Tree: "<<endl;
    levelOrderTraversal(root2);

    cout<<"Using the Recursive approach: "<<endl;
    if(isSameTreeRecursively(root1, root2)) {
        cout<<"Both the Binary Trees are same"<<endl;
    } else {
        cout<<"The Binary Trees are not same"<<endl;
    }

    cout<<"Using the Iterative approach: "<<endl;
    if(isSameTreeIterative(root1, root2)) {
        cout<<"Both the Binary Trees are same"<<endl;
    } else {
        cout<<"The Binary Trees are not same"<<endl;
    }

    // Clean up memory by deleting the nodes
    deleteTree(root1);
    deleteTree(root2);

    return 0;
}
