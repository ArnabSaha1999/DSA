//creates a Node class with next and value
class Node {
    constructor (value) {
        this.value = value;
        this.next = null;
    }
}
// creates a LinkedList class with a head , tail and length variable
class LinkedList{
    //initialized head , tail and length when constructor is called
    constructor (){
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    //inserts an element at the end of the list or after the tail
    append (element) {
        const newNode = new Node(element);
        if(this.head === null){ // if the linked list is empty
            this.head = this.tail = newNode;
            this.length++;
            return;
        } // when the linked list has at least one element
        this.tail.next = newNode;
        this.tail = newNode;
        this.length++;

    }
    // inserts an element before the head pointer or at the first position of the list
    prepend (element) {
        const newNode = new Node(element);
        newNode.next = this.head;
        this.head = newNode;
        this.length++;
    }
    // insert after a given index position
    insertAfterIndex (index , element) {
        if(index === undefined || index < 0 || element === undefined){ // if any of the parameter is not defined
            return 0;
        }
        const newNode = new Node(element);
        if(index >= this.length - 1) { // when entered index is greater than the length append is called
            this.append(element);
        } else{
            let currentNode = this.findIndex(index);
            newNode.next = currentNode.next;
            currentNode.next = newNode;
            this.length++;
        }

    }
    // insert an element before a given index
    insertBeforeIndex (index , element) {
        if(index === undefined || index < 0 || element === undefined){ //if any parameter is missing
            return 0;
        }
        if(index === 0){    // when the given index is the first position of the list
            this.prepend(element);
        }else if(index >= this.length-1) {  // when the given index is the last position of the list
            this.append(element);
        } else {
            const newNode = new Node(element);
            const currentNode = this.findIndex(index-1);
            newNode.next = currentNode.next;
            currentNode.next = newNode;
            this.length++;
        }

    }
    //to find a given value present or not in the list and return the index of it
    findValue (element) {
        let currentNode = this.head;
        let index = 0;
        while(currentNode !== null) {
            if(currentNode.value === element) {
                return index;
            }
            currentNode = currentNode.next;
            index ++;
        }
        console.log('The element ' + element + ' is not present in the link list');
        return -1;
    }
    //find the index no of the linked list
    findIndex (index){
        let currentNode = this.head;
        let counter = 0;
        while(counter !== index){
            counter++;
            currentNode = currentNode.next;
        }
        return currentNode;
    }
    //pops an element out from the start of the list
    popFront () {
        if(this.isEmpty()) {
            return ;
        }
        if(this.head === this.tail){ // when there is only one element present in the list
            this.length--;
            return this.head = this.tail = null;
        }
        this.head = this.head.next;
        this.length--;
    }
    //pops an element out of the list from the end of the list
    popBack (){
        if(this.isEmpty()) {
            return;
        }
        let currentNode = this.head;
        if(this.head === this.tail){    // when there is only one element present in the list
            this.head = this.tail = null;
            this.length--;
            return;
        }
        while(currentNode.next !== null){
            if(currentNode.next === this.tail ){
                currentNode.next = null;
                this.tail = currentNode;
                this.length--;
                break;
            }
            currentNode = currentNode.next;
        }
    }
    // deletes an element from the given position
    deleteNode (index) {
        if(this.isEmpty()) {
            return;
        }
        if(index === 0){ // when given index is first index
            this.popFront();
        } else if(index >= this.length) { // when given index is the last index
            this.popBack();
        } else {
            const currentNode = this.findIndex(index - 1);
            currentNode.next = currentNode.next.next;
            this.length--;
        }
    }
    // deletes the whole linked list
    deleteLinkedList () {
        if(this.isEmpty()) {
            return;
        }
        this.head = this.tail = null;
        this.length = 0;
    }
    // returns the head node of the list
    headNode () {
        return this.head;
    }
    // returns the tail node of the list
    tailNode() {
        return this.tail;
    }
    // returns the length of the list
    linkedListLength () {
        return this.length;
    }
    // sorts the list in ascending order
    sort () {
        if(this.isEmpty() || this.length === 1) {
            return;
        }
        let count;
        do {
            let currentNode = this.head;
            count = 0;
            while(currentNode.next !== null) {
                if(currentNode.value > currentNode.next.value){ // when we find an greater value we swaps the greater value with a smaller value
                    this.swap(currentNode , currentNode.next); // calls the swap function
                    count = 1;
                }
                currentNode = currentNode.next;
            }

        }while(count !== 0);
        this.display();
    }
    // to update an element using the index
    update (index , element) {
        if((index >= this.length || index < 0) || index === undefined || element === undefined) {
            return;
        }
        const targetNode = this.findIndex(index);
        targetNode.value = element;
    }
    // to search an element from the list
    search (element) {
        if(element === undefined) {
            return ;
        }
        const targetNode = this.findValue(element);
        console.log(targetNode);
    }
    //checks if the list is empty or not
    isEmpty () {
        if(this.length === 0) {
            console.log('The Linked List is Empty');
            return true;
        }
    }
    //reverses the list
    reverse () {
        if(this.isEmpty() || this.length === 1) {  // if the list is empty or if the list has only one element then we do not need to do any operation
            return;
        }
        let prevNode = null;
        let nextNode = null;
        let currentNode = this.head;
        this.tail = this.head;  //making the head node the tail node
        while(currentNode !== null) {
            nextNode = currentNode.next;
            currentNode.next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        this.head = prevNode; // assigning the head node a new value
    }
    //swaps two elements
    swap (smallValue , bigValue) {
        if(smallValue === undefined || bigValue === undefined) {
            return ;
        }
        let temp = smallValue.value;
        smallValue.value = bigValue.value;
        bigValue.value = temp;
    }
    //displays the elements of the linked list
    display () {
        if(this.isEmpty()) {
            return;
        }
        let currentNode = this.head;
        while(currentNode !== null){ //looping through each element
            console.log(currentNode.value);
            currentNode = currentNode.next;
        }
    }
}
// creating object of the LinkedList class
const linkedList = new LinkedList();
linkedList.append(3);
linkedList.append(2);
linkedList.append(2);
linkedList.append(6);
linkedList.append(10);
linkedList.prepend(0);
linkedList.append(14);
linkedList.insertAfterIndex(5, 19);
linkedList.popFront();
linkedList.popBack();
linkedList.prepend(43);
linkedList.update(0 , 100);
console.log(linkedList.headNode());
console.log(linkedList.tailNode());
linkedList.display();
linkedList.search(88)
linkedList.reverse();
console.log('after reversing');
console.log(linkedList.headNode());
console.log(linkedList.tailNode());
linkedList.display();
linkedList.append(0);
console.log('after sorting')
linkedList.sort();
console.log('after reversing again');
linkedList.reverse();
linkedList.display();
console.log("Length of the Linked List " + linkedList.linkedListLength());
