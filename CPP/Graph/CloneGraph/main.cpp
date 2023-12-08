#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

// Definition of the Graph class representing a node in the graph
class Graph {
public:
    int value;
    vector<Graph*> neighbors;

    // Constructor to initialize the node with a given value
    Graph(int value) {
        this->value = value;
        this->neighbors = {};
    }
};

// Function to print the graph using DFS traversal
void printGraph(Graph* node, vector<Graph*> &isVisited) {
    // Check if the node is null or has been visited to avoid infinite loops
    if(!node || find(isVisited.begin(), isVisited.end(), node) != isVisited.end()) {
        return;
    }
    // Mark the node as visited
    isVisited.push_back(node);
    // Print the node's value and its neighbors
    cout<<node->value<<": ";
    for(Graph* neighbor: node->neighbors) {
        cout<<neighbor->value<<" ";
    }
    cout<<endl;
    // Recursively print neighbors of the node
    for(Graph* neighbor: node->neighbors) {
        printGraph(neighbor, isVisited);
    }
}

//Approach: Function to perform DFS traversal and clone the graph
Graph* dfsTraversal(Graph* node, unordered_map<Graph*, Graph*> &visited) {
    // Create a new node in the cloned graph corresponding to the current node
    Graph* clonedNode = new Graph(node->value);
    // Map the original node to its cloned counterpart in the visited map
    visited[node] = clonedNode;
    // Traverse each neighbor of the current node
    for(auto neighbor: node->neighbors) {
        // Check if the neighbor has already been visited
        if(visited[neighbor]) {
            // If yes, connect the cloned node to the already visited cloned neighbor
            clonedNode->neighbors.push_back(visited[neighbor]);
        } else {
            // If not, recursively clone the neighbor and connect it
            Graph* clonedNeighbor = dfsTraversal(neighbor, visited);
            clonedNode->neighbors.push_back(clonedNeighbor);
        }
    }
    return clonedNode;
}

//Approach 1: Function to clone the graph using DFS
Graph* cloneGraphDFS(Graph* node) {
    // Check if the input node is nullptr
    if(!node) {
        return nullptr;
    }
    // Check if the node has no neighbors (leaf node)
    if(node->neighbors.size() == 0) {
        // Create a new node with the same value and return
        Graph* clonedNode = new Graph(node->value);
        return clonedNode;
    }
    // Create a map to track visited nodes during DFS traversal
    unordered_map<Graph*, Graph*> visited;
    // Call the DFS traversal function to clone the graph
    return dfsTraversal(node, visited);
}

//Approach 2: Function to clone the graph using BFS
Graph* cloneGraphBFS(Graph* node) {
    // Check if the input node is nullptr
    if(!node) {
        return nullptr;
    }
    // Check if the node has no neighbors (leaf node)
    if(node->neighbors.size() == 0) {
        // Create a new node with the same value and return
        Graph* clonedNode = new Graph(node->value);
        return clonedNode;
    }
    // Create a map to track visited nodes during BFS traversal
    unordered_map<Graph*, Graph*> visited;
    // Create a queue for BFS traversal and initialize it with the input node
    queue<Graph*> bfsQueue;
    bfsQueue.push(node);
    // Create the cloned node corresponding to the input node
    Graph* clonedNode = new Graph(node->value);
    // Map the input node to its corresponding cloned node
    visited[node] = clonedNode;
    // Perform BFS traversal
    while(!bfsQueue.empty()) {
        // Get the front node from the queue
        Graph* frontNode = bfsQueue.front();
        bfsQueue.pop();
        // Iterate through the neighbors of the front node
        for(auto neighbor: frontNode->neighbors) {
            // If the neighbor has not been visited, create a cloned node
            if(!visited[neighbor]) {
                Graph* clonedNeighbor = new Graph(neighbor->value);
                // Map the original neighbor to its cloned version
                visited[neighbor] = clonedNeighbor;
                // Enqueue the original neighbor for further exploration
                bfsQueue.push(neighbor);
            }
            // Connect the cloned nodes in the graph
            visited[frontNode]->neighbors.push_back(visited[neighbor]);
        }
    }
    // Return the cloned graph
    return clonedNode;
}

int main() {
    Graph* node1 = new Graph(0);
    Graph* node2 = new Graph(1);
    Graph* node3 = new Graph(2);
    Graph* node4 = new Graph(3);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    cout<<"The Initial Graph: "<<endl;
    vector<Graph*> isVisited;
    printGraph(node1, isVisited);

    cout<<endl<<"The Cloned Graph using DFS: "<<endl;
    Graph *clonedNodeDFS = cloneGraphDFS(node1);
    isVisited.clear();
    printGraph(clonedNodeDFS, isVisited);

    cout<<endl<<"The Cloned Graph using BFS: "<<endl;
    Graph *clonedNodeBFS = cloneGraphBFS(node1);
    isVisited.clear();
    printGraph(clonedNodeBFS, isVisited);

    return 0;
}
