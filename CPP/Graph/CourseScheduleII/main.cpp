#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

//Approach 1: Function to find the order of courses to complete based on prerequisites
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
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
    // Vector to store the ordering of the courses
    vector<int> topologicalSort;
    // Perform BFS traversal
    while(!bfsQueue.empty()) {
        int node = bfsQueue.front();
        bfsQueue.pop();
        topologicalSort.push_back(node);
        // Update in-degrees and enqueue neighbors
        for(int neighbor: adjacencyList[node]) {
            inDegree[neighbor]--;
            if(inDegree[neighbor] == 0) {
                bfsQueue.push(neighbor);
            }
        }
    }
    // Check if the topological sort size is equal to the number of courses
    return (topologicalSort.size() == numCourses) ? topologicalSort : vector<int> {};
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout<<"The given Prerequisite courses: "<<endl;
    for(auto pre: prerequisites) {
        cout<<"To take course "<<pre[0]<<" you have to complete course "<<pre[1]<<" first."<<endl;
    }
    vector<int> ans = findOrder(numCourses, prerequisites);
    if(ans.size() == 0) {
        cout<<"It's not possible to complete all courses"<<endl;
    } else {
        cout<<"The Order to complete courses: "<<endl;
        for(int a: ans) {
            cout<<a<<" ";
        } cout<<endl;
    }
    
    prerequisites = {{1, 0}, {0, 1}};
    cout<<endl<<"The given Prerequisite courses: "<<endl;
    for(auto pre: prerequisites) {
        cout<<"To take course "<<pre[0]<<" you have to complete course "<<pre[1]<<" first."<<endl;
    }
    ans = findOrder(numCourses, prerequisites);
    if(ans.size() == 0) {
        cout<<"It's not possible to complete all courses"<<endl;
    } else {
        cout<<"The Order to complete courses: "<<endl;
        for(int a: ans) {
            cout<<a<<" ";
        } cout<<endl;
    }

    numCourses = 4;
    prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout<<endl<<"The given Prerequisite courses: "<<endl;
    for(auto pre: prerequisites) {
        cout<<"To take course "<<pre[0]<<" you have to complete course "<<pre[1]<<" first."<<endl;
    }
    ans = findOrder(numCourses, prerequisites);
    if(ans.size() == 0) {
        cout<<"It's not possible to complete all courses"<<endl;
    } else {
        cout<<"The Order to complete courses: "<<endl;
        for(int a: ans) {
            cout<<a<<" ";
        } cout<<endl;
    }

    return 0;
}
