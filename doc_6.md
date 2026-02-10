# Documentation: Building Min Heap and Max Heap from an Unsorted Array

---

## Q1. How are the data structures defined in this program?

### Answer:

This program uses an **array** as its main data structure to implement both **Min Heap** and **Max Heap**.

A heap is a complete binary tree that is efficiently represented using an array.

In this program:

* Arrays are used to store integer elements
* Separate arrays are maintained for Min Heap and Max Heap

```c
int arr[10];
int minHeap[10];
int maxHeap[10];
```

### EXPLAINATION:

* `arr` stores the original unsorted input elements.
* `minHeap` is used to build the Min Heap.
* `maxHeap` is used to build the Max Heap.
* The heap structure is maintained using array indexing:
  * Left child index = `2*i + 1`
  * Right child index = `2*i + 2`
* Fixed-size arrays are used for simplicity.

---

## Q2. What functions are implemented in the program and what is their purpose?

### Answer:

The program implements six important functions:

* `swap()`
* `minHeapify()`
* `maxHeapify()`
* `buildMinHeap()`
* `buildMaxHeap()`
* `display()`

---

### Function 1: `swap(int *a, int *b)`

**Purpose:**  
To swap two integer values.

```c
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### EXPLAINATION:

* A temporary variable is used to exchange values.
* This function helps rearrange elements during heap construction.

---

### Function 2: `minHeapify(int arr[], int n, int i)`

**Purpose:**  
To maintain the Min Heap property.

```c
void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
```

### EXPLAINATION:

* Compares the parent node with its children.
* Finds the smallest value among them.
* Swaps elements if Min Heap property is violated.
* Uses recursion to fix the heap.

---

### Function 3: `maxHeapify(int arr[], int n, int i)`

**Purpose:**  
To maintain the Max Heap property.

```c
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
```

### EXPLAINATION:

* Compares parent and child nodes.
* Finds the largest element.
* Swaps values if Max Heap property is violated.
* Recursively restores heap structure.

---

### Function 4: `buildMinHeap(int arr[], int n)`

**Purpose:**  
To build a Min Heap from an unsorted array.

```c
void buildMinHeap(int arr[], int n)
{
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}
```

### EXPLAINATION:

* Starts heapification from the last non-leaf node.
* Ensures Min Heap property for all nodes.

---

### Function 5: `buildMaxHeap(int arr[], int n)`

**Purpose:**  
To build a Max Heap from an unsorted array.

```c
void buildMaxHeap(int arr[], int n)
{
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
```

### EXPLAINATION:

* Similar to Min Heap creation.
* Uses Max Heap rules instead.

---

### Function 6: `display(int arr[], int n)`

**Purpose:**  
To display the elements of the heap.

```c
void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
```

### EXPLAINATION:

* Traverses the array.
* Prints all heap elements.

---

## Q3. How is the `main()` function organized?

### Answer:

The `main()` function controls input, heap creation, and output display.

### STEPS performed in `main()`:

* Read number of elements.
* Accept unsorted array input.
* Copy array into Min Heap and Max Heap arrays.
* Build Min Heap.
* Build Max Heap.
* Display both heaps.

```c
int main()
{
    int arr[10], minHeap[10], maxHeap[10];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        minHeap[i] = arr[i];
        maxHeap[i] = arr[i];
    }

    buildMinHeap(minHeap, n);
    buildMaxHeap(maxHeap, n);

    printf("Min Heap:\n");
    display(minHeap, n);

    printf("Max Heap:\n");
    display(maxHeap, n);

    return 0;
}
```

---

## Q4. What is the sample output of a complete run of the program?

### Answer:

### Sample Input:

```
Enter number of elements: 6
Enter array elements:
10 30 20 5 7 15
```

### Sample Output:

```
Min Heap:
5 7 15 30 10 20

Max Heap:
30 10 20 5 7 15
```

---

### Explanation of Output:

* The Min Heap places the smallest element at the root.
* The Max Heap places the largest element at the root.
* This confirms correct heap construction.

---
