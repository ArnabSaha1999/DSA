#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

// Function to print the adjacency list of the graph
void printGraph(unordered_map<int, list<int>> &adjacencyList) {
    cout<<"The Adjacency List of Graph: "<<endl;
    for(auto adj: adjacencyList) {
        cout<<adj.first<<": ";
        for(auto a: adj.second) {
            cout<<a<<" ";
        } cout<<endl;
    }
}

// Function to add edges to the graph's adjacency list
void addEdge(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjacencyList) {
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    printGraph(adjacencyList);
}

//Approach 1: BFS traversal to check if a valid path exists from source to destination
bool validPathBFS(vector<vector<int>> &edges, int vertices, int source, int destination) {
    // Create the graph's adjacency list
    unordered_map<int, list<int>> adjacencyList;
    // Add edges to the adjacency list
    addEdge(edges, adjacencyList);
    // Initialize a vector to keep track of visited nodes
    vector<bool> visited(vertices, false);
    // Mark the source node as visited
    visited[source] = true;
    // Initialize a queue for BFS traversal
    queue<int> bfsQueue;
    // Enqueue the source node
    bfsQueue.push(source);
    // BFS Traversal
    while(!bfsQueue.empty()) {
        int node = bfsQueue.front();
        bfsQueue.pop();
        // Check if the dequeued node is the destination
        if(node == destination) {
            return true;
        }
        // Enqueue unvisited neighbors
        for(int neighbor: adjacencyList[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                bfsQueue.push(neighbor);
            }
        }
    }
    // Path does not exist
    return false;
}

// DFS traversal to check if a valid path exists from source to destination
bool dfsTraversal(int node, int destination, vector<bool> &visited, unordered_map<int, list<int>> &adjacencyList) {
    // Check if the current node is the destination
    if(node == destination) {
        return true;
    }
    // Mark the current node as visited
    visited[node] = true;
    // Recursively explore neighbors
    for(int neighbor: adjacencyList[node]) {
        if(!visited[neighbor]) {
            bool isFound = dfsTraversal(neighbor, destination, visited, adjacencyList);
            if(isFound) {
                // Path exists
                return true;
            }
        }
    }
    // Path does not exist
    return false;
}

//Approach 2: DFS-based function to check if a valid path exists from source to destination
bool validPathDFS(vector<vector<int>> &edges, int vertices, int source, int destination) {
    // Create the graph's adjacency list
    unordered_map<int, list<int>> adjacencyList;
    // Add edges to the adjacency list
    addEdge(edges, adjacencyList);
    // Initialize a vector to keep track of visited nodes
    vector<bool> visited(vertices, false);
    // Use DFS traversal to check for a valid path
    return dfsTraversal(source, destination, visited, adjacencyList);
}

int main() {
    int nodes = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
    int source = 0, destination = 2;

    cout<<"Using BFS Traversal Approach: "<<endl;
    if(validPathBFS(edges, nodes, source, destination)) {
        cout<<"The Given Path from "<<source<<" to "<<destination<<" Exists"<<endl;
    } else {
        cout<<"The Given Path from "<<source<<" to "<<destination<<" Not Exists"<<endl;
    }

    nodes = 6;
    edges = {{0, 1}, {0, 2}, {3, 4}, {3, 5}, {4, 5}};
    source = 0, destination = 5;

    cout<<endl<<"Using DFS Traversal Approach: "<<endl;
    if(validPathDFS(edges, nodes, source, destination)) {
        cout<<"The Given Path from "<<source<<" to "<<destination<<" Exists"<<endl;
    } else {
        cout<<"The Given Path from "<<source<<" to "<<destination<<" Not Exists"<<endl;
    }

    return 0;
}
