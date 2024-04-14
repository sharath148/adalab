#include<stdio.h>

void heapify(int a[], int n, int i) {
    int lar = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[lar])
        lar = l;
    if (r < n && a[r] > a[lar])
        lar = r;
    if (lar != i) {
        int temp = a[i];
        a[i] = a[lar];
        a[lar] = temp;
        heapify(a, n, lar);
    }
}

void heapSort(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    printf("\nHow many students?: ");
    scanf("%d", &n);
    int a[n];
    printf("\nEnter %d student id's in any order: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heapSort(a, n);

    printf("\nStudents id after sorting are:");
    for (int i = 0; i < n; i++)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
