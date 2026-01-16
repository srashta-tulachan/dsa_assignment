# Documentation: Balanced Parentheses Checking Using Stack

---

## Q1. How are the data structures defined in this program?

### Answer:
This program uses a **stack** as its main data structure.

A stack works on the **LIFO (Last In First Out)** principle, meaning the last element added is removed first.

In this program:
- The stack is implemented using a **character array**
- An integer variable is used to track the top of the stack

```c
#define MAX 100
char stack[MAX];
int top = -1;

EXPLAINATION:
MAX defines the maximum size of the stack.
stack[MAX] stores opening brackets such as (, {, [.
top keeps track of the index of the top element.
top = -1 indicates that the stack is empty at the start.

Q2. What functions are implemented in the program and what is their purpose?
Answer:
The program implements two main stack functions: push() and pop().

Function 1: push(char c)
Purpose:
To insert an opening bracket into the stack.

void push(char c) {
    top++;
    stack[top] = c;
}

EXPLAINATION:
The top value is increased by 1.
The character c is stored at the top position of the stack.
This function is called whenever an opening bracket is found.

Function 2: pop()
Purpose:
To remove and return the top element from the stack.

char pop() {
    return stack[top--];
}
EXPLAINATION:
The function returns the element currently at the top.
After returning, the top value is decreased.
This function is used when a closing bracket is encountered.

Q3. How is the main() function organized?
Answer:
The main() function controls the entire flow of the program.

STEPS performed in main():

Declare variables to store the expression and loop index.
Take the expression as input from the user.
Traverse each character of the expression using a loop.
If an opening bracket is found:
Push it into the stack.
If a closing bracket is found:
Check if the stack is empty.
If yes, the expression is NOT BALANCED.
Pop the last opening bracket.
Check if it matches the closing bracket.
If it does not match, the expression is NOT BALANCED.
After the loop:
If the stack is empty, print BALANCED.
Otherwise, print NOT BALANCED.
This ensures all brackets are properly opened and closed in the correct order.

Q4. What is the sample output of a complete run of the program?
Answer:
Sample Input:
Enter expression: {[()]}
Sample Output:
BALANCED
Another Sample Input:
Enter expression: {(a+b]*c}
Sample Output:
NOT BALANCED
