# Documentation: Doubly Linked List Operations

---

## Q1. How are the data structures defined in this program?

### Answer:

This program uses a **doubly linked list** as its main data structure.

A doubly linked list is a dynamic data structure where each node contains:

* Data
* A pointer to the next node
* A pointer to the previous node

In this program:

```c
struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};
```

### EXPLAINATION:

* `data` stores the integer value of the node.
* `next` points to the next node in the list.
* `prev` points to the previous node in the list.
* If `next` or `prev` is `NULL`, it indicates the end or beginning of the list.
* Memory for each node is allocated dynamically using `malloc()`.

---

## Q2. What functions are implemented in the program and what is their purpose?

### Answer:

The program implements four important functions:

1. `insertAtBeginning()`
2. `insertAfter()`
3. `deleteNode()`
4. `display()`

---

### Function 1: `insertAtBeginning(struct Node* head, int data)`

**Purpose:**  
To insert a new node at the beginning of the doubly linked list.

```c
struct Node* insertAtBeginning(struct Node* head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    return newNode;
}
```

### EXPLAINATION:

* A new node is created using dynamic memory allocation.
* The new node’s `next` pointer points to the current head.
* If the list is not empty, the previous head’s `prev` pointer is updated to the new node.
* The new node becomes the new head of the list.

---

### Function 2: `insertAfter(struct Node* givenNode, int data)`

**Purpose:**  
To insert a new node after a given node in the doubly linked list.

```c
void insertAfter(struct Node* givenNode, int data)
{
    if (givenNode == NULL) {
        printf("Given node is NULL\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = givenNode->next;
    newNode->prev = givenNode;

    if (givenNode->next != NULL)
        givenNode->next->prev = newNode;

    givenNode->next = newNode;
}
```

### EXPLAINATION:

* A new node is created and linked after `givenNode`.
* The `prev` and `next` pointers of surrounding nodes are updated to maintain the doubly linked list structure.
* This allows insertion **anywhere in the middle** of the list.

---

### Function 3: `deleteNode(struct Node* head, struct Node* delNode)`

**Purpose:**  
To delete a specified node from the doubly linked list.

```c
struct Node* deleteNode(struct Node* head, struct Node* delNode)
{
    if (head == NULL || delNode == NULL)
        return head;

    if (head == delNode)
        head = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    free(delNode);
    return head;
}
```

### EXPLAINATION:

* Handles deletion of any node: beginning, middle, or end.
* Updates the `next` and `prev` pointers of neighboring nodes.
* Frees memory allocated to the deleted node to avoid memory leaks.
* Returns the updated head in case the head was deleted.

---

### Function 4: `display(struct Node* head)`

**Purpose:**  
To display the elements of the doubly linked list.

```c
void display(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```

### EXPLAINATION:

* Traverses the list from head to end.
* Prints the `data` of each node.
* Shows the current state of the list after insertion or deletion.

---

## Q3. How is the `main()` function organized?

### Answer:

The `main()` function demonstrates creating and manipulating a doubly linked list using the implemented functions.

### STEPS performed in `main()`:

* Initialize the head pointer to `NULL`.
* Insert elements at the beginning of the list using `insertAtBeginning()`.
* Display the initial list.
* Insert a node after a specific node using `insertAfter()`.
* Display the list after insertion.
* Delete a node using `deleteNode()`.
* Display the list after deletion.

```c
int main()
{
    struct Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printf("Initial list:\n");
    display(head);

    insertAfter(head->next, 25);
    printf("After inserting 25 after second node:\n");
    display(head);

    head = deleteNode(head, head->next);
    printf("After deleting second node:\n");
    display(head);

    return 0;
}
```

---

## Q4. What is the sample output of a complete run of the program?

### Sample Output:

```
Initial list:
30 20 10
After inserting 25 after second node:
30 20 25 10
After deleting second node:
30 25 10
```

---

### Explanation of Output:

* Initially, nodes `30 → 20 → 10` are inserted at the beginning.
* `25` is inserted after the second node (`20`), resulting in `30 → 20 → 25 → 10`.
* Deleting the second node (`20`) updates the list to `30 → 25 → 10`.
* The display function confirms that the doubly linked list updates correctly after each operation.

---
