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

// In-order traversal of a binary search tree using Morris Traversal and store nodes
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

// Merge two sorted arrays of Node pointers, arr1 and arr2, into a single sorted array
vector<Node*> mergeArray(vector<Node*> &arr1, int m, vector<Node*> &arr2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    arr1.resize(k + 1);
    while(i >= 0 && j >= 0) {
        if(arr1[i]->value > arr2[j]->value) {
            // Select the greater element and place it in the merged array
            arr1[k--] = arr1[i--];
        } else {
            // Select the greater element and place it in the merged array
            arr1[k--] = arr2[j--];
        }
    }
    // If there are any remaining elements in arr2, add them to the merged array
    while(j >= 0) {
        arr1[k--] = arr2[j--];
    }
    // Return the merged array
    return arr1;
}

// Create a balanced Binary Search Tree from a sorted array of Node pointers
Node* createBST(vector<Node*> &arr, int start, int end) {
    if(start > end) {
        // Base case: If the start index is greater than the end index, return nullptr
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    Node* root = arr[mid];
    // Recursively build the left and right subtrees
    root->left = createBST(arr, start, mid - 1);
    root->right = createBST(arr, mid + 1, end);
    // Return the root of the BST
    return root;
}

//Approach 1: Merge two Binary Search Trees into a single Binary Search Tree using Inorder Traversal
Node* mergeBST(Node *root1, Node *root2) {
    // Initialize vectors to store the inorder traversal of the two BSTs
    vector<Node*> inorderBst1, inorderBst2;
    // Populate inorderBst1 and inorderBst2 with inorder traversals of root1 and root2
    inorderTraversal(root1, inorderBst1);
    inorderTraversal(root2, inorderBst2);
    // Merge the two inorder traversal arrays into one sorted array
    mergeArray(inorderBst1, inorderBst1.size(), inorderBst2, inorderBst2.size());
    // Create a balanced Binary Search Tree from the merged array and return its root
    return createBST(inorderBst1, 0, inorderBst1.size() - 1);
}

// Convert a Binary Search Tree (BST) to a sorted doubly linked list using in-order traversal
void covertBSTToSortedDoublyLinkedList(Node* root, Node* &head) {
    if(!root) {
        // Base case: If the current node is null, return
        return;
    }
    // Recursive call to traverse the right subtree first
    covertBSTToSortedDoublyLinkedList(root->right, head);
    // Make the current node the new head of the doubly linked list
    root->right = head;
    if(head) {
        head->left = root;
    } 
    head = root;
    // Recursive call to traverse the left subtree
    covertBSTToSortedDoublyLinkedList(root->left, head);
}

// Merge two sorted doubly linked lists into one sorted doubly linked list
Node* mergeSortedDoublyLinkedList(Node* head1, Node* head2) {
    Node* mergedHead = nullptr;
    Node* tailNode = mergedHead;
    while(head1 && head2) {
        if(head1->value <= head2->value) {
            if(!tailNode) {
                // Initialize the merged list with the first node from head1
                mergedHead = tailNode = head1;
            } else {
                // Connect the current node from head1 to the merged list
                tailNode->right = head1;
                head1->left = tailNode;
                tailNode = head1;
            }
            // Move to the next node in head1
            head1 = head1->right;
        } else {
            if(!tailNode) {
                // Initialize the merged list with the first node from head2
                mergedHead = tailNode = head2;
            } else {
                // Connect the current node from head2 to the merged list
                tailNode->right = head2;
                head2->left = tailNode;
                tailNode = head2;
            }
            // Move to the next node in head2
            head2 = head2->right;
        }
    }
    // Handle any remaining nodes in the two lists
    while(head1) {
        if(!tailNode) {
            // Initialize the merged list if it's still empty
            mergedHead = tailNode = head1;
        } else {
            // Connect the current node from head1 to the merged list
            tailNode->right = head1;
            head1->left = tailNode;
            tailNode = head1;
        }
        // Move to the next node in head1
        head1 = head1->right;
    }
    while(head2) {
        if(!tailNode) {
            // Initialize the merged list if it's still empty
            mergedHead = tailNode = head2;
        } else {
            // Connect the current node from head2 to the merged list
            tailNode->right = head2;
            head2->left = tailNode;
            tailNode = head2;
        }
        // Move to the next node in head2
        head2 = head2->right;
    }
    // Return the merged doubly linked list
    return mergedHead;
}

// Find the middle node in a doubly linked list
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    // Traverse the doubly linked list with two pointers: 'slow' moves one step at a time,
    // while 'fast' moves two steps at a time. When 'fast' reaches the end, 'slow' will be
    // at the middle node of the list
    while(fast->right && fast->right->right) {
        // Move 'slow' one step
        slow = slow->right;
        // Move 'fast' two steps
        fast = fast->right->right;
    }
    // Return the middle node found by 'slow'
    return slow;
}

