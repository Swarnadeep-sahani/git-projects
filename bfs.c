
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n;
int adj[MAX][MAX];
int visited[MAX];

void bfs(int v)
{
    int q[MAX], f = 0, r = -1;
    int i;

    visited[v] = 1;
    q[++r] = v;

    while (f <= r)
    {
        v = q[f++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] && !visited[i])
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
    }
}

int main()
{
    int i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    printf("BFS Traversal:\n");
    bfs(src);

    return 0;
}
