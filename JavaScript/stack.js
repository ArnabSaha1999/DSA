class Stack{
    // creates an empty stack
    constructor() {
        this.stack = [];
    }
    //checks if the stack is empty or not
    isEmpty(){
        if(this.stack.length === 0) {
            return true;
        }
        return false;
    }
    //pushes element onto the stack
    push(element) {
        this.stack.push(element);
    }
    //pops out an element from the stack
    pop() {
        if(this.isEmpty()){
            console.log("The Stack is empty");
        }else{
            this.stack.pop();
        }
    }
    //seeks the top element of the stack
    seek() {
        return this.stack[this.stack.length -1];
    }
    //displays the stack
    display() {
        if(this.isEmpty()){
            console.log("The Stack is empty");
        }else{
            for(let i of this.stack) {  //looping through the stack to print all the elements of the stack
                console.log(i);
            }
        }
    }
}

const stack = new Stack();
stack.pop();
stack.display();
stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);
stack.pop();
stack.push(5)
console.log("The Stack top element is : " + stack.seek());
stack.display();
