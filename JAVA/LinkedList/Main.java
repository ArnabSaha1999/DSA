package Arnab.com;

public class Main {

    public static void main(String[] args) {
	    LinkedList linkedList = new LinkedList();
	    linkedList.pushBack(34);
		linkedList.pushBack(45);
		linkedList.pushBack(35);
		linkedList.pushFront(25);
		linkedList.pushFront(15);
		linkedList.insertAfterIndex(2 , 55);
		linkedList.insertBeforeIndex(4 , 65);
		linkedList.deleteNode(0);
		linkedList.update(1, -44);
		linkedList.search(35);
		linkedList.reverse();
	    linkedList.headNode();
	    linkedList.tailNode();
	    linkedList.display();
    }
}
