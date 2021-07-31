# creates a Node class
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


# creates a LinkedList class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0
    # inserting nodes at the end of the linked list
    def append(self, element):
        new_node = Node(element)
        if self.head is None:   # when the linked list is empty
            self.head = self.tail = new_node
            self.length = self.length + 1
            return
        else:
            self.tail.next = new_node
            self.tail = new_node
            self.length = self.length + 1
    # inserting an element at the start of the linked list
    def prepend(self , element):
        if self.head is None :  # when the linked list is empty
            self.append(element)
            return
        new_node = Node(element)
        new_node.next = self.head
        self.length = self.length + 1
        self.head = new_node
    # inserting an element after a given index position
    def insert_after_index(self, index, value):
        if index < 0 :
            return
        if index >= self.length - 1 :
            self.append(value)
            return
        new_node = Node(value)
        current_node = self.find_index(index)
        new_node.next = current_node.next
        current_node.next = new_node
        self.length = self.length+1
    # insert an element before the given index position
    def insert_before_index(self , index , value):
        if index < 0:
            return
        if index == 0 :
            self.prepend(value)
            return
        if index > self.length-1 :
            self.append(value)
            return
        new_node = Node(value)
        current_node = self.find_index(index - 1)
        new_node.next = current_node.next
        current_node.next = new_node
        self.length = self.length + 1

    # deleting an element from the start of the linked list
    def pop_front(self):
        if self.is_empty() :
            return
        if self.head is self.tail:  # when there is only one node
            self.head = self.tail = None
            self.length = self.length - 1
            return
        self.head = self.head.next
        self.length = self.length - 1

    # deleting an element from the end of the linked list
    def pop_back(self):
        if self.is_empty():
            return
        if self.head == self.tail: # when there is only one node
            self.head = self.tail = None
            self.length = self.length - 1
            return
        current_node = self.head
        while current_node != self.tail:
            if current_node.next == self.tail :
                current_node.next = None
                self.tail = current_node
                self.length = self.length - 1
                return
            current_node = current_node.next

    # deleting an node from the given index position
    def delete_node(self , index):
        if index < 0: # if the given position is less than 0 do nothing
            return
        if index == 0:
            self.pop_front()
            return
        if index >= self.length - 1 :
            self.pop_back()
            return
        current_node = self.find_index(index - 1)
        current_node.next = current_node.next.next
        self.length = self.length - 1
        return

    # update the element value present at the given index position
    def update(self , index , value):
        if index >= self.length or index < 0 or self.is_empty():
            return
        current_node = self.find_index(index)
        current_node.value = value

    # reverse the linked list
    def reverse(self) :
        if self.is_empty() or self.length == 1: # when the linked list empty or only one node present do nothing
            return
        next_node = None
        prev_node = None
        current_node = self.head
        self.tail = self.head
        while current_node != None:
            next_node = current_node.next
            current_node.next = prev_node
            prev_node = current_node
            current_node = next_node
        self.head = prev_node
        return

    # searches an element if its present in the linked list and prints the index number
    def search(self , value):
        if self.is_empty():
            return
        current_node = self.find_value(value) # calls the find_value function
        print(current_node)

    # sorts the linked list in ascending order
    def sort(self):
        if self.is_empty() or self.length == 1:
            return

        count = 1
        while count != 0 :
            count = 0
            current_node = self.head
            while current_node.next != None :
                if current_node.value > current_node.next.value :
                    self.swap(current_node , current_node.next) # calls the swap function and swaps the nodes
                    count = 1
                current_node = current_node.next

    # to display the whole linked list
    def display(self):
        if self.is_empty():
            return
        current_node = self.head
        while current_node != None:
            print(current_node.value, end=" ")
            current_node = current_node.next

    # swap function used to swap to nodes
    def swap(self , first , second):
        temp = first.value
        first.value = second.value
        second.value = temp

    # find the index position of a given node
    def find_index(self , index):
        counter = 0
        current_node = self.head
        while counter != index :
            counter = counter+1
            current_node = current_node.next
        return current_node

    # finds the index position of a given value if not present returns -1
    def find_value(self ,value):
        index = 0
        current_node = self.head
        while current_node != None :
            if current_node.value == value :
                return index
            index = index+1
            current_node = current_node.next
        return -1

    # returns the head pointer
    def head_node(self):
        if self.is_empty() :
            return
        return self.head.value

    # returns the tail pointer
    def tail_node(self):
        if self.is_empty() :
            return
        return self.tail.value

    # returns the linked list length
    def linked_list_length(self) :
        return self.length

    # checks if the linked list empty or not
    def is_empty(self):
        if self.length == 0:
            return True
        return False

# program execution starts here the main function
if __name__ == '__main__':
    linked_list = LinkedList()
    linked_list.prepend(4)
    linked_list.prepend(13)
    linked_list.prepend(8)
    linked_list.append(7)
    linked_list.append(3)
    linked_list.append(2)
    linked_list.insert_after_index(8 , 11)
    linked_list.insert_before_index(7 , 6)
    linked_list.pop_back()
    linked_list.pop_front()
    linked_list.delete_node(0)
    linked_list.update(0 , 44)
    linked_list.search(7)
    print("Linked List head pointer :" , linked_list.head_node())
    print("Linked List tail pointer :" , linked_list.tail_node())
    print("Linked List length :" , linked_list.linked_list_length())
    linked_list.display()
    print()
    linked_list.sort()
    print("Linked List head pointer :" , linked_list.head_node())
    print("Linked List tail pointer :" , linked_list.tail_node())
    print("Linked List length :" , linked_list.linked_list_length())
    linked_list.display()
