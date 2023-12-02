#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<algorithm>

using namespace std;

// A Graph class with Nodes and Adjacency List
class Graph {
    // Number of nodes in the graph
    int nodes;

    // Comparison function for sorting edges based on their weights in ascending order
    static bool compare(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
        return a.second < b.second;
    }

    // Function to find the parent of a node using path compression
    int findParent(int node, vector<int> &parent) {
        // If the node is its own parent, return the node
        if(parent[node] == node) {
            return parent[node];
        }
        // Apply path compression and return the updated parent
        return parent[node] = findParent(parent[node], parent);
    }

    // Function to perform union of two sets with ranking to optimize the union operation
    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
        // If one set has higher rank, make the other set a child of it
        if(rank[u] > rank[v]) {
            parent[v] = u;
        } else if(rank[v] > rank[u]) {
            parent[u] = v;
        } else {
            // If ranks are equal, arbitrarily choose one as the parent and increment its rank
            parent[v] = u;
            rank[u]++;
        }
    }

public:

    // Constructor to initialize the number of nodes in the graph
    Graph(int nodes) {
        this->nodes = nodes;
    }

    //Approach 1: Kruskal's algorithm to find the minimum spanning tree
    vector<pair<pair<int, int>, int>> minimumSpanningTreeKrukshalsAlgo(int vertices, vector<pair<pair<int, int>, int>> &edges) {
        // Sort edges based on their weights
        sort(edges.begin(), edges.end(), compare);
        // Initialize parent array and rank array for union-find operations
        vector<int> parent(vertices);
        for(int i = 0; i < vertices; i++) {
            parent[i] = i;
        }
        vector<int> rank(vertices);
        // Vector to store the edges of the minimum spanning tree
        vector<pair<pair<int, int>, int>> ans;
        // Iterate through sorted edges and add to the minimum spanning tree if it doesn't form a cycle
        for(auto edge: edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            // Find the parent of the nodes in the edge
            int parentOfU = findParent(u, parent);
            int parentOfV = findParent(v, parent);
            // If the nodes belong to different sets, add the edge to the minimum spanning tree
            if(parentOfU != parentOfV) {
                unionSet(parentOfU, parentOfV, parent, rank);
                ans.push_back({{u, v}, w});
            }
        }
        // Return the minimum spanning tree
        return ans;
    }
};

int main() {
    int nodes = 5;
    vector<pair<pair<int, int>, int>> edges = {{{0, 1}, 2}, {{1, 2}, 3}, {{0, 3}, 6}, {{1, 3}, 8}, {{1, 4}, 5}, {{2, 4}, 7}};
    
    Graph undirectedGraph(nodes);
    
    vector<pair<pair<int, int>, int>> ans = undirectedGraph.minimumSpanningTreeKrukshalsAlgo(nodes, edges);
    cout<<endl<<"The Minimum Spanning Tree with Krukshal's Algo: "<<endl;
    for(auto a: ans) {
        cout<<a.first.first<<": "<<a.first.second<<"("<<a.second<<")"<<endl;
    }

    return 0;
}
