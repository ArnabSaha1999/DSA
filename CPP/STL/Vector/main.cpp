#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(const vector<int>& numbers) {
    cout<<"Vector: ";
    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main() {
    // Create an empty vector
    vector<int>numbers;

    // Check if the vector is empty using empty()
    if (numbers.empty()) {
        cout << "Vector is empty" << endl;
    }

    // Add elements to the vector using push_back()
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Access elements using operator[]
    cout<<"First element:"<<numbers[0]<<endl;
    cout<<"Second element:"<<numbers[1]<<endl;
    cout<<"Third element:"<<numbers[2]<<endl;
    cout<<"Printing Vector after inserting elements using operator[]:"<<endl;
    printVector(numbers);
    // Get the size of the vector using size()
    cout<<"Size of the vector: "<<numbers.size()<<endl;
    cout<<"Capacity of the vector: "<<numbers.capacity()<<endl;
    // Iterate over the elements using a range-based for loop
    cout<<"Elements in the vector: ";
    for(const auto& number : numbers) {
        cout<<number<<" ";
    }
    cout<<endl;

    // Modify an element using operator[]
    numbers[1] = 50;
    cout<<"Printing Vector after inserting elements using operator[]:"<<endl;
    printVector(numbers);

    // Insert an element at a specific position using insert()
    numbers.insert(numbers.begin() + 2, 40);
    cout<<"Printing Vector after inserting elements using insert():"<<endl;
    printVector(numbers);
    //The first and last element of the vector.
    cout<<"The first element of the vector: "<<numbers.front()<<endl;
    cout<<"The last element of the vector: "<<numbers.back()<<endl;
    //Sort vector using sort()
    sort(numbers.begin(), numbers.end());
    cout<<"Printing Vector after sorting elements using sort():"<<endl;
    printVector(numbers);

    // Erase an element at a specific position using erase()
    numbers.erase(numbers.begin() + 1);
    cout<<"Printing Vector after erasing elements using erase():"<<endl;
    printVector(numbers);

    // Erase an element at a specific position using erase()
    numbers.pop_back();
    cout<<"Printing Vector after pop element using pop_back():"<<endl;
    printVector(numbers);

    // Clear all elements using clear()
    numbers.clear();
    cout<<"Size after clearing the vector: "<<numbers.size()<<endl;
    cout<<"Capacity after clearing the vector: "<<numbers.capacity()<<endl;
    // Check if the vector is empty using empty()
    if(numbers.empty()) {
        cout<<"Vector is empty"<<endl;
    }
    cout<<"Capacity of vector: "<<numbers.capacity()<<endl;
    // Reserve capacity using reserve()
    numbers.reserve(10);
    cout<<"Capacity of vector: "<<numbers.capacity()<<endl;
    // Resize the vector using resize()
    numbers.resize(5);
    numbers.shrink_to_fit();
    printVector(numbers);
    cout<<"The Size of the vector after using resize(): "<<numbers.size()<<endl;
    cout<<"The Capacity of the vector after using shrink_to_fit(): "<<numbers.capacity()<<endl;

    // Swap the contents of two vectors using swap()
    vector<int> otherNumbers = {100, 200, 300};
    cout<<"Printing Vector before swapping two vector using swap():"<<endl;
    cout<<"Vector - numbers: "<<endl;
    printVector(numbers);
    cout<<"Vector - otherNumbers:"<<endl;
    printVector(otherNumbers);

    numbers.swap(otherNumbers);

    cout<<"Printing Vector after swapping two vector using swap():"<<endl;
    cout<<"Vector - numbers: "<<endl;
    printVector(numbers);
    cout<<"Vector - otherNumbers:"<<endl;
    printVector(otherNumbers);

    return 0;
}
