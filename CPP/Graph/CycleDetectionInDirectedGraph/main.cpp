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
                // Add edge from u to v
                adjacencyList[u].push_back(v);
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

    //Approach 1: Function to detect cycles in a directed graph using BFS (Modified Kahn's Alogrithm)
    bool detectCycleBFS(int vertices) {
        // Calculate in-degrees for each node
        vector<int> inDegree(vertices, 0);
        for(auto i: adjacencyList) {
            for(auto j: i.second) {
                inDegree[j]++;
            }
        }
        // Queue for BFS
        queue<int> bfsQueue;
        // Enqueue nodes with in-degree zero
        for(int i = 0; i < vertices; i++) {
            if(inDegree[i] == 0) {
                bfsQueue.push(i);
            }
        }
        // Count of visited nodes
        int count = 0;
        // Perform BFS
        while(!bfsQueue.empty()) {
            int node = bfsQueue.front();
            bfsQueue.pop();
            count++;
            // Reduce in-degree of neighbors and enqueue if in-degree becomes zero
            for(int neighbor: adjacencyList[node]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    bfsQueue.push(neighbor);
                }
            }
        }
        // If count equals the number of vertices, the graph is a DAG (Directed Acyclic Graph)
        if(count == vertices) {
            return false;
        } 
        return true;
    }

    // Helper function for DFS-based cycle detection
    bool cycleDetectionDFSHelper(int startNode, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjacencyList) {
        visited[startNode] = true;
        dfsVisited[startNode] = true;
        // Traverse neighbors
        for(int i: adjacencyList[startNode]) {
            if(!visited[i]) {
                // Recursively call DFS for unvisited neighbors
                bool isCycleDetected = cycleDetectionDFSHelper(i, visited, dfsVisited, adjacencyList);
                if(isCycleDetected) {
                    return true;
                }
            } else if(dfsVisited[i]) {
                // If the neighbor is visited in the current DFS traversal, a cycle is detected
                return true;
            }
        }
        // Reset DFS visited flag after traversal
        dfsVisited[startNode] = false;
        // No cycle detected
        return false;
    }

    //Approach 2: Function to detect cycles in a directed graph using DFS
    bool detectCycleDFS(int vertices) {
        unordered_map<int, bool> visited, dfsVisited;
        // Traverse each node
        for(int i = 0; i < vertices; i++) {
            if(!visited[i]) {
                // Call DFS helper for unvisited nodes
                if(cycleDetectionDFSHelper(i, visited, dfsVisited, adjacencyList)) {
                    // Cycle detected
                    return true;
                }
            }
        }
        // No cycle detected
        return false;
    }
};

int main() {
    int nodes = 8;
    vector<vector<int>> edges = {{0, 1}, {1, 0}, {0, 2}, {2, 1}, {5, 6}, {5, 7}};

    Graph directedGraph(nodes);
    directedGraph.addEdge(edges);

    cout<<"The Directed Graph Adjacency List: "<<endl;
    directedGraph.printGraph();

    if(directedGraph.detectCycleDFS(nodes)) {
        cout<<"The Graph is a Directed Cyclic Graph"<<endl;
    } else {
        cout<<"The Graph is a Directed Acyclic Graph"<<endl;
    }

    nodes = 3;
    edges = {{0, 1}, {0, 2}};

    Graph directedGraph1(nodes);
    directedGraph1.addEdge(edges);

    cout<<endl<<"The Directed Graph Adjacency List: "<<endl;
    directedGraph1.printGraph();

    if(directedGraph1.detectCycleBFS(nodes)) {
        cout<<"The Graph is a Directed Cyclic Graph"<<endl;
    } else {
        cout<<"The Graph is a Directed Acyclic Graph"<<endl;
    }

    return 0;
}
