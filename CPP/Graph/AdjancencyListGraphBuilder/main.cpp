#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>

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
};

int main() {
    int nodes = 6;
    vector<vector<int>> edges = {{0,1},{0,4},{4,1},{4,3},{1,3},{1,2},{3,2},{5}};
    cout<<"The Edges of Undirected/Directed Graph: "<<endl;
    for(int row = 0; row < edges.size(); row++) {
        for(int col = 0; col < edges[row].size(); col++) {
            cout<<edges[row][col]<<" ";
        } cout<<endl;
    }
    bool isDirected = false;
    Graph undirectedGraph(nodes);
    undirectedGraph.addEdge(edges, isDirected);
    cout<<endl<<"The Undirected Graph Adjacency List: "<<endl;
    undirectedGraph.printGraph();

    isDirected = true;
    Graph directedGraph(nodes);
    directedGraph.addEdge(edges, isDirected);
    cout<<endl<<"The Directed Graph Adjacency List: "<<endl;
    directedGraph.printGraph();
    return 0;
}
