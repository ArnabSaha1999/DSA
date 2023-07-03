#include<iostream>
#include<queue>

using namespace std;

int main() {
    //Creates a Max Heap where elements will be stored in decreasing order.
    priority_queue<int> maxHeap;
    
    if(maxHeap.empty()) {
        cout<<"The Max Heap is Empty"<<endl;
    }

    // Pushing elements to the heap
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(30);

    // Heap size
    cout<<"Max Heap size: "<<maxHeap.size()<<endl;

    // Removing elements from the heap and printing
    cout<<"The Max Heap elements: ";
    while(!maxHeap.empty()) {
        cout<<maxHeap.top()<<" ";
        maxHeap.pop();
    } cout<<endl;

    cout<<"Max Heap size after removing elements: "<<maxHeap.size()<<endl;


    //Creates a Min Heap where the elements will be stored in increasing order.
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    if(minHeap.empty()) {
        cout<<"The Min Heap is Empty"<<endl;
    }

    // Pushing elements to the heap
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(10);

    // heap size
    cout<<"Min Heap size: "<<minHeap.size()<<endl;

    // Removing elements from the heap and printing
    cout<<"The Min Heap elements: ";
    while(!minHeap.empty()) {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    } cout<<endl;

    cout<<"Min Heap size after removing elements: "<<minHeap.size()<<endl;

    return 0;
}
