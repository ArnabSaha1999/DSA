#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<queue>
#include<unordered_map>
#include<list>
#include<algorithm>

using namespace std;

// A Graph class with Nodes and Adjacency List
class Graph {
    // Number of nodes in the graph
    int nodes;
    // Adjacency list representation
    unordered_map<int, list<pair<int, int>>> adjacencyList;

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

    //Approach 1: Prim's Algorithm to find Minimum Spanning Tree Weight
    int minimumSpanningTreePrimsAlgo(int vertices) {
        // Initialize vectors to store key values, MST set, and parent vertices
        vector<int> key(vertices, INT_MAX);
        vector<bool> mst(vertices, false);
        vector<int> parent(vertices, -1);
        // Use a priority queue to efficiently find the minimum key value
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // Start from the first vertex
        minHeap.push({0, 0});
        key[0] = 0;
        // Variable store the weight of the minimum spanning tree
        int minAnsWeight = 0;
        // Process vertices until the priority queue is empty
        while(!minHeap.empty()) {
            // Include the selected vertex in the MST
            int minWeight = minHeap.top().first;
            int minIndex = minHeap.top().second;
            minHeap.pop();
            // Check if the selected vertex is already included in the MST
            if(mst[minIndex]) {
                // If already included, skip to the next iteration
                continue;
            }
            // Include the selected vertex in the MST
            mst[minIndex] = true;
            // Update the total weight of the MST
            minAnsWeight += minWeight;
            // Update key values and parent vertices for neighboring vertices
            for(auto neighbor: adjacencyList[minIndex]) {
                if(!mst[neighbor.first] && neighbor.second < key[neighbor.first]) {
                    key[neighbor.first] = neighbor.second;
                    parent[neighbor.first] = minIndex;
                    minHeap.push({neighbor.second, neighbor.first});
                }
            }
        }
        // Return the weight of minimum spanning tree
        return minAnsWeight;
    }

    //Approach 2: Kruskal's algorithm to find the minimum spanning tree weight
    int minimumSpanningTreeKrukshalsAlgo(int vertices, vector<pair<pair<int, int>, int>> &edges) {
        // Sort edges based on their weights
        sort(edges.begin(), edges.end(), compare);
        // Initialize parent array and rank array for union-find operations
        vector<int> parent(vertices);
        for(int i = 0; i < vertices; i++) {
            parent[i] = i;
        }
        vector<int> rank(vertices, 0);
        // Variable store the weight of the minimum spanning tree
        int minWeight = 0;
        // Iterate through sorted edges and calculate the weight of minimum spanning tree if it doesn't form a cycle
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
                minWeight += w;
            }
        }
        // Return the weight of minimum spanning tree
        return minWeight;
    }
};

int main() {
    int nodes = 5;
    vector<pair<pair<int, int>, int>> edges = {{{0, 1}, 2}, {{1, 2}, 3}, {{0, 3}, 6}, {{1, 3}, 8}, {{1, 4}, 5}, {{2, 4}, 7}};
    
    Graph undirectedGraph(nodes);
    
    undirectedGraph.addEdge(edges);

    int ans = undirectedGraph.minimumSpanningTreePrimsAlgo(nodes);
    cout<<endl<<"The Minimum Spanning Tree Weight with Prim's Algo: "<<ans<<endl;
    
    ans = undirectedGraph.minimumSpanningTreeKrukshalsAlgo(nodes, edges);
    cout<<endl<<"The Minimum Spanning Tree Weight with Krukshal's Algo: "<<ans<<endl;

    return 0;
}
