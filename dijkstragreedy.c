#include <stdio.h>
#include <stdbool.h>

#define V 4
#define inf 999

int minDist(int dist[], bool visited[])
{
    int min_idx = -1;
    int min = inf;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] < min)
        {
            min = dist[v];
            min_idx = v;
        }
    }
    return min_idx;
}

void dijkstra(int graph[V][V], int src)
{
    bool visited[V];
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = inf;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minDist(dist, visited);
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != inf && graph[u][v] + dist[u] < dist[v])
            {
                dist[v] = graph[u][v] + dist[u];
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main()
{
    int graph[V][V];
    printf("Enter the adjacency matrix (use %d for infinity):\n", inf);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("Enter the source vertex (Enter 0 for source): ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
