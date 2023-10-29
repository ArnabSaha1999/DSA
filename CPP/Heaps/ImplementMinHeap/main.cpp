#include<iostream>

using namespace std;

// Min-Heap class to create a Min-Heap
class MinHeap {
public:
    // Dynamic array to store the heap elements
    int* arr;
    // Current number of elements in the heap
    int size;
    // Capacity of the dynamic array
    int capacity;
    
    // Constructor to allocate memory for the dynamic array
    MinHeap() {
        this->size = 0;
        // Initial capacity
        this->capacity = 10;
        // Allocate memory for the dynamic array
        this->arr = new int[capacity];
    }
    
    // Function to insert a new element into the min-heap
    void insert(int value) {
        // If the array is full, double its capacity
        if(size == capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            // Copy elements from the old array to the new one
            for(int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            // Deallocate memory for the old array
            delete[] arr;
            arr = newArr;
        }
        int index = size++;
        arr[index] = value;
        // Heapify: Maintain the min-heap property
        while(index > 0) {
            int parent = (index - 1) / 2;
            // If the parent is greater than the current element (arr[index]),
            // swap them to maintain the min-heap property
            if(arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                // Update the index to the parent position
                index = parent;
            } else {
                // Min-heap property is preserved, so exit the loop
                return;
            }
        }
    }

    // Function to delete the minimum element from the min-heap
    void deleteHeapElement() {
        if(size == 0) {
            cout<<"Delete Operation can't be done Heap is Empty"<<endl;
            return;
        }
        arr[0] = arr[--size];
        int index = 0;
        // Heapify: Maintain the min-heap property
        while(index < size) {
            int leftIndex = 2 * index + 1;
            int rightIndex = 2 * index + 2;
            int smallestIndex = index;
            // Check if the left child exists and is smaller than the current smallest element
            if(leftIndex <= size && arr[leftIndex] < arr[smallestIndex]) {
                smallestIndex = leftIndex;
            } // Check if the right child exists and is smaller than the current smallest element
            if(rightIndex <= size && arr[rightIndex] < arr[smallestIndex]) {
                smallestIndex = rightIndex;
            }
            // If the smallest child is not the current element, swap them to maintain the min-heap property
            if(smallestIndex != index) {
                swap(arr[smallestIndex], arr[index]);
                index = smallestIndex;
            } else {
                // Min-heap property is preserved, so exit the loop
                return;
            }
        }
    }

    // Function to print the elements of the min-heap
    void printHeap() {
        if(size == 0) {
            cout<<"The Min Heap is Empty"<<endl;
            return;
        }
        cout<<"The Min Heap Elements: "<<endl;
        for(int i = 0; i < size; i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
    }

    // Function to get the minimum element of the min-heap
    int getMin() {
        if(size == 0) {
            cout<<"The Min Heap is Empty"<<endl;
            return -1;
        }
        return arr[0];
    }

    // Destructor to deallocate memory for the dynamic array
    ~MinHeap() {
        delete[] arr;
    }
};

int main() {
    MinHeap mh;
    mh.insert(55);
    mh.insert(33);
    mh.insert(44);
    mh.insert(22);
    mh.insert(11);
    mh.insert(40);
    mh.insert(66);

    mh.printHeap();

    cout<<"The Minimum Element of Heap: "<<mh.getMin()<<endl;

    for(int i = 1; i <= 6; i++) {
        cout<<"Min Heap after "<<i<<" deletion: "<<endl;
        mh.deleteHeapElement();
        mh.printHeap();
    }
    
    cout<<"The Minimum Element of Heap: "<<mh.getMin()<<endl;

    mh.insert(14);
    mh.insert(33);
    cout<<"The Minimum Element of Heap: "<<mh.getMin()<<endl;
    mh.printHeap();

    return 0;
}
