# Documentation: Comparison of Sorting Algorithms with Performance Analysis

---

## Q1. How are the data structures defined in this program?

### Answer:

This program uses a **one-dimensional array** to store integer elements that are to be sorted using different sorting algorithms.

In this program:

* An integer array is used to store data
* Global variables are used to count comparisons and swaps

```c
long comparisons = 0, swaps = 0;
```

```c
int arr[n];
```

### EXPLAINATION:

* `arr[]` stores the list of randomly generated integers.
* `comparisons` counts the number of key comparisons performed during sorting.
* `swaps` counts the number of swaps performed (not applicable for Merge Sort).
* These counters help analyze the performance of different sorting algorithms.

---

## Q2. What functions are implemented in the program and what is their purpose?

### Answer:

The program implements multiple sorting algorithms and helper functions:

1. `printArray()`
2. `bubbleSort()`
3. `selectionSort()`
4. `insertionSort()`
5. `mergeSort()` and `merge()`

---

### Function 1: `printArray(int arr[], int n)`

**Purpose:**  
To display the elements of the array.

```c
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
```

### EXPLAINATION:

* Traverses the array from index `0` to `n-1`.
* Prints each element.
* Used to display both unsorted and sorted arrays.

---

### Function 2: `bubbleSort(int arr[], int n)`

**Purpose:**  
To sort the array using **Bubble Sort** technique.

```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swaps++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

### EXPLAINATION:

* Repeatedly compares adjacent elements.
* Swaps elements if they are in the wrong order.
* Largest element moves to the end in each pass.
* Time Complexity: **O(n²)**.

---

### Function 3: `selectionSort(int arr[], int n)`

**Purpose:**  
To sort the array using **Selection Sort** technique.

```c
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            swaps++;
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
```

### EXPLAINATION:

* Selects the smallest element from the unsorted portion.
* Swaps it with the first unsorted element.
* Reduces number of swaps compared to Bubble Sort.
* Time Complexity: **O(n²)**.

---

### Function 4: `insertionSort(int arr[], int n)`

**Purpose:**  
To sort the array using **Insertion Sort** technique.

```c
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            swaps++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

### EXPLAINATION:

* Inserts each element into its correct position.
* Efficient for small or nearly sorted arrays.
* Time Complexity: **O(n²)** (worst case).

---

### Function 5: `mergeSort(int arr[], int left, int right)` and `merge()`

**Purpose:**  
To sort the array using **Merge Sort** technique.

```c
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
```

```c
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

### EXPLAINATION:

* Divides the array into smaller subarrays.
* Sorts each subarray recursively.
* Merges sorted subarrays.
* Time Complexity: **O(n log n)**.
* Does not use swaps.

---

## Q3. How is the `main()` function organized?

### Answer:

The `main()` function controls input, random number generation, sorting selection, and output.

### STEPS performed in `main()`:

* Read number of elements.
* Generate random numbers.
* Display unsorted array.
* Allow user to choose sorting algorithm.
* Apply selected sorting method.
* Display sorted array.
* Display number of comparisons and swaps.

```c
int main() {
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000 + 1;

    printf("\nGenerated Numbers:\n");
    printArray(arr, n);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    comparisons = swaps = 0;

    switch (choice) {
        case 1: bubbleSort(arr, n); break;
        case 2: selectionSort(arr, n); break;
        case 3: insertionSort(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1); break;
        default:
            printf("Invalid choice!");
            return 0;
    }

    printf("\nSorted Numbers:\n");
    printArray(arr, n);

    printf("\nTotal Comparisons: %ld\n", comparisons);
    if (choice != 4)
        printf("Total Swaps: %ld\n", swaps);
    else
        printf("Swaps: Not applicable for Merge Sort\n");

    return 0;
}
```

---

## Q4. What is the sample output of a complete run of the program?

### Answer:

### Sample Input:

```
Enter number of elements: 5
Choose Sorting Algorithm: 1
```

### Sample Output:

```
Generated Numbers:
432 120 987 54 301

Sorted Numbers:
54 120 301 432 987

Total Comparisons: 10
Total Swaps: 6
```

---

### Explanation of Output:

* Random numbers are generated automatically.
* Selected sorting algorithm sorts the array.
* Comparisons and swaps are counted.
* Performance metrics help compare sorting techniques.

---
