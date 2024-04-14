#include<stdio.h>

int cost[100][100], parent[20], x, y, i, j, n;

void findMin() {
    int min = 99;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                x = i;
                y = j;
            }
        }
    }
}

int checkCycle(int x, int y) {
    if ((parent[x] == parent[y]) && (parent[x] != 0))
        return 0;
    else if (parent[x] == 0 && parent[y] == 0)
        parent[x] = parent[y] = x;
    else if (parent[x] == 0)
        parent[x] = parent[y];
    else if (parent[x] != parent[y])
        parent[y] = parent[x];
    return 1;
}

int main() {
    int min;
    int count = 0, tot = 0, flag = 0;
    printf("No. Of vertices: ");
    scanf("%d", &n);
    printf("\nEnter cost matrix: ");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            parent[j] = 0;
        }
    }
    while (count != n - 1 && min != 99) {
        findMin();
        flag = checkCycle(x, y);
        if (flag == 1) {
            printf("%d--->%d=%d\n", x, y, cost[x][y]);
            count++;
            tot = tot + cost[x][y];
        }
        cost[x][y] = cost[y][x] = 99;
    }
    printf("Total cost: %d\n", tot);
    return 0;
}
