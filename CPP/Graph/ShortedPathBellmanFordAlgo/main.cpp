#include<iostream>
#include<vector>
#include<utility>
#include<climits>

using namespace std;

// A Graph class with Nodes and Adjacency List
class Graph {
    // Number of nodes in the graph
    int nodes;

public:
    // Constructor to initialize the number of nodes in the graph
    Graph(int nodes) {
        this->nodes = nodes;
    }

    //Approach 1: Function to find the shortest path using Bellman-Ford algorithm
    vector<int> findShortedPathBellmanFord(int vertices, int src, vector<pair<pair<int, int>, int>> &edges) {
        // Initialize distances to all vertices as infinity
        vector<int> distance(vertices, 1e9);
        // Set the distance of the source vertex to itself as 0
        distance[src] = 0;
        // Relax edges repeatedly to find the shortest paths
        for(int i = 0; i < vertices - 1; i++) {
            for(auto edge: edges) {
                int u = edge.first.first;
                int v = edge.first.second;
                int w = edge.second;
                // Relax the edge if a shorter path is found
                if(distance[u] != 1e9 && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }
        // Check for negative cycles
        for(auto edge: edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            // If a shorter path is still found, there is a negative cycle
            if(distance[u] != 1e9 && distance[u] + w < distance[v]) {
                return {-1};
            }
        }
        return distance;
    }
};


int main() {
    int nodes = 4;
    vector<pair<pair<int, int>, int>> edges = {{{0, 1}, 4}, {{0, 2}, 3}, {{1, 3}, 7}, {{2, 3}, -2}};
    int src = 0;
    
    Graph undirectedGraph(nodes);
    vector<int> ans = undirectedGraph.findShortedPathBellmanFord(nodes, src, edges);

    if(ans[0] == -1) {
        cout<<"Negative Cycle Detected in Graph"<<endl;
    } else {
        cout<<"The Shorted Path from "<<src<<" to all vertices: "<<endl;
        for(int a: ans) {
            cout<<a<<" ";
        } 
    }

    return 0;
}
