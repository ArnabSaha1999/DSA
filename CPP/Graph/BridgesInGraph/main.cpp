#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
#include<utility>

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
    void addEdge(vector<pair<int, int>> &edges, bool isDirected) {
        for(auto edge: edges) {
            int u = edge.first;
            int v = edge.second;
            adjacencyList[u].push_back(v);
            if(!isDirected) {
                adjacencyList[v].push_back(u);
            }
        }
    }

    // Function to print the adjacency list of the graph
    void printGraph() {
        for(auto it: adjacencyList) {
            cout<<it.first<<": ";
            for(auto i: it.second) {
                cout<<i<<" ";
            } cout<<endl;
        }
    }

    // Function to perform DFS traversal and find bridges in a graph
    void dfsTraversal(int startNode, int parentNode, int &time, vector<int> &discoveryTime, vector<int> &lowestTime, vector<bool> &visited, unordered_map<int, list<int>> &adjacencyList, vector<vector<int>> &bridges) {
        // Mark the current node as visited
        visited[startNode] = true;
        // Initialize discovery and lowest times for the current node
        discoveryTime[startNode] = lowestTime[startNode] = time++;
        // Traverse neighbors of the current node
        for(auto neighbor: adjacencyList[startNode]) {
            // Skip the edge to the parent node
            if(neighbor == parentNode) {
                continue;
            } else if(!visited[neighbor]) {
                // If the neighbor is not visited, recursively call DFS
                dfsTraversal(neighbor, startNode, time, discoveryTime, lowestTime, visited, adjacencyList, bridges);
                // Update the lowest time for the current node
                lowestTime[startNode] = min(lowestTime[startNode], lowestTime[neighbor]);
                // Check for a bridge and add it to the result
                if(lowestTime[neighbor] > discoveryTime[startNode]) {
                    bridges.push_back({startNode, neighbor});
                }
            } else {
                // If the neighbor is already visited, update the lowest time for the current node
                lowestTime[startNode] = min(lowestTime[startNode], discoveryTime[neighbor]);
            }
        }
    }

    //Approach 1: Function to find bridges in a graph
    vector<vector<int>> findBridges(int vertices) {
        // Initialize variables
        int time = 0;
        vector<int> discoveryTime(vertices, -1);
        vector<int> lowestTime(vertices, -1);
        vector<bool> visited(vertices, false);
        int parent = -1;
        vector<vector<int>> bridges;
        // Iterate through all vertices and perform DFS
        for(int i = 0; i < vertices; i++) {
            if(!visited[i]) {
                dfsTraversal(i, parent, time, discoveryTime, lowestTime, visited, adjacencyList, bridges);
            }
        }
        // Return the list of bridges
        return bridges;
    }
};

int main() {
    int nodes = 6;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {0, 4}, {4, 5}, {3, 4}, {3, 5}};
    bool isDirected = false;

    Graph undirectedGraph(nodes);
    cout<<"The Adjacency List of Undirected Graph: "<<endl;
    undirectedGraph.addEdge(edges, isDirected);
    undirectedGraph.printGraph();

    vector<vector<int>> ans = undirectedGraph.findBridges(nodes);

    cout<<"The Bridges in Undirected Graph: "<<endl;
    for(auto arr: ans) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    nodes = 5;
    edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    isDirected = true;

    Graph directedGraph(nodes);

    cout<<endl<<"The Adjacency List of Directed Graph: "<<endl;
    directedGraph.addEdge(edges, isDirected);
    directedGraph.printGraph();

    ans = directedGraph.findBridges(nodes);

    cout<<"The Bridges in Directed Graph: "<<endl;
    for(auto arr: ans) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }
    return 0;
}
