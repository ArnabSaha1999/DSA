#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
#include<utility>
#include<climits>

using namespace std;

// Function to print the adjacency list of the graph
void printGraph(unordered_map<int, list<pair<int, int>>> &adjacencyList) {
    cout<<"The Adjacency List of Graph: "<<endl;
    for(auto adj: adjacencyList) {
        cout<<adj.first<<": ";
        for(auto a: adj.second) {
            cout<<a.first<<"("<<a.second<<") ";
        } cout<<endl;
    }
}

// Function to add edges to the graph's adjacency list
void addEdge(vector<vector<int>> &edges, unordered_map<int, list<pair<int, int>>> &adjacencyList) {
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adjacencyList[u].push_back({v, w});
    }
    printGraph(adjacencyList);
}

//Approach 1: Function to find the minimum time to receive a signal to all nodes in the network using Dijakstra's Algorithm
int networkDelayTime(vector<vector<int>> &edges, int source, int vertices) {
    // Create an adjacency list to represent the graph
    unordered_map<int, list<pair<int, int>>> adjacencyList;
    // Populate the adjacency list with edges from the given vector
    addEdge(edges, adjacencyList);
    // Initialize a vector to store the minimum distances from the source to each node
    vector<int> distance(vertices, INT_MAX);
    // The distance from the source to itself is 0
    distance[source] = 0; 
    // Use a set to store pairs of (distance, node) where distance is the minimum distance from the source
    set<pair<int, int>> minSet;
    // Start with the source node and distance 0
    minSet.insert({0, source});
    // Dijkstra's algorithm to find the minimum distances
    while(!minSet.empty()) {
        // Get the node with the minimum distance from the set
        auto minNode = *(minSet.begin());
        // Remove the processed node from the set
        minSet.erase(minNode);
        // Explore neighbors of the current node
        for(auto neighbor: adjacencyList[minNode.second]) {
            // Check if a shorter path is found to the neighbor
            if(distance[neighbor.first] > minNode.first + neighbor.second) {
                // Check if the neighbor is already in the set
                auto record = minSet.find({distance[neighbor.first], neighbor.first});
                if(record != minSet.end()) {
                    // Remove the existing record from the set
                    minSet.erase(record);
                }
                // Update the distance to the neighbor
                distance[neighbor.first] = minNode.first + neighbor.second;
                // Insert the updated distance and neighbor into the set
                minSet.insert({distance[neighbor.first], neighbor.first});
            }
        }
    }
    // Find the maximum distance among all nodes
    int ans = INT_MIN;
    for(int i = 0; i < vertices; i++) {
        ans = max(ans, distance[i]);
    }
    // If any node is still unreachable, return -1; otherwise, return the maximum distance
    return (ans == INT_MAX) ? -1 : ans;
}

int main() {
    int nodes = 4;
    vector<vector<int>> edges = {{1, 0, 1}, {1, 2, 1}, {2, 3, 1}};
    int src = 1;
    cout<<"The Minimum Time to Receive Signal to All Nodes from "<<src<<": "<<networkDelayTime(edges, src, nodes)<<endl<<endl;

    nodes = 2;
    src = 1;
    edges = {{0, 1, 1}};
    cout<<"The Minimum Time to Receive Signal to All Nodes from "<<src<<": "<<networkDelayTime(edges, src, nodes)<<endl;

    return 0;
}
