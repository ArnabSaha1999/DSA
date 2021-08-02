package Arnab.com;

// A Node class with pointer next and value field
class Node {
    public Node next;
    public int value;
    Node(int value) {   //creates new node when object is created
        this.next = null;
        this.value = value;
    }
}
