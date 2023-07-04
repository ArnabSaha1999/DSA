#include<iostream>
#include<unordered_set>

using namespace std;

void printUnorderedSet(unordered_set<int> &mySet) {
    for(unordered_set<int>::iterator it = mySet.begin(); it != mySet.end(); it++) {
        cout<<*it<<" ";
    } cout<<endl;
}

int main() {
    unordered_set<int> mySet;
    //Check if set is empty
    if(mySet.empty()) {
        cout<<"The Unordered Set is empty"<<endl;
    }

    // Inserting elements into the set
    mySet.insert(10);
    mySet.insert(5);
    mySet.insert(15);
    mySet.insert(7);
    mySet.insert(12);
    mySet.insert(5);
    mySet.insert(12);

    // Printing the elements of the set
    cout<<"Elements of the Unordered Set: ";
    printUnorderedSet(mySet);
    cout<<"The size of the Unordered Set: "<<mySet.size()<<endl;

    // Checking if an element is present in the set
    int searchElement = 7;
    if (mySet.count(searchElement) != 0) {
        cout<<"Element "<<searchElement<<" is present in the Unordered Set."<<endl;
    } else {
        cout<<"Element "<<searchElement<<" is not present in the Unordered Set."<<endl;
    }

    // Removing an element from the set
    int removeElement = 10;
    mySet.erase(removeElement);

    // Printing the elements of the set after erasing an element
    cout<<"Elements of the Unordered Set after erasing "<<removeElement<<": ";
    printUnorderedSet(mySet);

    //Removing an element using iterator
    unordered_set<int>::iterator it = mySet.begin();
    ++it;
    cout<<"Elements of the Unordered Set after erasing "<<*it<< ": ";
    mySet.erase(it);
    printUnorderedSet(mySet);
    //Check if any element is present in Set.
    int target = 12;
    if(mySet.count(target)) {
        cout<<"The element "<<target<<" is present in the Unordered Set"<<endl;
    } else {
        cout<<"The element "<<target<<" is not present in the Unordered Set"<<endl;
    }

    //Search for any element

    mySet.insert(10);
    mySet.insert(99);
    target = 12;
    //Find function returns an iterator at the index of found target
    unordered_set<int>::iterator itr = mySet.find(target);
    cout<<"The elements from the target element till the end: ";
    for(unordered_set<int>::iterator tempIt = itr; tempIt != mySet.end(); tempIt++) {
        cout<<*tempIt<<" ";
    } cout<<endl;

    // Clearing the set
    mySet.clear();

    // Checking if the set is empty
    if (mySet.empty()) {
        cout<<"The Unorered Set is empty."<<endl;
    } else {
        cout<<"The Unordered Set is not empty."<<endl;
    }

    return 0;
}
