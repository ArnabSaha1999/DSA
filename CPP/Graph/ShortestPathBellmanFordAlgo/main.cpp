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
    vector<int> findShortedPathBellmanFord(int vertices, int src, vector<pair<pair<int, int>, int>> &edges, bool isDirected) {
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
                // If the graph is undirected, relax the reverse edge
                if (!isDirected && distance[v] != 1e9 && distance[v] + w < distance[u]) {
                    distance[u] = distance[v] + w;
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
            // If the graph is undirected, relax the reverse edge
            if (!isDirected && distance[v] != 1e9 && distance[v] + w < distance[u]) {
                return {-1};
            }
        }
        return distance;
    }
};


int main() {
    int nodes = 4;
    vector<pair<pair<int, int>, int>> edges = {{{0, 1}, 4}, {{0, 2}, 3}, {{1, 3}, 7}, {{2, 3}, -2}};
    bool isDirected = true;
    int src = 0;
    
    Graph directedGraph(nodes);
    vector<int> ans = directedGraph.findShortedPathBellmanFord(nodes, src, edges, isDirected);

    cout<<"Using Directed Graph: "<<endl;
    if(ans[0] == -1) {
        cout<<"Negative Cycle Detected in Graph"<<endl;
    } else {
        cout<<"The Shorted Path from "<<src<<" to all vertices: "<<endl;
        for(int a: ans) {
            cout<<a<<" ";
        } cout<<endl;
    }

    nodes = 5;
    isDirected = false;
    Graph undirectedGraph(nodes);
    edges = {{{0, 1}, 7}, {{0, 2}, 1}, {{0, 3}, 2}, {{1, 2}, 3}, {{1, 4}, 1}, {{3, 4}, 7}}; 
    ans = undirectedGraph.findShortedPathBellmanFord(nodes, src, edges, isDirected);
    cout<<endl<<"Using Undirected Graph: "<<endl;
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
