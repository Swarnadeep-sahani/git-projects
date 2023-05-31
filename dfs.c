#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int n;
int adj[MAX][MAX];
int visited[MAX];

void DFS(int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; ++i)
    {
        if(adj[v][i] && !visited[i])
        {
            DFS(i);
        }
    }
}
void main()
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

    printf("DFS Traversal:\n");
    DFS(src);
}