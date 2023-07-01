#include<iostream>
#include<queue>

using namespace std;

int main() {
    queue<int> myQueue;
    
    if(myQueue.empty()) {
        cout<<"The Queue is Empty"<<endl;
    }

    // Pushing elements to the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Queue size
    cout<<"Queue size: "<<myQueue.size()<<endl;

    // Accessing front and back elements
    cout<<"Front element: "<<myQueue.front()<<endl;
    cout<<"Back element: "<<myQueue.back()<<endl;

    // Removing elements from the queue and printing
    cout<<"The Queue elements: ";
    while(!myQueue.empty()) {
        cout<<myQueue.front()<<" ";
        myQueue.pop();
    } cout<<endl;

    cout<<"Queue size after removing elements: "<<myQueue.size()<<endl;

    return 0;
}
