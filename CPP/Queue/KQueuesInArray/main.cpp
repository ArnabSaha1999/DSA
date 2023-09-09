#include<iostream>
#include<cstring>

using namespace std;

class KQueues {
    int *arr, *front, *rear, *next;
    int freespot;
public:
    KQueues(int k, int n) {
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        //intializing array with -1
        memset(arr, -1, sizeof(int) * n);
        // Initializing front with -1
        memset(front, -1, sizeof(int) * k);
        // Initializing rear with -1
        memset(rear, -1, sizeof(int) * k);
        // Initializing next array to point to the next element
        for(int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        freespot = 0;
    }

    // Function to enqueue an element 'x' into queue 'm'.
    bool enQueue(int x, int m) {
        if(freespot == -1) {
            return false;
        } 
        int index = freespot;
        freespot = next[index];
        if(front[m - 1] == -1) {
            // Initialize front and rear for a new queue.
            front[m - 1] = rear[m - 1] = index;
        } else {
            // Update the next pointer of the previous rear to point to the new element.
            next[rear[m - 1]] = index;
            // Update rear to point to the new element.
            rear[m - 1] = index;
        }
        // Set the next pointer of the new element to -1 (end of queue).
        next[index] = -1;
        // Store the element in the array.
        arr[index] = x;
        return true;
    }

    // Function to dequeue an element from queue 'm'.
    int deQueue(int m) {
        if (front[m - 1] == -1) {
            return -1; // Queue is empty
        }

        int index = front[m - 1];

        front[m - 1] = next[index];

        if (front[m - 1] == -1) {
            rear[m - 1] = -1; // If the queue is now empty, reset the rear pointer.
        }

        next[index] = freespot;
        freespot = index;

        return arr[index];
    }

    // Function to check if queue 'm' is empty.
    bool isEmpty(int m) {
        return (front[m - 1] == -1) ? true : false;
    }

    // Function to check if queue 'm' is full.
    bool isFull(int m) {
        return (freespot == -1) ? true : false;
    }

    // Function to get the front element index of queue 'm'.
    int getFront(int m) {
        return (front[m - 1] == -1) ? -1 : front[m - 1];
    }

    // Function to get the rear element index of queue 'm'.
    int getRear(int m) {
        return (rear[m - 1] == -1) ? -1 : rear[m - 1];
    }

    // Function to get the size of queue 'm'.
    int getSize(int m) {
        int size = 0;
        int index = front[m - 1];
        while(index != -1) {
            size++;
            index = next[index];
        }
        return size;
    }

};

int main() {
    int k = 3;
    int n = 10;

    KQueues kQueues(k, n);

    kQueues.enQueue(1, 1);
    kQueues.enQueue(2, 2);
    kQueues.enQueue(3, 3);
    kQueues.enQueue(4, 1);
    kQueues.enQueue(5, 2);
    kQueues.enQueue(6, 3);

    cout << "Dequeued element from Queue 1: " << kQueues.deQueue(1) << endl;
    cout << "Dequeued element from Queue 2: " << kQueues.deQueue(2) << endl;
    cout << "Dequeued element from Queue 3: " << kQueues.deQueue(3) << endl;

    cout << "Is Queue 1 empty: " << (kQueues.isEmpty(1) ? "Yes" : "No") << endl;
    cout << "Is Queue 2 empty: " << (kQueues.isEmpty(2) ? "Yes" : "No") << endl;
    cout << "Is Queue 3 empty: " << (kQueues.isEmpty(3) ? "Yes" : "No") << endl;

    cout << "Is Queue 1 full: " << (kQueues.isFull(1) ? "Yes" : "No") << endl;
    cout << "Is Queue 2 full: " << (kQueues.isFull(2) ? "Yes" : "No") << endl;
    cout << "Is Queue 3 full: " << (kQueues.isFull(3) ? "Yes" : "No") << endl;

    cout << "Front of Queue 1: " << kQueues.getFront(1) << endl;
    cout << "Rear of Queue 1: " << kQueues.getRear(1) << endl;
    cout << "Size of Queue 1: " << kQueues.getSize(1) << endl;

    return 0;
}
