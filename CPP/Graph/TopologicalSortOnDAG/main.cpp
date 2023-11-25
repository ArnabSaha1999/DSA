#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

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

    // Helper DFS traversal function to store elements in Topological order
    void dfsHelper(int startNode, unordered_map<int, bool> &visited, stack<int> &topologicalStack) {
        // Mark the current node as visited
        visited[startNode] = true;
        // Explore all neighbors of the current node
        for(int i: adjacencyList[startNode]) {
            // If the neighbor is not visited, recursively call dfsHelper
            if(!visited[i]) {
                dfsHelper(i, visited, topologicalStack);
            }
        }        
        // Push the current node onto the stack after processing its neighbors
        topologicalStack.push(startNode);
    }

    //Approach 1: Function to perform topological sort using depth-first search (DFS)
    vector<int> topologicalSortUsingDFS(int vertices) {
        // Map to track visited nodes during DFS
        unordered_map<int, bool> visited;
        // Stack to store the topological ordering
        stack<int> topologicalStack;
        // Perform DFS for each unvisited node in the graph
        for(int i = 0; i < vertices; i++) {
            if(!visited[i]) {
                dfsHelper(i, visited, topologicalStack);
            }
        }
        // Construct the result vector from the stack
        vector<int> topologicalAns;
        while(!topologicalStack.empty()) {
            topologicalAns.push_back(topologicalStack.top());
            topologicalStack.pop();
        }
        // Return the topological ordering
        return topologicalAns;
    }

    //Approach 2: Function to perform topological sort using BFS (Kahn's Algorithm)
    vector<int> topologicalSortUsingBFS(int vertices) {
        // Vector to store in-degrees of nodes
        vector<int> inDegree(vertices);
        // Calculate in-degrees for each node in the graph
        for(auto &i: adjacencyList) {
            for(int j: i.second) {
                inDegree[j]++;
            }
        }
        // Queue for BFS traversal
        queue<int> bfsQueue;
        // Initialize the queue with nodes having in-degree zero
        for(int i = 0; i < vertices; i++) {
            if(inDegree[i] == 0) {
                bfsQueue.push(i);
            }
        }
        // Vector to store the topological ordering
        vector<int> topologicalAns;
        // Perform BFS
        while(!bfsQueue.empty()) {
            int node = bfsQueue.front();
            bfsQueue.pop();
            // Add the node to the topological ordering
            topologicalAns.push_back(node);
            // Update in-degrees and enqueue neighbors with in-degree zero
            for(int neighbor: adjacencyList[node]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    bfsQueue.push(neighbor);
                }
            }
        }
        // Return the topological ordering
        return topologicalAns;
    }
};

int main() {
    int nodes = 9;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3},{2, 5}, {1, 3}, {3, 4}, {4, 5}, {6, 7}, {6, 8}};

    Graph dag(nodes);
    dag.addEdge(edges);

    cout<<"The Directed Acyclic Graph Adjacency List: "<<endl;
    dag.printGraph();

    cout<<"The Topological of the DAG using DFS: "<<endl;
    vector<int> ans = dag.topologicalSortUsingDFS(nodes);
    for(int a: ans) {
        cout<<a<<" ";
    }
    cout<<endl;

    cout<<endl<<"The Topological Sort of the DAG using BFS (Kahn's Algorithm):"<<endl;
    ans = dag.topologicalSortUsingBFS(nodes);
    for(int a: ans) {
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}
