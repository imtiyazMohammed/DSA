// problem solving using recursion [Insertion sort, Selection Sort, Merge Sort]
#include <bits/stdc++.h>
using namespace std;

// merge function for merge sort
void merge(int *arr, int low, int high){
    int temp[high-low+1];
    int mid = (low+high)/2;
    int p1 = low, p2 = mid+1;
    int k = 0;
    while(p1<=mid && p2<=high){
        if(arr[p1] <= arr[p2]) temp[k++] = arr[p1++];
        else temp[k++] = arr[p2++];
    }
    
    while(p1<=mid) temp[k++] = arr[p1++];
    while(p2<=high) temp[k++] = arr[p2++];
    
    for(int i = 0; i < (high-low+1); i++){
        arr[i+low] = temp[i];
    }
}

// merge Sort
void mergeSort(int *arr, int low, int high){
    if(low == high) return;
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, high);
}

// Selection Sort - wrong code, hasn't solved yet, NEED TO BE UPDATED
void selectionSort(int *arr, int i){
    if(i<=0) return;
    selectionSort(arr, i-1);
    int idx = i-1;
    for(int j = i-1; j>=0; j--){
        if(arr[j] > arr[idx]) idx = j;
    }
    swap(arr[i], arr[idx]);
}

// Insertion sort  
void insertionSort(int *arr, int n){
    if(n<=0) return;
    insertionSort(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    while(j>=0 && arr[j] > last){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}


/* QuickSort - take an element and place it at its right position such that left side of the
elements contains only elements which are less than the element and right side consists of 
only larger elements*/

int partition(int *arr, int start, int end){
    int pivot = arr[start];
    int count = 0;
    for(int i = start+1; i <= end; i++){
        if(arr[i] < pivot) count++;
    }
    int pivotIdx = start+count;
    swap(arr[pivotIdx], arr[start]);
    
    int i = start, j = end;
    while(i<pivotIdx && j> pivotIdx){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        
        if(i<pivotIdx && j> pivotIdx){
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    return pivotIdx;
}

void quickSort(int *arr, int start, int end){
    if(start>=end) return;
    
    int p = partition(arr, start, end);
    
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}

int main() {
    int n = 5;
    int arr[n] = {2,1,5,4,3};
    //mergeSort(arr,0,n-1);
    //selectionSort(arr, n);
    //insertionSort(arr,n);
    quickSort(arr, 0, n-1);
    for(auto i: arr) cout<<i<<" ";
}
