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

    //Approach 1: Function to print the BFS Traversal of the Graph
    vector<vector<int>> bfsOfGraph(int vertices) {
        // Mark nodes as visited
        unordered_map<int, bool> visited;
        // Store the BFS traversal result
        vector<vector<int>> bfsTraversal;
        // Queue for BFS
        queue<int> bfsQueue;
        // Iterate through each node in the graph (For Disconnected Components)
        for(int i = 0; i < vertices; i++) {
            // Check if the current node is not visited
            if(!visited[i]) {
                // Temporary vector to store the current BFS traversal component
                vector<int> temp;
                // Start BFS from the current node
                bfsQueue.push(i);
                visited[i] = true;
                // Perform BFS
                while(!bfsQueue.empty()) {
                    // Get the front node from the queue
                    int node = bfsQueue.front();
                    bfsQueue.pop();
                    // Add the current node to the traversal component
                    temp.push_back(node);
                    // Explore neighbors of the current node
                    for(int &neighbor: adjacencyList[node]) {
                        // If the neighbor is not visited, add it to the queue and mark as visited
                        if(!visited[neighbor]) {
                            bfsQueue.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }
                // Add the current BFS traversal component to the overall result
                bfsTraversal.push_back(temp);
            }
        }
        // Return the final BFS traversal result
        return bfsTraversal;
    }    
};

int main() {
    int nodes = 8;
    vector<vector<int>> edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}, {5, 6}, {5, 7}};

    bool isDirected = false;
    Graph undirectedGraph(nodes);
    undirectedGraph.addEdge(edges, isDirected);

    cout<<"The Undirected Graph Adjacency List: "<<endl;
    undirectedGraph.printGraph();

    vector<vector<int>> ans = undirectedGraph.bfsOfGraph(nodes);
    
    cout<<endl<<"The BFS Traversal of Undirected Graph with Disconnected Components: "<<endl;
    for(auto &arr : ans) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    Graph directedGraph(nodes);
    isDirected = true;
    directedGraph.addEdge(edges, isDirected);

    cout<<endl<<"The Directed Graph Adjacency List: "<<endl;
    directedGraph.printGraph();

    ans = directedGraph.bfsOfGraph(nodes); 

    cout<<endl<<"The BFS Traversal of Directed Graph with Disconnected Components: "<<endl;
    for(auto &arr : ans) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    return 0;
}
