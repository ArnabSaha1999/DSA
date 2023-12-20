#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
#include<utility>
#include<climits>

using namespace std;

//Approach 1: Function to find the cheapest price from source to destination with at most k stops
int findCheapestPrice(int vertices, vector<vector<int>> &flights, int src, int dest, int k) {
    // Create an adjacency list to represent the graph
    unordered_map<int, list<pair<int, int>>> adjacencyList;
    // Populate the adjacency list with the given flights information
    for(auto flight: flights) {
        int u = flight[0];
        int v = flight[1];
        int p = flight[2];
        adjacencyList[u].push_back({v, p});
    }
    // Initialize a vector to store the cost of reaching each node from the source
    vector<int> cost(vertices, INT_MAX);
    // Set the cost of the source node to 0
    cost[src] = 0;
    // Use a BFS traversal with a queue to explore possible flights
    queue<pair<pair<int, int>, int>> bfsQueue;
    bfsQueue.push({{src, 0}, 0});
    // Perform BFS traversal
    while(!bfsQueue.empty()) {
        auto frontElement = bfsQueue.front();
        bfsQueue.pop();
        int element = frontElement.first.first;
        int price = frontElement.first.second;
        int stops = frontElement.second;
        // Check if the destination is reached with at most k stops
        if(stops == k + 1 && element == dest) {
            break;
        }
        // Skip if the number of stops exceeds the limit
        if(stops > k + 1) {
            continue;
        }
        // Explore neighbors of the current node
        for(auto neighbor: adjacencyList[element]) {
            // Update the cost if a cheaper path is found, and enqueue the neighbor
            if((cost[neighbor.first] > neighbor.second + price) && (stops < k + 1)) {
                cost[neighbor.first] = neighbor.second + price;
                bfsQueue.push({{neighbor.first, cost[neighbor.first]}, stops + 1});
            }
        }
    }
    // Return the cost of reaching the destination, or -1 if unreachable
    return (cost[dest] == INT_MAX) ? -1 : cost[dest];
}

int main() {
    int nodes = 4, src = 0, dest = 3, k = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {1, 3, 600}, {2, 3, 200}};
    cout<<"The given Flights: "<<endl;
    for(auto flight: flights) {
        cout<<flight[0]<<": "<<flight[1]<<" ("<<flight[2]<<")"<<endl;
    }
    cout<<src<<" to "<<dest<<" with at most "<<k<<" stops: "<<findCheapestPrice(nodes, flights, src, dest, k)<<endl;

    nodes = 5, src = 0, dest = 2, k = 2;
    flights = {{0, 1, 2}, {0, 2, 10}, {1, 2, 7}, {1, 3, 5}, {3, 2, 1}, {3, 4, 6}};
    cout<<endl<<"The given Flights: "<<endl;
    for(auto flight: flights) {
        cout<<flight[0]<<": "<<flight[1]<<" ("<<flight[2]<<")"<<endl;
    }
    cout<<src<<" to "<<dest<<" with at most "<<k<<" stops: "<<findCheapestPrice(nodes, flights, src, dest, k)<<endl;

    return 0;
}
