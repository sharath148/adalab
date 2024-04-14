#include<stdio.h>

int a[20][20], visited[20], n, v;

void DFS(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            printf("-->%d", i);
            visited[i] = 1;
            DFS(i);
        }
    }
}

int main() {
    int count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++)
            a[i][j] = 0;
    }

    printf("\nEnter adjacency matrix: ");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter starting vertex: ");
    scanf("%d", &v);

    printf("\nDFS traversal: \n");
    printf("%d", v);

    DFS(v);

    for (int i = 1; i <= n; i++)
        if (visited[i])
            count++;
    if (count == n)
        printf("\nGraph is connected");
    else
        printf("\nDisconnected");
    return 0;
}
