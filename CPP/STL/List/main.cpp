#include<iostream>
#include<list>

using namespace std;

//Print List function
void printList(list<int> &myList) {
    for(auto it = myList.begin(); it != myList.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

//Print list in reverse order function
void printListReverse(list<int> &myList) {
    for(auto rit = myList.rbegin(); rit != myList.rend(); ++rit) {
        cout<<*rit<<" ";
    }
    cout<<endl;
}

int main() {
    list<int> myList;

    //Check if List is empty.
    if(myList.empty()) {
        cout<<"The List is Empty"<<endl;
    }
    // Insert elements at the end and beginning
    myList.push_back(10);
    myList.push_front(5);
    myList.push_back(20);
    myList.push_front(10);

    // Display the elements using iterators
    cout<<"Elements in the list: ";
    printList(myList);


    // Insert an element at a specific position
    auto it = myList.begin();
    ++it;
    myList.insert(it, 15);

    cout<<"Elements after inserting 15 using insert(): ";
    printList(myList);
    // Remove all elements with value 10
    myList.remove(10);
    cout<<"Elements after removing all the values of 10 using remove(): ";
    printList(myList);

    // Display the elements in reverse order using reverse iterators
    cout<<"Elements in reverse order: ";
    printListReverse(myList);

    // Get the number of elements in the list
    cout<<"Size of the list: "<<myList.size()<<endl;

    // Access the first and last elements
    cout<<"First element using front(): "<<myList.front()<<endl;
    cout<<"Last element using back(): "<<myList.back()<<endl;
    it = myList.begin();
    it++;
    cout<<"The element at index 1 using Iterator: "<<*it<<endl;
    // Assign elements from another list
    list<int> otherList = {30, 40, 50};
    myList.assign(otherList.begin(), otherList.end());
    cout<<"After assining otherList to myList: "<<endl;
    cout<<"Printing myList: ";
    printList(myList);
    // Clear the list
    myList.clear();

    // Splice elements from another list
    myList.splice(myList.begin(), otherList);
    cout<<"The list after using splice(): ";
    printList(myList);

    // Merge two sorted lists
    list<int> sortedList = {2, 4, 6, 6};
    sortedList.merge(myList);
    cout<<"Printing Sorted list: ";
    printList(sortedList);
    // Remove consecutive duplicates
    sortedList.unique();
    cout<<"Printing Sorted list after using unique(): ";
    printList(sortedList);
    // Resize the list
    cout<<"The size of the list: "<<sortedList.size()<<endl;
    sortedList.resize(3);

    list<int>::iterator it1 = sortedList.begin();
    sortedList.erase(++it1);
    // Display the final elements
    cout << "The elements in the list after using erase(): ";
    printList(sortedList);
    return 0;
}
