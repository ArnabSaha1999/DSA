#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// A Graph class with Nodes and Adjacency List
class Graph {
    // Number of nodes in the graph
    int nodes;
    // Adjacency list representation
    unordered_map<int, list<int>> adjacencyList;

public:
    // Constructor to initialize the number of nodes in the graph
    Graph(int nodes) {
        this->nodes = nodes;
    }

    // Function to add edges to the graph
    void addEdge(vector<vector<int>> &edges) {
        for(auto edge : edges) {
            int u = edge[0];
            // Iterate over the vertices connected to u
            for(int i = 1; i < edge.size(); i++) {
                int v = edge[i];
                // Add edge from u to v and v to u
                adjacencyList[u].push_back(v);
                adjacencyList[v].push_back(u);
            }
        }
    }

    // Function to print the adjacency list of the graph
    void printGraph() {
        for(auto it : adjacencyList) {
            cout<<it.first<<" : ";
            for(int i : it.second) {
                cout<<i<<" ";
            } cout<<endl;
        }
    }

    //Approach 1: Function to perform cycle detection using Breadth-First Search (BFS)
    bool cycleDetectionUsingBFS(int vertices) {
        // Map to keep track of visited nodes
        unordered_map<int, bool> visited;
        // Map to store parent information for each node during BFS traversal
        unordered_map<int, int> parent;
        // Queue for BFS traversal
        queue<int> bfsQueue;
        // Iterate through each node in the graph (Including Disconnected Component)
        for(int i = 0; i < vertices; i++) {
            // Check if the current node is not visited
            if(!visited[i]) {
                // Mark the current node as visited and set its parent to -1
                visited[i] = true;
                parent[i] = -1;
                // Enqueue the current node for BFS traversal
                bfsQueue.push(i);
                // Perform BFS traversal
                while(!bfsQueue.empty()) {
                    // Dequeue a node from the queue
                    int node = bfsQueue.front();
                    bfsQueue.pop();
                    // Explore neighbors of the current node
                    for(auto neighbor: adjacencyList[node]) {
                        // If the neighbor is already visited and not the parent of the current node, a cycle is detected
                        if(visited[neighbor] && neighbor != parent[node]) {
                            return true;
                        } else if(!visited[neighbor]) {
                            // If the neighbor is not visited, enqueue it for further exploration in BFS
                            bfsQueue.push(neighbor);
                            visited[neighbor] = true;
                            parent[neighbor] = node;
                        }
                    }
                }
            }
        }
        // If no cycle is detected, return false
        return false;
    }

    // Helper function for recursive cycle detection using Depth-First Search (DFS)
    bool cycleDetectionDFSHelper(int startNode, int parentNode, unordered_map<int, bool> &visited) {
        // Mark the current node as visited
        visited[startNode] = true;
        // Explore neighbors of the current node
        for(int i: adjacencyList[startNode]) {
            // If the neighbor is not visited, recursively call cycleDetectionDFSHelper on it
            if(!visited[i]) {
                bool isCycleDetected = cycleDetectionDFSHelper(i, startNode, visited);
                // If a cycle is detected in the recursive call, return true
                if(isCycleDetected) {
                    return true;
                }
            } else if(i != parentNode) {
                // If the neighbor is already visited and not the parent of the current node, a cycle is detected
                return true;
            }
        }
        // If no cycle is detected, return false
        return false;
    }

    //Approach 2: Function to perform cycle detection using Depth-First Search (DFS)
    bool cycleDetectionUsingDFS(int vertices) {
        // Map to keep track of visited nodes
        unordered_map<int, bool> visited;
        // Iterate through each node in the graph
        for(int i = 0; i < vertices; i++) {
            // Check if the current node is not visited
            if(!visited[i]) {
                // If a cycle is detected in the DFS traversal, return true
                if(cycleDetectionDFSHelper(i, -1, visited)) {
                    return true;
                }
            }
        }
        // If no cycle is detected, return false
        return false;
    }
};

int main() {
    int nodes = 8;
    vector<vector<int>> edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}, {5, 6}, {5, 7}};

    Graph undirectedGraph(nodes);
    undirectedGraph.addEdge(edges);

    cout<<"The Undirected Graph Adjacency List: "<<endl;
    undirectedGraph.printGraph();

    if(undirectedGraph.cycleDetectionUsingBFS(nodes)) {
        cout<<"The Graph is a Undirected Cyclic Graph"<<endl;
    } else {
        cout<<"The Graph is a Undirect Acyclic Graph"<<endl;
    }

    nodes = 3;
    edges = {{0, 1}, {0, 2}};

    Graph undirectedGraph1(nodes);
    undirectedGraph1.addEdge(edges);

    cout<<endl<<"The Undirected Graph Adjacency List: "<<endl;
    undirectedGraph1.printGraph();

    if(undirectedGraph1.cycleDetectionUsingDFS(nodes)) {
        cout<<"The Graph is a Undirected Cyclic Graph"<<endl;
    } else {
        cout<<"The Graph is a Undirect Acyclic Graph"<<endl;
    }

    return 0;
}
