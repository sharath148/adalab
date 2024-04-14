
#include<stdio.h>

int a[20][20], visited[20], q[20], n, v, r = -1, f = 0;

void BFS(int v) {
    printf("\nBFS traversal: ");
    printf("%d", v);
    visited[v] = 1;

    while (f <= r) {
        int currentVertex = q[f++];
        for (int i = 1; i <= n; i++) {
            if (a[currentVertex][i] && !visited[i]) {
                printf("-->%d", i);
                visited[i] = 1;
                q[++r] = i;
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        q[i] = 0;
        for (int j = 1; j <= n; j++)
            a[i][j] = 0;
    }

    printf("\nEnter adjacency matrix: ");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter starting vertex: ");
    scanf("%d", &v);

    q[++r] = v;
    BFS(v);

    return 0;
}
