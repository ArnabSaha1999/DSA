#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <climits>

using namespace std;

// A Graph class with Nodes and Adjacency List
class Graph {
    // Number of nodes in the graph
    int nodes;
    // Adjacency list representation
    unordered_map<int, list<pair<int, int>>> adjacencyList;

public:
    // Constructor to initialize the number of nodes in the graph
    Graph(int nodes) {
        this->nodes = nodes;
    }

    // Function to add edges to the graph
    void addEdge(vector<vector<int>> &edges) {
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // If weight is not provided, default to 1
            int w = edge[2] ? edge[2] : 1;
            adjacencyList[u].push_back({v, w});
        }
    }

    // Function to print the adjacency list of the graph
    void printGraph() {
        for(auto it : adjacencyList) {
            cout<<it.first<<" : ";
            for(auto &i : it.second) {
                cout<<i.first<<"("<<i.second<<") ";
            } cout<<endl;
        }
    }

    // Helper DFS traversal function to store elements in Topological order
    void dfsHelper(int startNode, unordered_map<int, bool> &visited, stack<int> &topologicalStack) {
        // Mark the current node as visited
        visited[startNode] = true;
        // Explore all neighbors of the current node
        for(auto i: adjacencyList[startNode]) {
            // If the neighbor is not visited, recursively call dfsHelper
            if(!visited[i.first]) {
                dfsHelper(i.first, visited, topologicalStack);
            }
        }
        // Push the current node onto the stack after processing its neighbors
        topologicalStack.push(startNode);
    }

    //Approach 1: Function to find the shortest path using topological sorting and relaxation
    vector<int> findShortedPath(int vertices, int src) {
        // Map to track visited nodes during DFS
        unordered_map<int, bool> visited;
        // Stack to store the topological ordering
        stack<int> topologicalStack;
        // Perform DFS to obtain topological ordering
        for(int i = 0; i < vertices; i++) {
            if(!visited[i]) {
                dfsHelper(i, visited, topologicalStack);
            }
        }
        // Initialize distances with infinity, set source distance to 0
        vector<int> distance(vertices, INT_MAX);
        distance[src] = 0;
        // Process nodes in topological order and update distances
        while(!topologicalStack.empty()) {
            int topNode = topologicalStack.top();
            topologicalStack.pop();
            // Relaxation step
            if(distance[topNode] != INT_MAX) {
                for(auto neighbor: adjacencyList[topNode]) {
                    if(distance[topNode] + neighbor.second < distance[neighbor.first]) {
                        distance[neighbor.first] = distance[topNode] + neighbor.second;
                    }
                }
            } 
        }
        return distance;
    }
};

int main() {
    int nodes = 6;
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 3}, {1, 2, 2}, {1, 3, 6}, {2, 3, 7}, {2, 5, 2}, {3, 4, -1}, {4, 5, -2}};

    int src = 1;
    Graph directedGraph(nodes);
    directedGraph.addEdge(edges);

    cout<<"The Directed Graph with Weight Adjacency List: "<<endl;
    directedGraph.printGraph();

    cout<<"The Shortest Path of all vertices from "<<src<<" as follows: "<<endl;
    vector<int> ans = directedGraph.findShortedPath(6, 1);
    for(int a: ans) {
        cout<<a<<" ";
    } cout<<endl;

    return 0;
}
