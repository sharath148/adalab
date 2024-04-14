#include<stdio.h>

int n, a[20][20], s[20], d[20], v;

void dijkshtra() {
    int u;
    for (int i = 1; i <= n; i++) {
        d[i] = a[v][i];
        s[i] = 0;
    }
    d[v] = 0;
    s[v] = 1;
    for (int k = 2; k <= n; k++) {
        int min = 99;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }
        s[u] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 0) {
                if (d[i] > d[u] + a[u][i])
                    d[i] = d[u] + a[u][i];
            }
        }
    }
    printf("The shortest path from %d is:\n", v);
    for (int i = 1; i <= n; i++) {
        printf("%d-->%d=%d\n", v, i, d[i]);
    }
}

int main() {
    printf("Vertices: ");
    scanf("%d", &n);
    printf("\nCost matrix: ");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("\nSource vertex: ");
    scanf("%d", &v);
    dijkshtra();
    return 0;
}
