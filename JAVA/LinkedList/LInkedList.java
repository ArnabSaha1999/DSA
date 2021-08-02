package Arnab.com;

// A LinkedList class with pointer head and tail
class LinkedList{
    private int length ;
    private Node head , tail;
    public LinkedList() {   // creates an empty linked list
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    // pushes the element onto the end of the linked list
    public void pushBack (int value) {
        Node newNode = new Node (value);
        if(this.isEmpty()) {    //when the linked list is empty
            this.head = this.tail = newNode;
            this.length++;
            return;
        }
        this.tail.next = newNode;
        this.tail = newNode;
        this.length++;
    }

    // pushes the element onto the start of the linked list
    public void pushFront (int value) {
        Node newNode = new Node(value);
        if(this.isEmpty()) {   //when the linked list is empty
            this.insertWhileEmpty(newNode);
            return;
        }
        newNode.next = this.head;
        this.head = newNode;
        this.length++;
    }

    //inserts an element after a given index number
    public void insertAfterIndex (int index , int value) {
        if(index < 0) {     // if the given index is less than 0 do nothing
            return;
        }
        Node newNode = new Node(value);
        if(this.isEmpty()) {   //when the linked list is empty
            this.insertWhileEmpty(newNode);
            return;
        }
        if(index >= this.length) {     //when the given index is bigger the actual linked list size then insert the element onto the end of the linked list
            this.pushBack(value);
            return;
        }
        Node currentNode = findIndex(index);
        newNode.next = currentNode.next;
        currentNode.next = newNode;
        this.length++;
    }

    // inserts an element before a given index number
    public void insertBeforeIndex (int index , int value) {
        if(index < 0) { // when the given index is less than 0 do nothing
            return;
        }
        Node newNode = new Node(value);
        if(this.isEmpty()) {   // when the linked list is empty
            this.insertWhileEmpty(newNode);
            return;
        }
        if(index == 0) {        // when the given index is the first position in the linked list
            this.pushFront(value);
            return;
        }
        if(index >= this.length) { // when the given index is larger than actual size of the linked list do nothing
            return;
        }
        Node currentNode = this.findIndex(index-1);
        newNode.next = currentNode.next;
        currentNode.next = newNode;
        this.length++;
    }

    // pops the first element out of the linked list
    public void popFront () {
        if(this.isEmpty()) {   // when the linked list is empty
            System.out.println("The linked list is empty nothing to delete.");
            return;
        }
        this.head = this.head.next;
        this.length--;
    }

    // pops the last element out of the linked list
    public void popBack () {
        if(this.isEmpty()) {   // when the linked list empty
            System.out.println("The linked list is empty nothing to delete.");
            return;
        }
        if(this.head == this.tail) {  // when there is only one element to delete
            this.deleteOnlyElement();
            return;
        }

        Node currentNode = this.head;
        while(currentNode.next != this.tail) {
            currentNode = currentNode.next;
        }
        currentNode.next = null;
        this.tail = currentNode;
        this.length--;
    }

    public void deleteNode (int index) {
        if(this.isEmpty()) {   // when the linked list empty
            System.out.println("The linked list is empty nothing to delete.");
            return;
        }
        if(index > this.length-1 || index < 0) {   // when the index is less than 0 or greater than the length of the linked list
            return;
        }
        if(index == 0) {    // when the index position is the first element of the linked list
            this.popFront();
            return;
        }
        if(index == this.length - 1) { //when the given index position is the last element of the linked list
            this.popBack();
            return;
        }
        Node currentNode = this.findIndex(index - 1);
        currentNode.next = currentNode.next.next;
        this.length--;
    }

    // deletes the whole linked list
    public void deleteLinkedList () {
        if(this.isEmpty()) {   //when the linked list is empty
            System.out.println("The Linked is already empty");
            return;
        }
        this.head = this.tail = null;
        this.length = 0;
    }

    // displays the elements of the linked list
    public void display () {
        Node currentNode = this.head;
        while(currentNode != null) {    // loops through all the elements of the linked list till the currentNode reaches null value
            System.out.print(currentNode.value + " ");
            currentNode = currentNode.next;
        }
    }

    // to reverse the existing linked list
    public void reverse () {
        if(this.isEmpty() || this.length == 1) {  // when the linked list either empty or have only one element do not need to reverse it
            return;
        }
        Node prevNode = null , nextNode = null;
        Node currentNode = this.head;
        this.tail = this.head;
        while(currentNode != null) {     // looping through till the currentNode becomes null
            nextNode = currentNode.next;
            currentNode.next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        this.head = prevNode;
    }

    // to search an element and find its index position
    public void search (int value) {
        if(this.isEmpty()) { // when its empty
            System.out.println("The Linked List is empty");
            return ;
        }
        int index = this.findValue(value); // returns the index position
        if(index == -1) {   // when the index is -1 means the element is not present in the linked list
            System.out.println("The element "+ value +" is not present in the linked list");
            return;
        }
        System.out.println("The element " + value + " is present in the linked list at " + index + " index position");
    }

    // update the value of a existing node
    public void update (int index , int value) {
        if(index < 0 || index > this.length - 1) { // if the index is less than 0 or greater than the size of the linked list
            return;
        }
        Node currentNode = this.findIndex(index);
        currentNode.value = value;

    }

    // sort the linked list
    public void sort () {
        if(this.isEmpty() || this.length == 1) {
            return;
        }
        int count;
        do{
            count = 0;
            Node currentNode = this.head;
            while(currentNode.next != null) {
                if(currentNode.value > currentNode.next.value) {
                    this.swap(currentNode , currentNode.next);
                    count = 1;
                }
                currentNode = currentNode.next;
            }

        }while(count != 0);
    }


    private boolean isEmpty () {
        if(this.length == 0) {
            return true;
        }
        return false;
    }

    public void headNode () {
        if(this.isEmpty()) {
            System.out.println("The Linked List is Empty");
            return;
        }
        System.out.println("The Head Node of the Linked List : " + this.head.value);
    }
    public void tailNode () {
        if(this.isEmpty()) {
            System.out.println("The Linked List is Empty");
            return;
        }
        System.out.println("The Tail Node of the Linked List : " + this.tail.value);
    }

    // returns the length of the linked list
    public int linkedListLength () {
        return this.length;
    }


    // insert when the linked list is empty
    private void insertWhileEmpty (Node newNode) {
        this.head = this.tail = newNode;
        this.length++;
    }

    // deletes an element when there is only one element in the linked list
    private void deleteOnlyElement () {
        this.head = this.tail = null;
        this.length--;
    }
    // find the index of a given node value
    private Node findIndex (int index) {
        int count = 0;
        Node currentNode = this.head;
        while(count != index) {
            count++;
            currentNode = currentNode.next;
        }
        return currentNode;
    }

    // find the value of a given index position node
    private int findValue(int value) {
        int index = 0;
        Node currentNode = this.head;
        while(currentNode != null) {
            if(currentNode.value == value) {
                return index;
            }
            currentNode = currentNode.next;
            index++;
        }
        return -1;
    }
    // swaps two node element called by the sort function
    private void swap (Node first , Node second) {
        int temp = first.value;
        first.value = second.value;
        second.value = temp;
    }
}
