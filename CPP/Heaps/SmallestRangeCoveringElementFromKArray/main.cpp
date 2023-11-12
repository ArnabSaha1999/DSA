#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std; 

// Function to print the elements of an array
void printArr(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

// Class to represent an element with its value, row index, and column index
class Element {
    public:
    int value;
    int rowIndex;
    int colIndex;
    Element(int value, int rowIndex, int colIndex) {
        this->value = value;
        this->rowIndex = rowIndex;
        this->colIndex = colIndex;
    }
};

// Comparator class for elements in the priority queue
class CompareElement {
    public:
    bool operator() (Element *first, Element *second) {
        return first->value > second->value;
    }
};

//Approach 1: Function to find the smallest range covering elements from multiple arrays
pair<int, int> smallestRange(vector<vector<int>> &nums) {
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Element*, vector<Element*>, CompareElement> minHeap;
    // Initialize mini, maxi, and the priority queue with the first elements of each array
    for(int i = 0; i < nums.size(); i++) {
        mini = min(mini, nums[i][0]);
        maxi = max(maxi, nums[i][0]);
        Element *newElement = new Element(nums[i][0], i, 0);
        minHeap.push(newElement);
    }
    int start = mini, end = maxi;
    // Continue processing until the priority queue is not empty
    while(!minHeap.empty()) {
        Element *temp = minHeap.top(); 
        minHeap.pop();
        mini = temp->value;
        // Update the start and end of the smallest range if necessary
        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }
        int rowIndex = temp->rowIndex;
        int colIndex = temp->colIndex;
        // Check if there are more elements in the same array
        if(colIndex + 1 < nums[rowIndex].size()) {
            maxi = max(maxi, nums[rowIndex][colIndex + 1]);
            Element* newElement = new Element(nums[rowIndex][colIndex + 1], rowIndex, colIndex + 1);
            minHeap.push(newElement);
        } else {
            break;
        }
    }
    return {start, end};
}

int main() {
    vector<vector<int>> matrix = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };

    cout<<"The Input Vector: "<<endl;
    for(vector<int> arr : matrix) {
        printArr(arr);
    }

    cout<<endl<<"Using the Heap Approach to find the Smallest Range covering Elements from every Array: "<<endl;
    pair<int, int> ans = smallestRange(matrix);
    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;
}
