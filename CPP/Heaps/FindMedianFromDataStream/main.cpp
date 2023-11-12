#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//Approach 1: Class for the Brute Force approach to find the median
class MedianFinderBruteForce {
    // Container to store numbers
    vector<int> arr;
public:
    MedianFinderBruteForce() {}
    // Add a number to the container
    void addNum(int num) {
        arr.push_back(num);
    }
    // Find and return the median
    double findMedian() {
        int size = arr.size();
        // Sort the numbers
        sort(arr.begin(), arr.end());
        double median = -1;
        // Calculate median for even-sized array
        if((arr.size() & 1) == 0) {
            return (arr[(size - 1)/2] + arr[size/2]) / 2.00;
        }
        // Calculate median for odd-sized array
        return arr[size/2];
    }
};

//Approach 2: Class for the Optimized Heap approach to find the median
class MedianFinderOptimized {
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
public:
    MedianFinderOptimized() {}
    // Add a number to the appropriate heap
    void addNum(int num) {
        // If the number is less than or equal to the maximum value in the leftMaxHeap, add it to the leftMaxHeap
        if(leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        } else {
            // Otherwise, add it to the rightMinHeap
            rightMinHeap.push(num);
        }
        // Balance the heaps
        if(leftMaxHeap.size() > rightMinHeap.size() + 1) {
            // If leftMaxHeap has more elements than rightMinHeap by more than 1, move the maximum value from leftMaxHeap to rightMinHeap
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        } else if(rightMinHeap.size() > leftMaxHeap.size()) {
            // If rightMinHeap has more elements than leftMaxHeap, move the minimum value from rightMinHeap to leftMaxHeap
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    // Find and return the median
    double findMedian() {
        // Calculate median for even-sized array
        if(leftMaxHeap.size() == rightMinHeap.size()) {
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        }
        // Calculate median for odd-sized array
        return leftMaxHeap.top();
    }
};

int main() {
    cout<<endl<<"Using Brute Force Approach: "<<endl;
    MedianFinderBruteForce mfbf;
    mfbf.addNum(1);
    cout<<"The Median: "<<mfbf.findMedian()<<endl;
    mfbf.addNum(2);
    cout<<"The Median: "<<mfbf.findMedian()<<endl;
    mfbf.addNum(3);
    cout<<"The Median: "<<mfbf.findMedian()<<endl;
    mfbf.addNum(4);
    cout<<"The Median: "<<mfbf.findMedian()<<endl;
    mfbf.addNum(5);
    cout<<"The Median: "<<mfbf.findMedian()<<endl;
    mfbf.addNum(6);
    cout<<"The Median: "<<mfbf.findMedian()<<endl;

    cout<<endl<<"Using the Optimized Heap Approach: "<<endl;
    MedianFinderOptimized mf;
    mf.addNum(1);
    cout<<"The Median: "<<mf.findMedian()<<endl;
    mf.addNum(2);
    cout<<"The Median: "<<mf.findMedian()<<endl;
    mf.addNum(3);
    cout<<"The Median: "<<mf.findMedian()<<endl;
    mf.addNum(4);
    cout<<"The Median: "<<mf.findMedian()<<endl;
    mf.addNum(5);
    cout<<"The Median: "<<mf.findMedian()<<endl;
    mf.addNum(6);
    cout<<"The Median: "<<mf.findMedian()<<endl;

    return 0;
}
