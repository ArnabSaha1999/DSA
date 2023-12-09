#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

//Approach 1: Function to find all paths from source to target using BFS traversal
vector<vector<int>> allPathSourceToTargetBFS(vector<vector<int>> &graph) {
    int src = 0, target = graph.size() - 1;
    // To store all paths from source to target
    vector<vector<int>> ansPaths;
    // To store the current path during traversal
    vector<int> path;
    // Queue for BFS traversal
    queue<pair<int, vector<int>>> bfsQueue;
    // Start with the source node
    path.push_back(src);
    bfsQueue.push({src, path});
    // Perform BFS
    while(!bfsQueue.empty()) {
        auto node = bfsQueue.front();
        bfsQueue.pop();
        if(node.first == target) {
            // Found a path from source to target
            ansPaths.push_back(node.second);
        }
        // Explore neighbors of the current node in the graph
        for(int neighbor: graph[node.first]) {
            // Extend the current path with the neighbor
            node.second.push_back(neighbor);
            // Enqueue the neighbor with the extended path
            bfsQueue.push({neighbor, node.second});
            // Backtrack: Remove the last node to explore other neighbors
            node.second.pop_back();
        }
    }
    return ansPaths;
}

// Function to perform DFS traversal and find all paths from source to target
void dfsTraversal(int node, int target, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ansPaths) {
    // Extend the current path
    path.push_back(node);
    if(node == target) {
        // Found a path from source to target
        ansPaths.push_back(path);
    }
    // Explore neighbors of the current node in the graph using recursive DFS
    for(int neighbor: graph[node]) {
        // Recursive call to explore the neighbor
        dfsTraversal(neighbor, target, graph, path, ansPaths);
        // Backtrack: Remove the last node to explore other neighbors
        path.pop_back();
    }
}

//Approach 2: Function to find all paths from source to target using DFS traversal
vector<vector<int>> allPathSourceToTargetDFS(vector<vector<int>> &graph) {
    int src = 0, target = graph.size() - 1;
    // To store all paths from source to target
    vector<vector<int>> ansPaths;
    // To store the current path during traversal
    vector<int> path;
    dfsTraversal(src, target, graph, path, ansPaths);
    return ansPaths;
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    cout<<"The Initial AdjacencyList: "<<endl;
    for(int i = 0; i < graph.size(); i++) {
        cout<<i<<": ";
        for(int a: graph[i]) {
            cout<<a<<" ";
        } cout<<endl;
    }

    cout<<"The Paths from Source to Target using BFS Traversal: "<<endl;
    vector<vector<int>> ans = allPathSourceToTargetBFS(graph);
    for(auto arr: ans) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    cout<<endl<<"The Paths from Source to Target using DFS Traversal: "<<endl;
    ans = allPathSourceToTargetDFS(graph);
    for(auto arr: ans) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    cout<<endl<<"The Initial AdjacencyList: "<<endl;
    for(int i = 0; i < graph.size(); i++) {
        cout<<i<<": ";
        for(int a: graph[i]) {
            cout<<a<<" ";
        } cout<<endl;
    }

    cout<<"The Paths from Source to Target using BFS Traversal: "<<endl;
    ans = allPathSourceToTargetBFS(graph);
    for(auto arr: ans) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    cout<<endl<<"The Paths from Source to Target using DFS Traversal: "<<endl;
    ans = allPathSourceToTargetDFS(graph);
    for(auto arr: ans) {
        for(int a: arr) {
            cout<<a<<" ";
        } cout<<endl;
    }

    return 0;
}
