# Documentation: Infix to Postfix Conversion Using Stack

---

## Q1. How are the data structures defined in this program?

### Answer:

This program uses a **stack** as its main data structure.

A stack follows the **LIFO (Last In First Out)** principle, where the last inserted element is removed first.

In this program:

* The stack is implemented using a **character array**
* An integer variable is used to track the top of the stack

```c
char stack[100];
int top = -1;
```

### EXPLAINATION:

* `stack[100]` is used to store operators such as `+`, `-`, `*`, `/`, and parentheses.
* `top` stores the index of the top element in the stack.
* `top = -1` indicates that the stack is empty at the beginning of the program.

---

## Q2. What functions are implemented in the program and what is their purpose?

### Answer:

The program implements three important functions: `push()`, `pop()`, and `priority()`.

---

### Function 1: `push(char x)`

**Purpose:**
To insert an operator or parenthesis into the stack.

```c
void push(char x)
{
    stack[++top] = x;
}
```

### EXPLAINATION:

* The `top` variable is incremented first.
* The character `x` is stored at the new top position.
* This function is called when an operator or opening parenthesis is encountered.

---

### Function 2: `pop()`

**Purpose:**
To remove and return the top element from the stack.

```c
char pop()
{
    return stack[top--];
}
```

### EXPLAINATION:

* The function returns the element at the current top of the stack.
* After returning the element, `top` is decremented.
* This function is used to remove operators from the stack when required.

---

### Function 3: `priority(char x)`

**Purpose:**
To determine the precedence of operators.

```c
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}
```

### EXPLAINATION:

* Parentheses have the lowest priority.
* `*` and `/` have higher priority than `+` and `-`.
* This function helps maintain correct operator precedence during conversion.

---

## Q3. How is the `main()` function organized?

### Answer:

The `main()` function controls the complete process of converting an infix expression into a postfix expression.

### STEPS performed in `main()`:

* Declare variables to store the infix expression and pointer variables.
* Take the infix expression as input from the user.
* Traverse the expression character by character using a loop.
* If an operand (letter or digit) is found:

  * Print it directly as part of the postfix expression.
* If an opening parenthesis `(` is found:

  * Push it onto the stack.
* If a closing parenthesis `)` is found:

  * Pop and print elements from the stack until `(` is encountered.
* If an operator is found:

  * Pop operators from the stack that have higher or equal precedence.
  * Push the current operator onto the stack.
* After processing the entire expression:

  * Pop and print all remaining operators from the stack.

This ensures that the postfix expression follows correct operator precedence and order.

---

## Q4. What is the sample output of a complete run of the program?

### Answer:

### Sample Input:

```
Enter the expression: A+B*C
```

### Sample Output:

```
ABC*+
```

---

### Another Sample Input:

```
Enter the expression: (A+B)*C
```

### Sample Output:

```
AB+C*
```

---


