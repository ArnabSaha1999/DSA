#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<list>
#include<queue>
#include<utility>

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
    void addEdge(vector<pair<pair<int, int>, int>> &edges) {
        for(auto edge : edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            adjacencyList[u].push_back({v, w});
            adjacencyList[v].push_back({u, w});
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

    //Approach 1: Function to find the Minimum Spanning Tree using Prim's Algorithm
    vector<pair<pair<int, int>, int>> minimumSpanningTreePrimsAlgo(int vertices) {
        // Initialize vectors to store key values, MST set, and parent vertices
        vector<int> key(vertices, INT_MAX);
        vector<bool> mst(vertices, false);
        vector<int> parent(vertices, -1);
        // Start from the first vertex
        key[0] = 0;
        // Iterate through all vertices
        for(int i = 0; i < vertices; i++) {
            int minWeight = INT_MAX;    
            int minIndex;
            // Find the vertex with the minimum key value that is not yet included in the MST
            for(int j = 0; j < vertices; j++) {
                if(!mst[j] && minWeight > key[j]) {
                    minWeight = key[j];
                    minIndex = j;
                }
            }
            // Include the selected vertex in the MST
            mst[minIndex] = true;
            // Update key values and parent vertices for neighboring vertices
            for(auto neighbor: adjacencyList[minIndex]) {
                if(!mst[neighbor.first] && neighbor.second < key[neighbor.first]) {
                    key[neighbor.first] = neighbor.second;
                    parent[neighbor.first] = minIndex;
                }
            }
        }
        // Construct the result in the form of edges and their weights
        vector<pair<pair<int, int>, int>> ans;
        for(int i = 1; i < vertices; i++) {
            ans.push_back({{parent[i], i}, key[i]});
        }
        // Return ans with Minimum Spanning Tree values
        return ans;
    }

    //Approach 2: Function to find the Minimum Spanning Tree using Optimized Prim's Algorithm with a Priority Queue
    vector<pair<pair<int, int>, int>> minimumSpanningTreeOptimizedPrimsAlgo(int vertices) {
        // Initialize vectors to store key values, MST set, and parent vertices
        vector<int> key(vertices, INT_MAX);
        vector<bool> mst(vertices, false);
        vector<int> parent(vertices, -1);
        // Use a priority queue to efficiently find the minimum key value
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // Start from the first vertex
        minHeap.push({0, 0});
        key[0] = 0;
        // Process vertices until the priority queue is empty
        while(!minHeap.empty()) {
            // Include the selected vertex in the MST
            int minWeight = minHeap.top().first;
            int minIndex = minHeap.top().second;
            minHeap.pop();
            // Include the selected vertex in the MST
            mst[minIndex] = true;
            // Update key values and parent vertices for neighboring vertices
            for(auto neighbor: adjacencyList[minIndex]) {
                if(!mst[neighbor.first] && neighbor.second < key[neighbor.first]) {
                    key[neighbor.first] = neighbor.second;
                    parent[neighbor.first] = minIndex;
                    minHeap.push({neighbor.second, neighbor.first});
                }
            }
        }
        // Construct the result in the form of edges and their weights
        vector<pair<pair<int, int>, int>> ans;
        for(int i = 1; i < vertices; i++) {
            ans.push_back({{parent[i], i}, key[i]});
        }
        // Return ans with Minimum Spanning Tree values
        return ans;
    }
};

int main() {
    int nodes = 5;
    vector<pair<pair<int, int>, int>> edges = {{{0, 1}, 2}, {{1, 2}, 3}, {{0, 3}, 6}, {{1, 3}, 8}, {{1, 4}, 5}, {{2, 4}, 7}};
    
    Graph undirectedGraph(nodes);
    undirectedGraph.addEdge(edges);
    undirectedGraph.printGraph();
    
    vector<pair<pair<int, int>, int>> ans = undirectedGraph.minimumSpanningTreePrimsAlgo(nodes);
    cout<<endl<<"The Minimum Spanning Tree with Prim's Algo: "<<endl;
    for(auto a: ans) {
        cout<<a.first.first<<": "<<a.first.second<<"("<<a.second<<")"<<endl;
    }

    ans = undirectedGraph.minimumSpanningTreeOptimizedPrimsAlgo(nodes);
    cout<<endl<<"The Minimum Spanning Tree with Optimized Prim's Algo: "<<endl;
    for(auto a: ans) {
        cout<<a.first.first<<": "<<a.first.second<<"("<<a.second<<")"<<endl;
    }

    return 0;
}
