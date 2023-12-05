#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<list>
#include<set>
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
    void addEdge(vector<vector<int>> &edges, bool isDirected) {
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // If weight is not provided, default to 1
            int w = edge.size() == 3 ? edge[2] : 1;
            adjacencyList[u].push_back({v, w});
            // If undirected, add edge from v to u
            if(!isDirected) {
                adjacencyList[v].push_back({u, w});
            }
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

    //Approach 1: Function to find the shortest path from the source to all vertices using Dijkstra's algorithm
    vector<int> findShortestPathDijkstra(int vertices, int src) {
        // Initialize distances with infinity, set source distance to 0
        vector<int> distance(vertices, INT_MAX);
        distance[src] = 0;
        // Priority queue (set) to maintain vertices with their current distance from the source
        set<pair<int, int>> s;
        s.insert({0, src});
        // Dijkstra's algorithm
        while(!s.empty()) {
            // Extract the vertex with the smallest distance
            auto topNode = *(s.begin());
            s.erase(topNode);
            // Relaxation step: Update distances to neighbors if a shorter path is found
            for(auto neighbor: adjacencyList[topNode.second]) {
                if(topNode.first + neighbor.second < distance[neighbor.first]) {
                    // Remove the old entry for the neighbor from the set
                    auto record = s.find({distance[neighbor.first], neighbor.first});
                    if(record != s.end()) {
                        s.erase(record);
                    }
                    // Update distance and insert the updated entry into the set
                    distance[neighbor.first] = topNode.first + neighbor.second;
                    s.insert({distance[neighbor.first], neighbor.first});
                }
            }
        }
        // Return the vector containing the shortest distances to all vertices from the source
        return distance;
    }
};

int main() {
    int nodes = 5;
    vector<vector<int>> edges = {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 1}};
    int src = 0;
    bool isDirected = false;
    Graph undirectedGraph(nodes);
    undirectedGraph.addEdge(edges, isDirected);

    cout<<"The Undirected Graph Adjacency List: "<<endl;
    undirectedGraph.printGraph();

    vector<int> ans = undirectedGraph.findShortestPathDijkstra(nodes, src);

    cout<<"The Distance of all the vertices from "<<src<<": "<<endl;
    for(int a: ans) {
        cout<<a<<" "; 
    } cout<<endl;

    isDirected = true;
    edges = {{0, 2, 1}, {2, 1, 3}, {1, 0, 7}, {1, 4, 1}, {4, 3, 7}, {3, 0, 2}};

    Graph directedGraph(nodes);
    directedGraph.addEdge(edges, isDirected);

    cout<<endl<<"The Directed Graph Adjacency List: "<<endl;
    directedGraph.printGraph();

    ans = directedGraph.findShortestPathDijkstra(nodes, src);

    cout<<"The Distance of all the vertices from "<<src<<": "<<endl;
    for(int a: ans) {
        cout<<a<<" "; 
    } cout<<endl;

    return 0;
}
