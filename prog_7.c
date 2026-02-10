#include <stdio.h>

#define MAX 10
#define INF 9999

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
