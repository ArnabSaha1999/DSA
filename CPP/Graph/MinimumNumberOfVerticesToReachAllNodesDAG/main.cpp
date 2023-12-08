#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Find the minimum vertices to reach all nodes using Indegree count
vector<int> findSmallestSetOfVertices(int vertices, vector<vector<int>> &edges) {
    // Initialize in-degrees for each vertex
    vector<int> inDegree(vertices, 0);
    // Calculate in-degrees based on the given edges
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        inDegree[v]++;
    }
    // Identify vertices with in-degree 0 (those not reachable by any other vertices)
    vector<int> ans;
    for(int i = 0; i < vertices; i++) {
        if(inDegree[i] == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int nodes = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    cout<<"The Initial Graph Edges: "<<endl;
    for(auto edge: edges) {
        for(int e: edge) {
            cout<<e<<" ";
        } cout<<endl;
    }

    cout<<"The Vertices to Reach All Nodes in Directed Acyclic Graph: "<<endl;
    vector<int> ans = findSmallestSetOfVertices(nodes, edges);
    for(int a: ans) {
        cout<<a<<" ";
    } cout<<endl;

    nodes = 5;
    edges = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};
    cout<<endl<<"The Initial Graph Edges: "<<endl;
    for(auto edge: edges) {
        for(int e: edge) {
            cout<<e<<" ";
        } cout<<endl;
    }

    cout<<"The Vertices to Reach All Nodes in Directed Acyclic Graph: "<<endl;
    ans = findSmallestSetOfVertices(nodes, edges);
    for(int a: ans) {
        cout<<a<<" ";
    } cout<<endl;

    return 0;
}