// Create a balanced Binary Search Tree (BST) from a sorted doubly linked list
Node* createBST(Node* head) {
    if(!head) {
        // Base case: If the current doubly linked list node is null, return nullptr
        return nullptr;
    }
    // Find the middle node of the current doubly linked list
    Node* middle = findMiddle(head);
    // The middle node becomes the root of the BST
    Node* root = middle;
    if(middle->left) {
        // If there is a node to the left of the middle, disconnect it to form the left subtree
        middle->left->right = nullptr;
        // Recursively create the left subtree from the left portion of the doubly linked list
        root->left = createBST(head);
    }
    if(middle->right) {
        // If there is a node to the right of the middle, disconnect it to form the right subtree
        middle->right->left = nullptr;
        // Recursively create the right subtree from the right portion of the doubly linked list
        root->right = createBST(middle->right);
    }
    // Return the root of the balanced BST
    return root;
}

//Approach 2: Merge two BSTs into one optimized BST using Doubly Linked List
Node* mergeBSTOptimized(Node *root1, Node *root2) {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    // Convert BSTs to sorted doubly linked lists
    covertBSTToSortedDoublyLinkedList(root1, head1);
    covertBSTToSortedDoublyLinkedList(root2, head2);
    // Merge the sorted doubly linked lists into one
    Node* mergedHead = mergeSortedDoublyLinkedList(head1, head2);
    // Create a balanced BST from the merged doubly linked list
    return createBST(mergedHead);
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
    Node* root1 = nullptr;
    root1 = insertBST(root1, 10);
    root1 = insertBST(root1, 7);
    root1 = insertBST(root1, 17);
    root1 = insertBST(root1, 5);
    root1 = insertBST(root1, 19);
    root1 = insertBST(root1, 15);
    root1 = insertBST(root1, 3);
    root1 = insertBST(root1, 1);
    root1 = insertBST(root1, 13);

    Node* root2 = nullptr;
    root2 = insertBST(root2, 16);
    root2 = insertBST(root2, 14);
    root2 = insertBST(root2, 18);
    root2 = insertBST(root2, 6);
    root2 = insertBST(root2, 11);
    root2 = insertBST(root2, 12);

    cout<<"The Level Order Traversal of First Binary Search Tree: "<<endl;
    levelOrderTraversal(root1);

    cout<<"The Inorder Traversal of First Binary Search Tree: "<<endl;
    inorderTraversal(root1);

    cout<<endl<<"The Preorder Traversal of First Binary Search Tree: "<<endl;
    preorderTraversal(root1);

    cout<<endl<<"The Postorder Traversal of First Binary Search Tree: "<<endl;
    postorderTraversal(root1);
    cout<<endl;

    cout<<"The Level Order Traversal of second Binary Search Tree: "<<endl;
    levelOrderTraversal(root2);

    cout<<"The Inorder Traversal of second Binary Search Tree: "<<endl;
    inorderTraversal(root2);

    cout<<endl<<"The Preorder Traversal of second Binary Search Tree: "<<endl;
    preorderTraversal(root2);

    cout<<endl<<"The Postorder Traversal of second Binary Search Tree: "<<endl;
    postorderTraversal(root2);
    cout<<endl;

    cout<<endl<<"Using the MergeBST Function: "<<endl;

    Node* mergedBST = mergeBST(root1, root2);

    cout<<"The Level Order Traversal of Merged Binary Search Tree: "<<endl;
    levelOrderTraversal(mergedBST);

    cout<<"The Inorder Traversal of Merged Binary Search Tree: "<<endl;
    inorderTraversal(mergedBST);

    cout<<endl<<"The Preorder Traversal of Merged Binary Search Tree: "<<endl;
    preorderTraversal(mergedBST);

    cout<<endl<<"The Postorder Traversal of Merged Binary Search Tree: "<<endl;
    postorderTraversal(mergedBST);
    cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root1);

    // Clean up memory by deleting the nodes
    deleteTree(root2);


    root1 = nullptr;
    root1 = insertBST(root1, 10);
    root1 = insertBST(root1, 7);
    root1 = insertBST(root1, 17);
    root1 = insertBST(root1, 5);
    root1 = insertBST(root1, 19);
    root1 = insertBST(root1, 15);
    root1 = insertBST(root1, 3);
    root1 = insertBST(root1, 1);
    root1 = insertBST(root1, 13);
    
    root2 = nullptr;
    root2 = insertBST(root2, 16);
    root2 = insertBST(root2, 14);
    root2 = insertBST(root2, 18);
    root2 = insertBST(root2, 6);
    root2 = insertBST(root2, 11);
    root2 = insertBST(root2, 12);

    cout<<endl<<"Using the MergeBSTOptimized Function: "<<endl;

    mergedBST = mergeBSTOptimized(root1, root2);

    cout<<"The Level Order Traversal of Merged Binary Search Tree: "<<endl;
    levelOrderTraversal(mergedBST);

    cout<<"The Inorder Traversal of Merged Binary Search Tree: "<<endl;
    inorderTraversal(mergedBST);

    cout<<endl<<"The Preorder Traversal of Merged Binary Search Tree: "<<endl;
    preorderTraversal(mergedBST);

    cout<<endl<<"The Postorder Traversal of Merged Binary Search Tree: "<<endl;
    postorderTraversal(mergedBST);
    cout<<endl;

    // Clean up memory by deleting the nodes
    deleteTree(root1);

    // Clean up memory by deleting the nodes
    deleteTree(root2);

    return 0;
}
