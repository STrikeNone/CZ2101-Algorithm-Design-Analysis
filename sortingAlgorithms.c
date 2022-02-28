#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[20];
    for(int i=0; i<20; i++){
        arr[i] = rand() % 50;
    }

    printArray(arr, 20);
    heapSort(arr, 20);
    printArray(arr, 20);

    return 0;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
         int temp = arr[0];
         arr[0] = arr[i];
         arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int partition(int *arr, int n, int m){
    int mid = (n+m)/2, temp, i, j, k;
    temp = arr[n];
    arr[n] = arr[mid];
    arr[mid] = temp;
    j = n;
    for(int i=n+1; i<=m; i++){
        if(arr[i] < arr[n]){
            k = arr[i];
            arr[i] = arr[++j];
            arr[j] = k;
        }
    }
    temp = arr[j];
    arr[j] = arr[n];
    arr[n] = temp;
    return j;
}

void quickSort(int *arr, int n, int m){
    if(n >= m){
        return;
    }

    int part = partition(arr, n, m);
    quickSort(arr, n, part-1);
    quickSort(arr, part+1, m);
    return;
}

void mergeSort(int *arr, int n, int m){
    if(n >= m){
        return;
    }
    int mid = (n+m)/2;
    mergeSort(arr, n, mid);
    mergeSort(arr, mid+1, m);
    merge(arr, n, m);

}

void merge(int *arr, int n, int m){
    if(n >= m){
        return;
    }

    int secondHalf = (n+m)/2 + 1;
    int i = secondHalf, j, k;

    while(n <= i && secondHalf <= m){
        if(arr[n] <= arr[secondHalf]){
            n++;
        }else{
            j = arr[secondHalf];
            for(k=secondHalf; k>n; k--){
                arr[k] = arr[k-1];
            }
            arr[n] = j;
            secondHalf++;
            n++;
            i++;
        }
    }

}

void insertionSort(int *arr, int n){
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    printArray(arr, n);
    return;
}
