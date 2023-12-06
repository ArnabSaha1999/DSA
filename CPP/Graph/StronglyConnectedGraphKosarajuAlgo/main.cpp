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
    void addEdge(vector<pair<int, int>> &edges) {
        for(auto edge: edges) {
            int u = edge.first;
            int v = edge.second;
            adjacencyList[u].push_back(v);
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

    // Function to perform DFS traversal and fill finish times in a stack
    void dfsTraversal(int startNode, vector<bool> &visited, stack<int> &finishTimes) {
        visited[startNode] = true;
        // Traverse neighbors and recursively call DFS for unvisited neighbors
        for(int neighbor: adjacencyList[startNode]) {
            if(!visited[neighbor]) {
                dfsTraversal(neighbor, visited, finishTimes);
            }
        }
        // Push the current node to the stack after finishing its DFS traversal
        finishTimes.push(startNode);
    }

    // Function to create the transpose of the graph
    void createTransposeGraph(int vertices, vector<bool> &visited, unordered_map<int, list<int>> &transposeGraph) {
        for(int i = 0; i < vertices; i++) {
            visited[i] = false;
            // Iterate through neighbors and add reverse edges to the transpose graph
            for(int neighbor: adjacencyList[i]) {
                transposeGraph[neighbor].push_back(i);
            }
        }
    }
    
    // Function to perform reverse DFS traversal and find strongly connected components
    void reverseDfsTraversal(int node, vector<int> &component, vector<bool> &visited, unordered_map<int, list<int>> &transposeGraph) {
        visited[node] = true;
        // Add the current node to the current strongly connected component
        component.push_back(node);
        // Traverse neighbors and recursively call reverse DFS for unvisited neighbors
        for(int neighbor: transposeGraph[node]) {
            if(!visited[neighbor]) {
                reverseDfsTraversal(neighbor, component, visited, transposeGraph);
            }
        }
    }
    
    //Approach 1: Function to find strongly connected components using Kosaraju's Algorithm
    vector<vector<int>> stronglyConnectedComponentsKosarajusAlgo(int vertices) {
        stack<int> finishTimes;
        vector<bool> visited(vertices, false);
        // Step 1: Perform DFS traversal and fill finish times in the stack
        for(int i = 0; i < vertices; i++) {
            for(int neighbor: adjacencyList[i]) {
                if(!visited[neighbor]) {
                    dfsTraversal(neighbor, visited, finishTimes);
                }
            }
        }
        // Step 2: Create the transpose of the graph
        unordered_map<int, list<int>> transposeGraph;
        createTransposeGraph(vertices, visited, transposeGraph);
        // Step 3: Perform reverse DFS traversal on the transpose graph and find strongly connected components
        vector<vector<int>> stronglyConnectedComponents;
        while(!finishTimes.empty()) {
            int u = finishTimes.top();
            finishTimes.pop();
            vector<int> component;
            // If the node is not visited, perform reverse DFS traversal and add the component to the result
            if(!visited[u]) {
                reverseDfsTraversal(u, component, visited, transposeGraph);
                stronglyConnectedComponents.push_back(component);
            }
        }
        // Return the vector of strongly connected components
        return stronglyConnectedComponents;
    }
};

int main() {
    int nodes = 5;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};

    Graph directedGraph(nodes);

    directedGraph.addEdge(edges);
    cout<<"Printing the Directed Graph Adjacency List: "<<endl;
    directedGraph.printGraph();

    vector<vector<int>> ans = directedGraph.stronglyConnectedComponentsKosarajusAlgo(nodes);

    cout<<endl<<"The Strongly Connected Components using Kosaraju Algorithm: "<<endl;
    for(auto arr: ans) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    return 0;
}
