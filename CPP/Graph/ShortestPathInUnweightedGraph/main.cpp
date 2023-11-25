#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

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
    void addEdge(vector<vector<int>> &edges, bool isDirected) {
        for(auto edge : edges) {
            int u = edge[0];
            // Iterate over the vertices connected to u
            for(int i = 1; i < edge.size(); i++) {
                int v = edge[i];
                // Add edge from u to v
                adjacencyList[u].push_back(v);
                // If undirected, add edge from v to u
                if(!isDirected) {
                    adjacencyList[v].push_back(u);
                }
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

    //Approach 1: Function to find the shortest path from source to destination using BFS
    vector<int> shortestPath(int vertices, int src, int dest) {
        // Map to track whether a node is visited during BFS
        unordered_map<int, bool> visited;
        // Map to store the parent of each node in the shortest path
        unordered_map<int, int> parent;
        // Queue for BFS traversal
        queue<int> bfsQueue;
        for(int i = src; i < vertices; i++) {
            if(!visited[i]) {
                // Initialize the source node as visited and set its parent to -1
                visited[i] = true;
                parent[i] = -1;
                // Enqueue the source node to start BFS
                bfsQueue.push(i);
                // Perform BFS traversal starting from the source node
                while(!bfsQueue.empty()) {
                    int node = bfsQueue.front();
                    bfsQueue.pop();
                    // Explore neighbors of the current node
                    for(int neighbor: adjacencyList[node]) {
                        if(!visited[neighbor]) {
                            // If the neighbor is not visited, mark it as visited,
                            visited[neighbor] = true;
                            // set its parent to the current node, and enqueue it for further exploration
                            parent[neighbor] = node;
                            bfsQueue.push(neighbor);
                        }
                    }
                }
            }
        } 
        // Reconstruct the shortest path from destination to source
        int node = dest;
        vector<int> ansPath;
        ansPath.push_back(dest);
        // Traverse the parent links from destination to source
        while(node != src) {
            node = parent[node];
            ansPath.push_back(node);
        }
        // Reverse the path to obtain it from source to destination
        reverse(ansPath.begin(), ansPath.end());
        // Return the shortest path
        return ansPath;
    }
};

int main() {
    int nodes = 8;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {0, 4}, {1, 2}, {2, 7}, {3, 7}, {4, 5}, {5, 6}, {6, 7}};
    
    int src = 0, dest = 7;
    bool isDirected = false;
    Graph undirectedGraph(nodes);
    undirectedGraph.addEdge(edges, isDirected);

    cout<<"The Undirected Graph Adjacency List: "<<endl;
    undirectedGraph.printGraph();

    cout<<endl<<"The Shortest Path in Undirected Graph of "<<src<<" to "<<dest<<": "<<endl;
    vector<int> ans = undirectedGraph.shortestPath(nodes, src, dest);
    for(int a: ans) {
        cout<<a<<" ";
    } cout<<endl;

    edges = {{0, 1}, {0, 3}, {0, 4}, {1, 2}, {2, 7}, {7, 3}, {4, 5}, {6, 5}, {6, 7}};
    isDirected = true;
    Graph directedGraph(nodes);
    directedGraph.addEdge(edges, isDirected);

    cout<<endl<<"The Directed Graph Adjacency List: "<<endl;
    directedGraph.printGraph();

    cout<<endl<<"The Shortest Path in Directed Graph of "<<src<<" to "<<dest<<": "<<endl;
    ans = directedGraph.shortestPath(nodes, src, dest);
    for(int a: ans) {
        cout<<a<<" ";
    } cout<<endl;

    return 0;
}
