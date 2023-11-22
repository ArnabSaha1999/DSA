#include<iostream>
#include<vector>

using namespace std;

// A Graph class with Nodes and Adjacency Matrix
class Graph {
    // Number of nodes in the graph
    int nodes;
    // 2D vector to represent the adjacency matrix of the graph
    vector<vector<int>> adjacencyMatrix;
public:
    // Constructor to initialize the graph with the specified number of nodes
    Graph(int nodes) {
        this->nodes = nodes;
        // Initialize the adjacency matrix with zeros
        adjacencyMatrix = vector<vector<int>>(nodes, vector<int> (nodes, 0));
    }

    // Function to create the graph based on provided edges
    void createGraph(vector<vector<int>> &edges, bool isDirected) {
        for(auto edge : edges) {
            int u = edge[0];
            // Iterate over the vertices connected to u
            for(int i = 1; i < edge.size(); i++) {
                int v = edge[i];
                // Set the corresponding entry in the adjacency matrix to 1
                adjacencyMatrix[u][v] = 1;
                // If the graph is undirected, set the reverse entry to 1 as well
                if(!isDirected) {
                    adjacencyMatrix[v][u] = 1;
                }
            }
        }
    }

    // Function to print the adjacency matrix of the graph
    void printGraph() {
        for(int row = 0; row < adjacencyMatrix.size(); row++) {
            cout<<row<<" : ";
            for(int col = 0; col < adjacencyMatrix[row].size(); col++) {
                // Print the entry in the adjacency matrix
                cout<<adjacencyMatrix[row][col]<<" ";
            } cout<<endl;
        }
    }
};

int main() {
    int nodes = 5;
    vector<vector<int>> edges = {{0,1},{0,4},{4,1},{4,3},{1,3},{1,2},{3,2}};
    cout<<"The Edges of Undirected/Directed Graph: "<<endl;
    for(int row = 0; row < edges.size(); row++) {
        for(int col = 0; col < edges[row].size(); col++) {
            cout<<edges[row][col]<<" ";
        } cout<<endl;
    }
    
    bool isDirected = false;
    Graph undirectedGraph(nodes);
    undirectedGraph.createGraph(edges, isDirected);
    cout<<endl<<"The Undirected Graph Adjacency Matrix: "<<endl;
    undirectedGraph.printGraph();

    isDirected = true;
    Graph directedGraph(nodes);
    directedGraph.createGraph(edges, isDirected);
    cout<<endl<<"The Directed Graph Adjacency Matrix: "<<endl;
    directedGraph.printGraph();

    return 0;
}
