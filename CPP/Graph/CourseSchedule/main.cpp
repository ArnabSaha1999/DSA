#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

//Approach 1: Function to check if it's possible to finish all courses based on prerequisites
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // Create an adjacency list to represent the prerequisites
    unordered_map<int, list<int>> adjacencyList;
    // Populate the adjacency list based on the given prerequisites
    for(auto pre: prerequisites) {
        int u = pre[0];
        int v = pre[1];
        adjacencyList[v].push_back(u);
    }
    // Calculate in-degrees for each course
    vector<int> inDegree(numCourses, 0);
    for(auto it: adjacencyList) {
        for(auto i: it.second) {
            inDegree[i]++;
        }
    }
    // Initialize a queue for BFS traversal
    queue<int> bfsQueue;
    // Add courses with in-degree 0 to the queue
    for(int i = 0; i < numCourses; i++) {
        if(inDegree[i] == 0) {
            bfsQueue.push(i);
        }
    }
    // Initialize a variable to track the size of the topological sort
    int topoLogicalSortSize = 0;
    // Perform BFS traversal
    while(!bfsQueue.empty()) {
        int node = bfsQueue.front();
        bfsQueue.pop();
        topoLogicalSortSize++;
        // Update in-degrees and enqueue neighbors
        for(int neighbor: adjacencyList[node]) {
            inDegree[neighbor]--;
            if(inDegree[neighbor] == 0) {
                bfsQueue.push(neighbor);
            }
        }
    }
    // Check if the topological sort size is equal to the number of courses
    return (topoLogicalSortSize == numCourses) ? true : false;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout<<"The given Prerequisite courses: "<<endl;
    for(auto pre: prerequisites) {
        cout<<"To take course "<<pre[0]<<" you have to complete course "<<pre[1]<<" first."<<endl;
    }
    cout<<"Is it possible to finish all courses? ";
    if(canFinish(numCourses, prerequisites)) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    
    prerequisites = {{1, 0}, {0, 1}};
    cout<<endl<<"The given Prerequisite courses: "<<endl;
    for(auto pre: prerequisites) {
        cout<<"To take course "<<pre[0]<<" you have to complete course "<<pre[1]<<" first."<<endl;
    }
    cout<<"Is it possible to finish all courses? ";
    if(canFinish(numCourses, prerequisites)) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }

    return 0;
}
