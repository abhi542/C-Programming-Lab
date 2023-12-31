//Graph - Depth First Search
#include <stdio.h>
int a[20][20], visited[20], n;
void dfs(int v)
{
    int i;
    visited[v] = 1;
    for (i = 1; i <= n; i++)
        if (a[v][i] && !visited[i])
        {
            printf("\n %d->%d", v, i);
            dfs(i);
        }
}
int main()
{
    int i, j, count = 0;
    printf("\nEnter number of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    dfs(5);
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        if (visited[i])
            count++;
    }
    if (count == n)
        printf("\n Graph is connected");
    else
        printf("\n Graph is not connected");
}