#include<iostream>
#include<vector>

using namespace std;

// Function to find the parent of a node using path compression
int findParent(int node, vector<int> &parent) {
    if(node == parent[node]) {
        return node;
    }
    // Path compression: Update the parent of the current node to the root
    return parent[node] = findParent(parent[node], parent);
}

// Function to perform union operation of two sets based on rank
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

//Approach 1: Function to determine the minimum operations to make the network connected
int makeConnected(int vertices, vector<vector<int>> &edges) {
    // Check if there are enough edges to potentially connect all vertices
    if(edges.size() < vertices - 1) {
        return -1;
    }
    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);
    // Initialize each node as its own parent
    for(int i = 0; i < vertices; i++) {
        parent[i] = i;
    }
    // Initialize the count of connected components to the total number of vertices
    int components = vertices;
    // Iterate over the edges
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        // Find the parents of the sets containing u and v
        int parentOfU = findParent(u, parent);
        int parentOfV = findParent(v, parent);
        // If u and v are in different sets, perform union operation
        if(parentOfU != parentOfV) {
            unionSet(parentOfU, parentOfV, parent, rank);
            // Decrement the count because we are counting connected components
            components--;
        }
    }
    // Return the minimum operations needed to make the network connected
    return components - 1;
}

int main() {
    int nodes = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
    cout<<"The Initial Graph Edges: "<<endl;
    for(auto edge: edges) {
        cout<<edge[0]<<" "<<edge[1]<<endl;
    }
    cout<<"The Minimum Operations to make Network Connected: "<<makeConnected(nodes, edges)<<endl;

    nodes = 6;
    edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout<<endl<<"The Initial Graph Edges: "<<endl;
    for(auto edge: edges) {
        cout<<edge[0]<<" "<<edge[1]<<endl;
    }
    cout<<"The Minimum Operations to make Network Connected: "<<makeConnected(nodes, edges)<<endl;

    nodes = 6;
    edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
    cout<<endl<<"The Initial Graph Edges: "<<endl;
    for(auto edge: edges) {
        cout<<edge[0]<<" "<<edge[1]<<endl;
    }
    cout<<"The Minimum Operations to make Network Connected: "<<makeConnected(nodes, edges)<<endl;

    nodes = 12;
    edges = {{1, 5}, {1, 7}, {1, 2}, {1, 4}, {3, 7}, {4, 7}, {3, 5}, {0, 6}, {0, 1}, {0, 4}, {2, 6}, {0, 3}, {0, 2}};
    cout<<endl<<"The Initial Graph Edges: "<<endl;
    for(auto edge: edges) {
        cout<<edge[0]<<" "<<edge[1]<<endl;
    }
    cout<<"The Minimum Operations to make Network Connected: "<<makeConnected(nodes, edges)<<endl;

    return 0;
}
