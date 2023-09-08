#include<iostream>
#include<queue>

using namespace std; 

// Class representing a petrol pump with petrol and distance properties.
class PetrolPump {
public:
    int petrol, distance;
    // Constructor to initialize the petrol and distance properties
    PetrolPump(int p, int d) {
        petrol = p;
        distance = d;
    }
};

//Approach 1: Brute Force approach to find the starting point for a circular tour.
int circularTourBruteForce(PetrolPump p[], int n) {
    for(int start = 0; start < n; start++) {
        int balance = 0;
        int current = start;
        bool canComplete = true;
        // Traverse the circular tour starting from 'start'.
        for(int i = 0; i < n; i++) {
            balance += p[current].petrol - p[current].distance;
            if(balance < 0) {
                // Cannot complete the tour from this starting point.
                canComplete = false;
                break;
            }
            // Move to the next pump in a circular fashion.
            current = (current + 1) % n;
        }
        if(canComplete) {
            // This starting point can complete the circular tour.
            return start;
        }
    }
    // No starting point found that can complete the tour.
    return -1;
}

//Approach 2: Optimized approach to find the starting point for a circular tour.
int circularTourOptimized(PetrolPump p[], int n) {
    int balance = 0;
    int deficit = 0;
    int start = 0;
    // Traverse all pumps to find a valid starting point.
    for(int i = 0; i < n; i++) {
        balance += p[i].petrol - p[i].distance;
        if(balance < 0) {
            // Set a new starting point candidate.
            start = i + 1;
            // Accumulate the deficit.
            deficit += balance;
            // Reset the balance.
            balance = 0;
        }
    }
    // Return a valid starting point or -1 if not found.
    return (balance + deficit >= 0) ? start : -1; 
}

//Approach 3: Queue-based approach to find the starting point for a circular tour.
int circularTourQueue(PetrolPump p[], int n) {
    int balance = 0;
    int deficit = 0;
    int start = 0;
    queue<int> q;
    // Traverse all pumps to find a valid starting point.
    for(int i = 0; i < n; i++) {
        balance += p[i].petrol - p[i].distance;
        if(balance < 0) {
            // Set a new starting point candidate.
            start = i + 1;
            // Accumulate the deficit.
            deficit += balance;
            // Reset the balance.
            balance = 0;
            while(!q.empty()) {
                // Clear the queue as we need a new starting point.
                q.pop();
            }
        } else {
            // Add the current pump as a potential starting point.
            q.push(i);
        }
    }
    // Return a valid starting point or -1 if not found.
    return (balance + deficit >= 0) ? start : -1;
}

int main() {
    PetrolPump pumps[] = {{4,6}, {6,5}, {7,3}, {4,5}};
    int size = sizeof(pumps) / sizeof(pumps[0]);

    cout<<"The Starting point for Circular Tour using Brute Force approach: "<<circularTourBruteForce(pumps, size)<<endl;
    cout<<"The Starting point for Circular Tour using Optimized approach: "<<circularTourOptimized(pumps, size)<<endl;
    cout<<"The Starting poing for Circular Tour using Queue approach: "<<circularTourQueue(pumps, size)<<endl;

    return 0;
}
