#include<stdio.h>

void insertionsort(int arr[], int n); // Function prototype

int main() {
    int arr[] = {12, 11, 4, 2, 100, 98};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Calling insertion sort function
    insertionsort(arr, n);
    
    printf("Sorted array:");
    for(int i = 0; i < n; i++)
        printf(" %d", arr[i]);
    
    printf("\n");
    return 0;
}

// Function definition for insertion sort
void insertionsort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
