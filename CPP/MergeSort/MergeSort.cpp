#include <iostream>
using namespace std;

class MergeSort {
public:
    void mergeSort(int arr[] , int left , int right){
        if(left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr , left , mid);
            mergeSort(arr , mid+1 , right);
            merge(arr , left , mid , right);
        }
    }
    void merge (int arr[] , int left , int mid , int right) {
        int i = left , j = mid+1 , k = left;
        int size = (sizeof(arr)/sizeof(arr[0]));
        int temp[size];
        while(i <= mid && j <= right) {
            if(arr[i] < arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while(i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while(j <= right) {
            temp[k] = arr[j];
            j++;
            k++;
        }
        for(k = left ; k <= right ; k++) {
            arr[k] = temp[k];
        }
    }
    void printArray (int arr[] , int size) {
        for(int i = 0 ; i < size ; i++) {
            cout << arr[i] << " ";
        }

    }
};


int main() {
    MergeSort mergeSort;
    int arr[] = {55 , 99 , 10 , 5 , 0 , 96 , 45 , 66 , 78 , 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort.mergeSort(arr , 0 , size - 1);
    mergeSort.printArray(arr , size);
    return 0;
}
