# Documentation: Dijkstra’s Algorithm Using Adjacency Matrix

---

## Q1. How are the data structures defined in this program?

### Answer:

This program uses an **adjacency matrix** to represent a **weighted graph** and applies **Dijkstra’s Algorithm** to find the shortest path from a source node.

In this program:

* A 2D array is used to store the graph
* One-dimensional arrays are used to store distances and visited status

```c
#define MAX 10
#define INF 9999

int graph[MAX][MAX];
int distance[MAX];
int visited[MAX];
```

### EXPLAINATION:

* `graph[MAX][MAX]` represents the adjacency matrix of the graph.
* Each value in the matrix represents the weight of the edge.
* A value `0` indicates no direct edge between two nodes.
* `distance[MAX]` stores the shortest distance from the source node.
* `visited[MAX]` keeps track of nodes that have already been processed.
* `INF` is used to represent infinity (very large value).

---

## Q2. What functions are implemented in the program and what is their purpose?

### Answer:

This program does **not use user-defined functions**.

All the logic of **Dijkstra’s Algorithm** is implemented directly inside the `main()` function.

The program performs the following tasks:

* Accepts graph input
* Initializes required arrays
* Applies Dijkstra’s Algorithm
* Displays the shortest distances

---

## Q3. How is the `main()` function organized?

### Answer:

The `main()` function controls the entire execution of the program, including input, processing, and output.

### STEPS performed in `main()`:

* Read number of nodes
* Read adjacency matrix
* Read source node
* Initialize distance and visited arrays
* Apply Dijkstra’s Algorithm
* Print shortest distances

```c
int main() {
    int n, i, j, source;
    int graph[MAX][MAX];
    int distance[MAX];
    int visited[MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (i = 0; i < n - 1; i++) {
        int min = INF, u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] != 0 &&
                distance[u] + graph[u][j] < distance[j]) {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("To node %d = %d\n", i, distance[i]);
    }

    return 0;
}
```

---

## Q4. How does Dijkstra’s Algorithm work in this program?

### Answer:

Dijkstra’s Algorithm finds the **shortest path from a source node** to all other nodes in a weighted graph.

### WORKING PRINCIPLE:

* Start from the source node.
* Assign distance `0` to source and `INF` to all other nodes.
* Repeatedly select the unvisited node with the minimum distance.
* Mark the selected node as visited.
* Update distances of its neighboring nodes.
* Repeat until all nodes are visited.

---

## Q5. What is the sample output of a complete run of the program?

### Answer:

### Sample Input:

```
Enter number of nodes: 4
Enter adjacency matrix (0 for no edge):
0 1 4 0
1 0 2 6
4 2 0 3
0 6 3 0
Enter source node: 0
```

### Sample Output:

```
Shortest distances from source 0:
To node 0 = 0
To node 1 = 1
To node 2 = 3
To node 3 = 6
```

---

### Explanation of Output:

* The source node distance is always `0`.
* The algorithm calculates the shortest path to each node.
* Distance values are updated only if a shorter path is found.
* Final distances represent the minimum cost from the source.

---
