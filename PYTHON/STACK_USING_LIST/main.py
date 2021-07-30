class Stack:
    # creates an empty stack
    def __init__(self):
        self.stack = []
    # checks if the stack is empty
    def is_empty(self):
        if len(self.stack) == 0:
            return True
        return False

    # pushes an element onto stack
    def push(self , element):
        self.stack.append(element)
    # pops an element out of the stack
    def pop(self):
        if (self.is_empty()) :
            print("Stack Underflow")
        else:
            self.stack.pop()
    # seeks the top element of the stack
    def seek(self):
        return self.stack[len(self.stack)-1]
    # displays all the element of the stack
    def display(self):
        if self.is_empty() :
            print("The Stack is Empty")
        else:
            for i in self.stack:   #loops through all the element of the stack
                print(i , end=" ")

stack = Stack() #creates an object of class Stack
stack.push(109)
stack.pop()
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)
print(stack.seek())
stack.display()

