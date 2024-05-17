#include <stdio.h>
#include <stdbool.h>
#define V 5
#define inf 9999

int main() {
    int graph[V][V];
    int src = 0;
    int n = 0;
    int x, y, i, j, min;
    bool visited[V];

    // Input graph from the user
    printf("Enter the adjacency matrix for the graph (%d x %d) separated by spaces or commas:\n", V, V);
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < V; i++) {
        visited[i] = false;
    }

    visited[src] = true;
    while (n < V - 1) {
        x = 0;
        y = 0;
        min = inf;
        for (i = 0; i < V; i++) {
            if (visited[i]) {
                for (j = 0; j < V; j++) {
                    if (!visited[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d -> %d: %d\n", x, y, graph[x][y]);
        visited[y] = true;
        n++;
    }
    return 0;
}
