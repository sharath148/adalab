
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int x[100];

int place(int k, int i) {
    for (int j = 1; j < k; j++)
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    return 1;
}

void nQueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                count++;
                for (int j = 1; j <= n; j++) {
                    for (int p = 1; p <= n; p++) {
                        if (x[j] == p)
                            printf("Q");
                        else
                            printf("0");
                    }
                    printf("\n");
                }
            } else {
                nQueen(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    nQueen(1, n);
    if (count == 0)
        printf("\nNo solution");
    else
        printf("Number of solutions: %d\n", count);
    return 0;
}
