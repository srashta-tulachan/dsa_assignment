# Documentation: Undirected Graph Traversal Using Adjacency Matrix (BFS and DFS)

---

## Q1. How are the data structures defined in this program?

### Answer:

This program uses an **adjacency matrix** to represent an **undirected graph**.

An adjacency matrix is a **2D array** where:

* `1` indicates the presence of an edge
* `0` indicates the absence of an edge

In this program:

* A 2D integer array is used to store the graph
* A 1D array is used to track visited vertices

```c
int adj[10][10];
int visited[10];
int n;
```

### EXPLAINATION:

* `adj[10][10]` represents the adjacency matrix of the graph.
* `visited[10]` keeps track of which vertices have already been visited.
* `n` stores the number of vertices in the graph.
* Since the graph is **undirected**, the adjacency matrix is symmetric.

---

## Q2. What functions are implemented in the program and what is their purpose?

### Answer:

The program implements two important functions: `BFS()` and `DFS()`.

---

### Function 1: `BFS(int start)`

**Purpose:**  
To traverse the graph using the **Breadth First Search (BFS)** technique.

```c
void BFS(int start)
{
    int queue[10];
    int front = 0, rear = 0;
    int i;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
```

### EXPLAINATION:

* BFS uses a **queue** to traverse the graph.
* It visits all neighboring vertices before moving to the next level.
* Each vertex is visited only once using the `visited` array.
* BFS explores the graph **level by level**.

---

### Function 2: `DFS(int v)`

**Purpose:**  
To traverse the graph using the **Depth First Search (DFS)** technique.

```c
void DFS(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}
```

### EXPLAINATION:

* DFS uses **recursion** to traverse the graph.
* It goes as deep as possible before backtracking.
* Each vertex is marked visited to avoid revisiting.
* DFS explores one path completely before moving to another.

---

## Q3. How is the `main()` function organized?

### Answer:

The `main()` function handles input, initializes data structures, and demonstrates BFS and DFS traversal.

### STEPS performed in `main()`:

* Read the number of vertices.
* Read the adjacency matrix from the user.
* Initialize the `visited` array.
* Call the `BFS()` function starting from vertex `0`.
* Reset the `visited` array.
* Call the `DFS()` function starting from vertex `0`.

```c
int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    BFS(0);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");

    return 0;
}
```

This structure ensures correct traversal of the graph using both BFS and DFS techniques.

---

## Q4. What is the sample output of a complete run of the program?

### Sample Input:

```
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
```

### Sample Output:

```
BFS Traversal: 0 1 2 3
DFS Traversal: 0 1 3 2
```

---

### Explanation of Output:

* BFS visits vertices level by level starting from vertex `0`.
* DFS explores one complete path before backtracking.
* The output confirms correct traversal of the undirected graph.

---
