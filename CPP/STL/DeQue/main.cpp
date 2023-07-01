#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

//To print the Deque.
void printDeQue(deque<int> &myDeque) {
    for(auto it = myDeque.begin(); it != myDeque.end(); it++) {
        cout<<*it<<" ";
    } cout<<endl;
}

//To print the Deque in reverse order
void printDeQueReverse(deque<int> &myDeque) {
    for(deque<int>::reverse_iterator rit = myDeque.rbegin(); rit != myDeque.rend(); ++rit) {
        cout<<*rit<<" ";
    }
    cout<<endl;
}

int main() {
    // Create an empty deque
    deque<int> myDeque;

    // Check if the deque is empty
    if(myDeque.empty()) {
        cout<<"Deque is empty"<<endl;
    }

    // Insert elements at the front and back of the deque
    myDeque.push_front(1);
    myDeque.push_back(2);

    // Insert elements at specific positions
    deque<int>::iterator insertPosition = myDeque.begin() + 1;
    myDeque.insert(insertPosition, 3, 4);
    //print the deque
    cout<<"Printing DeQue elements: ";
    printDeQue(myDeque);
    

    // Display the elements using reverse iteration
    cout<<"Printing Deque element in reverse order: ";
    printDeQueReverse(myDeque);

    // Access elements at specific positions
    cout<<"Element at index 3 using operator[] : "<<myDeque[3]<<endl;
    cout<<"Element at index 2 using at(): "<<myDeque.at(2) <<endl;
    cout<<"First element using front(): "<<myDeque.front() <<endl;
    cout<<"Last element using back(): "<<myDeque.back() <<endl;

    //Sorting the Deque.
    sort(myDeque.begin(), myDeque.end());
    cout<<"The Deque elements after sorting: ";
    printDeQue(myDeque);

    // Erase elements at specific positions
    deque<int>::iterator erasePosition = myDeque.begin() + 1;
    myDeque.erase(erasePosition);

    // Remove elements from the front and back of the deque
    myDeque.pop_front();
    myDeque.pop_back();

    // Resize the deque
    myDeque.resize(2);

    // Display the final elements using range-based for loop
    cout<<"The Deque elements: ";
    printDeQue(myDeque);

    // Check the size of the deque
    cout<<"Size of the deque: "<<myDeque.size()<<endl;

    // Clear the deque
    myDeque.clear();
    cout<<"The size of the Deque after using clear(): "<<myDeque.size()<<endl;

    // Check if the deque is empty
    if(myDeque.empty()) {
        cout<<"Deque is empty"<<endl;
    }

    return 0;
}
