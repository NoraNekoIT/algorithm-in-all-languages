//heap sort
#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int arr[]={93,46,87,52,92,15,30,26,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    heapSort(arr,n);    
    printf("\nSorted array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);    
    return 0;
}