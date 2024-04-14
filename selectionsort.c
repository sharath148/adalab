#include<stdio.h>
int main(){
    int arr[]={45, 10, 3, 100, 150,98};
     int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr,n);
    printf("SORTED ARRAY \n");
       
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

int selectionsort(int arr[],int n){
    int i,j,minindex;
    for(int i=0;i<n-1;i++){
        minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex])
            minindex=j;
        }
        int temp=arr[minindex];
         arr[minindex]=arr[i];
        arr[i]=temp;

    }
}

