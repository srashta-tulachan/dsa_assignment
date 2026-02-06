# Documentation: Reverse Traversal of a Linked List Using Recursion

---

## Q1. How are the data structures defined in this program?

### Answer:

This program uses a **singly linked list** as its main data structure.

A linked list is a dynamic data structure where each element (node) contains data and a pointer to the next node.

In this program:

* The linked list is implemented using a **structure**
* Each node contains an integer value and a pointer to the next node

```c
struct Node
{
    int data;
    struct Node* next;
};
```

### EXPLAINATION:

* `data` stores the integer value of the node.
* `next` stores the address of the next node in the linked list.
* If `next` is `NULL`, it indicates the end of the linked list.
* Memory for each node is allocated dynamically using `malloc()`.

---

## Q2. What functions are implemented in the program and what is their purpose?

### Answer:

The program implements two important functions: `Insert()` and `Print()`.

---

### Function 1: `Insert(struct Node* head, int data)`

**Purpose:**  
To insert a new node at the end of the linked list.

```c
struct Node* Insert(struct Node* head, int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
        head = temp;
    else
    {
        struct Node* temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}
```

### EXPLAINATION:

* A new node is created using dynamic memory allocation.
* The given value is stored in the `data` field.
* If the list is empty, the new node becomes the head.
* Otherwise, the function traverses to the last node and inserts the new node.
* The updated head pointer is returned.

---

### Function 2: `Print(struct Node* p)`

**Purpose:**  
To print the elements of the linked list in **reverse order** using recursion.

```c
void Print(struct Node* p)
{
    if(p == NULL)
    {
        printf("\n");
        return;
    }
    Print(p->next);
    printf("%d ", p->data);
}
```

### EXPLAINATION:

* The function uses recursion to traverse the linked list.
* If the pointer is `NULL`, the recursion stops.
* The recursive call is made before printing the data.
* This causes the elements to be printed in reverse order.

---

## Q3. How is the `main()` function organized?

### Answer:

The `main()` function controls the creation of the linked list and performs reverse traversal.

### STEPS performed in `main()`:

* Initialize the head pointer to `NULL`.
* Insert elements into the linked list using the `Insert()` function.
* Call the `Print()` function to display the list in reverse order.

```c
int main()
{
    struct Node* head = NULL;

    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);

    Print(head);
}
```

This ensures that the linked list is created correctly and printed in reverse order.

---

## Q4. What is the sample output of a complete run of the program?

### Answer:

### Sample Input:

```
Linked List Elements: 2 4 6 5
```

### Sample Output:

```
5 6 4 2
```

---

### Explanation of Output:

* The elements are inserted in normal order.
* The `Print()` function uses recursion.
* Due to recursive calls, the last element is printed first.
* This results in reverse traversal of the linked list.

---
