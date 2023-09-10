#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>

using namespace std;

//Approach 1: Implementation of LRUCache using Queue and Hashmap approach
class LRUCacheQueue {
    int capacity;
    unordered_map<int, int> cache;
    queue<int> cacheQueue;

public:
    LRUCacheQueue(int capacity) {
        this->capacity = capacity;
    }

    // Get the value associated with the given key
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            // Reorganize the queue to move the accessed key to the front
            queue<int> temp;
            while(!cacheQueue.empty()) {
                if(cacheQueue.front() != key) {
                    temp.push(cacheQueue.front());
                }
                cacheQueue.pop();
            }
            cacheQueue = temp;
            cacheQueue.push(key);
            // Return the value associated with the key
            return cache[key];
        }
        // Key not found, return -1
        return -1;
    }

    // Put a key-value pair into the cache
    void put(int key, int value) {
        if(cache.find(key) == cache.end()) {
            if(cache.size() >= capacity) {
                // Remove the least recently used key
                int removedKey = cacheQueue.front();
                cacheQueue.pop();
                // Remove the key from the cache
                cache.erase(removedKey);
            }
            // Add the new key to the queue
            cacheQueue.push(key);
        } else {
            // Reorganize the queue to move the modified key to the front
            queue<int> temp;
            while(!cacheQueue.empty()) {
                if(cacheQueue.front() != key) {
                    temp.push(cacheQueue.front());
                }
                cacheQueue.pop();
            }
            cacheQueue = temp;
            // Add the key to the queue
            cacheQueue.push(key);
        }
        // Update the value associated with the key in the cache
        cache[key] = value;
    }
};

// Doubly Linked List Node
class Node{
public:
    Node *next, *prev;
    int value;
    int key;
    Node(int key ,int value) {
        this->value = value;
        this->key = key;
        next = prev = nullptr;
    }
};

//Approach 2: Implementation of LRUCache using Doubly Linked List and Hashmap approach
class LRUCache {
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;

    // Add a node to the front of the linked list
    void addNodeToFront(Node* &node) {
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

    // Remove a node from the linked list
    void removeNode(Node* &node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Get the value associated with the given key
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // Remove the node from its current position
            removeNode(node);
            // Add the node to the front of the linked list
            addNodeToFront(node);
            // Return the value associated with the key
            return node->value;
        }
        return -1;
    }

    // Put a key-value pair into the cache
    void put(int key, int value) {
        if(cache.find(key) == cache.end()) {
            if(cache.size() >= capacity) {
                // Find the least recently used node
                Node* leastRecentlyUsedNode = tail->prev;
                // Remove it from the cache
                cache.erase(leastRecentlyUsedNode->key);
                // Remove it from the linked list
                removeNode(leastRecentlyUsedNode);
            }
            // Create a new node
            Node *newNode = new Node(key, value);
            cache[key] = newNode;
            // Add it to the cache
            addNodeToFront(newNode);
        } else {
            Node* node = cache[key];
            // Update the value associated with the key
            node->value = value;
            // Remove the node from its current position
            removeNode(node);
            // Add the node to the front of the linked list
            addNodeToFront(node);
        }
    }
};

int main() {
    cout<<"Least Recently Used (LRU) using Queue and Hashmap approach: "<<endl;
    LRUCacheQueue cacheQueue(3);
    cacheQueue.put(1, 1);
    cacheQueue.put(2, 1);
    cacheQueue.put(3, 1);
    cout<<"LRU value of 1: "<<cacheQueue.get(1)<<endl;
    cacheQueue.put(4, 4);
    cacheQueue.put(5, 5);
    cout<<"LRU value of 1: "<<cacheQueue.get(1)<<endl;
    cout<<"LRU value of 2: "<<cacheQueue.get(2)<<endl;
    cout<<"LRU value of 3: "<<cacheQueue.get(3)<<endl;
    cout<<"LRU value of 4: "<<cacheQueue.get(4)<<endl;
    cout<<"LRU value of 5: "<<cacheQueue.get(5)<<endl;

    cout<<"Least Recently Used (LRU) using Doubly Linked List and Hashmap approach: "<<endl;
    LRUCache cache(3);
    cacheQueue.put(1, 1);
    cacheQueue.put(2, 1);
    cacheQueue.put(3, 1);
    cout<<"LRU value of 1: "<<cacheQueue.get(1)<<endl;
    cacheQueue.put(4, 4);
    cacheQueue.put(5, 5);
    cout<<"LRU value of 1: "<<cacheQueue.get(1)<<endl;
    cout<<"LRU value of 2: "<<cacheQueue.get(2)<<endl;
    cout<<"LRU value of 3: "<<cacheQueue.get(3)<<endl;
    cout<<"LRU value of 4: "<<cacheQueue.get(4)<<endl;
    cout<<"LRU value of 5: "<<cacheQueue.get(5)<<endl;

    return 0;
}
